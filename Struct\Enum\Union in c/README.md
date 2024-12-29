
# Esercizi su struct/enum/union in C
Questo repository contiene esercizi di programmazione in C che esplorano l'utilizzo di struct, enum e union. Di seguito vengono descritti gli esercizi e l'idea dietro ciascuno.

## ATTENZIONE: prima di vedere come sono stati svolti gli esercizi, provate a farli da voi o per lo meno a sviluppare una logica dietro l'esercizio. Comprendete il codice ma soprattutto la logica che c'è dietro.
Ogni codice sarà commentato con spiegazioni sulle varie linee di codice; qui nel README troverete solo versioni "grezze" senza commenti (ma con eventuali correzioni essenziali).

## Inizializzazione di una Struttura con Elementi Pseudo-Casuali in C
### Descrizione dell'Esercizio
L'obiettivo di questo esercizio è definire una struttura (`struct`) chiamata `record`, che contiene:
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

### Codice

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
    ptr->W[2] = '
