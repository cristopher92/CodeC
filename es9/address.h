#ifndef ADDRESS_H
#define ADDRESS_H
#define MAX_LENGTH 25

 struct address{
    char street[MAX_LENGTH];
    char city[MAX_LENGTH];
    int cap;
    char country[MAX_LENGTH];
};
extern struct address *new_address();
extern struct address *set_address(struct address *);
extern void remove_address(struct address *);
extern void print_address(struct address *);
#endif