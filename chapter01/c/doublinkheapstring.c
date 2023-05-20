#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
  define doubly linked list of heap-allocated strings
  write funcs for: insert, find and delete
*/

struct Node {
  struct Node* next;
  struct Node* prev;
  char *value;
};

struct Node *create_node(char val[]) {
  struct Node *result = malloc(sizeof(struct Node));
  result->value = val;
  result->next = NULL;
  result->prev = NULL;
  return result;
}

struct Node *find_node(struct Node *n, char val[]) {
  while(n != NULL) {
    if (n->value == val) return n;
    n = n->next;
  }
  return NULL;
}

void insert_node_after(struct Node *list, struct Node *n) {

  if (list->next != NULL) {
    struct Node *tmp = list->next;
    list->next = n;
    n->next = tmp;
    tmp->prev = n;
    // return;
  }
  list->next = n;
  n->prev = list;
}

// remember to free memory !
/*
       L                   R
       A         B         C
    (p   n)<->(p   n)<->(p   n)

*/
void remove_node(struct Node *rm_node) {
  struct Node *left = rm_node->prev;
  struct Node *right = rm_node->next;

  if (left == NULL) {
    printf("remove(right->prev=%p)",right->prev);
    right->prev = NULL;
    // free();
    return;
  }
  if (right == NULL) {
    printf("remove(left->next=%p)",left->next);
    left->next = NULL;
    // free();
    return;
  }
  // printf("left->next=%p = right->prev=%p\n",left->next, right->prev);
  left->next = right->prev;
  // printf("right->prev=%p = left->next=%p\n",right->prev, left->next);
  right->prev = left->next;

  printf("left=%zu left->next=%zu left->prev=%zu\n", left, left->next, left->prev);
  printf("right=%zu right->next=%zu right->prev=%zu\n", right, right->next, right->prev);

  printf("remove(rm_node->next=%zu)\n",rm_node->next);
  rm_node->next = NULL;
  printf("remove(rm_node->prev=%zu)\n",rm_node->prev);
  rm_node->prev = NULL;

  printf("left=%zu left->next=%zu left->prev=%zu\n", left, left->next, left->prev);
  printf("right=%zu right->next=%zu right->prev=%zu\n", right, right->next, right->prev);
  /*
    pointer to a pointer !

L n=5517633952 n->next=5517633984 n->prev=0 n->val=AAA
D n=5517633984 n->next=5517633280 n->prev=5517633952 n->val=BBB
R n=5517633280 n->next=5517634016 n->prev=5517633984 n->val=DDD
  n=5517634016 n->next=0 n->prev=5517633280 n->val=CCC

  left=5517633952 left->next=5517633984 left->prev=0
  right=5517633280 right->next=5517634016 right->prev=5517633984
  remove(rm_node->next=5517633280)
  remove(rm_node->prev=5517633952)
  left=5517633952 left->next=5517633984 left->prev=0
  right=5517633280 right->next=5517634016 right->prev=5517633984
  n=5517633952 n->next=5517633984 n->prev=0 n->val=AAA
  n=5517633984 n->next=0 n->prev=0 n->val=BBB


  ------

L n=0x151e069a0 n->next=0x151e069c0 n->prev=0x0 n->val=AAA
D n=0x151e069c0 n->next=0x151e06700 n->prev=0x151e069a0 n->val=BBB
R n=0x151e06700 n->next=0x151e069e0 n->prev=0x151e069c0 n->val=DDD
  n=0x151e069e0 n->next=0x0 n->prev=0x151e06700 n->val=CCC

  left=0x151e069a0 left->next=0x151e069c0 left->prev=0x0
  right=0x151e06700 right->next=0x151e069e0 right->prev=0x151e069c0

  remove(rm_node->next=0x151e06700)
  remove(rm_node->prev=0x151e069a0)

  left=0x151e069a0 left->next=0x151e069c0 left->prev=0x0
  right=0x151e06700 right->next=0x151e069e0 right->prev=0x151e069c0



  n=0x151e069a0 n->next=0x151e069c0 n->prev=0x0 n->val=AAA
  n=0x151e069c0 n->next=0x0 n->prev=0x0 n->val=BBB
  */
}

void print_list(struct Node *n) {
  while(n != NULL) {
    // printf("n=%p n->next=%p n->prev=%p n->val=%s\n", n, n->next, n->prev, n->value);
    printf("n=%zu n->next=%zu n->prev=%zu n->val=%s\n", n, n->next, n->prev, n->value);
    n = n->next;
  }
}

void traverse_right_from(struct Node *n) {
  while(n != NULL) {
    printf("'%s'", n->value);
    n = n->next;
    if (n!=NULL) printf("-");
  }
  printf("\n");
}

void traverse_left_from(struct Node *n) {
  while(n != NULL) {
    printf("'%s'", n->value);
    // printf("'%p'", n->prev);
    n = n->prev;
    if (n!=NULL) printf("-");
  }
  printf("\n");
}


int main() {
  //zeroing memory to set the initial values
  // memset(&msg, 0, sizeof(Node));
//   a.value = malloc(12);
//   snprintf(a.value, 12, "'hello %d'", 42);
//   strcpy(a.value, "12");

  struct Node *a = create_node("AAA");
  struct Node *b = create_node("BBB");
  struct Node *c = create_node("CCC");
  struct Node *d = create_node("DDD");

  insert_node_after(a,b);
  insert_node_after(b,c);
  insert_node_after(b,d);

  // insert_node_after(b,d); <- infiloop if d is tail


  print_list(a);
  printf("\n");
  traverse_right_from(a);
  traverse_left_from(c);

  printf("\n");

  struct Node *f = find_node(a, "BBB");
  if ( f != NULL)
    printf("f=%p f->next=%p f->prev=%p f->val=%s\n", f, f->next, f->prev, f->value);

  printf("\n");

  remove_node(f);
  print_list(a);
  return 0;
}
