# stack vs heap


https://www.youtube.com/watch?v=_8-ht2AKyH4

## get heap size on os

> n Visual Studio the default stack size is 1 MB i think, so with a recursion depth of 10,000 each stack frame can be at most ~100 bytes which should be sufficient for a DFS algorithm

```sh
uname -s
```

[stackoverflow.com/c-maximum-stack-size-of-program-on-mainstream-oses](https://stackoverflow.com/a/1825996/14523221)


```
                               Application Memory

                                  ┌────────────────┐
             Dynamic         ┌─   │                │
           "free store"      │    │ Heap           │
                             └─   │                │
                                  ├────────────────┤
              Static         ┌─   │                │
        alloc+freed autom.   │    │ Stack          │
                             └─   │                │
                                  ├────────────────┤
         lives as long as    ┌─   │                │
        the application runs │    │ Static/Global  │
                             └─   │                │
                                  ├────────────────┤
                             ┌─   │                │
          the actuall app    │    │ code (text)    │
                             └─   │                │
                                  └────────────────┘

                              Stack
                           (Fixed Size)
                        ┌────────────────┐           ┌────────────────┐
                        │                │           │                │
                        │                │           │                │
                        │                │           │                │
                        │                │           │                │
                        │                │           │                │
                        │                │           │                │
                        ├────────────────┤           │                │
                     ▲  │   Square()     │           │                │
                     │  │   x            │ │         │                │
                     │  ├────────────────┤ │         ├────────────────┤
                     │  │   SquareSum()  │ │         │  printf()      │
                        │   x,y,z        │ │       ▲ │                │ │
                    ┌─  ├────────────────┤ │       │ ├────────────────┤ │
                    │   │   main()       │ ▼       │ │   main()       │ │
       stack-frame ─┤   │   a,b          │    ───►   │   a,b          │ ▼
                    └─  └────────────────┘           └────────────────┘

                          Global                       Global
                        ┌────────────────┐           ┌────────────────┐
                        │   total        │           │   total        │
                        └────────────────┘           └────────────────┘


                                           Heap

              Stack                     ┌──────────────────┐
          ┌────────────────┐            │                  │
          │                │            ├──────────────────┤
          │                │            │                  │
          │                │            │  20*sizeof(int)  │
          │                │  ┌────────►│                  │ addr: 400
          │                │  │         │                  │
          │                │  │         │                  │
          │                │  │         │                  │
          │                │  │         ├──────────────────┤
          ├────────────────┤  │  ┌─────►│  value: 10       │ addr: 200
          │                │  │  │      ├──────────────────┤
          │  *p2 = 400     ├──┘  │      │                  │
          ├────────────────┤     │      │                  │
          │  *p  = 200     ├─────┘      └──────────────────┘
          ├────────────────┤
          │  a             │
          └────────────────┘

            Global
          ┌────────────────┐
          │   total        │
          └────────────────┘
```
