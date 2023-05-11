# chapter 01

## challenges

1. pick open source implementation of language

- download source, poke around
- find code that implements scanner and parser
- are they handwritten or generated using tools like Lex `.l` and Yacc `.y`

2. JIT compilation tends to be the fastest way to implement dynamically typed languages, but not all of them use it.

- What reasons are there not to use JIT ?

python pypy
javascript v8 engine
ruby jruby
lua luajit

reasons to not use jit could be:

- implementing a jit compiler is complex and time consuming
- no significatn perfomance increas when codebase too small
- target platform limitations


3. most lisp implementations that compile to c also contain an interpreter that lets them execute lisp on the fly as well

- Why ?

lisps implementations written in c

- gnu emacs lisp
- common lisp
- scheme
- tiny lisp
- newlisp

using an interpreter on the fly allow for quick test and debugging of code
portability, when c compilation may be timeconsuming
