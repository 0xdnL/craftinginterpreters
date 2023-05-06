#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct person {
  char  name[50];    // array of characters
  int   age;
  int   height;
};

int main() {

  struct person me;
  printf("sizeof(me.name)=%lu\n", sizeof(me.name));
  // me.name = "john";      // arrays can't be assigned only copied !
  // strcpy(me.name, "tim");
  // me.age = 24;
  // me.height = 80;
  // printf("struct{name=%s age=%i height=%i}\n", me.name, me.age, me.height);

//   struct person people[5];
//   struct person *p_Person = &people;
//
//   for (int i=0; i<5; i++) {
//     // strcpy(p_Person->name, "tim");
//     p_Person->name[0] = "\0";
//     p_Person->age = 1;
//     p_Person->height = 1;
//     p_Person += 1;
//   }
//
//   for (int i=0; i<5; i++) {
//     printf("{name: %s, age: %i, height: %i}\n",p_Person->name, p_Person->age, p_Person->height);
//     p_Person++;
//   }

    typedef struct{
        char* firstName;
        char* lastName;
        int day;
        int month;
        int year;

    }STUDENT;

    int numStudents=3;
    int x;
    STUDENT* students = malloc(numStudents * sizeof *students);
    for (x = 0; x < numStudents; x++){
        students[x].firstName=(char*)malloc(sizeof(char*));
        students[x].firstName = "foo";
        students[x].lastName=(char*)malloc(sizeof(char*));
        students[x].lastName = "bar";
        students[x].day = 1;
        students[x].month = 1;
        students[x].year = 1;
    }

    for (x = 0; x < numStudents; x++)
        printf("first name: %s, surname: %s, day: %d, month: %d, year: %d\n",students[x].firstName,students[x].lastName,students[x].day,students[x].month,students[x].year);

    return 0;
}
