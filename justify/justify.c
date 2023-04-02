#include "word.h"
#include "line.h"
#include "string.h"
#define MAX_WORD_LEN 20
int main(){
    char word[MAX_WORD_LEN+2];
    int word_len;
    clear_line();
    for(;;){
        //legge una parola ignorando l'andata a capo e le tabulazioni
        word_len = read_word(word, MAX_WORD_LEN+1);
        //se è uguale a zero vuol dire che l'input è finito
        if(word_len == 0){
            flush_line();
            return 0;
        }
        //altrimenti se è più lunga del limite imposto tronca la parola
        if(word_len > MAX_WORD_LEN){
            word[MAX_WORD_LEN] = '*';
        }

        if(word_len+1 > space_remaining()){
            write_line();
            clear_line();
        }
        add_word(word);
    }
}