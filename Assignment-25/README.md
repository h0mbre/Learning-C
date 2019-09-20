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
