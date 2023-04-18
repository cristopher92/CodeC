#ifndef _PORT_H_
#define _PORT_H_

#include "stuff.h"
#include "ship.h"
#include "position.h"


/*
 * Structure for rapresenting a port
 * Parameters:
 * -position:       position on the map
 * -max_ships:      max number of ships that can do operations
 * -stuff_to_send:  stuff available to be shipped
 * -requests:       request for stuffs on the
 * */
typedef struct Port{
    const Position position;
    int max_ships;
    Stuff stuff_to_send[5];
    Stuff requests[3];
}Port;

/*
 * Function to create the request of the port
 * */
void make_requests(Port *port);

/*
 * Function to unload the staff on the ship
 * */
int unload_stuff_port(Port *port, Ship *ship);

/*
 * Function to load the stuff requested in the port
 * */
int load_stuff_port(Port *port, Ship *ship);


#endif