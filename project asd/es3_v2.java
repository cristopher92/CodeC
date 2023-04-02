import java.util.*;

public class PriorityQueue<E> implements AbstractQueue<E> {

    private List<E> heap;
    private Comparator<E> comparator;

    public PriorityQueue(Comparator<E> comparator) {
        heap = new ArrayList<>();
        this.comparator = comparator;
    }

    public PriorityQueue() {
        this(null);
    }

    private int compare(E a, E b) {
        if (comparator == null) {
            return ((Comparable<E>) a).compareTo(b);
        } else {
            return comparator.compare(a, b);
        }
    }

    private void swap(int i, int j) {
        E tmp = heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, tmp);
    }

    private void heapifyUp(int i) {
        if (i == 0) {
            return;
        }
        int parent = (i - 1) / 2;
        if (compare(heap.get(i), heap.get(parent)) > 0) {
            swap(i, parent);
            heapifyUp(parent);
        }
    }

    private void heapifyDown(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if (left < heap.size() && compare(heap.get(left), heap.get(largest)) > 0) {
            largest = left;
        }
        if (right < heap.size() && compare(heap.get(right), heap.get(largest)) > 0) {
            largest = right;
        }
        if (largest != i) {
            swap(i, largest);
            heapifyDown(largest);
        }
    }

    public boolean empty() {
        return heap.isEmpty();
    }

    public boolean push(E e) {
        heap.add(e);
        heapifyUp(heap.size() - 1);
        return true;
    }

    public E top() {
        if (empty()) {
            throw new NoSuchElementException();
        }
        return heap.get(0);
    }

    public void pop() {
        if (empty()) {
            throw new NoSuchElementException();
        }
        swap(0, heap.size() - 1);
        heap.remove(heap.size() - 1);
        heapifyDown(0);
    }

}
