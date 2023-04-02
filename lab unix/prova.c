#include "stdio.h"
#include "unistd.h"

int main(int argc, char *argv[]){
    printf("test process id\n");

    printf("id del processo %d\n", getpid());
    printf("id del processo padre %d\n", getppid());
}