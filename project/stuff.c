#include "stuff.h"
#include <stdlib.h>
#include "time.h"
#include "stdio.h"

typedef struct Stuff{
    int type;
    int creation_time;
    int expiration_time;
    int qty;
}Stuff;

int time_left(Stuff stuff, int current_time ){
    return current_time - stuff.creation_time;
}

Stuff *init_stuff(int current_time){
    Stuff *stuff = malloc(sizeof(Stuff));
    srand(time(NULL));
    stuff->type = rand() % (NUM_STUFF + 1);
    stuff->qty = rand() % (SO_SIZE + 1);
    stuff->creation_time = current_time;
    switch (stuff->type) {
        case BANANE:
            stuff->expiration_time = 8;
            break;
        case MANGO:
            stuff->expiration_time = 8;
            break;
        case VITELLO:
            stuff->expiration_time = 5;
            break;
        case MAIALE:
            stuff->expiration_time = 6;
            break;
        case TONNO:
            stuff->expiration_time = 10;
            break;
        case MERLUZZO:
            stuff->expiration_time = 10;
            break;
        default:
            fprintf(stderr,"Error in init_stuff");
            break;
    }
    return stuff;
}

int remove_stuff(Stuff *stuff){
    free(stuff);
}
