#include <stdio.h>

int total;

int Square(int x) {
  return x*x;
}

int SquareSum(int x, int y) {
  int z = Square(x+y);
  return z;
}

int main() {
  int a = 4, b = 8;
  total = SquareSum(a,b);
  printf("squaresum is: %d", total);
  return 0;
}
