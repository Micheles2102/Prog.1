# Guida al Codice: Strutture, Enum e Union in C

Questo repository contiene un esempio di codice C che illustra i seguenti concetti fondamentali:
- Strutture (struct)
- Enumerazioni (enum)
- Unioni (union)
- Puntatori e allocazione dinamica
- Puntatori a funzione

## Contenuto del Codice

### Strutture (struct)
Le strutture sono un insieme di dati che possono contenere variabili di tipi diversi. Nel codice sono presentati esempi di:
- Dichiarazione di strutture globali (da evitare per motivi di modularità).
- Inizializzazione di strutture utilizzando diversi approcci, tra cui:
  - Inizializzazione completa.
  - Inizializzazione designata.

Esempio:
```c
struct esame prog2 = {"Prog2", 29, "25/07/2099", NULL};
```

### Puntatori a Strutture
Il codice mostra come utilizzare i puntatori per accedere e manipolare i dati delle strutture. Include un esempio corretto di allocazione dinamica:
```c
strutture.next = (struct esame*)malloc(sizeof(struct esame));
if (strutture.next == NULL) {
    perror("Errore nell'allocazione di memoria");
    return 1;
}
strutture.next->data = "23/3/2148";
```

### Puntatori a Funzione
Le strutture possono includere puntatori a funzione per implementare comportamenti specifici basati sui dati della struttura stessa.
Esempio:
```c
struct macchina ferrari;
ferrari.modello = "Ferrari";
ferrari.chilometri = giri_motore;
int giri = ferrari.chilometri(&ferrari);
```

### Alias di Tipo con `typedef`
L'utilizzo di `typedef` consente di creare alias per tipi complessi, migliorando la leggibilità del codice. Nel file è presente un esempio con `Esami_universita`:
```c
typedef struct esami {
    struct esame *esame1;
    struct esame *esame2;
    struct esame *esame3;
    int x;
} Esami_universita;
```

### Enumerazioni (enum)
Le enumerazioni sono utili per definire un insieme di valori costanti. Sono mostrati due esempi:
1. Enumerazione semplice:
   ```c
   enum Materie_da_dare {
       Algoritmi,
       Strutture,
       Reti,
       Sistemi_operativi
   };
   ```
2. Enumerazione con valori personalizzati:
   ```c
   enum Materie_da_dare2 {
       Prog1 = 3,
       Prog2,
       Fondamenti = 23
   };
   ```

### Unioni (union)
Le unioni sono tipi di dati che consentono di risparmiare memoria, permettendo a diversi valori di condividere lo stesso spazio. Esempio:
```c
union Rinuncia {
    char* rinuncia;
    char* ci_sto;
    int tasse;
};
```
**Nota:** Solo un membro della union può contenere un valore alla volta.

## Funzionamento del Codice
Il codice include esempi pratici di utilizzo di strutture, enum e union:
1. Inizializzazione e collegamento di strutture concatenate.
2. Uso di puntatori a funzione per definire comportamenti specifici delle strutture.
3. Allocazione dinamica di memoria e gestione degli errori.
4. Uso delle enumerazioni per migliorare la leggibilità e l'organizzazione del codice.
5. Utilizzo delle union per ottimizzare l'uso della memoria.

## Requisiti
- Compilatore C (ad esempio, `gcc`)

## Compilazione e Esecuzione
Per compilare il codice, utilizzare il comando:
```bash
gcc -o main main.c
```
Eseguire il programma con:
```bash
./main
```

## Note Importanti
- Evitare l'uso di strutture globali.(spesso richiesto agli esami)
- Prestare attenzione alla gestione della memoria dinamica (eseguire sempre il controllo del puntatore).
- Utilizzare gli enum per aumentare la leggibilità del codice e ridurre gli errori.
- Le union devono essere utilizzate con cautela per evitare problemi legati alla sovrascrittura dei dati.


## Estensione dell'Esercizio: Struttura Annidata
In questo esercizio, estenderemo la struttura precedente creando una nuova struttura chiamata `data` che contiene:
- Un intero `ID`.
- Un campo di tipo `record` definito nel precedente esercizio (struttura annidata).

### Dettagli del Codice

L'esercizio prevede di:
- Inizializzare l'array di strutture `data`, con un numero `k` di elementi inizializzati e il resto degli elementi con `ID = -1`.
- Ogni elemento di tipo `data` ha un ID univoco, e per ogni elemento, viene inizializzato il campo `RecordPrincipale` utilizzando la funzione di inizializzazione del primo esercizio.

### Codice

```c
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 5
#define k 3

struct record {
    float x;
    char c;
    char* S;
    char* W;
};

void inizializzazione(struct record *ptr) {
    ptr->x = (float) rand() / RAND_MAX * 7.0; // Numero casuale tra 0.0 e 7.0
    ptr->c = rand() % 26 + 'a'; // Carattere casuale tra 'a' e 'z'

    // Allocazione dinamica per la stringa W
    ptr->W = (char*) malloc(3 * sizeof(char));
    ptr->W[0] = (rand() % 10) + '0';
    ptr->W[1] = (rand() % 10) + '0';
    ptr->W[2] = '
