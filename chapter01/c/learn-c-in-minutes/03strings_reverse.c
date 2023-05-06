#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
  strings

  ['T', 'e', 'x', 't', '0']  // strings are array of characters
  //                    ^ null terminator

  characters 1btyte 0-128 ascii


  void reverse(char *s);
  - destructive reverse, destroys the original string
  - implies string is null terminated and enough memory has been allocated

  void reverse(char *s, int length);
  - no need to look up null termination

  void reverse(char *s, char *s2, int length);
  - keep original by passing new array

  char *reverse(char *s, int length);
  - use malloc to alloc new copy and return copy keeping original string
  - need to free memory after function call
*/

void rev0(char *str) {
  int length = strlen(str);
  for (int i=0; i<length/2; i++) {
    char temp = str[i];
    str[i] = str[length-1-i];
    str[length-1-i] = temp;
  }
}

void rev1(char *str) {
  int length = strlen(str);
  for (int i=0, j=length-1; i<j; i++, j--) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}

void rev3(char *str1, char *str2, size_t len) {
  int i, j;
  for (i=len-1, j=0; i>=0; i--, j++)
    str2[j] = str1[i];
  str2[j] = '\0'; // needs to be set !
}


void rev4(char *str) {
  char *end = str+strlen(str)-1;
  while (str<end) {
    char temp = *str;
    *str = *end;
    *end = temp;
    str++;
    end--;
  }
}

void rev5(char *str) {
  for (char *end = str+strlen(str)-1; str<end; str++,end--) {
    char temp = *str;
    *str = *end;
    *end = temp;
  }
}

void rev6(char *str, int len) {
  if (len <= 1) return;
  char tmp = str[0];
  str[0] = str[len-1];
  str[len-1] = tmp;
  rev6(str+1, len-2);
}

char * rev7(const char *str) {
  int len = strlen(str);
  char *result = malloc(len+1);   // THIS MUST BE FREED OUTSIDE LATER !

  for (int i=0; i<len; i++) {
    result[i] = str[len-1-i];
  }

  result[len] = 0;
  return result;
}

char * rev8(const char *str) {
  char *result = malloc(strlen(str)+1); // THIS MUST BE FREED OUTSIDE LATER !
  strcpy(result, str);
  rev4(result);
  return result;
}

char * rev9(const char *str) {
  int len = strlen(str);
  char *result = malloc(len+1);
  memset(result, 0, len);
  int leftToSwap = len/2;

  while (leftToSwap) {
      int ridx = rand() % (len/2);
      if (result[ridx] == 0) {
        result[ridx] = str[len-1-ridx];
        result[len-1-ridx] = str[ridx];
        leftToSwap--;
      }
  }
  result[len] = 0;
  return result;
}

int main() {
  char str[] = "foobar";
  size_t str_len = strlen(str);

  printf("str=%s\n", str);
  // rev0(str);
  // rev1(str);
  // rev4(str);
  // rev5(str);
  rev6(str, str_len);
  printf("str=%s\n", str);

  strcpy(str, "foobar");
  char *revStr2 = rev7(str);
  printf("revStr2=%s\n", revStr2);

  strcpy(str, "foobar");
  char *revStr3 = rev8(str);
  printf("revStr3=%s\n", revStr3);

  strcpy(str, "foobar");
  char *revStr4 = rev9(str);
  printf("revStr4=%s\n", revStr4);

  char revStr1[str_len];
  strcpy(str, "foobar");
  rev3(str, revStr1, str_len);
  printf("revStr1=%s\n", revStr1);
}
