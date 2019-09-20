## Assignment
Now that we've successfully used syscalls and we know how to parse arguments with some research, let's move onto something a little bit more complicated but still very doable. We're going to create a C program that binds a command shell to a listening port, also known as a bind shell. (in TCP!)

I'm going to tell you the syscalls we need to make in order to accomplish this and also try and drop some hints about potential sticking points. I won't be fully walking through this one like our previous excercise, but as always there will be a solution made available should you get stuck (`assignment26.c`). 

A good resource throughout this excercise will be the socket programming tutorial here: http://www.cs.rpi.edu/~moorthy/Courses/os98/Pgms/socket.html **Keep referencing this document for every single parameter, every single function.**

@epi052 also recommended the following great resource: https://beej.us/guide/bgnet/html/multi/index.html

## Getting Started

### Header Files
We're going to need to include the following header files:
```c
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
```

Pull these header files up and read through them, learn what they're for and why we need them. You should be finding man pages for all of these syscalls and reading about their parameters and finding their definitions. 

## Syscalls

### Socket()
The first syscall we're going to make is `socket()`. The explanation for socket is not very difficult, you can do this! Make sure you pay attention to the return value, this value will be needed for subsequent syscalls. 

### Bind()
The next syscall will be `bind()`. This one is a bit of a doozie so I will help you with this one. The function definition for bind is: `int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)`. We can get the `sockfd` parameter from our `socket()` call. 

Next we need to build a struct which we're used to. The struct definition we'll be using is the one for `sockaddr_in`. This is because `bind()` takes an argument that is a pointer to a struct of type `sockaddr`; however, we actually use `sockaddr_in` as our struct type because they are the same size and according to the manpage for bind, "the only purpose of \[the sockaddr structure\] is to cast the structure pointer passed in addr in order to avoid compiler warnings."

We first need to create an instace of the `sockaddr_in` struct called `server_addr` as this code will be run on the server in a client-server paradigm of network connections:
```c
struct sockaddr_in server_addr;
```
Next, we need to start assigning values to the members of this struct. The relevant members for us are:
+ `sin_family`,
+ `sin_port`, and
+ `sin_addr`. 

`sin_family`, if we read the manpages **like we always do**, can take values defined inside of `<sys/socket.h>`. We're interested in creating a TCP bind shell, so we'll need to use the `AF_INET` value for this struct member as it's for 'internetwork: UDP, TCP, etc' addresses families. So we can give this a value with our dot notation we learned with: `server_adder.sin_family = AF_INET;`. Easy! We've done that a bunch already.

Next, we need to set `sin_addr`. The `sin_addr` member is actually of type `struct in_addr` which is also defined in `<netinet/in.h>`. The struct `in_addr` contains only one member, an unsigned long `s_addr`. So we'll need to double up our dot notation for this one since we're creating a value for a member that is a struct of another struct. (We did this already as well.) Both struct prototypes are detailed [here](https://www.gta.ufrj.br/ensino/eel878/sockets/sockaddr_inman.html) as follows:
```c
#include <netinet/in.h>

struct sockaddr_in {
    short            sin_family;   // e.g. AF_INET
    unsigned short   sin_port;     // e.g. htons(3490)
    struct in_addr   sin_addr;     // see struct in_addr, below
    char             sin_zero[8];  // zero this if you want to
};

struct in_addr {
    unsigned long s_addr;  // load with inet_aton()
};
```
So, to set the value to the `sin_addr` member, we need to specify: `sever_addr.sin_addr.s_addr = <insert value>`. What does `sin_addr` even do? It specifies the address of the machine we want to listen on (the server). From the ip manpage: "*When a process wants to receive new incoming packets or connections, it should bind a socket to a local interface address using bind(2). In this case, only one IP socket may be bound to any given local(address, port) pair.  When INADDR_ANY is specified in the bind call, the socket will be bound to all local interfaces.*" We want to listen on all interfaces, so we'll set this value to `INADDR_ANY`. We can set it with: `sever_addr.sin_addr.s_addr = INADDR_ANY` 

The last member of our struct is `sin_port`, and according to the aforementioned `sockaddr_in` definition, we need to use `htons()` function to convert our port value to network byte order. This should be relatively simple! `server_addr.sin_port = htons(5555)` should do the trick. 

We've now completed our struct! That's two of the three `bind()` arguments down. 

Lastly, we need `socklen_t addrlen` which according to the `bind()` manpage is just the size, in bytes, of the struct pointed to in the parameter we just filled with our newly created struct. So this argument will simply be `sizeof(server_addr)`, something we've already done before. 

Altogether, our bind argument should look like this `bind(sockfd <figure this out by yourself>, (struct sockaddr *)&server_addr, sizeof(server_addr));`

We have `(struct sockaddr *)` which creates a pointer of type sockaddr (a struct), and we point it to the location in memory of our `server_addr` struct with the `&`. Lastly, we tacked on our `sizeof()` final argument. Not too bad and that was by far the hardest syscall in the program!

### Listen()
The good news is that this syscall is very straight forward. I'd say for the backlog you can specify `0`. 

### Accept()
For this syscall, read the description of the syscall here: https://www.geeksforgeeks.org/accept-system-call/. For this excercise, we can go ahead and use `NULL` as the value for the 2nd and 3rd arguments. **Pay close attention to the return value of this call. This value will be used in subsequent syscalls.**

### Dup2()
This syscall itself isn't tricky, but its implementation in our program is. What duplicate does is take an old file descriptor (returned from our `accept()` syscall), and duplicates it to stdin, stdout, and stderr. These three file descriptors have values of `0`, `1`, and `2` respectively, which we learned in our last assignment. Use `dup2()` three times to copy the old file descriptor to these three new ones. (Extra credit: implement a for loop.)

### Execve()
This is our last syscall. We want to use this syscall to execute `/bin/sh` so that our client can have a shell! This syscall can be called with the name of the program you want executed and then two `NULL` arguments for this program. 

## Summary
If this is your first time working with sockets, you will probably spend a lot of time researching, that is perfectly fine and intended. Don't get frustrated, if you run into any problems reach out. As a last resort, check the solution which has been commented. 

Extra Credit: Add error checking to your program!
