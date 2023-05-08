#include <stdio.h>
#include <stdlib.h>


extern char **environ;

// int main(int argc, char *argv[]) {
// int main(int argc, char **argv) {
int main(int argc, char **argv, char **envp) {

  putenv("FOO=BAR");
  setenv("WHAT", "THE", 1);

  char *value;

  value = getenv("FOO");
  printf("FOO=%s\n", value);

  value = getenv("WHAT");
  printf("WHAT=%s\n", value);

  value = getenv("FROM_PARENT");
  printf("FROM_PARENT=%s\n", value);

  // use **envp to print env
  // for (int i=0; envp[i] != NULL; i++) {
  //   printf("envp[%i]=%s\n", i, envp[i]);
  // }

  // use **environ to print env
  // for (int i=0; environ[i] != NULL; i++) {
  //   printf("environ[%i]=%s\n", i, envp[i]);
  // }
}
