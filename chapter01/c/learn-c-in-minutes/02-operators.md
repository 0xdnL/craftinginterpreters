# operators

## arithmetic operators

```c
+ - / * %

++ --
```

## comparison operators

eval to `true` or `false`

```c
== !=   /* equivalenz operator */
< <=
> >=
```

## locaigal statements

```c
!((x>y) && ((a>b) || (a<b)))
```

## bitwise operators

```c
int x = 5; // stored internally as: 0b101

// bitwise AND
9&5 //   0b1001
    // & 0b0101
    //     0001
1

// bitwise OR
9|5 //   0b1001
    // | 0b0101
    //     1101
13

// bitwise XOR "Exclusive Or"
9^5 //   0b1001
    // ^ 0b0101
    //     1100
12

// bitwise NOT "complement"
~  00100011
=> 11011100
```

## SHIFT operators

```c
<<
9>>2 // shift right 9 by 2
     // 1001 => 0010
     //    9 => 2

/*
    shift right by 1 bit = dividing by 2
       8 >>1
    1000 >>1
 => 0100 => 4

    shift left by 1 bit = multiply by 2
       9 <<1
    1001 >>1
=> 10010 => 18

*/

```
