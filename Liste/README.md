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

## 🛠️ Contenuto della cartella

### 1. [linked_list_basics.c](./linked_list_basics.c)
Questo file mostra la logica di base:
- Definizione della `struct Node`.
- Uso della `malloc` per creare nodi nello HEAP.
- Funzione per inserire elementi in testa.

### 2. [library_management.c](./library_management.c)
Un esempio pratico che simula un sistema di gestione per una biblioteca:
- **Struttura**: Ogni nodo è un `Book` con titolo e autore.
- **Aggiunta**: Inserisce nuovi libri nella collezione.
- **Rimozione**: Cerca un libro per titolo, "sgancia" il nodo dalla lista e libera la memoria con `free`.

### 3. [queue.c](./queue.c)
Implementazione di una **Coda (Queue)** tramite lista collegata:
- Segue la logica **FIFO** (First-In, First-Out).
- Funzioni di `enqueue` (aggiunta in coda) e `dequeue` (rimozione dalla testa).
- Gestione dei puntatori `front` e `rear` per operazioni efficienti.

---

> [!IMPORTANT]
> Ricorda sempre di usare la funzione `free()` per ogni nodo creato con `malloc()` quando la lista non serve più, per evitare **memory leaks**.
