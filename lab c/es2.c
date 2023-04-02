/*
 * Esercizio A.2 Usando la funzione scanf() della libreria standard di I/O scrivere un
programma che chieda all’utente di inserire su una linea e separandoli con degli
spazi bianchi dei valori numerici interi positivi non nulli. La lista deve essere
terminata con il valore 0 (end of list). Il programma deve calcolare la media
aritmetica dei valori inseriti e deve stampare il risultato sullo standard output.*/
#include "stdio.h"
int main(){
    printf("inserisci una serie di valori numerici interi positivi non nulli. Termina con 0\n");
    int sum = 0, input, count = 0;
    do {
        scanf("%d", &input);
        if(input>0){
            sum += input;
            count++;
        }

    } while (input != 0);
    printf("%.2f",(float)sum/count);

}