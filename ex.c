#include  <stdio.h>
#include <string.h>

void print_reverse(const char* s) {
  if (*s == '\0') {return;}
  print_reverse(s + 1);
  printf("%c", *s);
}

char* strcpy (char* s, const char* t) {
  char * p = s;
  while ((*s++ = *t++) != '\0') {}
  return p;
}

char* strncpy(char* s, const char* t, size_t n) {
  char* p = s;
  n++;
  while( n-- > 1 && ((*s++ = *t++) != '\0' )) {}
  while ( n-- > 0 ) {
     *s++ = '\0';
  }
  *s++ = '\0';
  return p;
}

int strcmp(const char* s, const char* t) {
  while(*s != '\0' && *t != '\0' && *s == *t) {
    ++s;
    ++t;
  }
  return *s - *t;
}

int main () {
  const char* line = "abcde";
  char buf[50];
  print_reverse(line);
  strncpy(buf, line, 4);

  printf("\ncopy = %s\nline = %s\n", buf, line);
}
