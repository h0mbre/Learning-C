## Assignment
By now you can do a lot with C. You've used syscalls, you created shared libraries, you learned about some data structures, you learned some socket programming, you learned about I/O streams, and you learned about some userland rootkit techniques. 

There is still a lot to learn, we barely even scratched the surface of C. We didn't even discuss data typing much! 

Your assignment is to read about the Jynx userland rootkit which used `LD_PRELOAD` and try to create your own version **for educational purposes**. This is some good analysis of some of the Jynx techniques: http://www.infosecisland.com/blogview/22440-Analyzing-Jynx-and-LDPRELOAD-Based-Rootkits.html 

Jynx was pretty awesome. It hid processes, hid netstat connections, hid files, provided an encrypted password protected backdoor, all through the use of the exact same technique we learned: system call hooking via malicious libraries. Let's see how creative you can get with your design.

There is no limit except how much research you want to do and your imagination. Your rootkit can hide files, hide connections, open ports, steal SSH data, etc. Let me know what you come up with! I will make a blog post detailing mine when I'm finished with it. 

**You should explain how to mitigate and discover your rootkit's techniques.**

My write-up has been posted here!!: https://h0mbre.github.io/Learn-C-By-Creating-A-Rootkit/
