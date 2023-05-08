#include <stdio.h>

int y = 5;


void dumb_func(int a, int b) {  // pass by value
  a = a + 1;                    // copy of value is put on stack
  b = b - 1;
  // after functions end copyies get destroyed
}

void smart_func(int *a, int *b) {  // pass by reference
  *a = *a + 1;
  *b = *b - 1;
}

int sum_func(int a, int b) {
  return a + b;
}

int main(int argc, char **argv) {

  int x = 4;

  dumb_func(x,y);
  printf("x=%i y=%i\n", x, y);

  smart_func(&x,&y);
  printf("x=%i y=%i\n", x, y);

  printf("x+y=%i\n", sum_func(x, y));
}
