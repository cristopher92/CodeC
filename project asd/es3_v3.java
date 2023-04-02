import java.util.*;

public class PriorityQueue<E> implements AbstractQueue<E> {

    private List<E> queue;
    private Comparator<E> comparator;

    public PriorityQueue(Comparator<E> comparator) {
        this.queue = new ArrayList<>();
        this.comparator = comparator;
    }

    @Override
    public boolean empty() {
        return queue.isEmpty();
    }

    @Override
    public boolean push(E e) {
        return queue.add(e) && bubbleUp(queue.size() - 1);
    }

    @Override
    public E top() {
        if (empty()) {
            throw new NoSuchElementException("Queue is empty");
        }
        return queue.get(0);
    }

    @Override
    public void pop() {
        if (empty()) {
            throw new NoSuchElementException("Queue is empty");
        }
        swap(0, queue.size() - 1);
        queue.remove(queue.size() - 1);
        bubbleDown(0);
    }

    private boolean bubbleUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (compare(queue.get(i), queue.get(parent)) < 0) {
                swap(i, parent);
                i = parent;
            } else {
                break;
            }
        }
        return true;
    }

    private void bubbleDown(int i) {
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;
            if (left < queue.size() && compare(queue.get(left), queue.get(smallest)) < 0) {
                smallest = left;
            }
            if (right < queue.size() && compare(queue.get(right), queue.get(smallest)) < 0) {
                smallest = right;
            }
            if (smallest == i) {
                break;
            }
            swap(i, smallest);
            i = smallest;
        }
    }

    private void swap(int i, int j) {
        E temp = queue.get(i);
        queue.set(i, queue.get(j));
        queue.set(j, temp);
    }

    private int compare(E a, E b) {
        if (comparator != null) {
            return comparator.compare(a, b);
        } else {
            return ((Comparable<E>) a).compareTo(b);
        }
    }
}

/*
* Costruttore: Il costruttore crea una nuova coda con priorità vuota, utilizzando un Comparator per
* confrontare gli elementi. La coda è rappresentata da una lista (ArrayList) di elementi di
* tipo generico E. Il Comparator viene passato come parametro al costruttore.
*
* empty: Il metodo empty controlla se la coda con priorità è vuota, restituendo true se
* lo è e false altrimenti. Questo viene fatto verificando se la lista di elementi è vuota.
*
* push: Il metodo push aggiunge un nuovo elemento alla coda con priorità, restituendo true se
* l'elemento è stato aggiunto correttamente e false altrimenti. L'elemento viene aggiunto alla fine
* della lista di elementi, e poi viene fatto "risalire" nella posizione corretta tramite la chiamata
* al metodo bubbleUp. Il metodo bubbleUp confronta l'elemento appena aggiunto con il suo genitore,
* scambiandoli se necessario, fino a quando l'elemento non raggiunge la posizione corretta nella coda con priorità.
*
* top: Il metodo top restituisce l'elemento in cima alla coda con priorità, ovvero il primo elemento
* della lista di elementi. Se la coda è vuota, viene lanciata un'eccezione di tipo NoSuchElementException.
*
* pop: Il metodo pop rimuove l'elemento in cima alla coda con priorità e lo sostituisce
* con l'ultimo elemento della lista di elementi. Poi l'ultimo elemento viene fatto "scendere"
* nella posizione corretta tramite la chiamata al metodo bubbleDown. Il metodo bubbleDown confronta
* l'elemento appena spostato con i suoi figli, scambiandoli se necessario, fino a quando l'elemento non
* raggiunge la posizione corretta nella coda con priorità. Se la coda è vuota, viene lanciata un'eccezione
* di tipo NoSuchElementException.
*
* bubleUp: Il metodo bubbleUp viene chiamato quando un nuovo elemento viene aggiunto alla coda e
* ha una priorità superiore a quella dell'elemento in cima alla coda. Il metodo confronta l'elemento
* appena aggiunto con il padre dell'elemento nella posizione corrente, scambiando i due se necessario,
* fino a quando l'elemento in posizione corrente ha una priorità maggiore di quella del padre o arriva alla
* radice dell'albero (posizione 0).
*
* bubleDown: Il metodo bubbleDown viene chiamato quando un elemento viene rimosso dalla coda, e il
* nuovo elemento in cima alla coda ha una priorità inferiore a quella di almeno uno dei suoi figli.
* Il metodo confronta l'elemento in cima alla coda con i suoi figli, scambiando l'elemento con il figlio con
* la priorità più alta fino a quando l'elemento in cima ha una priorità maggiore di entrambi i figli o arriva
* alle foglie dell'albero.
*
* swap: Il metodo swap scambia due elementi nella lista di elementi, dati i loro indici.
*
* compare: Il metodo compare confronta due elementi di tipo generico E utilizzando il Comparator
* fornito al costruttore. Se il Comparator non è stato fornito al costruttore, viene lanciata
* un'eccezione di tipo NullPointerException.
*
*
* */
