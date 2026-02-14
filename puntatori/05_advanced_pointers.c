#include <stdio.h>

/**
 * Esempio 5: Puntatori Avanzati
 * 
 * Questo esempio dimostra:
 * 1. Doppi Puntatori (puntatore a puntatore).
 * 2. Correttezza di Const con i puntatori.
 * 3. Array di Puntatori.
 */

void modify_pointer(int **ptr_to_ptr, int *new_target) {
    // Stiamo cambiando dove punta il puntatore originale!
    *ptr_to_ptr = new_target;
}

int main() {
    int x = 10;
    int y = 20;

    // 1. Logica Puntatori Const
    printf("--- Puntatori Const ---\n");

    // Caso A: Puntatore a Valore Costante
    // Non puoi cambiare il valore (*p), ma puoi cambiare dove punta p.
    const int *ptr_to_const = &x; 
    // *ptr_to_const = 15; // ERRORE: assegnazione a locazione di sola lettura
    ptr_to_const = &y;     // OK: cambio l'indirizzo memorizzato nel puntatore
    printf("ptr_to_const punta al val: %d\n", *ptr_to_const);

    // Caso B: Puntatore Costante
    // Puoi cambiare il valore (*p), ma non dove punta p.
    int * const const_ptr = &x;
    *const_ptr = 15;      // OK: cambio il valore
    // const_ptr = &y;    // ERRORE: assegnazione a variabile di sola lettura 'const_ptr'
    printf("const_ptr punta al val: %d\n", *const_ptr);

    // Caso C: Puntatore Costante a Valore Costante
    // Non puoi cambiare NULLA.
    const int * const strict_ptr = &x;
    // *strict_ptr = 20;  // ERRORE
    // strict_ptr = &y;   // ERRORE


    // 2. Doppi Puntatori (Modifica diretta di un puntatore)
    printf("\n--- Doppi Puntatori ---\n");
    
    int *my_ptr = &x;
    printf("my_ptr originariamente punta a x (val: %d)\n", *my_ptr);

    modify_pointer(&my_ptr, &y); // Passa l'indirizzo del puntatore!
    
    printf("my_ptr ora punta a y (val: %d)\n", *my_ptr);


    // 3. Array di Puntatori
    // Utile per stringhe (char*) o array frastagliati (jagged arrays)
    printf("\n--- Array di Puntatori ---\n");
    
    int *arr_ptrs[3]; // Array di 3 puntatori a int
    arr_ptrs[0] = &x;
    arr_ptrs[1] = &y;
    arr_ptrs[2] = NULL; // Buona pratica usare NULL per slot vuoti

    for(int i = 0; i < 3; i++) {
        if(arr_ptrs[i] != NULL) {
            printf("arr_ptrs[%d] punta al valore: %d\n", i, *arr_ptrs[i]);
        } else {
            printf("arr_ptrs[%d] e' NULL\n", i);
        }
    }

    return 0;
}
