## Assignment
For this excercise we're going to build a C program that executes syscalls! We've already learned basically everything we need to know in C up until this point to accomplish this. We are going to keep it simple and we're going to use the `open()` syscall only here. *It should be noted that technically we are not making syscalls directly in user programs, but instead are using wrapper functions defined in libc for our purposes.* 

## Getting Started
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

The first thing to realize is that *our file doesn't yet exist*. We will definitely be needing the `O_CREAT` value. This value also specifies we need a third paramter for our syscall function. What is the third parameter? A second function definition for `open()` from codewiki states the definition with the third parameter is: `int open(const char *path, int oflags, mode_t mode);`

So, this `mode_t mode` parameter is going to be needed. A quick google search yields us [this result](https://jameshfisher.com/2017/02/24/what-is-mode_t/). We'll want to set permissions on the file to `700` so we'll use the `S_IRWXU` value for the `mode_t mode` parameter. 

We'll open our file in write mode (`O_WRONLY`), so this is our code up until this point:
```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main (void)
{
	open("testfile.txt", O_WRONLY | O_CREAT, S_IRWXU);

	return 0;
}
```
We've replaced `const char *path` with the name of our file and we've replaced `int oflags` with `O_WRONLY` and `O_CREAT` separated by the logical or operator `|` as specified on the codewiki definition for that parameter. Lastly, we've placed `S_IRWXU` as the value for the `mode_t mode` paramenter. 

Next, we want to include a mechanism for ensuring that the call succeeded. The man page for `open()` states that upon successful completion, the function will **return** a non-zero integer as a `file descriptor` and if it fails, it will return a `-1` value. So let's add some logic to our program that makes sure the returned value is not `-1`. 

Let's create a variable called `filedescriptor` like they have done on Codewiki, and set it equal to the return value of our function. Next, we'll add control flow that determines whether or not the function failed. Now our program looks like this:
```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main (void)
{
	int filedescriptor;

	filedescriptor = open("testfile.txt", O_WRONLY | O_CREAT, S_IRWXU);

	if (filedescriptor < 0)
	{
		printf("The open operation failed...");
		return -1;
	}
	else 
	{
		printf("The open operation succeeded!");
		return 0;
	}
	
}
```

Let's run it and check the output:
```terminal_session
tokyo:~/LearningC/ # ./assignment24                                          
The open operation succeeded!#
```

Awesome, our code apparently worked. Let's check the directory and see the permissions for the newly created `testfile.txt`.

```terminal_session
tokyo:~/LearningC/ # ls -lah                                       
total 32K
drwxr-xr-x  2 root root 4.0K Sep 19 19:46 .
drwxr-xr-x 35 root root 4.0K Sep 19 19:46 ..
-rw-r--r--  1 root root  328 Sep 19 19:46 assignment24.c
-rwxr-xr-x  1 root root  16K Sep 19 19:42 assignment24
-rwx------  1 root root    0 Sep 19 19:42 testfile.txt
```

Awesome, it was created with `700` permissions just like we intended. Next, we'll need to write to the file!
