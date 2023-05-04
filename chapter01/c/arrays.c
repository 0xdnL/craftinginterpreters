# include <stdio.h>

int len (int a[]);

int main () {
  int values[5];    // 5 x 4-bytes => compiler allocate 20 bytes of memory

  values[2] = 45;

  int len = sizeof(values) / sizeof(*values);

  printf("values[2] = %d\n", values[2]);
  printf("sizeof(values)=%lu\n", sizeof(values));
  printf("sizeof(values[0])=%lu\n", sizeof(values[0]));
  // printf("len(values)=%d\n", len(values));

  // printf("----\n");
  // printf("length(values)=%lu\n", sizeof(values) / sizeof(values[0]));
  // printf("length(values)=%lu\n", sizeof(values) / sizeof(*values));

  for (int i=0; i<len;i++) {
    printf("value[%d]=%d\n", i, values[i]);
  }
}

/*
    how to pass an array to a function ?

    array aren't first class citizens okay ?!
*/
int len (int a[]) {

  printf("> a[2] = %d\n", a[2]);
  printf("> sizeof(a)=%lu\n", sizeof(a));
  printf("> sizeof(&a)=%lu\n", sizeof(&a));
  printf("> sizeof(a[0])=%lu\n", sizeof(a[0]));

  return sizeof(a) / sizeof(a[0]);
}
