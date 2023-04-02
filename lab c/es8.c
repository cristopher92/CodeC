/*
 * Esercizio A.8 Scrivere un programma il quale legga dallo standard input una linea
alla volta e restituisca per ogni parola nella linea la dimensione in caratteri. Dopo
averne consultato la pagina di manuale usare la funzione fgets() per ottenere una
linea dallo standard input e memorizzarla in un array di char, successivamente
processare l’array per ottenere i conteggi.
Esempio di sessione:
Inserisci una linea:
> Hello, how are you?
le dimensioni delle parole inserite sono:
> 6 3 3 4
 * */

#include "stdio.h"
#define MAX_LINE_LENGTH 100
int main(){

    char string[MAX_LINE_LENGTH];
    printf("Inserisci una linea\n");
    fgets(string, MAX_LINE_LENGTH, stdin);
    int count=0;
    for(int i = 0; string[i] != '\n'; i++){
        if(string[i] != ' '&& string[i] != '\n'){
            count++;
        }
        else if(count>0){
            printf("%d ", count);
            count = 0;
        }
    }
    if(count > 0 ){
        printf("%d\n", count);
    }
    return 0;
}