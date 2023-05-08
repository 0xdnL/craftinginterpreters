#include <stdlib.h>
#include <stdio.h>

struct node {
  int value;
  struct node* next;
  struct node* prev;
};

typedef struct node node_t; // don't have to type struct all the time

void printlist(node_t *head) {
  node_t *temp = head;

  while (temp != NULL) {
    printf("%d", temp->value);
    temp = temp->next;
    if (temp != NULL) printf(" - ");
  }
  printf("\n");
}

node_t *create_new_node(int value) {
  node_t *result = malloc(sizeof(node_t));
  result->value = value;
  result->next = NULL;
  result->prev = NULL;
  return result;
}

node_t *insert_at_head(node_t **head, node_t *node_to_insert) {
  node_to_insert->next = *head;
  if (*head != NULL) {
    (*head)->prev = node_to_insert;
  }
  *head = node_to_insert;
  node_to_insert->prev = NULL;
  return node_to_insert;
}

void remove_node(node_t **head, node_t *node_to_remove) {
  if (*head == node_to_remove) {  // special case, when deleting head
    *head = node_to_remove->next;
    if (*head != NULL) {
      (*head)->prev = NULL;
    }
  } else {
    node_to_remove->prev->next = node_to_remove->next;
    if (node_to_remove->next != NULL) {
      node_to_remove->next->prev = node_to_remove->prev;
    }
  }
  node_to_remove->next = NULL;
  node_to_remove->prev = NULL;
  return;
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
  if(new_node->next != NULL) new_node->next->prev = node_to_insert_after;
  node_to_insert_after->next = new_node;
}

int main() {

  node_t *head = NULL;
  node_t *tmp;

  int num_nodes = 10;

  for (int i=0; i<num_nodes; i++) {
    if (i==5) continue;
    tmp = create_new_node(((i+1)*2)-1);
    insert_at_head(&head, tmp);
  }

  tmp = find_node(head, 17);
  if (tmp != NULL) printf("found node=[%p] with value=[%d]\n", tmp, tmp->value);

  insert_after_node(find_node(head, 9), create_new_node(55));  // add 5 back in again lol
  remove_node(&head, find_node(head, 19));
  remove_node(&head, tmp);
  remove_node(&head, head);
  printlist(head);

  return 0;
}
