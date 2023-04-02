#include "operazioni.h"
#include "stdio.h"

int main(void){
    int i = 3, j = 5;

    printf("La moltiplicazione tra %d e %d è: %d\n", i, j, multiplication(i, 5));
    printf("La somma tra %d e %d è: %d\n", i, j, add(i, 5));
    printf("La sottrazione tra %d e %d è: %d\n", i, j, subtraction(i, 5));

    return 0;
}