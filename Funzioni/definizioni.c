// Questo file contiene la definizione delle funzioni dichiarate nel file prototipi.h

#include "prototipi.h"

// Definizione della funzione somma
int somma(int a, int b) {
    return a + b;
}

// Definizione della funzione prodotto
int prodotto(int a, int b) {
    return a * b;
}

// Definizione della funzione per calcolare l'area di un quadrato
float area_quadrato(float lato) {
    return lato * lato;
}

// Definizione della funzione per calcolare l'area di un triangolo
float area_triangolo(float base, float altezza) {
    return (base * altezza) / 2;
}
