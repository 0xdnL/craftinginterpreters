#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 50

int main(int argc, char **argv) {

  int fd = open(argv[1], O_RDONLY);
  char buffer[BUFF_SIZE];
  int bytesread;

  if (fd == -1) {
    printf("couldn't open file..\n");
    return -1;
  }

  while ((bytesread = read(fd, buffer, BUFF_SIZE)) > 0) {
    dprintf(STDOUT_FILENO, "Chunks read: %d bytes \n", bytesread);
    write(STDOUT_FILENO, buffer, bytesread);
    dprintf(STDOUT_FILENO, "\n");
  }

  close(fd);
}
