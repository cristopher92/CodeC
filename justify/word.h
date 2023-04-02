#ifndef WORD_H
#define WORD_H
/**********************************************
 * legge la successiva parola dall'input e la *
 * memorizza. Fa diventare la parola una      *
 * stringa vuota se nessuna parola può essere *
 * letta a causa della fine del file.         *
 * Tronca la parola se la sua lunghezza eccede*
 * len.                                       *
 *********************************************/
int read_word(char *word, int len);
#endif