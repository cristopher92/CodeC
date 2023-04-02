/*
cancella logicamente dalla stringa passata
come argomento l’ultima parola senza ri-allocarla; restituisce il puntatore alla
stringa stessa;*/
#include <malloc.h>
#include "stdio.h"
#include "string.h"

int string_how_many(char c, char s[]){
    if (s == NULL){
        return -1;
    }
    int ret_value = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        if(s[i] == c){
            ret_value++;
        }
    }
    return ret_value;
}


int main(){
    char c[] = "stringa          con   tanti spazi  ";
    printf("%d", string_how_many('a',c));
}