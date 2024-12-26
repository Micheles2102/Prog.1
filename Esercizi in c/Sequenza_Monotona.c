/* Esercizio:
Codificare una funzione in C che prenda in input un parametro
formale matrice A di interi di dimensioni n × m, uno short k ed uno
short w, e restituisca il valore booleano true (1) se la matrice
contiene almeno w colonne che contengono almeno una sequenza
di interi monotona crescente di lunghezza maggiore o uguale a k.

Note:
Una sequenza di interi monotona crescente è una sequenza ordinata
di numeri interi in cui ogni elemento è maggiore o uguale al precedente
Monotona Crescente:1,2,3,4,4,5,5,5,5,6,7,8....

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define n 3
#define m 4

bool sequenza_monotona(int A[n][m],short w, short k){
    int monotona=0;//conta quante colonne sono monotone
    int lunghezza;

    for(int j=0;j<m;j++){
        lunghezza=1;//nella sequenza ci sarà sempre un elemento da cui iniziamo
        for(int i=1;i<n;i++){ //ATTENZIONE faccio partire da i=1 pochè il primo elemento non necessita di confronto 
            if(A[i][j] && A[i][j]>=A[i-1][j]){ // in questa maniera facendo A[i][j]>=A[i-1][j] stiamo sempre controllando se il valore precedente è minore di uno rispetto a quello attuale( avendo posto i=1 non corrismo rischi se mai i fosse stato 0)
             lunghezza++;
            } 
            else{
                lunghezza=1;//iniziamo una nuova sequenza 
            }
            if(lunghezza>=k){
                monotona++;
                break; //necessario per non incrementare monotona di false colonne;
            }
        }
    }

    return monotona>=w; //Se questa condizione è vera ritornerà 1 se no 0
}


int main() {
    int matrice1[n][m] = {
        {1, 2, 1, 4},
        {2, 3, 5, 5},
        {3, 4, 6, 6}
    };

    int matrice2[n][m] = {
        {1, 5, 1, 3},
        {8, 3, 9, 8},
        {3, 1, 3, 6}
    };
     int matrice3[n][m] = {
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4}
    };

    printf("Matrice 1 (w=2, k=2): %d\n", sequenza_monotona(matrice1, 2, 2)); // Dovrebbe stampare 1 (true)
    printf("Matrice 2 (w=2, k=3): %d\n", sequenza_monotona(matrice2, 2, 3)); // Dovrebbe stampare 0 (false)
    printf("Matrice 3 (w=2, k=3): %d\n", sequenza_monotona(matrice3, 2, 3)); // Dovrebbe stampare 1 (true)

    return 0;
}
