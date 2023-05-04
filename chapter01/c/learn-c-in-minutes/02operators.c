#include <stdio.h>

int main (){

  int x = 0, y = 0;

  x = 1, y = x++;  // increments x but evals to old value for y
  printf("x=%d y=%d\n", x, y);

  x = 1, y = ++x;
  printf("x=%d y=%d\n", x, y);

  x = 1, y = x--;
  printf("x=%d y=%d\n", x, y);

  x = 1, y = --x;
  printf("x=%d y=%d\n", x, y);

}
