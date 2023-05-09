#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "08variadicfunc.h"

// implementation of printf
// see also http://sourceware.org/git/?p=glibc.git;a=blob;f=stdio-common/printf.c
int printf (const char *format, ...) {
  va_list args;
  int done;

  // char *substring = strstr(format, "4");
  // if (substring != format) return 0;

  va_start(args, format);
  done = vfprintf(stdout, format, args);
  va_end(args);
  return done;
}

void print_ints(int num, ...) {
  // ----------     ^^^ number of arguments !!
  va_list pargs;                       //        declaring pointer to arg list
  va_start(pargs, num);                // macro: init arg to list pointers

  for (int i=0; i<num; i++) {
    int val = va_arg(pargs, int);      // macro, notice second type param, needs to know size
    printf("%d: %d\n", i, val);
  }
  va_end(pargs);                       // macro: end arg list traversla, not needed with gcc and clan
}

int sum(int num, ...) {
  va_list pargs;
  va_start(pargs, num);
  int sum = 0;
  for (int i=0; i<num; i++) {
    sum += va_arg(pargs, int);
  }
  return sum;
}

int main() {
  print_ints(2, 6, 7, 8, 9);
  printf("sum(4, 60, 70, 80, 90)=%i\n", sum(4, 60, 70, 80, 90));
  return 0;
}
