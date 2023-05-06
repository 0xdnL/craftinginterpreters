#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char **argv) {

  // using syscall open, read, write and close compared to libc-calls
  int fd_to_read  = open("05sometext.txt", O_RDONLY);
  int fd_to_write = open("05newtext.txt", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);

  if (fd_to_read == -1 || fd_to_write == -1) {
    printf("one file can't be opened.\n");
    return -1;
  }

  char c;
  int bytes;
  while((bytes = read(fd_to_read, &c, sizeof(c))) > 0) {
    if (c == '.') {
      c = '!';
      printf("found a dot.\n");
    }
    write(fd_to_write, &c, sizeof(c));    // a syscall for each iteration ! slower
  }

  close(fd_to_read);
  close(fd_to_write);
}
