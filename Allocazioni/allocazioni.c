#include <stdio.h>
#include <stdlib.h>

// ALLOCAZIONE STATICA
// Allocazione che avviene a tempo di compilazione
// Le variabili hanno vita per tutta l'esecuzione del programma
// Vengono memorizzate nel segmento data/bss del programma
#define SIZE 100
static int array_statico[SIZE];  // Esempio di allocazione statica
static int contatore = 0;        // Altro esempio di allocazione statica

// ALLOCAZIONE AUTOMATICA 
// Allocata nello stack di una funzione
// Creazione e distruzione automatica all'entrata/uscita della funzione
// Più veloce dell'allocazione dinamica (heap)
int somma(int x, int y) {
    int risultato = x + y;  // Variabile automatica
    return risultato;
}

// Esempio di allocazione dinamica con return
int* crea_array(int k) {
    int* arr = malloc(sizeof(int) * k);
    if (arr == NULL) {
        return NULL;  // Gestione errore malloc
    }
    for (int i = 0; i < k; i++) {
        arr[i] = 2 * i;
    }
    return arr;
}

int main() {
    // ESEMPI ALLOCAZIONE AUTOMATICA
    int x;                      // Allocazione automatica (valore non inizializzato)
    int y = 3;                  // Allocazione automatica con inizializzazione
    double tentativi_prog1[7] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};  // Array automatico

    // ESEMPI ALLOCAZIONE DINAMICA
    // Usa malloc per allocare e free per deallocare
    // Più flessibile ma richiede gestione manuale
    // Ideale per strutture dati di dimensione variabile (code, liste, ecc.)
    
    int* array_dinamico = (int*)malloc(5 * sizeof(int));
    if (array_dinamico == NULL) {
        printf("Errore allocazione memoria\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        array_dinamico[i] = i + 1;
    }

    // Uso della funzione che ritorna memoria allocata dinamicamente
    int* arr = crea_array(10);
    if (arr == NULL) {
        printf("Errore allocazione memoria\n");
        free(array_dinamico);  // Liberiamo la memoria già allocata
        return 1;
    }

    // Deallocazione della memoria
    free(array_dinamico);
    free(arr);
    
    // ESEMPI USO ALLOCAZIONE STATICA
    array_statico[0] = 42;
    contatore++;

    return 0;
}
