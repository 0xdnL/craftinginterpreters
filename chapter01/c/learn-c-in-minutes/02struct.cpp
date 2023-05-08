#include <string>
#include <iostream>

struct person {
  int age;
  std::string name;
};

/*
clang++ -g -Wall -o 02struct 02struct.cpp
*/

int main() {
  person p1, p2;
  person *p_person = &p1;

  p1.age = 25;
  p1.name = "Horst";

  (*p_person).age = 44;
  p_person->age = 52;     // arrow is syntactic sugar for (*pointer)

  std::cout << p1.name << " is " << p1.age << " years old." << std::endl;
}
