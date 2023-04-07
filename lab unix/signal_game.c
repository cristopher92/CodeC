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


int time;
pid_t my_pid, value;

void my_handler(int sig){
    printf("Non hai fatto in tempo ad indovinare!\n");
    exit(EXIT_FAILURE);
}
int conversion(char c[]){
    int conversion(char c[]) {
        int retvalue;
        if (c != NULL) {
            retvalue = atoi(c);
        } else {
            char input[100], *endptr;
            fgets(input, sizeof(input), stdin);
            retvalue = strtol(input, &endptr, 10);
            if (input[0] == '\n' || *endptr != '\n' && *endptr != '\0') {
                printf("Input non valido\n");
                return -1;
            }
        }
        return retvalue;
    }

}
int main(int argc, char * argv[]) {
       if(argc != 3){
           fprintf(stderr, "inserisci il limite e il tempo per il gioco, error: %s\n",
                   strerror(errno));
           exit(EXIT_FAILURE);
       }
       int win_number, user_try, flag = 0, limit, status;
    limit = conversion(argv[1]);
    time = conversion(argv[2]);

    if (limit == -1 || time == -1){
        printf("inseriti valori non idonei\n");
        exit(EXIT_FAILURE);
    }




       struct sigaction sa;
       bzero(&sa, sizeof (sa));
       sa.sa_handler = my_handler;
       sigaction(SIGALRM, &sa, NULL);

    switch (value = fork()) {
        case -1:
            fprintf(stderr, "error in %s", strerror(errno));
            exit(EXIT_FAILURE);
        case 0:
            my_pid = getpid();
            printf("%d", my_pid);
            while (1) {
                printf("mancano %d secondi\n",alarm(time-=1));
                sleep(1);
            }
            break;
        default:
            srand(my_pid);
            win_number = rand() % (limit + 1);
            alarm(time);
            while (1) {
                do {
                    printf("Inserisci un intero compreso tra 0 e %d\n", limit);
                } while ((user_try = conversion(NULL)) == -1);

                if (user_try < win_number) {
                    printf("il tuo numero è minore\n");
                } else if (user_try > win_number) {
                    printf("il tuo numero è maggiore\n");
                } else {
                    printf("Complimenti hai vinto!\n");
                    exit(EXIT_SUCCESS);
                }
            }
            break;
    }

}
