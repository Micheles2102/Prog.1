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
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int* media_aritmetica(int n,int m,int k,int A[n][m],double B[k][n]){
    int variabile_appoggio=0;
    int somma=0;
    int parole_trovate=0;
    int* array=(int* ) malloc (sizeof(int)*n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int t=0;t<k;t++){
                variabile_appoggio=(int)round(B[t][i]);
                if(A[i][j]==variabile_appoggio){
                    parole_trovate++;
                    somma+=variabile_appoggio;
                    break;
                }
            }
        }
        array[i] = (parole_trovate > 0) ? somma / parole_trovate : 0;
        somma=0;
        parole_trovate=0;
    }
    return array;
}

int main(){
    int n=3;
    int m=4;
    int k=5;
    int A[n][m];
    double B[k][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j<m/2)
             A[i][j]=j+3;
            A[i][j]=j+1;
        }
        for(int t=0;t<k;t++){
            if(t>(k/2))
             B[t][i]=t+2.7;
            B[t][i]=t+1.3;
        }   
    }
    int *arr=media_aritmetica(n,m,k,A,B);
    for(int i=0;i<n;i++){
        printf(" I valori dell'array sono: %d\n",arr[i]);
    }
    free(arr);
    return 0;
}
