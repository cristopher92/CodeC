#include <stdlib.h>
#include <string.h>

void binary_insertion_sort(void *base, size_t nitems, size_t size,
                           int (*compar)(const void *, const void *)) {
    char *p = base;
    for (size_t i = 1; i < nitems; i++) {
        char *key = p + i * size;
        size_t left = 0, right = i;
        while (left < right) {
            size_t mid = left + (right - left) / 2;
            char *mid_key = p + mid * size;
            if (compar(mid_key, key) <= 0) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        memmove(p + left * size + size, p + left * size, (i - left) * size);
        memcpy(p + left * size, key, size);
    }
}

void merge(void *left, void *right, size_t left_len, size_t right_len,
           size_t size, int (*compar)(const void *, const void *), void *tmp) {
    char *l = left, *r = right, *t = tmp;
    while (left_len > 0 && right_len > 0) {
        if (compar(l, r) <= 0) {
            memcpy(t, l, size);
            l += size;
            left_len--;
        } else {
            memcpy(t, r, size);
            r += size;
            right_len--;
        }
        t += size;
    }
    if (left_len > 0) {
        memcpy(t, l, left_len * size);
    } else {
        memcpy(t, r, right_len * size);
    }
    memcpy(left, tmp, (left_len + right_len) * size);
}

void merge_binary_insertion_sort_impl(void *base, size_t nitems, size_t size,
                                      size_t k,
                                      int (*compar)(const void *, const void *),
                                      void *tmp) {
    if (nitems <= 1) {
        return;
    }
    if (nitems <= k) {
        binary_insertion_sort(base, nitems, size, compar);
        return;
    }
    size_t left_len = nitems / 2;
    size_t right_len = nitems - left_len;
    char *left = base;
    char *right = base + left_len * size;
    merge_binary_insertion_sort_impl(left, left_len, size, k, compar, tmp);
    merge_binary_insertion_sort_impl(right, right_len, size, k, compar, tmp);
    merge(left, right, left_len, right_len, size, compar, tmp);
}

void merge_binary_insertion_sort(void *base, size_t nitems, size_t size,
                                 size_t k,
                                 int (*compar)(const void *, const void *)) {
    void *tmp = malloc(nitems * size);
    if (tmp == NULL) {
        return;
    }
    merge_binary_insertion_sort_impl(base, nitems, size, k, compar, tmp);
    free(tmp);
}
/*
 * Questo codice contiene l'implementazione di un algoritmo di ordinamento chiamato "Merge-Binary Insertion Sort".
 * Questo codice contiene l'implementazione di un algoritmo di ordinamento chiamato "Merge-Binary Insertion Sort".
 * L'algoritmo combina due algoritmi di ordinamento, ovvero il "Merge Sort" e il "Binary Insertion Sort",
 * in modo da ottenere un algoritmo efficiente per ordinare grandi array di dati.
 *
 * La funzione "binary_insertion_sort" implementa l'algoritmo di ordinamento "Binary Insertion Sort".
 * Questo algoritmo è simile all'ordinamento a inserimento standard, ma anziché confrontare l'elemento
 * da inserire con ogni elemento dell'array, utilizza una ricerca binaria per trovare la posizione corretta
 * in cui inserirlo. Ciò riduce il numero di confronti necessari e quindi rende l'algoritmo più efficiente.
 *
 * La funzione "merge" implementa l'algoritmo di ordinamento "Merge Sort". Questo algoritmo divide ricorsivamente
 * l'array in due metà, ordina le due metà separatamente e poi le combina in modo ordinato.
 * L'implementazione usa una variabile temporanea "tmp" per memorizzare gli elementi durante la fusione.
 *
 * La funzione "merge_binary_insertion_sort_impl" è la funzione principale dell'algoritmo
 * Merge-Binary Insertion Sort. Divide l'array in due metà ricorsivamente fino a quando la
 * dimensione dell'array non è inferiore a "k", che viene scelto come soglia per il passaggio
 * all'ordinamento a inserimento binario. Quando la dimensione dell'array è inferiore a "k",
 * utilizza l'ordinamento a inserimento binario per ordinare l'array. Infine, combina le due metà
 * ordinate utilizzando l'ordinamento "Merge Sort".
 *
 * La funzione "merge_binary_insertion_sort" è la funzione pubblica dell'algoritmo.
 * Alloca memoria temporanea "tmp" e invoca la funzione "merge_binary_insertion_sort_impl" per ordinare l'array.
 * Inoltre, gestisce il caso in cui non c'è abbastanza memoria per allocare la variabile temporanea "tmp".
 * In sintesi, l'algoritmo Merge-Binary Insertion Sort è una combinazione dell'ordinamento a inserimento
 * binario e dell'ordinamento Merge Sort. L'algoritmo divide l'array in due metà, ricorsivamente,
 * fino a quando l'array non raggiunge una dimensione inferiore alla soglia "k".
 * Quando l'array è abbastanza piccolo, utilizza l'ordinamento a inserimento binario per ordinare l'array e
 * poi combina le due metà ordinate utilizzando l'ordinamento Merge Sort. Questo algoritmo è particolarmente
 * utile per ordinare grandi array di dati, poiché combina le caratteristiche di entrambi gli algoritmi per
 * ottenere un algoritmo efficiente e veloce.
 ***************************************************************************************************************/
