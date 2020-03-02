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

int strncmp(const char* s, const char* t, size_t n) {
  n++;
  while(*s != '\0' && *t != '\0' && *s == *t && n-- > 1) {
    ++s;
    ++t;
  }
  return *s - *t;
}

char* strcat(char* s, const char* t) {
  while (*s) {
    ++s;
  }
  return strcpy(s, t);
}

char* strncat(char* s, const char* t, size_t n) {
  n++;
  while (*s && n-- > 0) {
    ++s;
  }
  return strcpy(s, t);
}

int strend(char* s, char* t){
  int end = 0;
  int slen = 0;
  int tlen = 0;
  slen = strlen(s);
  tlen = strlen(t);
  if (tlen <= slen) {
    s += slen - tlen;

    if (strcmp(s, t) == 0) {
      end = 1;
    }
  }
  return end;
}

int main () {
  const char* line = "abcde";
  const char* second = "abcdef";
  const char* add = "Hello->";
  char* beg = "Beginning";
  char* end = "ing";
  char* not = "not";
  char buf[50];

  print_reverse(line);
  strcpy(buf, line);
  printf("\n\ncopy = %s\nline = %s\n", buf, line);

  strncpy(buf, line, 4);
  printf("\ncopy = %s\nline = %s\n", buf, line);

  printf("strcmp = %d\nline = %s\nsecond = %s\n\n",strcmp(line,second), line, second);

  printf("strcmp = %d\nsecond = %s\nline = %s\n\n",strcmp(second,line), second, line);

  printf("strcmp = %d\nline = %s\nline = %s\n\n",strcmp(line,line), line, line);

  printf("strncmp = %d\nline = %s\nsecond = %s\n\n",strncmp(line,second, 4), line, second);

  printf("strncmp = %d\nsecond = %s\nline = %s\n\n",strncmp(second,line, 5), second, line);

  printf("strncmp = %d\nline = %s\nline = %s\n\n",strncmp(line,line, 6), line, line);

  printf("strcat = %s\nbuf = %s\nstrcat 2 = %s\nbuf = %s\n\n",strcat(buf, line), buf, strcat(buf,add), buf);

  printf("strend = %d\nbeg = %s\nend = %s\n\n",strend(beg, end), beg, end);

  printf("strend = %d\nend = %s\nbeg = %s\n\n",strend(end, beg), end, beg); 

  printf("strend = %d\nnot = %s\nbeg = %s\n",strend(not, beg), not, beg);
}
