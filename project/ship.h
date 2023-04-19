#ifndef _SHIP_H_
#define _SHIP_H_
#include "stuff.h"
#include "position.h"

#define NO_STUFF NULL
#define CAPACITY 20
#define SO_SPEED 30

/*
 * Structure rapresenting a ship
 * Parameters:
 * -id:         ship identifier
 * -capacity:   carrying capacity of the ship
 * -speed:      speed to travel
 * -stuff:      type of stuff on board
 * -position:   current position in the map
 * */
typedef struct Ship{
    int id;
    int capacity;
    double speed;
    Stuff stuff;
    Position position;
}Ship;

/*
 * Function to init a ship
 * */
Ship* init_ship(int id, int capacity, int max_side);


/*
 * Function to remove a ship
 * */
void remove_ship(Ship *ship);


/*
 * Function to calculate the time to move the ship from start to destination
 * */
int time_for_trip(Position destination, Position start);

/*
 * Function to move the ship from start to destination
 * */
void trip_ship(Position destination, Position start);


/*
 * Function to load the stuff on board, return 0 to success, -1 for errors
 * */
int load_stuff(Stuff stuff, Ship *ship);

/*
 * Function to unload the stuff on board, return 0 to success, -1 for errors
 * */
int unload_stuff(Stuff stuff, Ship *ship);

#endif