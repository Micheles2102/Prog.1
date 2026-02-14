# Allocazione Dinamica della Memoria


## Cos'è l'Allocazione Dinamica?

L'allocazione dinamica è il processo di riservare memoria durante l'esecuzione del programma (runtime), piuttosto che durante la compilazione. In C, questa memoria viene presa dallo **Heap**, una regione di memoria ampia e flessibile, a differenza dello **Stack** che è gestito automaticamente e ha dimensioni più limitate.

Le funzioni principali per gestirla in C sono:
- `malloc(size_t size)`: Alloca un blocco di memoria.
- `calloc(size_t num, size_t size)`: Alloca e inizializza a zero.
- `realloc(void *ptr, size_t size)`: Ridimensiona un blocco esistente.
- `free(void *ptr)`: Libera la memoria (fondamentale!).

## Vantaggi Principali

### 1. Flessibilità Dimensionale (Runtime Sizing)
Con gli array statici (`int arr[100]`), devi sapere la dimensione a tempo di compilazione. Se ti servono 101 elementi, il programma fallisce o devi ricompilare.
Con l'allocazione dinamica, puoi chiedere esattamente la memoria che ti serve in base all'input dell'utente o ai dati letti da un file:
```c
int n;
scanf("%d", &n);
int *arr = malloc(n * sizeof(int)); // Dimensione decisa "al volo"
```

### 2. Gestione del Ciclo di Vita (Lifetime Control)
Le variabili locali (nello Stack) "muoiono" quando la funzione termina. I dati allocati dinamicamente (nello Heap) sopravvivono finché non decidi tu di liberarli con `free()`.
Questo permette di:
- Creare dati in una funzione e restituirli al chiamante.
- Mantenere strutture dati complesse (come liste collegate, alberi, grafi) che crescono e si riducono nel tempo.

### 3. Gestione di Grandi Quantità di Dati
Lo Stack ha dimensioni limitate (spesso pochi MB). Tentare di allocare array enormi nello stack può causare uno "Stack Overflow".
Lo Heap è limitato solo dalla memoria RAM disponibile (e swap), permettendo di gestire dataset molto più grandi (immagini, database in memoria, ecc.).

## Svantaggi e Rischi
- **Gestione Manuale**: Devi ricordarti di chiamare `free()`, altrimenti crei **Memory Leaks** (la memoria si riempie fino al crash).
- **Frammentazione**: Allocare e liberare continuamente può frammentare lo Heap.
- **Performance**: L'allocazione sullo Heap è leggermente più lenta di quella sullo Stack.

---
Per approfondire come funziona `malloc` "sotto il cofano", consulta la repository:
[manual-malloc](https://github.com/Micheles2102/c-journey/tree/main/manual-malloc)
