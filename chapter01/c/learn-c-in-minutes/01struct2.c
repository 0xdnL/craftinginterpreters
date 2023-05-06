#include <stdio.h>

struct Person {
  char name[64];
  int age;
};

int main(int argc, char *argv[]) {

  struct Person people[10];
  // struct Person *p_Person = &people;
  struct Person *p_Person = &people[0];

  for (int i=0; i<10; i++) {
      p_Person->age = 0;
      p_Person->name[0] = 'a';
      p_Person += 1;
  }

  for (int x = 0; x < 10; x++) {
    printf("name: %s, age: %d\n",p_Person->name, p_Person->age);

    // aprently the compiler should know to jump to the next Person struct ?!
    // p_Person += sizeof(Person); would have been wrong ??
    // https://youtu.be/q24-QTbKQS8?t=231
    p_Person += 1;
  }

  return 0;
}
