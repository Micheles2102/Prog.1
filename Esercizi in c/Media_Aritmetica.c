/* Esercizio:
Codificare una funzione in C che prenda in input un parametro
formale matrice A di interi di dimensioni n × m di elementi distinti ed
una matrice B di double di dimensioni k × n, e restituisca un array di
n interi nel quale lo i-esimo elemento sia uguale alla media
aritmetica degli elementi presenti sia nella riga i-esima di A che
nella colonna i-esima di B. NB: per decidere se un elemento int
della matrice A `e uguale ad un elemento double della matrice B si
calcoli l’approssimazione all’intero pi`u vicino di quest’ultimo.

Note: 
Per arrotondare si utilizza la funzione round che è presente in math.h, ma poi bisogna castare ad int in quanto quest'ultimo ritorna un double:
esempio:
(int) round(0.60)--> avviene round(0.60)=1.00 --> che col cast (int)1.00 ritorna 1

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define n 3
#define m 4
#define k 2

int* media_aritmetica(int A[n][m],double B[k][n]){
    int somma_elementi;
    int elementi_trovati;
    int valore_castato=0;
    int* array=(int*)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++){
        elementi_trovati=0;
        somma_elementi=0;
        for(int j=0;j<m;j++){
            for(int t=0;t<k;t++){
                valore_castato=(int)round(B[t][i]);
                if(A[i][j] == valore_castato){  // qui controlliamo che l'elemento sia identico sia in A che in B dove l'elemento in B è stata castato a int
                    somma_elementi+=valore_castato;
                    elementi_trovati+=1;
                }
            }
        }
        if(elementi_trovati!=0){//preveniamo  il fatto che si effettui una divisione per 0
            array[i]=somma_elementi/elementi_trovati;
        }
        else{
            array[i]=0; // nel caso in cui non ci siano elementi comuni non posso lasciare un inizializzazione casuale dell'elemento nella posizione i-esima. Lo imposto manualmente a 0
        }
    }

    return array;
}



int main() {
   int A[n][m] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    double B[k][n] = {{1.1, 5.2, 9.3}, {2.9, 6.1, 10.8}};

    int* media_aritmetica_di_matrice = media_aritmetica(A, B);

    printf("Medie:\n");
    for (int i = 0; i < n; i++) {
        printf("Media[%d]: %d\n", i, media_aritmetica_di_matrice[i]);
    }

    free(media_aritmetica_di_matrice); // Libera la memoria allocata

    return 0;
}
