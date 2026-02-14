#include <stdio.h>

/**
 * Esempio 3: Array e Cicli
 * 
 * Questo esempio dimostra:
 * 1. Definire e inizializzare array.
 * 2. Passare array a funzioni (gli array decadono a puntatori).
 * 3. Iterare attraverso gli array usando i cicli.
 * 4. Modificare elementi dell'array dentro una funzione.
 */

// Funzione per stampare un array
// Nota: Gli array sono sempre passati per riferimento (come puntatore al primo elemento)
// 'size' è necessario perché il C non memorizza la lunghezza dell'array nell'array stesso
void print_array(const int arr[], int size) {
    printf("Contenuto Array: [ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

// Funzione per inizializzare un array con valori: 0, 2, 4, 6...
void initialize_even_numbers(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;
    }
}

// Funzione per sommare tutti gli elementi in un array
int sum_array(const int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

int main() {
    // 1. Inizializzazione Statica
    // La dimensione è determinata automaticamente (5 elementi)
    int explicit_array[] = {10, 20, 30, 40, 50}; 
    int explicit_size = 5;

    printf("Array inizializzato esplicitamente:\n");
    print_array(explicit_array, explicit_size); 

    // 2. Inizializzazione Dinamica (usando un ciclo)
    #define SIZE 10
    int computed_array[SIZE]; // Array non inizializzato di dimensione 10

    initialize_even_numbers(computed_array, SIZE);
    
    printf("\nArray calcolato (numeri pari):\n");
    print_array(computed_array, SIZE);

    // 3. Calcolo della Somma
    int total = sum_array(computed_array, SIZE);
    printf("\nSomma degli elementi nell'array calcolato: %d\n", total);

    return 0;
}
