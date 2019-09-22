## Assignment
Now that we've got some more syscall experience under our belt, we're going to take a step back and actually look at how syscalls are implemented. We're going to create a malicious shared library to hook some syscalls. We are getting very naughty. 

We will be using these excellent blog posts: https://ketansingh.net/overview-on-linux-userland-rootkits/ and https://blog.netspi.com/function-hooking-part-i-hooking-shared-library-function-calls-in-linux/ as our guides, I recommend reading through these posts at least twice. 

## Shared Libraries
A shared library is essentially a compiled .c file that contains definitions of functions. These files typically end with the extension `.so`. When you run a dynamically linked binary and it makes a `write()` syscall for instance, it seeks out the defintion for `write()` in a shared library file called `libc`. As far as the binary knows, `write()` means whatever `libc` says it means. Normally, this a good thing. Instead of having to recompile all binaries when a function is altered in a shared library, users can instead just update the shared library and have all of its dependent binaries across the system work as intended. 

We can see what shared libraries are consulted by a binary with the `ldd` utility which checks for dynamic dependencies. Let's see which shared libraries `ls` uses on a Kali Linux installation: 
```terminal_session
tokyo:/lib/ # ldd /bin/ls
	linux-gate.so.1 (0xb7f54000)
	libselinux.so.1 => /lib/i386-linux-gnu/libselinux.so.1 (0xb7ed7000)
	libc.so.6 => /lib/i386-linux-gnu/libc.so.6 (0xb7cf9000)
	libdl.so.2 => /lib/i386-linux-gnu/libdl.so.2 (0xb7cf3000)
	libpcre.so.3 => /lib/i386-linux-gnu/libpcre.so.3 (0xb7c7a000)
	/lib/ld-linux.so.2 (0xb7f56000)
	libpthread.so.0 => /lib/i386-linux-gnu/libpthread.so.0 (0xb7c59000)
```

We see a reference to `libc.so.6` and see that it's located at `/lib/i386-linux-gnu/libc.so.6`. This is where 


