#include "ship.h"

Ship* init_ship(int id, int capacity, int max_side) {
    Ship *new_ship = malloc(sizeof(Ship));
    if (new_ship == NULL) {
        fprintf(stderr,"Error allocating memory for ship" );
        return NULL;
    }
    new_ship->id = id;
    new_ship->capacity = CAPACITY;
    new_ship->speed = SO_SPEED;
    new_ship->stuff = NO_STUFF;
    new_ship->position = init_position(max_side);
    if(new_ship->position == NULL){
        return NULL;
    }
    return new_ship;
}

void remove_ship(Stuff *stuff){
    free(stuff);
}

int time_for_trip(Position destination, Position start){

}
