#ifndef _POSITION_H_
#define _POSITION_H_


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
void random_point(Position *position, max);


#endif