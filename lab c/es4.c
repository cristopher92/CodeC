/*
 * Esercizio A.4 Usando la funzione scanf() della libreria standard di I/O scrivere un
programma che chieda all’utente di inserire il numero n di voti dei quali fare la
media aritmetica. Successivamente il programma legge dallo standard input un voto
per linea e al termine ne calcola la media.
 * */
#include "stdio.h"
int main(){
    int qty, count, userinput, sum = 0;
    printf("Inserisci il quantitativo di numeri di cui vuoi fare la media aritmetica\n");
    scanf("%d",&qty);
    count = qty;
    while (count > 0){
        printf("Inserisci un numero\n");
        scanf("%d",&userinput);
        sum += userinput;
        count--;
    }

    printf("La media artimetica è %.2f\n",(float)sum / qty);
}