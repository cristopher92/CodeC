#ifndef LINE_H
#define LINE_H
/**************************************
 * pulisce la linea corrente          *
 *************************************/
 void clear_line(void);
 /********************************************
 * aggiunge una parola alla fine della linea*
 * corrente. Se non è la pirma parola della *
 * riga mette uno spazio prima della parola *
 *******************************************/
 void add_word(const char *word);

 /*******************************************
  * restituisce il numero dei caratteri     *
  * rimanenti nella riga corrente           *
  ******************************************/
 int space_remaining(void);

 /******************************************
  * scrive la riga corrente giustificandola*
  *****************************************/
  void write_line(void);
  /*****************************************
   * scrive la linea corrente senza        *
   * giustificazione. Se la riga è vuota   *
   * non fa niente                         *
   ****************************************/
  void flush_line(void);

#endif