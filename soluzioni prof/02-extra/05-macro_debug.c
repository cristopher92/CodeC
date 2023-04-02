#include <stdio.h>

#define DEBUG_CODE(v) printf("Linea %i - file \"%s\". Il valore di \"%s\" è %i\n", \
           __LINE__, \
           __FILE__,\
           #v, v)



int main() {
  char *time,
       *date,
       *file;
  int line,stdc;

  int a=90;
  int index=1;
  int i=0;

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

  for (;i<10;i++) {
    printf("Iterazione...\n");
    a=a+1;
    #ifdef DEBUG
    DEBUG_CODE(i);
    #endif
  }

  #ifdef DEBUG
  DEBUG_CODE(a);
  #endif

}
