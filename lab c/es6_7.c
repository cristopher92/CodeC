#include "string_utilities.h"
#include "stdio.h"
int main(){
    char *c = "Questa è una prova per testare le funzioni appena create";
    printf("Slenght = %d\n", slength(c));

    printf("%s\n", scut_last_word(c));

}