#ifndef _POSITION_H_
#define _POSITION_H_
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#include "stdio.h"

/*
 * Structure for rappresentin one point in the map
 * */
typedef struct Position{
    double x;
    double y;
}Position;

/*
 * Function to generate a random point
 * */
Position *init_position(int max_side);

/*
 * Fuction to remove a position
 * */

void remove_position(Position *position);




#endif