# syscall vs libc call

system call
- process requests something from os
- write to screen or disk, send over network
- os has to allow this


```sh
man syscall     # get kernel's system calls (linux!)

man -k . | grep '(2)'
```
