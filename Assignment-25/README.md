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



