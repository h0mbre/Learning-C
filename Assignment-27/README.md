## Assignment
Now that we've got some more syscall experience under our belt, we're going to take a step back and actually look at how syscalls are implemented. We're going to create a malicious shared library which will provide an arbitrary defintion of a syscall that fits our purposes and then use it to hijack program syscalls. We are getting very naughty. 
