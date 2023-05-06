# syscall vs libc call

system call
- process requests something from os
- write to screen or disk, send over network
- os has to allow this


```sh
man syscall     # get kernel's system calls (linux!)

man -k . | grep '(2)'
```

## syscall "open"
```sh
gcc 05file-syscall.c -o 05file-syscall && time ./05file-syscall

real    0m0.141s
user    0m0.001s
sys     0m0.002s
```

## libcall "fopen"

```sh
gcc 05file-libcall.c -o 05file-libcall && time ./05file-libcall

real    0m0.247s
user    0m0.001s
sys     0m0.005s
```

fopen uses buffering ! Buffered I/O
