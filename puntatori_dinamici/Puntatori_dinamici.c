#include <stdio.h>
#include <stdlib.h>

/*
 * ESEMPIO PUNTATORI DINAMICI
 *
 * Per vedere il comportamento di malloc e cosa avviene "sotto il cofano" 
 * nella gestione della memoria, visita questa repository:
 * https://github.com/Micheles2102/c-journey/tree/main/manual-malloc
 */

int main() {
    printf("--- 1. PUNTATORE SINGOLO DINAMICO ---\n");

    int *p = (int*)malloc(sizeof(int));
    if (p == NULL) {
        fprintf(stderr, "Errore di allocazione memoria per p\n");
        return 1;
    }

    *p = 10;
    printf("Valore puntato da p: %d\n", *p);
    printf("Indirizzo di memoria allocato: %p\n", (void*)p);

    free(p);
    p = NULL;
    printf("Memoria di p liberata.\n\n");


    printf("--- 2. ARRAY DINAMICO ---\n");
    int n = 5;

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Errore di allocazione memoria per arr\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = (i + 1) * 10;
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);
    arr = NULL;
    printf("Memoria dell'array liberata.\n\n");


    printf("--- 3. MATRICE DINAMICA (ARRAY DI PUNTATORI) ---\n");
    int rows = 3;
    int cols = 4;

    // Alloco memoria per le righe (array di puntatori)
    int **matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        fprintf(stderr, "Errore di allocazione memoria per le righe della matrice\n");
        return 1;
    }

    // Alloco ogni riga
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Errore di allocazione memoria per la riga %d\n", i);
            return 1; 
        }
    }

    printf("Contenuto della matrice %dx%d:\n", rows, cols);
    int count = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = count++;
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Libero la matrice
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    matrix = NULL;

    printf("Memoria della matrice liberata.\n");

    return 0;
}
