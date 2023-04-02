#include <stdlib.h>
#include <string.h>

void binary_insertion_sort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
{
    for (size_t i = 1; i < nitems; i++) {
        char *pivot = (char *) base + i * size;
        size_t left = 0;
        size_t right = i;
        while (left < right) {
            size_t mid = left + (right - left) / 2;
            char *midval = (char *) base + mid * size;
            if (compar(midval, pivot) <= 0) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        size_t j = i;
        while (j > left) {
            char *dst = (char *) base + j * size;
            char *src = (char *) base + (j - 1) * size;
            memmove(dst, src, size);
            j--;
        }
        char *dst = (char *) base + left * size;
        memmove(dst, pivot, size);
    }
}

void merge_binary_insertion_sort(void *base, size_t nitems, size_t size, size_t k, int (*compar)(const void *, const void*))
{
    if (nitems <= 1) {
        return;
    }
    if (nitems <= k) {
        binary_insertion_sort(base, nitems, size, compar);
        return;
    }
    size_t mid = nitems / 2;
    merge_binary_insertion_sort(base, mid, size, k, compar);
    merge_binary_insertion_sort((char *) base + mid * size, nitems - mid, size, k, compar);
    void *temp = malloc(nitems * size);
    if (temp == NULL) {
        return;
    }
    size_t i = 0;
    size_t j = mid;
    for (size_t k = 0; k < nitems; k++) {
        if (i < mid && (j >= nitems || compar((char *) base + i * size, (char *) base + j * size) <= 0)) {
            memcpy((char *) temp + k * size, (char *) base + i * size, size);
            i++;
        } else {
            memcpy((char *) temp + k * size, (char *) base + j * size, size);
            j++;
        }
    }
    memcpy(base, temp, nitems * size);
    free(temp);
}

/*
 * L'ordinamento Merge-BinaryInsertion Sort è un algoritmo ibrido che combina Merge Sort e BinaryInsertion Sort.
 * L'idea principale dell'algoritmo è di utilizzare il BinaryInsertion Sort per ordinare le sottoliste più corte,
 * in modo da sfruttare la sua efficienza quando l'input è già parzialmente ordinato, mentre le sottoliste più
 * lunghe vengono ordinate con il Merge Sort.
 * L'algoritmo Merge-BinaryInsertion Sort funziona in questo modo:
 * Dividi la lista in due parti uguali, ricorsivamente ordina le due metà utilizzando l'algoritmo Merge Sort.
 * Quando le due metà sono ordinate, le combiniamo utilizzando il meccanismo di fusione del Merge Sort.
 * Nel caso in cui la sottolista da ordinare abbia dimensione k o inferiore,
 * applichiamo il BinaryInsertion Sort invece del Merge Sort.
 * Il valore del parametro k è importante per bilanciare l'utilizzo dei due algoritmi.
 * Se k è uguale a 0, Merge-BinaryInsertion Sort si comporta esattamente come il Merge Sort classico,
 * mentre se k è molto grande, la maggior parte delle sottoliste saranno ordinate utilizzando il BinaryInsertion Sort.
 * L'utilizzo del BinaryInsertion Sort può essere vantaggioso in diverse situazioni, ad esempio quando la lista è
 * già parzialmente ordinata, oppure quando la dimensione della lista è piccola.
 * In conclusione, Merge-BinaryInsertion Sort combina l'efficienza del Merge Sort per liste di grandi dimensioni
 * e l'efficienza del BinaryInsertion Sort per liste di piccole dimensioni. Il valore di k deve essere scelto
 * in base alle caratteristiche del dataset in modo da massimizzare l'efficienza dell'algoritmo.

 * */