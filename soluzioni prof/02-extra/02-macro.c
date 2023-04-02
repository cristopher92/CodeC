#include <stdio.h>

#define SQ(x) ((x) * (x))

#define SQ_err(x) (x * x)

int main() {
  int i=3;

  printf("SQ(%d) = %d\n", i, SQ(i));
  printf("SQ(%d) = %d\n", i, SQ_err(i));

  printf("SQ(%d) = %d\n", i, SQ(7+i));
  printf("SQ(%d) = %d\n", i, SQ_err(7+i));
}
