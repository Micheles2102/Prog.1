#include <stdio.h>
#include "prototipi.h"

int main(int argc, char* argv[]) {
    int x = 3;
    int y = 5;

    int s = somma_numerica(x, y);
    printf("Somma (passaggio per valore): %d + %d = %d\n", x, y, s);

    aggiungi_con_reference(&x, y);
    printf("Il valore aggiornato di x (passaggio per indirizzo): %d\n", x);

    int risultato = aggiungi_senza_reference(x, y);
    printf("Risultato con passaggio per valore: %d\n", risultato);
    printf("Il valore di x rimane invariato (passaggio per valore): %d\n", x);

    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    stampa_array(array, 10);

    int *v[COLONNE];
    costruisci_array(v, COLONNE);

    int matrice[5][5];
    printf("Inizializzazione di una matrice 5x5:\n");
    costruisci_matrice(5, matrice);

    int matrice2[RIGHE][COLONNE];
    printf("\nInizializzazione di una matrice con dimensioni %dx%d definite da dimensioni:\n", RIGHE, COLONNE);
    costruisci_matrice_dimensioni_variabili1(matrice2, RIGHE, COLONNE);

    printf("\nProgramma terminato.\n");

    return 0;
}
