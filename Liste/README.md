# 🔗 Liste Collegate (Linked Lists) in C

Le liste collegate sono strutture dati dinamiche fondamentali per la gestione flessibile della memoria. A differenza degli array, non richiedono spazio contiguo e possono crescere o ridursi a runtime.

## 📖 Cosa sono le Liste?

Una lista è composta da **nodi**. Ogni nodo contiene:
1.  **Dati**: L'informazione utile (es. un intero, una stringa o una struct).
2.  **Puntatore al prossimo**: L'indirizzo di memoria del nodo successivo.

Il termine della lista è indicato da un puntatore `NULL`.

### 🚀 Vantaggi
- **Dinamicità**: Non devi dichiarare la dimensione massima all'inizio.
- **Inserimento/Rimozione**: Molto efficienti (O(1)) se si opera in testa.

---

## 🎨 Diagrammi Comparativi

### Struttura della Lista
```mermaid
graph LR
    Head((TESTA)) --> Node1["Dato: 10 | Next"]
    Node1 --> Node2["Dato: 20 | Next"]
    Node2 --> Node3["Dato: 30 | Next"]
    Node3 --> Null[NULL]
    
    style Head fill:#2980b9,color:#fff
    style Null fill:#7f8c8d,color:#fff
```

### Logica di Inserimento (`insert_at_head`)
```mermaid
graph LR
    Head((TESTA)) --> NewNode["NUOVO NODO"]
    NewNode --> OldHead["VECCHIA TESTA"]
    style Head fill:#2980b9,color:#fff
    style NewNode fill:#27ae60,color:#fff
```

---

## 🛠️ Contenuto della cartella

### 1. [linked_list_basics.c](./linked_list_basics.c)
Logica di base: Definizione `struct Node`, `malloc` e inserimento in testa.

### 2. [library_management.c](./library_management.c)
Esempio pratico: Gestione di una biblioteca con inserimento e rimozione per titolo.

### 3. [queue.c](./queue.c)
Implementazione di una **Coda (Queue)** tramite lista collegata (logica FIFO).

---

## 🌐 Altre Risorse
*   [Visualizzazione Liste Collegate (VisuAlgo)](https://visualgo.net/en/list)
*   [Visualizzazione Code (VisuAlgo)](https://visualgo.net/en/list)

> [!IMPORTANT]
> Ricorda sempre di usare la funzione `free()` per ogni nodo creato con `malloc()` quando la lista non serve più.
