#include <malloc.h>
#include "string_utilities.h"
#include "stdio.h"

/*
restituisce la dimensione in caratteri della stringa
passata come argomento, -1 in caso di errore;*/

int slength(char s[]){
    if(s == NULL){
        return -1;
    }
    int index = 0;
    while (s[index] != '\0' ){
        index++;
    }
    return index;
}

/*
cancella logicamente dalla stringa passata
come argomento l’ultima parola senza ri-allocarla; restituisce il puntatore alla
stringa stessa;*/
char *scut_last_word(char s[]) {
    int lastSpace;
    char *newString;

    if (s == NULL || s[0] == '\0') { // gestione errore
        return s;
    }

    lastSpace = -1;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            lastSpace = i;
        }
    }

    if (lastSpace == -1) { // non ci sono spazi
        newString = (char *)malloc(sizeof(char ));
        newString[0] = '\0'; // cancella tutta la stringa
    } else {
        // cancella l'ultima parola
        newString = (char *)malloc(lastSpace +1 * sizeof (char));
        for (int i = 0; i < lastSpace; ++i) {
            newString[i] = s[i];
        }
        newString[lastSpace] = '\0';
    }

    return newString;
}

/*
 * il metodo rimuove tutti gli spazi bianchi da una stringa
 * */

/*
il metodo restituisce 1 (true) se la stringa s
è vuota, altrimenti 0; -1 in caso di errore;.*/
int string_is_empty(char s[]){
    if(s == NULL){
        return -1;
    }
    else if(s[0] == '\0'){
        return 1;
    }
    else return 0;
}


/*
restituisce 1 (true) se la stringa s è
una palindrome, altrimenti 0;*/

int string_is_palindrome(char s[]){
    if(s == NULL){
        return 0;
    }
    int size = slength(s);
    for (int i = 0, j = size-1; i < size/2 ; ++i, j--) {
        if(s[i] != s[j]){
            return 0;
        }
    }
    return 1;
}

/*
onfronta le stringhe s1 e s2 e
restituisce 1 se s1 lessicograficamente è prima di s2, 0 se s1 e s2 sono identiche,
-1 se s1 è lessicograficamente dopo di s2;*/
int string_compare(char s1[], char s2[]){
    int index = 0;
    while (s1[index] == s2[index]) {
        if (s1[index] == '\0') {
            return 0;  // le due stringhe sono identiche
        }
        index++;
    }
    if (s1[index] < s2[index]) {
        return 1;  // s1 precede s2
    } else {
        return -1;  // s1 segue s2
    }
}

/*
il metodo elimina gli spazi
bianchi ridondanti nella stringa s;*/
void string_wipe_whitespaces(char s[]) {
    if(s != NULL){
        int i, j;
        for (i = 0, j = 0; s[i] != '\0'; i++) {
            if (s[i] != ' ' || (i > 0 && s[i-1] != ' ')) {
                s[j] = s[i];
                j++;
            }
        }
        s[j] = '\0';
    }
}

/*
4. int string_how_many(char c, char s[]): restituisce il numero di occorrenze
del carattere c nella stringa s .
 * */
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

