#include <stdio.h>

/**
 * Esempio 1: Funzioni Base e Passaggio per Valore
 * 
 * Questo esempio dimostra:
 * 1. Definire una funzione semplice che restituisce un valore.
 * 2. Chiamare una funzione dal main.
 * 3. Capire che modificare una variabile dentro una funzione (passata per valore)
 *    NON modifica la variabile originale nel main.
 */

// Funzione per calcolare la somma di due interi
// 'a' e 'b' sono parametri di input (copie dei valori passati)
int sum(int a, int b) {
    return a + b;
}

// Funzione che tenta di modificare un valore
// 'x' è una copia della variabile passata dal main
void try_to_modify(int x) {
    x = x + 10;
    printf("Dentro try_to_modify: x = %d\n", x);
}

int main() {
    int num1 = 5;
    int num2 = 10;

    // 1. Chiamata di funzione base
    int result = sum(num1, num2);
    printf("Somma di %d e %d è: %d\n\n", num1, num2, result);


    // 2. Dimostrazione del passaggio per valore
    int value = 20;
    printf("Prima di try_to_modify: value = %d\n", value);
    
    try_to_modify(value); // Passiamo 'value' (20) alla funzione
    
    printf("Dopo try_to_modify:  value = %d\n", value);
    printf("(Nota che 'value' non è cambiato perché abbiamo modificato solo una copia)\n");

    return 0;
}
