/*
 * Scrivere un programma che crei una pipe per far comunicare due processi “fratelli”. Il
processo padre deve creare i due figli, che usano la pipe generata prima delle fork().
Stampare come negli esercizi precedenti un messaggio inviato tramite la pipe.*/

#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include <sys/wait.h>
#include "errno.h"
#include "string.h"
#define BUF 256

int main (){

    pid_t child_1, child_2;
    char buf[BUF];
    int fd[2], i, nbytes;

    if(pipe(fd) == -1){
        fprintf(stderr, "Err: %s\n", strerror(errno) );
        exit(EXIT_FAILURE);
    }


    switch (child_1 = fork()) {
        case -1:
            fprintf(stderr, "Err: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        case 0:
                close(fd[0]);
                printf("Sono il primo fratello, il mio pid è: %d\n", getpid());
                char msg[]= "Ciao fratello, piacere di sentirti\n";
                nbytes = write(fd[1], msg, sizeof(msg));
            exit(EXIT_SUCCESS);
        default:
            printf("Sono il padre con il pid %d\n", getpid());
            break;
    }
    switch (child_2 = fork() ) {
        case -1:
            fprintf(stderr, "Err: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        case 0:
            close(fd[1]);
            sleep(2);
            printf("Sono il secondo fratello, il mio pid è: %d\n", getpid());
            memset(buf, '\0', BUF);
            nbytes = read(fd[0],buf, BUF );
            printf("Mio fratello mi ha scritto:\n%s\n",buf);
            exit(EXIT_SUCCESS);
        default:
            printf("Sono il padre con il pid %d\n", getpid());
            break;
    }

    waitpid(child_1, NULL, 0);
    waitpid(child_2, NULL, 0);


}