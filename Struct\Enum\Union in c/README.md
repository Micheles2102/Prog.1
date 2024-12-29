# Esercizi su struct/enum/union in C
Questo repository contiene esercizi di programmazione in C che esplorano l'utilizzo di struct, enum e union. Di seguito vengono descritti gli esercizi e l'idea dietro ciascuno.

## ATTENZIONE: prima di vedere come sono stati svolti gli esercizi, provate a farli da voi o per lo meno a sviluppare una logica dietro l'esercizio. Comprendete il codice ma soprattutto la logica che c'è dietro.
Ogni codice sarà commentato con spiegazioni sulle varie linee di codice; qui nel README troverete solo versioni "grezze" senza commenti (ma con eventuali correzioni essenziali).

## Inizializzazione di una Struttura con Elementi Pseudo-Casuali in C
## Dettagli del Codice

### Descrizione dell'Esercizio
L'obiettivo di questo esercizio è definire una struttura (struct) chiamata `record`, che contiene:
- Un numero in virgola mobile (`float`).
- Un carattere (`char`).
- Due puntatori a caratteri (`char*`), indicanti due stringhe chiamate `S` e `W`.

Il codice include una funzione che:
1. Prende in input un puntatore a una struttura `record`.
2. Inizializza i campi della struttura con valori pseudo-casuali:
   - Il campo `x` è un numero casuale tra `0.0` e `7.0`.
   - Il campo `c` è un carattere casuale tra `'a'` e `'z'`.
   - La stringa `W` contiene due caratteri numerici casuali (tra `'0'` e `'9'`).
   - La stringa `S` contiene due caratteri alfabetici casuali (tra `'a'` e `'z'`).

Infine, la funzione viene chiamata dal `main`, che stampa i valori generati e libera la memoria allocata dinamicamente per le stringhe.

---

## Codice

### Implementazione
Ecco il codice completo:

```c
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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
    ptr->W[2] = '\0'; // Terminatore di stringa

    // Allocazione dinamica per la stringa S
    ptr->S = (char*) malloc(3 * sizeof(char));
    ptr->S[0] = (rand() % 26) + 'a';
    ptr->S[1] = (rand() % 26) + 'a';
    ptr->S[2] = '\0'; // Terminatore di stringa
}

int main() {
    srand(time(0)); // Inizializzazione del seed per numeri casuali

    struct record rec;
    inizializzazione(&rec);

    // Stampa dei valori della struttura
    printf("Il valore di x in record e': %f\n", rec.x);
    printf("Il valore di c in record e': %c\n", rec.c);
    printf("Il valore di W in record e': %s\n", rec.W);
    printf("Il valore di S in record e': %s\n", rec.S);

    // Liberazione della memoria allocata dinamicamente
    free(rec.W);
    free(rec.S);

    return 0;
}
```

---

## Funzionamento del Codice

1. **Struttura `record`**:
   - Contiene quattro campi, di cui due sono puntatori a stringhe allocate dinamicamente.

2. **Funzione `inizializzazione`**:
   - Utilizza la libreria `stdlib.h` per generare numeri casuali.
   - Converte i numeri casuali in valori specifici (caratteri o stringhe) utilizzando la codifica ASCII.
   - Alloca memoria dinamica per i campi stringa (`W` e `S`).

3. **Funzione `main`**:
   - Inizializza il seed della funzione `rand`.
   - Crea un'istanza della struttura `record` e la passa alla funzione `inizializzazione`.
   - Stampa i valori inizializzati e libera la memoria dinamica.

---

## Note Importanti

- **Gestione della Memoria**:
  Ricordarsi di liberare la memoria allocata dinamicamente con `free` per evitare fughe di memoria (memory leaks).

- **Codifica ASCII**:
  La conversione dei numeri casuali in caratteri alfabetici o numerici si basa sulla codifica ASCII.

- **Riproducibilità**:
  Il seed di `rand` può essere inizializzato con un valore fisso per ottenere sempre la stessa sequenza di numeri casuali (ad esempio, durante il debug).

---
