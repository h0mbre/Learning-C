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

## Open() Syscall
Next, we need to determine how to open the file using the `open()` syscall. To do this, we can consult [codewiki](http://codewiki.wikidot.com/c:system-calls:open). The function definition according to codewiki is:
`int open(const char *path, int oflags);`

+ `const char *path` is "The relative or absolute path to the file that is to be opened."
+ `int oflags` is "A bitwise 'or' separated list of values that determine the method in which the file is to be opened (whether it should be read only, read/write, whether it should be cleared when opened, etc)"

Codewiki also provides a list legal values for `int oflags`: 

`O_RDONLY` - Open the file so that it is read only.

`O_WRONLY` - Open the file so that it is write only.

`O_RDWR` - Open the file so that it can be read from and written to.

`O_APPEND` -	Append new information to the end of the file.

`O_TRUNC` -	Initially clear all data from the file.

`O_CREAT` -	If the file does not exist, create it. If the O_CREAT option is used, then you must include the third parameter.

`O_EXCL` -	Combined with the O_CREAT option, it ensures that the caller must create the file. If the file already exists, the call will fail.

We'll open our file in read and write mode, so for this we'll use `O_RDWR`. This is our code up until this point:
```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main (void)
{
	open("assignment24.txt", O_RDWR);

	return 0;
}
```
We've replaced `const char *path` with the name of our file, relative pathed since we are in the same directory, and we've replaced `int oflags` with `O_RDWR` so that we can perform both reads and writes, although in case only a write. 

Next, we want to include a mechanism for ensuring that the call succeeded. The man page for `open()` states that upon successful completion, the function will return a non-zero integer as a `file descriptor` and if it fails, it will return a `-1` value. So let's add some logic to our program that makes sure the returned value is not `-1`. 

Let's create a variable called `filedescriptor` like they have done on Codewiki, and set it equal to the return value of our function. Next, we'll add control flow that determines whether or not the function failed. Now our program looks like this:
```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main (void)
{
	int filedescriptor;

	filedescriptor = open("assignment24.txt", O_RDWR);
		if (filedescriptor != -1)
		{
			printf("The file was successfully opened.");
			return 0;
		}
		else 
		{
			printf("The file failed to open!");
			return 1;
		}
	
	return 0;
}
```

Let's run it and check the output:
```terminal_session
tokyo:~/LearningC/ # ./assignment24c                                         
The file was successfully opened.
```

Awesome! We got back a non-zero, non-negative-one file descriptor value. Let's change the name of the file in our code to `idontexist.txt` and run it to see if it fails. 
```terminal_session
tokyo:~/LearningC/ # ./assignment24                                         
The file failed to open!
```

Awesome again! We got it to fail in a predictable manner, our code works well thus far. Now we need to write to the file. 

## Write() Syscall
The codewiki site provides a nice digestable definition of the function for us as: `ssize_t write(int fildes, const void *buf, size_t nbytes);`

It further provides us with the meaning of these arguments:
`int fildes` - The file descriptor of where to write the output. You can either use a file descriptor obtained from the open system call, or you can use 0, 1, or 2, to refer to standard input, standard output, or standard error, respectively.
`const void *buf` - A pointer to a buffer of at least nbytes bytes, which will be written to the file.
`size_t nbytes` - The number of bytes to write. If smaller than the provided buffer, the output is truncated.
`return value` - Returns the number of bytes that were written. If value is negative, then the system call returned an error.

The file descriptor we already have from the return value of our `open()` operation, so that's taken care of. We could've alternatively written to standard output with a `1` or standard error with a `2`. We will save the error output for checking to make sure our code worked later. 

`const void *buf` will be the message we want written.

`size_t nbytes` will be the size of the message, from the example on codewiki they used `36` for the message `This will be output to testfile.txt\n`. That is 36 characters long, so we'll just need a character count of our message for this parameter. 

The return value is the number of bytes that were written, so we know if this value is not the length of our message, the write operation did not succeed. Let's write a functioning write syscall before worry about error handling. Let's plug in our parameters. 

