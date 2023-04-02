/*
 * Esercizio A.9 Implementare le seguenti funzioni sul dato list_cl:
1. list_cl l_add_cl(list_cl l, client p): aggiunge il cliente p in coda alla
lista l; restituisce la lista stessa, la lista vuota in caso di errore;
2. List_cl l_rem_cl(list_cl l, client *p): restituisce il cliente in testa alla
lista l, il cliente vuoto se la lista è vuota;
3. int l_is_empty(list_cl l) restituisce 1 se e solo se la lista l è vuota;
4. list_cl l_clear(list_cl l) rimuove tutti gli elementi dalla lista l
rilasciando le risorse allocate per essi; restituisce la lista vuota;
5. int l_length(lists_cl l) restituisce il numero di elementi nella lista l.
 * */
#include "cl_list.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

/*crate a empty list*/
struct cl_list *create_list() {
    struct cl_list *new_cl_list;
    new_cl_list = malloc(sizeof (struct cl_list));
    if(new_cl_list == NULL){
        printf("Error in malloc in create_list, there is no space left\n");
        return NULL;
    }
    new_cl_list->head = NULL;
    new_cl_list->tail = NULL;
    return new_cl_list;
}
/*insert a client in the tail of the list*/
struct cl_list *add_cl(struct cl_list *list, struct client *client){
    struct node *new_node, *prev;
    new_node = malloc(sizeof (struct node));
    if(new_node == NULL){
        printf("Error in malloc in add_cl, there is no space left\n");
        return NULL;
    }
    /*first element*/
    if(list->head == NULL){
        new_node->id = 1;
        new_node->next = NULL;
        list->head = new_node;
        list->tail = new_node;
    }
    /*increare the id counter, save the new client in the tail of the list*/
    else{
        unsigned int tmp = list->tail->id +1;
        new_node->id = tmp;
        prev = list->tail;
        new_node->next = prev;
        list->tail = new_node;
    }
    new_node->client = client;
    return list;
}

/*remove a client from the list*/

 struct cl_list *rem_cl(struct cl_list *cl_list, char *cf) {
    struct node *curr_node, *prev_node = NULL;
    struct client *curr_client;
    int found = 0;
    for(curr_node = cl_list->head; curr_node != NULL; prev_node = curr_node, curr_node = curr_node->next) {
        curr_client = curr_node->client;
        if(strcmp(curr_client->cf, cf) == 0) {
            found = 1;
            break;
        }
    }
    if(found) {
        if(prev_node == NULL) { // case: remove head
            cl_list->head = curr_node->next;
        } else {
            prev_node->next = curr_node->next;
        }
        if(curr_node == cl_list->tail) { // case: remove tail
            cl_list->tail = prev_node;
        }
        remove_client(curr_client);
        free(curr_node);
    } else {
        printf("Client with fiscal code %s not found.\n", cf);
    }
    return cl_list;
}



/*return 1 if the list is empty*/
int list_is_empty(struct cl_list *list){
    if(list->head == NULL)
        return 1;
    return 0;
}

/*clear the list*/
struct cl_list *clear_list(struct cl_list *list){
    if(list->tail != NULL){
        struct node *prev, *cur = list->tail;
        while (cur != NULL){
            free(cur->client);
            prev = cur;
            cur = cur->next;
            free(prev);
        }
    }
    return list;
}

int list_length(struct cl_list *list){
    unsigned int count = 0;
    struct node *cur;
    if(list->tail != NULL){
        cur = list->tail;
        while (cur != NULL){
            cur = cur->next;
            count++;
        }
    }
    return count;
}

void print_list(struct cl_list *list){
    if(!list_is_empty(list)){
        struct node *cur;
        cur = list->tail;
        while (cur != NULL){
            print_client(cur->client);
            cur = cur->next;
        }
    }
}