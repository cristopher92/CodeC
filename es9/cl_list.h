#ifndef CL_LIST_H
#define CL_LIST_H
#include "client.h"

struct node{
    unsigned int id;
    struct client *client;
    struct node *next;
};

struct cl_list{
    struct node *head;
    struct node *tail;
};

extern struct cl_list *create_list();
extern struct cl_list *add_cl(struct cl_list *, struct client *);
extern struct cl_list *rem_cl(struct cl_list *, char *);
extern int list_is_empty(struct cl_list *);
extern struct cl_list *clear_list(struct cl_list *);
extern int list_length(struct cl_list *);
extern void print_list(struct cl_list *);
#endif