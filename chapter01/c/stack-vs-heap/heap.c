#include <stdio.h>
#include <stdlib.h>

int main() {
  int a;                            // local variable -> goes to stack
  int *p;
  p = (int*)malloc(sizeof(int));    // malloc returns a void-pointer to some allocated memory
  *p = 10;
  free(p);                          // needs to cleared manually !
  p = (int*)malloc(sizeof(int));
  *p = 20;
  return 0;
}
