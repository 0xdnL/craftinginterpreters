#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {

  putenv("FROM_PARENT='hello child'");

  if (fork() == 0) {
    // child process
    execl("./a.out", "./a.out", NULL);
  }
}
