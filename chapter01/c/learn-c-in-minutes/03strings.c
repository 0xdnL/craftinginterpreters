#include <stdio.h>
#include <string.h>

/*
    man string

    strcpy(3), strlen(3)

    bstring(3), index(3), rindex(3), stpcpy(3),

    strcasecmp(3)
    strcat(3)
    strchr(3)
    strcmp(3) ,
    strcspn(3)
    strerror(3)
    strpbrk(3)
    strrchr(3)
    strsep(3)
    strspn(3)
    strstr(3)
    strtok(3)
*/

int get_string_length(char *str) {
  int offset = 0;
  while(str[offset]!=0) {
    offset++;
  }
  return offset;
}

void copy_string(char *from, char *to) {
  int offset = 0;
  while(from[offset] != 0) {
    to[offset] = from[offset];
    offset++;
  }
  to[offset] = 0; // ensur NULL termination !
}

void reverse_string(char *str) {

  int len = get_string_length(str) - 1;
  int index = 0, end = len;
  char temp[1];

  while(index <= len/2) {
    temp[0] = str[index];
    str[index] = str[end];
    str[end] = temp[0];
    index++;
    end--;
  }
}

int main() {

  char *str1  = "hello world";
  char str2[] = "hello world";

  /*
    numerical character codes can be specified in octal (base8) or hexdec (base16)

    man ascii

    000 nul  001 soh  002 stx  003 etx  004 eot  005 enq  006 ack  007 bel
    010 bs   011 ht   012 nl   013 vt   014 np   015 cr   016 so   017 si

    The hexadecimal set:
    00 nul   01 soh   02 stx   03 etx   04 eot   05 enq   06 ack   07 bel
    08 bs    09 ht    0a nl    0b vt    0c np    0d cr    0e so    0f si

    The decimal set:
    0 nul    1 soh    2 stx    3 etx    4 eot    5 enq    6 ack    7 bel
    8 bs     9 ht    10 nl    11 vt    12 np    13 cr    14 so    15 si

    nl => new line => linebreak
  */
  printf("hello world\12"); // \12 <- base8  "octal"
  printf("%s\xA", str1);    // \xA <- base16 "hexadecimal"
  printf("%s\n", str2);

  char str3[] = "Hello World!";
  printf("sizeof(str3)=%lu\n", sizeof(str3));
  printf("get_string_length(str3)=%d\n", get_string_length(str3));
  printf("strlen(str3)=%lu\n", strlen(str3));
  /*
    characters 1btyte 0-128 ascii
    12*1byte + 0 terminator = 13 bytes
    ['H', 'e', 'l',...'d', '!', '0']
    => length +1 !
   */

  char str4[] = "Hello World!";
  char str5[get_string_length(str4)];
  printf("\n");
  printf("str4=%s => str5=%s\n", str4, str5);
  copy_string(str4, str5);
  printf("str4=%s => str5=%s\n", str4, str5);
  printf("\n");

  char str6[] = "future video";
  reverse_string(str6);
  printf("reversed stringe(str6)='%s'\n", str6);
}
