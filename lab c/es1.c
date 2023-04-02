/*Esercizio A.1 Scrivere un programma che analizza carattere per carattere la stringa
costante di testo ”Hello WoRLd! Today’s temperature is 34C.”: se il
carattere analizzato non è una lettera dell’alfabeto o è una lettera minuscola ne fa
l’eco sullo standard output, se è una lettera dell’alfabeto in maiuscolo (uppercase) la
converte in minuscolo (lowercase) e ne fa l’eco. L’output deve quindi essere:
”hello world! today’s temperature is 34c.”.
La stringa, allocata nei dati costanti del programma, deve essere analizzata tramite
una variabile puntatore. Usare solo argomenti trattati finora per risolvere l’esercizio.*/
#include "stdio.h"
int main(){
    char string [] = "Hello WoRLd! Today’s temperature is 34C.";
    int index = 0;
    while (string[index] != '\0'){
        if(string[index] >= 'A' && string[index] <= 'Z'){
            printf("%c",string[index]+32);
        }
        else{
            printf("%c", string[index]);
        }
        index++;
    }
}