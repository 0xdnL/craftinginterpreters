.global _start    // provide starting addr to linker
.align 2          // macos the program must start on a 64-bit boundary


// macos linker/loader doesn’t like doing relocations,
// use ADR rather than LDR instruction to load addresses

_start:
  mov X0, #1          // 1 = stdout
  adr X1, helloworld  // string to print
  mov X2, #13         // length of string
  mov X16, #4         // macos syscall for write
  svc 0               // output string

  // setup parameters to exit the program
  mov X0, #0      // 0 return code
  mov X16, #1     // service command code 1 terminates program
  svc 0           // call macos to terminate the program

helloworld: .ascii "Hello World!\n"
