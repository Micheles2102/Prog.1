#include <stdio.h>
#include "prototipi.h"

int somma(int a, int b) {
    return a + b;
}

int prodotto(int a, int b) {
    return a * b;
}

float area_quadrato(float lato) {
    return lato * lato;
}

float area_triangolo(float base, float altezza) {
    return (base * altezza) / 2;
}

int somma_numerica(int a, int b) {
    return a + b;
}

int somma_numerica_reference(int* a, int* b) {
    return *a + *b;
}

void aggiungi_con_reference(int* x, int y) {
    *x += y;
}

int aggiungi_senza_reference(int x, int y) {
    x += y;
    return x;
}

void stampa_array(int* v, int t) {
    for (int i = 0; i < t; i++) {
        printf("Il valore in posizione %d di v è: %d\n", i, v[i]);
    }
}

void costruisci_array(int** v, int N) {
    printf("Funzione costruisci_array: array di puntatori a int\n");
    for (int i = 0; i < N; i++) {
        v[i] = NULL;
        printf("Il valore in posizione %d di v e': %p\n\n", i, (void*)v[i]);
    }
}

void costruisci_matrice(int N, int (*v)[N]) {
    printf("Funzione costruisci_matrice: matrice di interi %d %d\n", N, N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            v[i][j] = i * N + j;
            printf("v[%d][%d]= %d\n\n", i, j, v[i][j]);
        }
    }
}

void costruisci_matrice_dimensioni_variabili1(int v[][COLONNE], int N, int M) {
    printf("Funzione costruisci_matrice_dimensioni_variabili1\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            v[i][j] = i + j;
            printf("v[%d][%d] = %d\n", i, j, v[i][j]);
        }
    }
}
