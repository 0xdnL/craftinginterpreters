#include <stdio.h>

int main() {

  int v[5] = {5, 2, 1, 3, 4};

  int counter = 0;
  int v_size = sizeof(v)/sizeof(*v);

  while (counter <= v_size) {
    printf("v[%i]=%i\n", counter, v[counter]);
    counter++;
  }
  printf("\n");

  counter = 0;
  do {
    printf("v[%i]=%i\n", counter, v[counter]);
    counter++;
  } while (counter <= v_size);
  printf("\n");

  /*
    for (expr; expr; expr) { .. }
    for (init; cond; post) { .. }
  */

  for (int counter=v_size; counter>=0; counter--) {
    printf("v[%i]=%i\n", counter, v[counter]);
  }

  return 0;
}
