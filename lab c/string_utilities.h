/*
 * Esercizio A.6 Implementare le seguenti funzioni su stringhe C:
1. int slength(char s[]): restituisce la dimensione in caratteri della stringa
passata come argomento, -1 in caso di errore;
2. char *scut_last_word(char s[]): cancella logicamente dalla stringa passata
come argomento l’ultima parola senza ri-allocarla; restituisce il puntatore alla
stringa stessa;
3. int string_is_empty(char s[]): il metodo restituisce 1 (true) se la stringa s
è vuota, altrimenti 0; -1 in caso di errore;.
Esercizio A.7 Implementare le seguenti funzioni su stringhe C:
1. int string_is_palindrome(char s[]): restituisce 1 (true) se la stringa s è
una palindrome, altrimenti 0;
2. int string_compare(char s1[], char s2[]): confronta le stringhe s1 e s2 e
restituisce 1 se s1 lessicograficamente è prima di s2, 0 se s1 e s2 sono identiche,
-1 se s1 è lessicograficamente dopo di s2;
3. void string_wipe_whitespaces(char s[]): il metodo elimina gli spazi
bianchi ridondanti nella stringa s;
4. int string_how_many(char c, char s[]): restituisce il numero di occorrenze
del carattere c nella stringa s .
 * */
#ifndef STRING_UTILITIES_H
#define STRING_UTILITIES_H

//definizione delle funzioni
int slength(char s[]);
char *scut_last_word(char s[]);
int string_is_empty(char s[]);
int string_is_palindrome(char s[]);
int string_compare(char s1[], char s2[]);
void string_wipe_whitespaces(char s[]);
int string_how_many(char c, char s[]);

#endif