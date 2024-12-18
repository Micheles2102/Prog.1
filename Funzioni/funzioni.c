#include <stdio.h>
// Definizione delle dimensioni di array e matrici
#define n 3
#define m 4 

// Funzione che restituisce la somma di due numeri passati per valore
int somma_numerica(int a, int b) { // a e b sono parametri formali
    return a + b;
}

// Funzione che restituisce la somma di due numeri passati per indirizzo (reference)
int somma_numerica_reference(int* a, int* b) { // a e b sono puntatori a interi
    return *a + *b; // Dereferenziazione per accedere ai valori puntati
}

// Funzione che modifica il valore di x tramite il passaggio per indirizzo
void aggiungi_con_reference(int* x, int y) {
    *x += y; // Aggiorna il valore di x con l'aggiunta di y
}

// Funzione che prova a modificare il valore di x senza successo (passaggio per valore)
int aggiungi_senza_reference(int x, int y) {
    x += y; // Modifica solo una copia locale di x
    return x; // Restituisce la somma senza alterare il valore originale
}

// Funzione per stampare un array monodimensionale
void stampa_array(int* v, int n) { // Posso dichiarare v anche come int v[]
    for (int i = 0; i < n; i++) {
        printf("Il valore in posizione %d di v è: %d\n", i, v[i]); // Accesso all'array tramite indicizzazione
    }
}

 

// Funzione per costruire un array di puntatori a interi
void costruisci_array(int *v[m], int N) {
    printf("Funzione costruisci_array: array di puntatori a int\n");
    for (int i = 0; i < N; i++) {
        v[i] = NULL; // Inizializza i puntatori a NULL
    }
}

// Funzione per costruire una matrice (array bidimensionale)
void costruisci_matrice(int (*v)[m], int N) {
    printf("Funzione costruisci_matrice: matrice di interi %dx%d\n", N, m);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < m; j++) {
            v[i][j] = i * m + j; // Inizializza ogni elemento della matrice con un valore unico
            printf("v[%d][%d] = %d\n", i, j, v[i][j]);
        }
    }
}

// Funzione per costruire una matrice con dimensioni variabili (seconda dimensione nota)
void costruisci_matrice_dimensioni_variabili1(int v[][m], int N, int M) {
    printf("Funzione costruisci_matrice_dimensioni_variabili1\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            v[i][j] = i + j; // Somma degli indici
            printf("v[%d][%d] = %d\n", i, j, v[i][j]);
        }
    }
}

// Funzione che genera errore: matrice senza specificare dimensioni
// void costruisci_matrice_dimensioni_variabili3(int v[][], int N, int M);

int main(int argc, char* argv[]) {
    // Dichiarazione variabili
    int x = 3;
    int y = 5;

    // Esempio di funzione con parametri formali e attuali
    int somma = somma_numerica(x, y); // x e y sono parametri attuali
    printf("Somma (passaggio per valore): %d + %d = %d\n", x, y, somma);

    // Passaggio per indirizzo e per valore
    aggiungi_con_reference(&x, y); // Modifica x tramite indirizzo
    printf("Il valore aggiornato di x (passaggio per indirizzo): %d\n", x);

    int risultato = aggiungi_senza_reference(x, y); // Non modifica x
    printf("Risultato con passaggio per valore: %d\n", risultato);
    printf("Il valore di x rimane invariato (passaggio per valore): %d\n", x);

    // Passaggio di un array a una funzione
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Inizializzazione
    stampa_array(array, 10); // Stampa l'array

    // Esempio con matrici
    int matrice[5][5];
    printf("\nInizializzazione di una matrice 5x5:\n");
    costruisci_matrice(matrice, 5); // Inizializza e stampa la matrice

    // Matrice con dimensioni definite
    int matrice2[n][m];
    printf("\nInizializzazione di una matrice con dimensioni %dx%d definite da dimensioni:\n", n, m);
    costruisci_matrice_dimensioni_variabili1(matrice2, n, m); // Funzione con dimensioni variabili

    // Conclusione
    printf("\nProgramma terminato.\n");

    return 0;
}

