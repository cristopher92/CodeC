#include <stdio.h>

int main() {
  char *time,
       *date,
       *file;
  int line,stdc;

  time = __TIME__;
  date = __DATE__;
  file = __FILE__;
  line = __LINE__;
  stdc = __STDC__;

  printf("__TIME__: %s\n", time);
  printf("__DATE__ = %s\n", date);
  printf("__FILE__ = %s\n", file);
  printf("__LINE__ = %d\n", line);
  printf("__STDC__ = %d\n", stdc);
}
