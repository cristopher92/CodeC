/*
 *Scrivere un programma che realizzi un semplice gioco. Il programma
seleziona un numero intero casuale tra 0 e argv[1] (il primo
argomento passato a riga di comando), e l’utente deve indovinare
questo numero. Per fare questo, viene realizzato un ciclo in cui il
programma legge da tastiera un numero inserito dall’utente:
• se il numero è stato indovinato, il gioco finisce;
• se il numero è maggiore o minore di quello estratto casualmente, viene
stampato a video la scritta “maggiore” o “minore”, rispettivamente.
• Se il giocatore non indovina entro argv[2] secondi (da realizzare con
alarm e gestendo il segnale SIGALRM), il programma stampa a video
“tempo scaduto”, ed esce.
 * */
#define _GNU_SOURCE
#include "signal.h"
#include "errno.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "unistd.h"




void my_handler(int sig){
    printf("Non hai fatto in tempo, sarai più fortunato la prossima volta.\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
    if (argc != 3){
        fprintf(stderr, "Error: \nInserisci come primo parametro il limite e come secondo il tempo\n");
        exit(EXIT_FAILURE);
    }
    int limit, time;
    char *endptr;
    limit = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || limit <= 0) {
        fprintf(stderr, "Error: Invalid limit '%s'\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    time = strtol(argv[2], &endptr, 10);
    if (*endptr != '\0' || time <= 0) {
        fprintf(stderr, "Error: Invalid time '%s'\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    /*gestione del segnale*/
    struct sigaction sa;
    bzero(&sa, sizeof (sa));
    sa.sa_handler = my_handler;
    sigaction(SIGALRM, &sa, NULL);

    srand(getpid());
    int win_number, user_input;
    win_number = rand() % limit +1;

    printf("Pronti, partenzaaaaa....VIA!\n");
    alarm(time);

    do {
        printf("Inserisci un numero compreso tra 0 e %d\n", limit);
        char input[256];
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &user_input) != 1) {
            printf("Input non valido, inserisci un numero intero\n");
            continue;
        }
        if (user_input < win_number){
            printf("Il tuo numero è minore\n");
        }
        else if(user_input > win_number){
            printf("Il tuo numero è maggiore\n");
        } else{
            printf("Complimenti! Hai vinto. \n");
            exit(EXIT_SUCCESS);
        }
    } while (1);




}