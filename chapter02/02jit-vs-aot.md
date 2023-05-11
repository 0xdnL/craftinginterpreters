# aot vs jit compilation in java

> https://www.cesarsotovalero.net/blog/aot-vs-jit-compilation-in-java.html

"compilation strategies" -> jit, aot

Java HotSpot VM -> translate bytecode to machine code at runtime
GraavlVM        -> statically compiles bytecode directly into machine code at build time


"Compiling"    -> transforming source code from a high-level programming language into machine code
"Machine code" -> are low-level instructions tailored to execute in a particular microprocessor

"Compiler"     -> designed to perform translation efficiently
               -> goal: create a consistent executable of the compiled program

"consistent executable" -> is attained to the specification that is written in the source code, runs fast, and it is safe

"Compilers optimizations" -> constant inlining, loop unrolling, partial evaluation at compiletime


"Hotspot Virtual Machine" uses 2 compilers

"C1"  -> fast, lightly optimized bytedcode compiler
      -> uses
        - a simple CFG-oriented SSA "high" IR, a machine-oriented "low" IR
        - a linear scan register allocation
        - a template-style code generator
      -> optimizations
        - performs value numbering, inlining and class analysis

"C2"  -> highly optimizing bytecode compiler that
      -> uses
        - a "sea of nodes" SSA "ideal" IR, which lowers to a machine-specific IR of the same kind
      -> has a graph-coloring register allocator. Colors are machine states, including local, global, and argument registers and stack.
      -> optimizations
        - global value numbering, conditional constant type propagation, constant folding, global code motion, algebraic identities, method inlining, intrinsic replacement, loop transformations, array range check elimination



graalvm

Quarkus         by RedHat
Micronaut       by The Micronaut Foundation
Helidon         by Oracle
Spring Native   by Spring

native image creation analyzes the bytecode in the application and all its dependencies
=> there is a risk of violating the "close world" if at least one of the dependencies relies on some dynamic Java feature

"close world" -> assumption no Java dynamic features are allowed





https://www.graalvm.org/22.0/docs/getting-started/
https://www.graalvm.org/22.0/docs/getting-started/macos/
