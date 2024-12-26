/* Esercizio:
Codificare una funzione in C che prenda in input una matrice di
stringhe S (puntatori a caratteri) di dimensione n × m e due array
di caratteri C e D di dimensione n e restituisca un array di short
nel quale il generico elemento di posto i contiene il numero di
stringhe che iniziano con il carattere di C di indice i e finiscono con
il carattere in D di indice i.

Note: ATTENZIONE NON SONO STATI EFFETTUATI CONTROLLI  in quanto ho scritto io il main. Nel caso generico(come all'esame) dovete aggiungere degli if di controllo
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 3
#define m 4

short* inizio_fine_stringa(char* S[n][m], char C[n],char D[n]) {
    short* array=(short*)malloc(sizeof(short)*n);
    char* parola;

    for(int i=0;i<n;i++){
        array[i]=0;
        for(int j=0;j<m;j++){
            parola=S[i][j];
            if(parola[0]==C[i] && parola[strlen(parola)-1]==D[i]){
                array[i]+=1;
            }
        }
    }
    return array;
}

int main() {
    char* S[n][m] = {
        {"casa", "albero", "chitarra","ok"}, 
        {"camera", "topo", "uccello","prova"}, 
        {"sole", "luna", "salame","mouse"}
    };
    char C[n] = {'c', 't', 's'};
    char D[n] = {'a', 'o', 'a'};

    short* risultato = inizio_fine_stringa(S, C, D);

    for (int i = 0; i < n; i++) {
        printf("Riga %d: %d stringhe\n", i, risultato[i]);
    }

    free(risultato);
    return 0;
}

