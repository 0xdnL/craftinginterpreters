#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  printf("argument count=%i\n", argc);

  for (int i=0; i < argc; i++) {
    printf("argv[%d]=%s, %i, %f\n", i, argv[i], atoi(argv[i]), atof(argv[i]));
  }
}
