#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

  // using syscall open, read, write and close compared to libc-calls
  FILE *file_to_read  = fopen("05sometext.txt", "r");
  FILE *file_to_write = fopen("05newtext.txt", "w");

  if (file_to_read == NULL || file_to_write == NULL) {
    printf("one file can't be fopened.\n");
    return -1;
  }

  char c;

  while((c = fgetc(file_to_read)) != EOF) {
    if (c == '.') {
      c = '!';
      printf("found a dot.\n");
    }
    fputc(c, file_to_write);    // gets buffered
  }

  fclose(file_to_read);
  fclose(file_to_write);
}
