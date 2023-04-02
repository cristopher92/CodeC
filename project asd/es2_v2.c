#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEIGHT 16

struct Node {
    struct Node **next;
    size_t size;
    void *item;
};

struct SkipList {
    struct Node *head;
    size_t max_level;
    size_t max_height;
    int (*compare)(const void *, const void *);
};

void new_skiplist(struct SkipList **list, size_t max_height, int (*compar)(const void *, const void *)) {
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->next = (struct Node **)calloc(max_height, sizeof(struct Node *));
    head->size = 1;
    head->item = NULL;

    *list = (struct SkipList *)malloc(sizeof(struct SkipList));
    (*list)->head = head;
    (*list)->max_level = 1;
    (*list)->max_height = max_height;
    (*list)->compare = compar;
}

void clear_skiplist(struct SkipList **list) {
    struct Node *current = (*list)->head;
    struct Node *temp = NULL;

    while (current) {
        temp = current;
        current = current->next[0];
        free(temp->next);
        free(temp);
    }

    free(*list);
    *list = NULL;
}

static struct Node *create_node(void *item, size_t level) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->next = (struct Node **)calloc(level, sizeof(struct Node *));
    new_node->size = level;
    new_node->item = item;
    return new_node;
}

static size_t random_level() {
    size_t level = 1;
    while (((double)rand() / RAND_MAX) < 0.5 && level < MAX_HEIGHT) {
        level++;
    }
    return level;
}

void insert_skiplist(struct SkipList *list, void *item) {
    struct Node *new_node = create_node(item, random_level());

    if (new_node->size > list->max_level) {
        list->max_level = new_node->size;
    }

    struct Node *current = list->head;
    for (size_t i = list->max_level; i > 0; i--) {
        while (current->next[i - 1] != NULL && list->compare(current->next[i - 1]->item, item) < 0) {
            current = current->next[i - 1];
        }
        if (i <= new_node->size) {
            new_node->next[i - 1] = current->next[i - 1];
            current->next[i - 1] = new_node;
        }
    }
}

const void *search_skiplist(struct SkipList *list, void *item) {
    struct Node *current = list->head;

    for (size_t i = list->max_level; i > 0; i--) {
        while (current->next[i - 1] != NULL && list->compare(current->next[i - 1]->item, item) < 0) {
            current = current->next[i - 1];
        }
    }

    if (current->next[0] != NULL && list->compare(current->next[0]->item, item) == 0) {
        return current->next[0]->item;
    } else {
        return NULL;
    }
}
/*
 * new_skiplist(struct SkipList **list, size_t max_height, int (*compar)(const void *, const void*)):
 * questa funzione alloca una nuova SkipList, inizializzando i parametri passati come argomenti.
 * Viene allocato lo spazio per la struct SkipList e viene inizializzato il puntatore head a NULL,
 * il parametro max_height con il valore passato come argomento e il parametro compare con il puntatore
 * alla funzione di comparazione passata come argomento.
 *
 * clear_skiplist(struct SkipList **list): questa funzione elimina una SkipList, liberando la memoria
 * allocata per la SkipList e per tutti i nodi contenuti all'interno di essa. Viene chiamata la
 * funzione free() per tutti i nodi della SkipList e poi per la SkipList stessa.
 *
 * insert_skiplist(struct SkipList *list, void *item): questa funzione inserisce un nuovo elemento
 * item nella SkipList. Viene allocata la memoria per il nuovo nodo Node e viene assegnato l'elemento
 * item al puntatore item all'interno del nodo. La funzione randomLevel() viene chiamata per determinare
 * l'altezza del nuovo nodo, quindi il nuovo nodo viene inserito nella SkipList utilizzando la logica di
 * inserimento della SkipList.
 *
 * const void* search_skiplist(struct SkipList *list, void *item): questa funzione cerca un
 * elemento item nella SkipList. Viene iniziato il ciclo dalla testa della SkipList e
 * scende attraverso i livelli della SkipList fino a trovare il nodo desiderato. Se l'elemento viene trovato,
 * viene restituito il puntatore all'elemento; in caso contrario viene restituito NULL.
 * randomLevel(): questa funzione restituisce un valore intero che rappresenta l'altezza di un nuovo nodo.
 * L'algoritmo utilizzato per determinare l'altezza è basato sulla probabilità, e restituisce valori casuali
 * compresi tra 1 e la massima altezza consentita per la SkipList.
 * */