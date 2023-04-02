#include "client.h"
#include "address.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

struct client *add_new_client(){
    struct client *new_client;
    new_client = malloc(sizeof (struct client));
    if(new_client == NULL){
        printf("Error in malloc on add_new_client, there is no space left\n");
    }
    set_client(new_client);
    return new_client;
}

void set_client(struct client *cl){
    printf("Insert the first name: ");
    scanf("%s", cl->first_name);
    printf("\n\nInsert the second name: ");
    scanf("%s", cl->second_name);
    printf("\n\nInsert the fiscal code: ");
    scanf("%s", cl->cf);
    struct address *address = new_address();
    cl->address = address;
    printf("\n\n");
}

void remove_client(struct client *client){
    remove_address(client->address);
    free(client);
}

void print_client(struct client *client){
    printf("First name: %s\nSecond name: %s\nCF: %s\n", client->first_name, client->second_name, client->cf);
    print_address(client->address);
}




