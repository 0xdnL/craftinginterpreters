# learn c in minutes

1. Preprosessor Directives aka "Macros is a compilation process

> `#include <stdio.h>` -> every thing going to Preprosessor starts with `#`

```c
#define M                   // substitutes a preprocessor using macro
#undef                      // undefines a certain preprocessor macro
#include                    // helps to insert a certain header from another file
#ifdef                      // returns true if a certain macro is defined
#ifndef                     // returns true if a certain macro is not defined
#if, #elif, #else, #endif   // tests program using a certain condition; can be nested
#line                       // handles line numbers on the errors and warnings. can be used to change line number and source files while generating output during compile time
#error, #warning            // can be used for generating errors and warnings
#error                      // can be performed to stop compilation
#warning                    // is performed to continue compilation with messages in the console window
#region, #endregion         // define sections of the code to make them more understandable and readable, we can use the region using expansion and collapse features
```

## 4 Types of Preprocessor Directives

1 Macro Expansion
2 File Inlcusion
3 Conditional Compilation
4 Miscellaneous Directives

[simplilearn.com/tutorials/c-tutorial/c-preprocessor-directives](https://www.simplilearn.com/tutorials/c-tutorial/c-preprocessor-directives)

2. variable declarations
3. Type Definitions
4. Functino Definitions
5. Statements & Expressiosn
6. Comments
