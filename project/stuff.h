#ifndef _STUFF_H_
#define _STUFF_H_

/*
 * set food macro
 */
#define BANANE 1
#define MANGO 2
#define VITELLO 3
#define MAIALE 4
#define TONNO 5
#define MERLUZZO 6

#define NUM_STUFF 10
#define MAX_QTY 5

/*
 * Structure for rappresenting stuff
 * Parameters:
 * type:                type of stuff, es BANANE etc
 * creation_time:
 * expiration_time:     time before the stuff expire
 * qty:                 quantities of this type
 * */
typedef struct Stuff{
    int type;
    int creation_time;
    int expiration_time;
    int qty;
}Stuff;

/*
 * Function that returns the day left before the stuff expires
 * */
int time_left(Stuff stuff, int current_time);

/*
 * Function to randm initialize a stuff
 * */
Stuff *init_stuff(int current_time);

#endif