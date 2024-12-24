/* Esercizio:
Codificare una funzione in C che prenda in input un parametro
formale matrice S di puntatori a carattere di dimensione n × m (S
quindi contiene stringhe), uno short w ed uno short k, e restituisca
il valore booleano true (1) se in S sono presenti almeno una riga
ed almeno una colonna che presentano ciascuna almeno w stringhe
di lunghezza minore di k

Note: Prestare attenzione al fatto che deve essere contenuto sia nelle colonne che nelle righe . Basta una sola volta.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define n 3
#define m 4

bool stringhe_minori(char* S[n][m],short w, short k){
    int lunghezza_parola=0;
    int stringhe_trovate;
    bool trovate=0;

    //controllo sulle righe
    for(int i=0;i<n;i++){
        stringhe_trovate=0;
        for(int j=0;j<m;j++){
            if(S[i][j]){
                lunghezza_parola=strlen(S[i][j]);
                if((lunghezza_parola)<k){
                    stringhe_trovate+=1;
                }
                
            }
        }
        if(stringhe_trovate>=w){
            trovate=1;
            break;
        }
    }
    //controllo sulle colonne
    if(trovate){// se non trova una riga che soddisfi le condizioni non c'è bisogno che entri in questi for
        trovate=0;//importante resettarlo una volta entrato.(essendo entrato abbiamo garantito che nelle righe ci sia, ma se non viene trovato nelle colonne deve restituire 0. Se non resettiamo ritornerà sempre 1.
        for(int j=0;j<m;j++){
            stringhe_trovate=0;
            for(int i=0;i<n;i++){
                if(S[i][j]){
                    lunghezza_parola=strlen(S[i][j]);
                    if((lunghezza_parola)<k){
                        stringhe_trovate+=1;
                    }
                }
            }
            if(stringhe_trovate>=w){
                trovate=1;
                break;
            }
        }
    }
    return trovate;
}




int main() {
    char* S[n][m] = {
        {"ciao", "a", "tutti", "oggi"},
        {"sono", "qui", "per", "voi"},
        {"e", "voi", "con", "me"}
    };

    printf("Test con w=2 e k=4: %d\n", stringhe_minori(S, 2, 4)); // Dovrebbe stampare 1 (true)

    char* S2[n][m] = {
        {"ciao", "a", "tutti", "oggi"},
        {"sono", "qui", "per", "voi"},
        {"lunghissima", "stringa", "con", "me"}
    };

    printf("Test con w=2 e k=4 (nessuna colonna): %d\n", stringhe_minori(S2, 2, 4)); // Dovrebbe stampare 1 (true)
      char* S3[n][m] = {
        {"ciao", "abcd", "tutti", "oggi"},
        {"sono", "quis", "personaggio", "voi"},
        {"etanolo", "a", "constantino", "merenda"}
    };

    printf("Test con w=2 e k=4 (nessuna riga): %d\n", stringhe_minori(S3, 3, 4)); // Dovrebbe stampare 0 (false)

    return 0;
}
