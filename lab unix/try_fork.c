#include "unistd.h"
#include "sys/wait.h"
#include "stdio.h"
#include "errno.h"
#include "stdlib.h"
#include "string.h"
#define FILE_NAME "file.txt"

int main(){
    FILE *fp;
    if((fp = fopen(FILE_NAME, "w+"))== NULL){
        fprintf(stderr, "error opening %s. Error %d. MSG: %s\n", FILE_NAME, errno, strerror(errno));
        exit(0);
    }
    printf("fork programm starting\n");
    pid_t father_pid, child_pid;
    int status;

    switch (child_pid = fork()) {
        case -1:
            perror("fork failed");
            exit(1);
        case 0:
            printf("i'm the child %d\n", getpid());
            int i;
            for (i = 0; i < 10 ; i++) {
                fprintf(fp, "%d ciao papà mi sei mancato\n", i);
            }
            fclose(fp);
            break;
        default:
            wait(&status);
            rewind(fp);
            char buffer[255];
            while(fgets(buffer, 255, fp) != NULL) {
                printf("%s", buffer);
            };
            fclose(fp);
    }
}
