/*
 * Scrivere un programma che legge dallo standard input un testo e conta in esso la
frequenza di ogni carattere dell’alfabeto (senza distinzione tra stile minuscolo e
maiuscolo) e la frequenza degli spazi bianchi. Usando il carattere * come
mattone elementare dare una rappresentazione ad istogramma orizzontale delle
frequenze delle lettere dell’alfabeto
 * */
#include <stdio.h>
#include <ctype.h>
#define ALPHABET_SIZE 26


int main(){
    char alphabet[ALPHABET_SIZE] = {0};
    char c;
    int countWhiteSpaces = 0, index;

    printf("Inserisci un testo\n");
    while ((c = getchar()) != EOF){
        if(isalpha(c)){
            index = tolower(c) - 'a';
            alphabet[index]++;
        }
        if(isspace(c)){
            countWhiteSpaces++;
        }
    }

    int maxFreq = 0;
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if(alphabet[i] > maxFreq){
            maxFreq = alphabet[i];
        }
    }

    printf("\nFrequenza delle lettere:\n");
    for (int frq = maxFreq; frq > 0 ; --frq) {
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if(alphabet[i] == frq){
                printf("%c: ", i+'a');
                for (int j = 0; j < alphabet[i]; ++j) {
                    printf("*");
                }
                printf("\n");
            }
        }
    }


    printf("Frequenza degli spazi bianchi:\n");
    for (int i = 0; i < countWhiteSpaces; ++i) {
        printf("*");
    }
    printf("\n");

}