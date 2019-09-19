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

Next, we need to determine how to open the file using the `open()` syscall. To do this, we can consult [codewiki](http://codewiki.wikidot.com/c:system-calls:open). The function definition according to codewiki is:
`int open(const char *path, int oflags);`

+ `const char *path` is "The relative or absolute path to the file that is to be opened."
+ `int oflags` is "A bitwise 'or' separated list of values that determine the method in which the file is to be opened (whether it should be read only, read/write, whether it should be cleared when opened, etc)"

Codewiki also provides a list legal values for `int oflags`: 

O_RDONLY	Open the file so that it is read only.

O_WRONLY	Open the file so that it is write only.

O_RDWR	Open the file so that it can be read from and written to.

O_APPEND	Append new information to the end of the file.

O_TRUNC	Initially clear all data from the file.

O_CREAT	If the file does not exist, create it. If the O_CREAT option is used, then you must include the third parameter.

O_EXCL	Combined with the O_CREAT option, it ensures that the caller must create the file. If the file already exists, the call will fail.

