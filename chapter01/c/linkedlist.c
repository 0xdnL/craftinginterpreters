#include <stdlib.h>
#include <stdio.h>

struct node {
  int value;
  struct node* next;
};

typedef struct node node_t; // don't have to type struct all the time

void printlist(node_t *head) {
  node_t *temp = head;

  while (temp != NULL) {
    printf("%d - ", temp->value);
    temp = temp->next;
  }
  printf("\n");
}

node_t *create_new_node(int value) {
  node_t *result = malloc(sizeof(node_t));
  result->value = value;
  result->next = NULL;
  return result;
}

node_t *insert_at_head(node_t **head, node_t *node_to_insert) {
  node_to_insert->next = *head;
  *head = node_to_insert;
  return node_to_insert;
}

node_t *find_node(node_t *head, int value) {
  node_t *tmp = head;
  while (tmp != NULL) {
    if (tmp->value == value) return tmp;
    tmp = tmp->next;
  }
  return NULL;
}

void insert_after_node(node_t *node_to_insert_after, node_t *new_node) {
  new_node->next = node_to_insert_after->next;
  node_to_insert_after->next = new_node;
}

/*
      node_t n1;
(A)   n1.value = 123
      n1 = malloce(sizeof(node_t));
(B)   n1->value = 123
      'arrow' operator is syntactic sugar; bar->member is the same as (*bar).member
      https://stackoverflow.com/questions/10036381/arrow-operator-vs-dot-operator
*/

int main() {

  node_t *head = NULL;
  node_t *tmp;            // "the thing pointed to by tmp is an node_t"

  for (int i=0; i<25; i++) {
    if (i==5) continue;
    tmp = create_new_node(i);
    insert_at_head(&head, tmp);
  }

  tmp = find_node(head, 22);
  if (tmp != NULL) printf("found node=[%p] with value=[%d]\n", tmp, tmp->value);

  insert_after_node(find_node(head, 6), create_new_node(55));  // add 5 back in again lol

  printlist(head);

  return 0;
}
