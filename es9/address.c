#include <stdlib.h>
#include <stdio.h>
#include "address.h"

struct address *new_address(){
    struct address *new;
    new = malloc(sizeof (struct address));
    if(new == NULL){
        printf("Error in malloc, there is no space left\n");
        exit(EXIT_FAILURE);
    }
    new = set_address(new);
    return new;
}

struct address *set_address(struct address *ad){
    printf("\nInsert the street: ");
    scanf("%s", ad->street);
    printf("\n\nInsert the city: ");
    scanf("%s", ad->city);
    printf("\n\nInsert the cap: ");
    while (scanf("%d", &ad->cap) != 1) {
        printf("Invalid input. Please insert a valid integer: \n");
        scanf("%*[^\n]"); // discard the rest of the line
    }
    printf("\n\nInsert the country: ");
    scanf("%s", ad->country);
    printf("\n\n");
    return ad;

}

void remove_address(struct address* ad){
    free(ad);
}

void print_address(struct address *address){
    printf("Street: %s\n City: %s\nCap: %d\nCountry: %s\n",
           address->street, address->city, address->cap, address->country);
}
