#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_HEIGHT 16

struct Node {
    void* item;
    size_t size;
    struct Node** next;
};

struct SkipList {
    struct Node* head;
    size_t max_level;
    size_t max_height;
    int (*compare)(const void*, const void*);
};

void new_skiplist(struct SkipList** list, size_t max_height, int (*compare)(const void*, const void*)) {
    *list = malloc(sizeof(struct SkipList));
    (*list)->head = malloc(sizeof(struct Node));
    (*list)->head->next = malloc(sizeof(struct Node*) * max_height);
    (*list)->head->size = 1;
    (*list)->head->item = NULL;
    (*list)->max_level = 1;
    (*list)->max_height = max_height;
    (*list)->compare = compare;
    for (int i = 0; i < max_height; i++) {
        (*list)->head->next[i] = NULL;
    }
    srand(time(NULL));
}

void clear_skiplist(struct SkipList** list) {
    struct Node* curr = (*list)->head;
    while (curr != NULL) {
        struct Node* temp = curr;
        curr = curr->next[0];
        free(temp->next);
        free(temp->item);
        free(temp);
    }
    free(*list);
    *list = NULL;
}

struct Node* createNode(void* item, size_t size) {
    struct Node* node = malloc(sizeof(struct Node));
    node->item = item;
    node->size = size;
    node->next = malloc(sizeof(struct Node*) * size);
    for (int i = 0; i < size; i++) {
        node->next[i] = NULL;
    }
    return node;
}

int randomLevel() {
    int lvl = 1;
    while (((double)rand() / (double)RAND_MAX) < 0.5 && lvl < MAX_HEIGHT) {
        lvl++;
    }
    return lvl;
}

void insert_skiplist(struct SkipList* list, void* item) {
    size_t size = randomLevel();
    if (size > list->max_level) {
        list->max_level = size;
    }
    struct Node* new = createNode(item, size);
    struct Node* x = list->head;
    for (int k = list->max_level - 1; k >= 0; k--) {
        while (x->next[k] != NULL && list->compare(x->next[k]->item, item) < 0) {
            x = x->next[k];
        }
        if (k < new->size) {
            new->next[k] = x->next[k];
            x->next[k] = new;
        }
    }
}

const void* search_skiplist(struct SkipList *list, void *item) {
    struct Node *x = list->head;
    for (size_t k = list->max_level; k > 0; k--) {
        while (x->next[k-1] != NULL && list->compare(x->next[k-1]->item, item) < 0) {
            x = x->next[k-1];
        }
    }
    if (x->next[0] != NULL && list->compare(x->next[0]->item, item) == 0) {
        return x->next[0]->item;
    } else {
        return NULL;
    }
}
/*
 * La funzione insert_skiplist inserisce un nuovo nodo con l'elemento item nella SkipList list.
 * La funzione crea un nuovo nodo con create_node e determina il livello del nuovo nodo tramite random_level.
 * Se il livello del nuovo nodo è maggiore del massimo livello della SkipList, viene aggiornato il
 * valore max_level di list. La funzione quindi cerca il punto di inserimento per il nuovo nodo,
 * partendo dall'elemento head della SkipList e muovendosi verso il basso, fino ad arrivare al livello 1.
 * Quando trova il punto di inserimento, la funzione collega il nuovo nodo al nodo precedente e al nodo successivo,
 * a partire dal livello 1 e salendo fino al livello del nuovo nodo.
 * La funzione search_skiplist cerca l'elemento item nella SkipList list.
 * La funzione parte dall'elemento head della SkipList e si sposta verso il basso, finché non trova
 * l'elemento cercato o arriva al livello 1. Se trova l'elemento cercato, la funzione restituisce un
 * puntatore a esso. Altrimenti, la funzione restituisce NULL.
 * */