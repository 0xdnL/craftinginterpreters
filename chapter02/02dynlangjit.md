# dynamic languages and JIT

statically typed: type of a variable is known at compile time

- C, C++, Java, Rust, Go, Scala

dynamically typed: type is associated with run-time values

- Perl, Ruby, Python, PHP, JavaScript, Erlang

https://stackoverflow.com/a/1517670/14523221


## compiler interpreter

c:  compilation is done before execution
js: compilation is done during execution

once code runs it gets optimized

## "The JIT in JavaScript: Just In Time Compiler"

> https://blog.bitsrc.io/the-jit-in-javascript-just-in-time-compiler-798b66e44143


- each runtime/browser implement own version of JIT Compiler

JIT Phases

"The monitor or profiler"
  track how many times different statements are hit, if growing, mark "warm"
  if grows enough mark "hot" -> detect most used code and send to baseline compiler

"The baseline compiler"
  warm section compiled to bytecode, then run by interpreter optimized for bytecode
  turns poliymorphic code into stubs

"The optimizing compiler"
  turns isolated stubs into group and typing it, allows typechecking only once


=> good for code with long lifespan, for short scripts not so much

tips for using a jit

"don't change classes/objects shape"

```
class Person {
  construct(name, age) { this.name = name; this.age = age; }
}

p1 = new Person("jim", 12),

p1.height = 180       # this changes objects shape !
```

"keep function argumens constant" -> monomorphic
https://mrale.ph/blog/2015/01/11/whats-up-with-monomorphism.html

```
someFunc(1,2)           // monomorphic
someFunc("a","b")       // now polymorphic
someFunc("a",3)
someFunc(true,func(){}) // now megamorphic
```

## "A crash course in just-in-time (JIT) compilers"

> https://hacks.mozilla.org/2017/02/a-crash-course-in-just-in-time-jit-compilers/

translate human readable to machine readable

interpreter: translation line by line, on the fly
compiler: translatoin ahead of time, all at once
