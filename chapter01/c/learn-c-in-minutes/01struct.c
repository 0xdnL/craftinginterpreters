#include <stdio.h>
#include <string.h>

struct person {
  char  name[50];    // array of characters
  int   age;
  int   height;
};

int main() {

  struct person me;

  printf("sizeof(me.name)=%lu\n", sizeof(me.name));

  // me.name = "john";      // arrays can't be assigned only copied !
  strcpy(me.name, "tim");
  me.age = 24;
  me.height = 80;

  printf("struct{name=%s age=%i height=%i}\n", me.name, me.age, me.height);

  return 0;
}


/*
    man strcpy
*/
