# chapter 01

## challenges

### six domain specific languaes used to publish th ebook ?

HTML 83.7%
C     4.8%
Dart  4.6%
Java  4.4%
SCSS  1.0%
CSS   0.9%

see: https://github.com/munificent/craftinginterpreters


### "hello, world" written in java

- setup tooling
- use a debugger and step through program

###  "hello, world" written in c

- setup tooling
- use a debugger and step through program
- practice pointers
- define doubly linked list of heap-allocated strings
- write functions to insert, find and delete item from it
- test them

#### c pointers

- a pointer in c is a variable that stores the memory addr of another variable
- pointer vars point to data-type

```c
int  num = 42
int* ptr = &n         // create point by using * operator, storing addr of num -> & "reference operator"
printf("%d\n", *ptr); // * operator dereferences pointer and returns its value
```
