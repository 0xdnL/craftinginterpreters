#include <stdio.h>

int main() {

  int v[5] = {5, 2, 1, 3, 4};                                     // compiler allocates space in memroy
  int *p = v;       // assign pointer to array .. okay ?!         // compiler didn't allocate a new array
  // int n = 8;
  // int *pN = n;   // yea compiler doesn't like that


  // p and v are almost the same for the compiler
  v[3] = 7;
  p[4] = 1000;    // pointers can act like arrays

  printf("p  =%p\n", p);
  printf("p+2=%p\n", p+2); // original addres of p + 8 => adding 2 x sizeof(int) => + 2 * 4bytes
  printf("\n");

  // pointer are arrays in different form => "pointer arithmatic"

  *v     = 9111;
  *(v+2) = 4999;

  printf(" v=%p\n", v);
  printf("&v=%p\n", &v);
  // printf("v[0]=%i by *p\n", *p);
  // printf("v[1]=%i by *(p+1)\n", *(p+1));
  printf("v[0]=%i\n", v[0]);
  printf("v[1]=%i\n", v[1]);
  printf("v[2]=%i\n", v[2]);
  printf("v[3]=%i\n", v[3]);
  printf("v[4]=%i\n", v[4]);
  printf("\n");

  int v_len = sizeof(v) / sizeof(*v);
  for (int i=0; i<v_len; i++) {
    printf("> *(p+%i)=v[%i]=%i \n", i, i, *(p+i));
  }

  /*
    why arrays start at 0 ?
    array[0] is asking for value that is "0" bytes away from beginning !
  */

  return 0;
}
