#include "position.h"


Position *init_position ( int max_side) {
    Position *new_position = malloc(sizeof(struct Position));
    if(new_position == NULL){
        fprintf(stderr,"Error allocating memory for position");
        return NULL;
    }
    srand(time(NULL));
    new_position->x = (double)(rand() % max_side);
    new_position->y = (double)(rand() % max_side);
    return new_position;
}

void remove_position(Position *position){
    free(position);
}