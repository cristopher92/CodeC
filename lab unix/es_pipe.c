/*
 * Scrivere un semplice programma che crei una pipe, chiudendo i file descriptors
inutilizzati nei due processi che seguono dopo una fork(). Il padre deve essere
configurato come scrittore ed il figlio come lettore.
 Partendo dall’esercizio 1, far comunicare padre e figlio attraverso la pipe (il padre
deve scrivere una stringa sul pipe ed il figlio la deve stampare su terminale).
(Ricordarsi di chiudere il write end del pipe del padre al termine della scrittura.)
3. Partendo dall’esercizio 2, far comunicare padre e figlio attraverso la pipe in cui
vengono passati all’interno di un ciclo for diversi (10) numeri.*/

#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include <sys/wait.h>
#define NUM_MSG 10



int main(){
    
    int f_descriptor[2], num;
    //char buffer[BUFSIZ];
    pid_t result;

    if((pipe(f_descriptor)) == -1){
        fprintf(stderr, "Error in creation of pipe\n");
        exit(EXIT_FAILURE);
    }


    switch (result = fork()) {
        case -1:
            fprintf(stderr, "Error in fork creation\n");
            exit(EXIT_FAILURE);
        case 0:
            /*child process*/
            sleep(2);
            close(f_descriptor[1]);;
            printf("Hi, i'm the child, with the pid %d\n", getpid());
            while ((read(f_descriptor[0], &num, sizeof(int))) > 0){
                printf("My dad %d wrote: %d\n", getppid(), num);
            }
            close(f_descriptor[0]);
            break;
        default:
            close(f_descriptor[0]);
            //char msg[] = "faidi coddai";
            printf("Hi, i'm the dad, with the pid %d\n", getpid());
            int i;
            for (i = 0; i < NUM_MSG; ++i) {
                num = i+1;
                write(f_descriptor[1], &num, sizeof(int));
            }

            close(f_descriptor[1]);
            wait(NULL);
            printf("he finish to read\n");
            break;
    }
    
}