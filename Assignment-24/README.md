## Assignment
For this excercise we're going to build a C program that executes syscalls! We've already learned basically everything we need to know in C up until this point to accomplish this. We are going to keep it simple and we're going to use the `open()` and `write()` sycalls only here. 

## Getting Started
Let's go ahead and create a blank file in our working directory called assignment24.txt with `echo "" > assignment24.txt`.
Look in your working directory and you should see the file now. Next we're going to start writing our code. 

The first thing you need to know is that the `unistd.h` header file contains all of the syscall wrapper functions we need and `fcntl.h` contains file control functions. So we need to include those:
```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
```

Next, we need to determine how to open the file using the `open()` syscall. To do this, we can consult [codewiki](http://codewiki.wikidot.com/c:system-calls:open). 

