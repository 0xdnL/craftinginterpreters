# basic types

## 4 Categories of types in c

## numeric types

```c
/* [signed|unsigned] */ char          // 1 byte  ->  8 bits -> 2^8  = 256    largest number char can contains

char c = 'A';       // stores numeric value of character A
printf("%c\n", c);

/* [signed|unsigned] */ short         // 2 bytes -> 16 bits -> 2^16 = 65535
/* [signed|unsigned] */ int           // 4 bytes
/* [signed|unsigned] */ long          // 4 bytes
/* [signed|unsigned] */ long long     // 8 bytes -> 2^64 - 1
```

`int` can be 2 or 4  byte depending on architecture
using fixed width integers from `stdint.h` will always have the same size -> portable/predictable !

```c
 int8_t      // integer that is 8 bits long, _t <- convention used for naming data types, and avoiding name space pollution
uint64_t     // unsigned int 64 bits long
```

[stackoverflow.com/questions/231760/what-does-a-type-followed-by-t-underscore-t-represent](https://stackoverflow.com/questions/231760/what-does-a-type-followed-by-t-underscore-t-represent)

## arrays

```c
int x[50];
printf("%i, %i\n", x[0], x[3])
```

## structures

```c
struct person {
  char name[50];
  int age;
  int height;
}

struct person me;
struct person you;

strcopy(me.name, "Bert") // array not assignable !
me.age = 24;
me.height = 24;
```

## pointers

```c
int x   = 4;        // integer         named  x is set to 4

int *pX = &x;       // integer pointer named pX is set to the address of x

int y = *pX;        // integer         named y is set to the value pointed to by pX
```
