#include <stdio.h>

/**
 * Esempio 2: Puntatori e Passaggio per Riferimento
 * 
 * Questo esempio dimostra:
 * 1. Cos'è un puntatore (variabile che memorizza un indirizzo).
 * 2. Come ottenere l'indirizzo di una variabile usando '&'.
 * 3. Come accedere al valore a un indirizzo usando '*'.
 * 4. Come modificare variabili in una funzione usando i puntatori (passaggio per riferimento).
 */

// Funzione per scambiare due interi usando i puntatori
// Passiamo gli indirizzi di 'a' e 'b' per poter modificare le variabili originali
void swap(int *a, int *b) {
    int temp = *a; // prendi il valore all'indirizzo 'a'
    *a = *b;       // metti il valore all'indirizzo 'b' nell'indirizzo 'a'
    *b = temp;     // metti il valore temp nell'indirizzo 'b'
}

// Funzione per aggiungere un valore a un riferimento variabile
void add_to_value(int *target, int amount) {
    *target += amount; // Modifica il valore all'indirizzo 'target'
}

int main() {
    int x = 10;
    int y = 20;

    printf("Valori originali: x = %d, y = %d\n\n", x, y);

    // 1. Uso base dei Puntatori
    int *ptr = &x; // 'ptr' memorizza l'indirizzo di 'x'
    
    printf("Indirizzo di x: %p\n", (void*)&x);
    printf("Valore di ptr: %p\n", (void*)ptr);
    printf("Valore puntato da ptr (*ptr): %d\n\n", *ptr);

    // 2. Modifica tramite puntatore
    *ptr = 15; // Cambia 'x' direttamente
    printf("Nuovo valore di x (dopo *ptr = 15): %d\n\n", x);

    // 3. Passaggio per Riferimento (Scambio)
    printf("Prima dello swap: x = %d, y = %d\n", x, y);
    swap(&x, &y); // Passa gli indirizzi
    printf("Dopo lo swap:  x = %d, y = %d\n\n", x, y);

    // 4. Modifica tramite funzione con riferimento
    add_to_value(&x, 5); // Aggiungi 5 a x
    printf("Dopo aver aggiunto 5 a x: %d\n", x);

    return 0;
}
