/* Esercizio:
Codificare una funzione in C che prenda un parametro formale
matrice A di double di dimensioni n × k ed un array B di interi di
dimensione n, e restituisca l’indice della colonna in A che contiene
il maggior numero di elementi tali che l’approssimazione
dell’elemento stesso al numero intero pi`u vicino sia uguale al
corrispondente elemento intero in B (NB: in pratica il generico
elemento di indice (i,j) va confrontato con l’elemento in B di indice
i)

Note:
Per risolvere questo esercizio applicheremo la funzione round() castando ad int.(Ricordo che per usarla bisogna definire la libreria math.h)
NON SONO STATI SVOLTI CONTROLLI. Ho scritto io il main quindi non ho inserito controlli. In sede di esame assicuratevi di inserire controlli
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define n 3
#define k 2

int trova_colonna_maggiore(double A[n][k], int B[n]) {
   int colonna_maggiore_numero=-1;
   int numero_elementi_attuali;
   int numero_elementi_precedenti=0;
   int numero_castato;
   for(int j=0;j<k;j++){
      int numero_elementi_attuali=0;
        for(int i=0;i<n;i++){
          numero_castato=(int)round(A[i][j]);
            if(numero_castato==B[i]){
              numero_elementi_attuali++;
            }
        }
        if(numero_elementi_attuali>numero_elementi_precedenti){
            colonna_maggiore_numero=j;
            numero_elementi_precedenti=numero_elementi_attuali;
        }
    }
    return colonna_maggiore_numero;
}

int main() {
    double A[n][k] = {
        {1.2, 2.8}, 
        {3.5, 2.3}, 
        {4.9, 5.6}
    };
    int B[n] = {1, 2, 5};

    int colonna_max = trova_colonna_maggiore(A, B);
    if (colonna_max != -1) {
        printf("La colonna con il maggior numero di corrispondenze e': %d\n", colonna_max);
    } else {
        printf("Errore: indice fuori dai limiti\n");
    }

    return 0;
}
