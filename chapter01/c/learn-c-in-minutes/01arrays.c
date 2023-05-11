#include <stdio.h>

void foo () {
  int v[5] = {5, 2, 1, 3, 4};                                     // compiler allocates space in memroy
  int *p = v;       // assign pointer to array .. okay ?!         // compiler didn't allocate a new array
  // int n = 8;
  // int *pN = n;   // yea compiler doesn't like that

  v[3] = 7;       // p and v are almost the same for the compiler
  p[4] = 1000;    // pointers can act like arrays

  printf("p  =%p\n", p);
  printf("p+2=%p\n", p+2); // original addres of p + 8 => adding 2 x sizeof(int) => + 2 * 4bytes
  printf("\n");

  *v     = 9111;    // pointer are arrays in different form => "pointer arithmatic"
  *(v+2) = 4999;
  printf("&v=%p v=%p\n", v, &v);

  int v_len = sizeof(v) / sizeof(*v);

  for (int i=0; i<v_len; i++) {
    printf("v[%i]=%i\n", i, v[i]);
  }

  printf("\n");


  for (int i=0; i<v_len; i++) {
    printf("> *(p+%i)=v[%i]=%i \n", i, i, *(p+i));
  }
  /*
    why arrays start at 0 ?
    array[0] is asking for value that is "0" bytes away from beginning !
  */
}

void difference_array_and_ANDarray() {
  /*
    array vs &array Pointers Difference Explained
    https://www.youtube.com/watch?v=WL1P6xiA_KY
  */
  int array[5];
  array[2] = 5;
  printf("   sizeof(array)=%d\n", sizeof(array));
  printf("sizeof(array[0])=%d\n", sizeof(array[0]));
  printf("\n");
  printf("array     : %zu\n", array);
  printf("array  + 1: %zu\n", array +1); // increase mem addr by size of what "array" is pointing to -> array[0]
  printf("&array    : %zu\n", &array);
  printf("&array + 1: %zu\n", &array +1); // &array points to entire array, increase by 5 * 4 bytes
  printf("\n");

  int matrix[3][5] =
  {
    {0,1,2,3,4},
    {5,6,7,8,9},
    {10,11,12,13,14}
  };

  //   matrix[1] pointer to first element of second row -> points to 5
  //  &matrix[1] pointer to the second row -> point so {5,6,7,8,9}

  printf("   matrix[1]     : %zu\n",   matrix[1]);
  printf("   matrix[1] + 1 : %zu\n",   matrix[1] + 1);  // increase mem addr by size of int
  printf(" *(matrix[1] + 1): %zu\n", *(matrix[1] + 1)); // deref value

  printf("    &matrix[1]      : %zu\n",   &matrix[1]);
  printf("    &matrix[1] + 1  : %zu\n",   &matrix[1] + 1); // memory address of first elem in row three
  printf("  *(&matrix[1] + 1) : %zu\n", *(&matrix[1] + 1));// same value as before what ?
  printf("*(*(&matrix[1] + 1)): %zu\n", *(*(&matrix[1] + 1)));// same value as before what ?

  int *pointer1 =          &matrix[1] + 1;  // this works, because it points to an int
  int *pointer2 = (int *) (&matrix[1] + 1); // typecast
  int *pointer3 = (int *)  &matrix[1] + 1;  // typecast, operator presedence, prints second val of row two
  printf("   pointer1         : %zu\n",  pointer1);
  printf("  *pointer1         : %zu\n", *pointer1);
  printf("   pointer2         : %zu\n",  pointer2);
  printf("  *pointer2         : %zu\n", *pointer2);
  printf("   pointer3         : %zu\n",  pointer3);
  printf("  *pointer3         : %zu\n", *pointer3);
}

int main() {
  //foo();
  difference_array_and_ANDarray();
  return 0;
}
