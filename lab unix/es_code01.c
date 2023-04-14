/*
 * Esercizio 1: esplorazione della struttura msqid_ds
Scrivere un programma in cui è creata una coda di messaggi.
1. Prima di effettuare qualsiasi operazione di invio di messaggi sulla coda, utilizzando la
struttura di tipo msqid_ds associata alla coda, stampare la dimensione della coda (membro
msg_qbytes), il numero di messaggi in coda (membro msg_qnum) e il tempo dell’ultima
msgsnd() (deve essere 0, poiché non ci sono ancora stati invii sulla coda).
2. Effettuare una msgsnd(), e verificare che il momento della msgsnd() è cambiato. Utilizzare la
funzione ctime() di time.h per visualizzare il momento in cui è occorsa la msgsnd().
3. Prima di terminare il programma deve deallocare la coda
 * */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "string.h"
#include "errno.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "code.h"

int main(){
    int id;
    struct msg_buf msg;
    struct msqid_ds ds;

    if( (id = msgget(KEY, IPC_CREAT | 0600 )) < 0){
        fprintf(stderr, "Error 1: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if(msgctl(id, IPC_STAT, &ds) < 0){
        fprintf(stderr, "Error 2: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("The dimension of the code is %ld\n", ds.msg_qbytes);
    printf("The numbers of message on the code is %ld\n", ds.msg_qnum);
    printf("The time of the last msg is %s", ctime(&ds.msg_stime));

    msg.mtype = 1;
    sprintf(msg.mtext, "prova di invio messaggio\n");

    if(msgsnd(id, &msg, sizeof(struct msg_buf)- sizeof(long ), 0) < 0){
        fprintf(stderr, "Error 3: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    };
    if(msgctl(id, IPC_STAT, &ds) < 0){
        fprintf(stderr, "Error 2: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("The dimension of the code is %ld\n", ds.msg_qbytes);
    printf("The numbers of message on the code is %ld\n", ds.msg_qnum);
    printf("The time of the last msg is %s", ctime(&ds.msg_stime));

    if (msgctl(id, IPC_RMID, NULL)<0) {
        fprintf(stderr, "%s: %d. Errore in msgctl (IPC_RMID) #%03d: %s\n", __FILE__, __LINE__, errno, strerror(errno));
        exit(EXIT_FAILURE);
    }


    return 0;

}


