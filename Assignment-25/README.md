## Assignment
This assignment will pick up where we left off. We have successfully implemented an `open()` syscall and will now pair that with a `write()` sycall to insert text into our open file.

## Getting Started
Again, we will reference the noob friendly [codewiki](http://codewiki.wikidot.com/c:system-calls:write) site. 

## Write() Syscall
Jumping right in, codewiki gives us the following functiond defintion: `ssize_t write(int fildes, const void *buf, size_t nbytes);`. It elaborates on the parameter values as follows: 
+ `int fildes` - The file descriptor of where to write the output. You can either use a file descriptor obtained from the open system call, or you can use 0, 1, or 2, to refer to standard input, standard output, or standard error, respectively.
+ `const void *buf` - A pointer to a buffer of at least nbytes bytes, which will be written to the file.
+ `size_t nbytes` - The number of bytes to write. If smaller than the provided buffer, the output is truncated.
+ return value - Returns the number of bytes that were written. If value is negative, then the system call returned an error.

We already have the `int fildes` in our program saved as the value for our `filedescriptor` variable. 

`const void *buf` is the content we want to write to the file, in this case we will fill this paramter with the value "Writing test data to the file." 

`size_t nbytes` is the number of bytes our message is. To calculate this let's just use Python in the terminal real quick:
```terminal_session
tokyo:~/LearningC/ # python                                          
Python 2.7.15+ (default, Nov 28 2018, 16:27:22) 
[GCC 8.2.0] on linux2
Type "help", "copyright", "credits" or "license" for more information.
>>> string = "Writing test data to the file."
>>> print(len(string))
30
>>>
```

Ok, so our message is 30 bytes long. At this point, we have everything we need to make a `write()` syscall. Our code now looks like this: 
```terminal_session
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
		
	}

	write(filedescriptor, "Writing test data to the file", 30);
	
}
```

If we run this, we see that our write operation succeeded!
```terminal_session
tokyo:~/LearningC/ # gcc assignment25.c -o assignment25                       
tokyo:~/LearningC/ # ./assignment25                                          
The open operation succeeded!#      
tokyo:~/LearningC/ # cat testfile.txt                   
Writing test data to the file#
```
Awesome, now to build in some error handling. The codewiki page tells us that the return value is the number of bytes we wrote to the file, so we know that if we don't get a `30` return value, our operation didn't succeed. Let's add some logic to save the return value in the variable `writertn` and return a `-1` if it fails. 

Our code now looks like this:
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
		printf("The open operation succeeded!\n");
		
	}

	int writertn;

	writertn = write(filedescriptor, "Writing test data to the file", 30);

	if (writertn != 30)
	{
		printf("The write operation failed...");
		return -1;
	}
	else
	{
		printf("The write operation succeeded!");
	}

	return 0;

}
```

Running the program seems to indicate successes with both operations:
```terminal_session
tokyo:~/LearningC/ # ./assignment25                                 
The open operation succeeded!
The write operation succeeded!#                                                
tokyo:~/LearningC/ # cat testfile.txt                               
Writing test data to the file#  
```

Now we just need to add a `close()` operation to our file so that our file is not left open, I'll leave this excercise to you!



