#ifndef CLIENT_H
#define CLIENT_H
#define CF 16
#define MAX_LENGTH_NAME 20
#include "address.h"

struct client {
    char first_name[MAX_LENGTH_NAME];
    char second_name[MAX_LENGTH_NAME];
    char cf[CF];
    struct address *address;
};

extern struct client *add_new_client();
extern void set_client(struct client *);
extern void remove_client(struct client *);
extern void print_client(struct client *);
#endif