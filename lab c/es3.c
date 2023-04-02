/*
 * Esercizio A.3 Usando la funzione scanf() della libreria standard di I/O scrivere un
programma che chieda all’utente di inserire un carattere. In base al carattere
inserito il programma deve stampare: "Il carattere che hai inserito è
un numero." , "Il carattere che hai inserito è una lettera
dell’alfabeto." oppure "Il carattere che hai inserito non è
alfanumerico."
 */
#include "stdio.h"
int main(){
    printf("Inserisci un carattere\n");
    char userInput;
    scanf("%c", &userInput);
    if(userInput >= 'a' && userInput <= 'z' || userInput >= 'A' && userInput <= 'Z'){
        printf("Hai inserito una lettera!\n");
    }
    else if(userInput >= '0' && userInput <= '9'){
        printf("Hai inserito un numero!\n");
    } else{
        printf("Hai inserito un carattere non alfanumerico!\n");
    }
}