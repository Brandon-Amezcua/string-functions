#include  <stdio.h>
#include <string.h>
#include <assert.h>

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
  while ( (int)n-- > 0 ) {
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
  while (*s && n-- > 1) {
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

size_t strspn(const char* s, const char* t) {
  size_t i;
   for(i = 0; s[i] != '\0'; i++) {
     for(size_t l = 0; s[i] != t[l]; l++) {
       if (t[l] == '\0') {
         return i;
       }
     }
   }
   return i;
}

size_t strcspn(const char* s, const char* t) {
  size_t i;
   for(i = 0; s[i] != '\0'; i++) {
     for(size_t l = 0; s[i] == t[l]; l++) {
       if (t[l] == s[i]) {
         return --i;
       }
     }
   }
   return --i;
}

char* strpbrk(const char* s, const char* t) {
  char* ret;
  size_t ex = strcspn(s,t);
  for (size_t m = 0; m == ex; m++) {}
  *ret = *s;
  printf("ret = %s", ret);
  return ret;
}

void test_strspn(const char* s, const char* t) {
   size_t test = strspn(s, t);
   printf("c = %s\tt = %s\ttest = %zu\n", s, t, test);
}

void tests_strspn() {
  printf("\ntests_strspn:\n");
  test_strspn("badeggs", "abde");
  test_strspn("badeggs", "xyzs");
}

void test_strcspn(const char* s, const char* t) {
   size_t test = strcspn(s, t);
   printf("c = %s\tt = %s\ttest = %zu\n", s, t, test);
}

void tests_strcspn() {
  printf("\ntests_strcspn:\n");
  test_strcspn("badeggs", "abde");
  test_strcspn("badeggs", "xyzs");
}

int main () {
  const char* line = "abcde";
  const char* second = "abcdef";
  const char* add = "Hello->";
  char* beg = "Beginning";
  char* end = "ing";
  char* not = "not";
  char buf[50];
  /*
  print_reverse(line);
  strcpy(buf, line);
  printf("\n\ncopy = %s\nline = %s\n", buf, line);

  strncpy(buf, line, 4);
  printf("\ncopy = %s\nline = %s\n\n", buf, line);

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
  */
  char* got = strpbrk("badeggs", "abde");

  tests_strspn();

  tests_strcspn();
}
