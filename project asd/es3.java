import java.util.Comparator;

public class PriorityQueue<E> implements AbstractQueue<E> {
    private Node<E> head;
    private Comparator<E> comparator;

    private static class Node<E> {
        private E element;
        private int priority;
        private Node<E> next;

        private Node(E element, int priority, Node<E> next) {
            this.element = element;
            this.priority = priority;
            this.next = next;
        }
    }

    public PriorityQueue(Comparator<E> comparator) {
        this.head = null;
        this.comparator = comparator;
    }

    public boolean empty() {
        return head == null;
    }

    public boolean push(E element) {
        int priority = 0;
        Node<E> newNode = new Node<>(element, priority, null);

        if (empty()) {
            head = newNode;
            return true;
        }

        if (comparator.compare(element, head.element) > 0) {
            newNode.next = head;
            head = newNode;
            return true;
        }

        Node<E> current = head;
        while (current.next != null && comparator.compare(element, current.next.element) <= 0) {
            current = current.next;
        }

        newNode.next = current.next;
        current.next = newNode;
        return true;
    }

    public E top() {
        if (empty()) {
            return null;
        }

        return head.element;
    }

    public void pop() {
        if (empty()) {
            return;
        }

        head = head.next;
    }
}

/*
* Nella classe PriorityQueue<E>, il campo head è un riferimento al nodo in cima alla coda con priorità.
*
* Il campo comparator è un oggetto che implementa l'interfaccia Comparator<E> e viene usato per confrontare
* gli elementi della coda con priorità.
*
* Il costruttore PriorityQueue(Comparator<E> comparator) crea una coda vuota e prende come argomento un
* oggetto Comparator<E> da usare per confrontare gli elementi.
*
* Il metodo empty() restituisce true se la coda è vuota, false altrimenti.
*
* Il metodo push(E element) aggiunge un elemento alla coda con priorità. Il metodo crea un nuovo nodo con
* l'elemento e la priorità iniziale di 0. Se la coda è vuota, il nuovo nodo diventa il primo elemento della coda.
* Se l'elemento ha una priorità maggiore rispetto all'elemento in cima alla coda, il nuovo nodo diventa
* il nuovo elemento in cima alla coda. Altrimenti, il nuovo nodo viene inserito nella coda in modo
* ordinato in base alla priorità.
*
* Il metodo top() restituisce l'elemento in cima alla coda con priorità, se la coda non è vuota.
* Se la coda è vuota, il metodo restituisce null.
*
* Il metodo pop() rimuove l'elemento in cima alla coda con priorità, se la coda non è vuota.
*   Se la coda è vuota, il metodo non fa nulla.
*
* */