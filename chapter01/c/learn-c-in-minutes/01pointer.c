#include <stdio.h>

int main() {

  int x   = 4;        // integer         named  x is set to 4

  int *pX = &x;       // integer pointer named pX is set to the address of x

  int y = *pX;        // integer         named y is set to the value pointed to by pX

  printf("val[x]=%i,val[pX]=%p,val[*pX]=%i (deref),val[y]=%d\n", x, pX, *pX, y);

  *pX = 8;            // set the thing pX is pointing to value 8

  printf("val[x]=%i,val[pX]=%p,val[*pX]=%i (deref),val[y]=%d\n", x, pX, *pX, y);

  return 0;
}
