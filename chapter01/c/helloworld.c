#include <stdio.h>
#include <string.h>

// user-defined function prototype
int addNumbers(int n, int m);
const char* greet(char *name);

int main() {

  printf("hello world\n");

  int  num = 100;
  int* ptr = &num;

  if (ptr == &num) {
    printf("> value: %d, memoryAddr: %p, pointer: %p\n", num, &num, ptr);
  }

  printf("> adding: %d and %d = %d\n", num, 2, addNumbers(num,2));

  char name[] = "human";
  printf("> %s: %s\n", name, greet(name));

  return 0;
}


int addNumbers(int n, int m) {
  return n + m;
}

const char* greet(char *name) {
  char greet[] = "greeting ";
  strcpy(name, greet);
  return name;
}
