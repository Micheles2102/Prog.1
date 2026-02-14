#include <stdio.h>

/**
 * Esempio 4: Matrici (Array 2D)
 * 
 * Questo esempio dimostra:
 * 1. Definire e inizializzare array 2D (matrici).
 * 2. Cicli annidati per attraversare righe/colonne.
 * 3. Passare array 2D a funzioni (Gestione delle dimensioni).
 */

#define ROWS 3
#define COLS 4

// Funzione per stampare una matrice con dimensioni FISSE
// Semplice, ma creare una funzione generica è più difficile senza VLA (Variable Length Arrays)
// o aritmetica dei puntatori.
void print_fixed_matrix(int matrix[ROWS][COLS]) {
    printf("Matrice Fissa (%dx%d):\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Funzione per inizializzare una matrice usando VLA (Variable Length Arrays - standard C99)
// Nota: 'cols' deve essere specificato *prima* di 'matrix' nella lista dei parametri!
void initialize_matrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (i + 1) * (j + 1); // Esempio formula: riga * colonna (base 1)
        }
    }
}

// Funzione per stampare una matrice con dimensioni VARIABILI
void print_vla_matrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Matrice VLA (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main() {
    // 1. Inizializzazione Matrice Fissa
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    print_fixed_matrix(matrix);


    // 2. Inizializzazione Matrice Dimensione Variabile
    int dynamic_rows = 4;
    int dynamic_cols = 5;
    
    // Allocazione stack VLA (attenzione con dimensioni molto grandi sullo stack!)
    int big_matrix[dynamic_rows][dynamic_cols]; 

    initialize_matrix(dynamic_rows, dynamic_cols, big_matrix);
    print_vla_matrix(dynamic_rows, dynamic_cols, big_matrix);

    return 0;
}
