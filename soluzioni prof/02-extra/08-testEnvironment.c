#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int main(int argc, char * argv[]) {

  printf("Test variabili di ambiente\n");

  int i=0;
  while (environ[i]!=NULL) {
    printf("%s \n",environ[i]);

    i++;
  }

  if (argc  == 2) {
    char * valore=getenv(argv[1]);
    if (valore)
      printf("\n\nIl valore della variabile \"%s\" è \"%s\"\n", argv[1], valore);
    else
      printf("\n\nLa variabile di ambiente non esiste %s\n", argv[1]);
  }
}
