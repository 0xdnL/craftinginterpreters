#include <stdio.h>
#include <stdlib.h>

void print_array(int *a, size_t length) {
  printf("[");
  for(int i=0; i<length; i++) {
    printf("%i", *(a+i));
    if (i+1<length) printf(" ");
  }
  printf("]\n");
}

void bubble_sort(int *to_sort) {
  for (int i=0; i<7; i++) {
     printf("%i ", *(to_sort+i));
  }
  printf("]\n");
}

int main() {

  int array[] = {9, 8, 7, 2, 5};

  size_t array_size = sizeof(array);
  printf("array_size = %zu bytes\n", array_size);
  size_t array_len = sizeof(array)/sizeof(int);
  printf("array_len = %zu elements\n", array_len);

  size_t int_size = sizeof(int);
  size_t malloc_assign = array_len * sizeof(int);
  printf("malloc(%zu * sizeof(%zu))=%zu\n", array_len, int_size, malloc_assign);

  int *brray = malloc(malloc_assign);

  for (int i=0; i<array_len; i++) {
     brray[i] = ((i+1)*2)-1;
  }

  print_array(array, array_len);
  print_array(brray, array_len);

  return 0;
}
