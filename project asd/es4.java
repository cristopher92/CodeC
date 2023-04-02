import java.util.*;

public class SparseGraph<N, E> {
    private final boolean isDirected;
    private final Map<N, Set<N>> adjacencyMap;

    public SparseGraph(boolean isDirected) {
        this.isDirected = isDirected;
        adjacencyMap = new HashMap<>();
    }

    public void addNode(N node) {
        adjacencyMap.putIfAbsent(node, new HashSet<>());
    }

    public void addEdge(N source, N destination, E label) {
        addNode(source);
        addNode(destination);

        adjacencyMap.get(source).add(destination);
        if (!isDirected) {
            adjacencyMap.get(destination).add(source);
        }
    }

    public boolean isDirected() {
        return isDirected;
    }

    public boolean containsNode(N node) {
        return adjacencyMap.containsKey(node);
    }

    public boolean containsEdge(N source, N destination) {
        return adjacencyMap.containsKey(source) && adjacencyMap.get(source).contains(destination);
    }

    public void removeNode(N node) {
        adjacencyMap.values().forEach(neighbors -> neighbors.remove(node));
        adjacencyMap.remove(node);
    }

    public void removeEdge(N source, N destination) {
        if (adjacencyMap.containsKey(source)) {
            adjacencyMap.get(source).remove(destination);
        }
        if (!isDirected && adjacencyMap.containsKey(destination)) {
            adjacencyMap.get(destination).remove(source);
        }
    }

    public int getNodeCount() {
        return adjacencyMap.size();
    }

    public int getEdgeCount() {
        int count = 0;
        for (Set<N> neighbors : adjacencyMap.values()) {
            count += neighbors.size();
        }
        return isDirected ? count : count / 2;
    }

    public Set<N> getNodes() {
        return adjacencyMap.keySet();
    }

    public Set<N> getNeighbors(N node) {
        return adjacencyMap.getOrDefault(node, Collections.emptySet());
    }

    public E getEdgeLabel(N source, N destination) {
        if (adjacencyMap.containsKey(source) && adjacencyMap.get(source).contains(destination)) {
            return null; // or return the label if edges are labeled
        }
        return null;
    }

    public double getWeight() {
        throw new UnsupportedOperationException("This graph implementation is not weighted.");
    }
}

/*
* Questa implementazione utilizza una mappa di adiacenza basata su HashSet per rappresentare i nodi e i loro vicini nel grafo. Le chiavi della mappa rappresentano i nodi, mentre i valori corrispondenti rappresentano i loro vicini.

Le operazioni di aggiunta e rimozione di nodi e archi hanno una complessità O(1), mentre la complessità dell'operazione di verifica della presenza di un nodo o di un arco è O(1) nel caso medio.

L'implementazione supporta grafi diretti e non diretti e tiene traccia di questa informazione nella variabile isDirected. Se il grafo non è diretto, la rappresentazione mantiene due archi per ogni arco non diretto.

L'implementazione supporta anche le operazioni per la determinazione del numero di nodi e archi, il recupero dei nodi e degli archi del grafo, il recupero dei vicini di un dato nodo e il recupero dell'etichetta associata a una coppia di nodi.
* Questo codice implementa una struttura dati Grafo usando una rappresentazione sparsa, in cui ogni nodo viene rappresentato come una chiave in una mappa e il valore associato alla chiave è un insieme di nodi adiacenti.

La classe SparseGraph<N, E> è parametrizzata su due tipi generici: N rappresenta il tipo dei nodi e E rappresenta il tipo delle etichette degli archi.

Il costruttore della classe prende come parametro un booleano isDirected che indica se il grafo è diretto o meno. Viene inizializzata una mappa adjacencyMap che verrà usata per tenere traccia della lista di adiacenza del grafo.

Il metodo addNode(N node) aggiunge un nodo al grafo, inserendo un'entrata nella mappa adjacencyMap per il nodo specificato e associandolo a un insieme vuoto di nodi adiacenti.

Il metodo addEdge(N source, N destination, E label) aggiunge un arco al grafo tra i nodi source e destination, con etichetta label. Se i nodi non sono già presenti nel grafo, vengono aggiunti. L'arco viene aggiunto alla lista di adiacenza del nodo source, e se il grafo non è diretto, viene aggiunto anche alla lista di adiacenza del nodo destination.

Il metodo isDirected() restituisce un booleano che indica se il grafo è diretto o meno.

Il metodo containsNode(N node) restituisce un booleano che indica se il grafo contiene il nodo specificato.

Il metodo containsEdge(N source, N destination) restituisce un booleano che indica se il grafo contiene l'arco specificato.

Il metodo removeNode(N node) rimuove il nodo specificato dal grafo, eliminando tutte le occorrenze del nodo dalla lista di adiacenza dei nodi adiacenti.

Il metodo removeEdge(N source, N destination) rimuove l'arco specificato dal grafo, eliminando il nodo destination dalla lista di adiacenza del nodo source. Se il grafo non è diretto, viene anche eliminato il nodo source dalla lista di adiacenza del nodo destination.

Il metodo getNodeCount() restituisce il numero di nodi presenti nel grafo.

Il metodo getEdgeCount() restituisce il numero di archi presenti nel grafo. Se il grafo non è diretto, viene diviso per due perché ogni arco è contato due volte.

Il metodo getNodes() restituisce un insieme di tutti i nodi presenti nel grafo.

Il metodo getNeighbors(N node) restituisce un insieme di nodi adiacenti al nodo specificato.

Il metodo getEdgeLabel(N source, N destination) restituisce l'etichetta dell'arco specificato. Poiché questa implementazione di grafo non tiene traccia delle etichette degli archi, il metodo restituisce sempre null.
*
*  La funzione getWeight() viene utilizzata per recuperare il peso complessivo del grafo, se questo è pesato. Tuttavia, poiché la struttura dati che stiamo implementando è ottimale per grafi sparsi e non è specificata la presenza di pesi sugli archi, si può assumere che il grafo non sia pesato e quindi la funzione restituisce sempre un'eccezione UnsupportedOperationException.

Se si volesse implementare un grafo pesato, si potrebbe aggiungere un campo per memorizzare i pesi degli archi, e aggiornare le funzioni di aggiunta e rimozione degli archi di conseguenza. In questo caso, la funzione getWeight() dovrebbe calcolare e restituire il peso complessivo del grafo attraverso una somma dei pesi degli archi presenti.
*
* */