## Assignment
Now that we've got some more syscall experience under our belt, we're going to take a step back and actually look at how syscalls are implemented. We're going to create a malicious shared library to hook some syscalls. We are getting very naughty. 

We will be using these excellent blog posts: https://ketansingh.net/overview-on-linux-userland-rootkits/ and https://blog.netspi.com/function-hooking-part-i-hooking-shared-library-function-calls-in-linux/ as our guides, I recommend reading through these posts at least twice. 

## Shared Libraries
