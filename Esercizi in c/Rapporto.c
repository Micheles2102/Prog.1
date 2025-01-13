/* Esercizio:
Codificare una funzione in C che prenda in input due parametri
formali: una matrice A di dimensioni n × m ed una matrice B di
dimensioni k × n entrambe di interi positivi. Il metodo restituisca
un array C di double di dimensione n nel quale lo i-esimo elemento
dello array C sia uguale al rapporto tra la somma degli elementi
della riga i-esima di A e il prodotto degli elementi della colonna
i-esima di B.

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define n 3
#define m 4
#define k 2

double* rapporto_tra_matrici(int **A,int **B){
    double* rapporto=(double*) malloc(sizeof(double)*n);
    int somma_righe;
    int prodotto_colonne;
    //calcolo somma degli elementi della riga
    for(int i=0;i<n;i++){
        somma_righe=0;
        prodotto_colonne=1;//importante metterlo a 1 non a 0 se no quando moltiplichiamo otterremo sempre 0. Questo porterò ad una divisione con 0 che fornirà solo infiniti
        for(int j=0;j<m;j++){
            somma_righe+=A[i][j];
        }
        for(int t=0;t<k;t++){
            prodotto_colonne*=B[t][i];
        }
        rapporto[i]=(double)somma_righe/prodotto_colonne;
    }
    return rapporto;
}



int main() {
    // Allocazione dinamica delle matrici A e B
    int** A = (int**)malloc(n * sizeof(int*));
    int** B = (int**)malloc(k * sizeof(int*));

    for (int i = 0; i < n; i++) {
        A[i] = (int*)malloc(m * sizeof(int));
        if (!A[i]) {
            perror("Errore nell'allocazione di memoria per A[i]"); //perror viene usato invece di printf per segnalare la presenza di un errore( BUONA NORMA USARLO NON NECESSARIO POSSIBILE USARE PRINTF)
            return 1;
        }
    }
    for (int i = 0; i < k; i++) {
        B[i] = (int*)malloc(n * sizeof(int));
        if (!B[i]) {
            perror("Errore nell'allocazione di memoria per B[i]");
            return 2;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = i+2;
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j] = j+2;
        }
    }

    // Chiamata alla funzione
    double* D = rapporto_tra_matrici(A, B);

    // Stampa dell'array D
    printf("Array D:\n");
    for (int i = 0; i < n; i++) {
        printf("D[%d] = %lf\n", i, D[i]);
    }

    // Liberare la memoria allocata dinamicamente
    for (int i = 0; i < n; i++) free(A[i]);//devo deallocare le colonne
    free(A);//deallcoo poi le righe
    for (int i = 0; i < k; i++) free(B[i]);
    free(B);
    free(D); 
    /* //Anche se D nel main è un puntatore che riceve l'indirizzo restituito dalla funzione calcola_rapporti, e non viene allocato direttamente con malloc nel main, 
     la memoria a cui punta è stata allocata dinamicamente all'interno di calcola_rapporti.

     Quindi,bisogna assolutamente fare free(D) nel main per evitare memory leak. 
     Ricordando che è compito del chiamante liberare la memoria quando non serve più.
     */

    return 0;
}
