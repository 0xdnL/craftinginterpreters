# helloworld in c

## usage

```sh
make
```


## debugger

```sh
gcc -g -o doublelinkedlist  doublelinkedlist.c

lldb ./doublelinkedlist
```

```c
(lldb) target create "./doublelinkedlist"
Current executable set to '/PATH/TO/craftinginterpreters/chapter01/c/doublelinkedlist' (arm64).
(lldb) r
Process 11599 launched: '/PATH/TO/craftinginterpreters/chapter01/c/doublelinkedlist' (arm64)
Process 11599 stopped
* thread #1, queue = 'com.apple.main-thread', stop reason = EXC_BAD_ACCESS (code=1, address=0x10)
    frame #0: 0x0000000100003c74 doublelinkedlist`insert_at_head(head=0x000000016fdfe550, node_to_insert=0x0000000100204180) at doublelinkedlist.c:33:17
   30
   31   node_t *insert_at_head(node_t **head, node_t *node_to_insert) {
   32     node_to_insert->next = *head;
-> 33     (*head)->prev = node_to_insert;
   34     *head = node_to_insert;
   35     return node_to_insert;
   36   }
Target 0: (doublelinkedlist) stopped.

(lldb) p head
(node_t **) $0 = 0x000000016fdfe550

(lldb) p *head
(node_t *) $1 = NULL
```
