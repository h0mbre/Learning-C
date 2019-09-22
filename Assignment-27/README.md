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

We see a reference to `libc.so.6` and see that it's located at `/lib/i386-linux-gnu/libc.so.6`. I recommend you read more about shared libraries, dynamic linking/loading, and static linking. There's a ton of useful information there for noobs like us. 

What we're after, is finding out what order the dynamic linker finds and loads shared libraries needed by a program. According to the [ld.so manpage](http://man7.org/linux/man-pages/man8/ld.so.8.html), the order is:
"*Using the directories specified in the DT_RPATH dynamic section
attribute of the binary if present and DT_RUNPATH attribute does
not exist.  Use of DT_RPATH is deprecated.*

*Using the environment variable LD_LIBRARY_PATH, unless the
executable is being run in secure-execution mode (see below), in
which case this variable is ignored.*

*Using the directories specified in the DT_RUNPATH dynamic section
attribute of the binary if present.  Such directories are searched
only to find those objects required by DT_NEEDED (direct
dependencies) entries and do not apply to those objects' children,
which must themselves have their own DT_RUNPATH entries.  This is
unlike DT_RPATH, which is applied to searches for all children in
the dependency tree.*

*From the cache file /etc/ld.so.cache, which contains a compiled
list of candidate shared objects previously found in the augmented
library path.  If, however, the binary was linked with the -z
nodeflib linker option, shared objects in the default paths are
skipped.  Shared objects installed in hardware capability
directories (see below) are preferred to other shared objects.*

*In the default path /lib, and then /usr/lib.  (On some 64-bit
architectures, the default paths for 64-bit shared objects are
/lib64, and then /usr/lib64.)  If the binary was linked with the
-z nodeflib linker option, this step is skipped.*"

Or, as they put it on the ketansingh blogpost:
"*directories listed in the LD_LIBRARY_PATH environment variable.
directories listed in the executable’s rpath.
directories on the system search path, which consists of the entries in /etc/ld.so.conf plus /lib and /usr/lib"*

We can also see in the `ld.so` manpage that there is an option for an `LD_PRELOAD` environment variable which will always be sought first. Outside of declaring an environment variable, we can also use the `/etc/ld.so.preload` file to list the file path of a `.so` to load first. (Technically, `LD_PRELOAD` will load before an `.so` specified in the `/etc/ld.so.preload` file.)

## So, What? 
So what is the significance of all of this? Well, if we can have a binary reference a malicious shared library instead of the legitimate shared library, we could have the binary behave in a way that is beneficial to us and potentially invisible to the end user of the binary. What if, for example, we redefined the `write()` syscall in a malicious shared library so that when it's invoked, it silently sends a copy of its write buffer to a file somewhere and then continues a normal `write()` operation? The end user of the binary invoking `write()` would have no idea their content was being copied to another file on the system. 

This technique is one way in which its possible to hook syscalls. The advantage as an attacker of using `LD_PRELOAD` instead of specifying an `.so` in the `/etc/ld.so.preload` file is that with the environment variable you can specify a binary for which it applies. If you use `/etc/ld.so.preload`, it applies to all syscalls system wide. 

The aforementioned blog posts do a great job of explaining all of this, I highly recommend you read through them carefully! 

## Getting Evil
In the [blog.netspi.com blog post](https://blog.netspi.com/function-hooking-part-i-hooking-shared-library-function-calls-in-linux/), they hook the `puts()` syscall with the following malicious shared library: 
```c
#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>
int puts(const char *message)
{
int (*new_puts)(const char *message);
int result;
new_puts = dlsym(RTLD_NEXT, "puts");
if(strcmp(message, "Hello world!n") == 0)
{
result = new_puts("Goodbye, cruel world!n");
}
else
{
result = new_puts(message);
}
return result;
}
```

You can see: 
+ `int puts(const char *message)` is a function declaration that perfectly matches the real `puts` function so our binary will reference this on its first stop instead of continuing on to other shared libraries,
+ `int (*new_puts)(const char *message)` is a new function declaration that will point to the legitimate `puts()` call, it also matches the real `puts()` function definition exactly, 
+ `int result` is the return value of a `puts()` call,
+ `new_puts = dlsym(RTLD_NEXT, "puts")` actually initializes our pointer to the `new_puts` function and returns the next instance of the `"puts"` with `RTLD_NEXT`. `dlsym` returning thie value to `new_puts` now means that our function is pointing to the legitimate `puts()` call,
+ `if(strcmp(message, "Hello world!n") == 0` is comparing the message that is passed to `puts()` as the parameter with the string `"Hello world!n"`, if the result of the comparison is `0` (`strcmp()` returns a `0` if there is a match), then it instead feeds the `message` of `"Goodbye, cruel world!n"` to `puts()`. If there is no match, execution is just passed to the normal `puts()` call as intended. 

So if this shared library is loaded and used by a binary, the only way the binary would behave differently is if it made use of a `puts()` call with `"Hello world!n"` in the message parameter and it would change the message to `"Goodbye, cruel world!n"`.

Very very sick. 

## Assignment Details
The blog posts show you how to hook `puts()` and `SSL_write()` syscalls. Your assignment is to hook the `write()` syscall and replace `"Hello, World!"` in write buffers with `"Goodbye, cruel world!"`. 

We already know how to use `write()`. We know how to hook `puts()`. The syntax won't be identical but the concepts and library structure will be very similar. The only clue I'll give you is that to compile your shared library, I found success with the following syntax: `gcc -ldl malicious.c -fPIC -shared -D_GNU_SOURCE -o malicious.so`. 

To test your malicious library:
+ compile it,
+ create and compile a program which uses `write()` to write "Hello, World!" to stdout,
+ see what is printed to the terminal. 

## Example Output
```terminal_session
tokyo:~/LearningC/ # ./output
Hello, World!#
tokyo:~/LearningC/ # export LD_PRELOAD=/root/LearningC/write.so
tokyo:~/LearningC/ # ./output
Goodbye, cruel world!#
```
