#ifndef PROTOTIPI_H
#define PROTOTIPI_H

// Costanti
#define RIGHE 3
#define COLONNE 4

// Funzioni matematiche base
int somma(int a, int b);
int prodotto(int a, int b);
float area_quadrato(float lato);
float area_triangolo(float base, float altezza);

// Funzioni su interi e puntatori
int somma_numerica(int a, int b);
int somma_numerica_reference(int* a, int* b);
void aggiungi_con_reference(int* x, int y);
int aggiungi_senza_reference(int x, int y);

// Funzioni su array e matrici
void stampa_array(int* v, int t);
void costruisci_array(int** v, int N);
void costruisci_matrice(int N, int (*v)[N]);
void costruisci_matrice_dimensioni_variabili1(int v[][COLONNE], int N, int M);

#endif // PROTOTIPI_H


/*
   Per utilizzare questi prototipi:
   - Includi questo file nei tuoi sorgenti con #include "prototipi.h"
   - Compila insieme ai file con le definizioni delle funzioni
*/
