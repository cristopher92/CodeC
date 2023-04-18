#include <stdlib.h>
#include "time.h"
#define BANANE 1
#define ARANCE 2
#define CARNE  3
#define PESCE  4
#define MOLLUSCHI 5

#define NUM_STUFF 10
#define MAX_QTY 5

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
    stuff->qty = rand() % (MAX_QTY + 1);
    stuff->creation_time = current_time;
    switch (expression) {
        
    }
    return stuff;
}
