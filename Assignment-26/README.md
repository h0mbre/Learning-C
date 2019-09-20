## Assignment
Now that we've successfully used syscalls and we know how to parse arguments with some research, let's move onto something a little bit more complicated but still very doable. We're going to create a C program that binds a command shell to a listening port, also known as a bind shell. 

I'm going to tell you the syscalls we need to make in order to accomplish this and also try and drop some hints about potential sticking points. I won't be fully walking through this one like our previous excercise, but as always there will be a solution made available should you get stuck (`assignment26.c`). 

A good resource throughout this excercise will be the socket programming tutorial here: http://www.cs.rpi.edu/~moorthy/Courses/os98/Pgms/socket.html

## Getting Started

### Header Files
We're going to need to include the following header files:
```c
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
```

Pull these header files up and read through them, learn what they're for and why we need them. You should be finding man pages for all of these syscalls and reading about their parameters and finding their definitions. 

### Syscalls

The first syscall we're going to make is `socket()`. The explanation for socket is not very difficult



The first syscall we're going to use is the `socket()` syscall, you can read about it here: 

 
