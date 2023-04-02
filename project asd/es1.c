/*
 *
Implementare una libreria che offre un algoritmo di ordinamento
Merge-BinaryInsertion Sort su dati generici, implementando il seguente prototipo di funzione:
void merge_binary_insertion_sort(void *base, size_t nitems, size_t size, size_t k, int (*compar)(const void *, const void*));

base è un puntatore al primo elemento dell'array da ordinare;
nitems è il numero di elementi nell'array da ordinare;
size è la dimensione in bytes di ogni elemento dell'array;
k è un parametro dell'algoritmo;

 compar è il criterio secondo cui ordinare i dati
(dati due puntatori a elementi dell'array, restituisce un numero maggiore, uguale o minore
di zero se il primo argomento è rispettivamente maggiore, uguale o minore del secondo).

Con BinaryInsertion Sort ci riferiamo a una versione dell'algoritmo Insertion Sort in cui la posizione,
all'interno della sezione ordinata del vettore, in cui inserire l'elemento corrente è determinata
tramite ricerca binaria. Il Merge-BinaryInsertion Sort è un algoritmo ibrido che combina
Merge Sort e BinaryInsertion Sort.  L'idea è di approfittare del fatto che il BinaryInsertion Sort
può essere più veloce del Merge Sort quando la sottolista da ordinare è piccola. Ciò suggerisce di considerare
una modifica del Merge Sort in cui le sottoliste di lunghezza k o inferiore sono ordinate usando il
BinaryInsertion Sort e sono poi combinate usando il meccanismo tradizionale di fusione del Merge Sort.
Il valore del parametro k dovrà essere studiato e discusso nella relazione.
Ad esempio, k=0 implica che Merge-BinaryInsertion Sort si comporta esattamente come il Merge Sort classico,
mentre k>>0 aumenta l'utilizzo del BinaryInsertion Sort*/
#include <stdlib.h>
#include <string.h>

/* Funzione di confronto da passare a qsort */
int compare(const void *a, const void *b, void *compar) {
    int (*comp)(const void *, const void *) = compar;
    return comp(a, b);
}

/* Merge Sort */
void merge(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)) {
    if (nmemb > 1) {
        size_t mid = nmemb / 2;
        void *left = base;
        void *right = (char *) base + mid * size;
        merge(left, mid, size, compar);
        merge(right, nmemb - mid, size, compar);
        void *tmp = malloc(nmemb * size);
        size_t i = 0, j = 0, k = 0;
        while (i < mid && j < nmemb - mid) {
            if (compar((char *) left + i * size, (char *) right + j * size) <= 0) {
                memcpy((char *) tmp + k * size, (char *) left + i * size, size);
                i++;
            } else {
                memcpy((char *) tmp + k * size, (char *) right + j * size, size);
                j++;
            }
            k++;
        }
        while (i < mid) {
            memcpy((char *) tmp + k * size, (char *) left + i * size, size);
            i++;
            k++;
        }
        while (j < nmemb - mid) {
            memcpy((char *) tmp + k * size, (char *) right + j * size, size);
            j++;
            k++;
        }
        memcpy(base, tmp, nmemb * size);
        free(tmp);
    }
}

/* Binary Insertion Sort */
void binary_insertion_sort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)) {
    size_t i, j, l, r, m;
    char *tmp = malloc(size);
    for (i = 1; i < nmemb; i++) {
        j = i - 1;
        memcpy(tmp, (char *) base + i * size, size);
        l = 0;
        r = j;
        while (l <= r) {
            m = (l + r) / 2;
            if (compar(tmp, (char *) base + m * size) < 0) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        while (j >= l) {
            memcpy((char *) base + (j + 1) * size, (char *) base + j * size, size);
            j--;
        }
        memcpy((char *) base + l * size, tmp, size);
    }
    free(tmp);
}

void merge_binary_insertion_sort(void *base, size_t nitems, size_t size, size_t k, int (*compar)(const void *, const void*)) {
    if (nitems <= k) {
        binary_insertion_sort(base, nitems, size, compar);
    } else {
        size_t mid = nitems / 2;
        void *left = base;
        void *right = (char *) base + mid * size;
        merge_binary_insertion_sort(left, mid, size, k, compar);
        merge_binary_insertion_sort(right, nitems - mid, size, k, compar);
        void *tmp = malloc(nitems * size);
        size_t i = 0, j = 0, l = 0, r = mid;
        while (i < mid && j < nitems - mid) {
            if (compar((char *) left + i * size, (char *) right + j * size) <= 0) {
                memcpy((char *) tmp + l * size, (char *) left + i * size, size);
                i++;
            } else {
                memcpy((char *) tmp + l * size, (char *) right + j * size, size);
                j++;
            }
            l++;
        }
        while (i < mid) {
            memcpy((char *) tmp + l * size, (char *) left + i * size, size);
            i++;
            l++;
        }
        while (j < nitems - mid) {
            memcpy((char *) tmp + l * size, (char *) right + j * size, size);
            j++;
            l++;
        }
        memcpy(base, tmp, nitems * size);
        free(tmp);
    }
}

/*
 * Questo codice è una libreria che implementa un algoritmo di ordinamento ibrido,
 * chiamato "Merge-Binary Insertion Sort".
 * La libreria include due funzioni di ordinamento:
 *
 * La prima funzione, "merge", implementa l'algoritmo di ordinamento "Merge Sort",
 * che ordina un array di elementi generici (void *) in ordine crescente o decrescente,
 * utilizzando la tecnica di "dividi-et-impera" per dividere l'array in due parti, ordinare le due parti
 * separatamente e poi unirle insieme.
 *
 * La seconda funzione, "binary_insertion_sort", implementa l'algoritmo di ordinamento
 * "Binary Insertion Sort", che ordina un array di elementi generici (void *) in ordine crescente o decrescente,
 * utilizzando la tecnica di inserimento binario per inserire ogni elemento nell'array ordinato,
 * partendo dall'elemento in posizione 1.
 *
 * La terza funzione, "merge_binary_insertion_sort", implementa l'algoritmo di ordinamento
 * "Merge-Binary Insertion Sort", che utilizza l'algoritmo di "Merge Sort" per dividere l'array in parti più piccole,
 * e poi l'algoritmo di "Binary Insertion Sort" per ordinare ciascuna parte. L'algoritmo usa il parametro k per
 * determinare la dimensione minima dell'array in cui si usa l'algoritmo di "Binary Insertion Sort" invece
 * che quello di "Merge Sort", per ridurre la complessità in termini di tempo e spazio.
 *
 * */