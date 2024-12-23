/* Esercizio:
Codificare una funzione in C che prenda in input tre parametri
formali: una matrice di stringhe S di dimensioni n × m, un array di
caratteri C che contiene per ipotesi elementi distinti, ed un float
w. Il metodo restituisca true se esiste almeno una riga o una
colonna della matrice tale che la percentuale di caratteri di C
presenti in essa `e maggiore di w

Note: percentuale --> contiamo quanti elementi ci sono nella stringa quanti sono quelle presenti in c: se la stringhe in tutta la riga ad esempio ha 6 elementi e 3 sono quelli presenti in c avremo 3*100=300/6=50%
Esempio: 
prima riga del main:                          array C: 

"hello", "world", "abc", "def"                 aeiou

caratteri uguali :
hello=2    --> 5 caratteri
world=1    --> 5 caratteri
abc=2      --> 3 caraatteri
def=1      --> 3 caraatteri
quindi: 2+1+2+1= 6 ---> numero totale 16 caratteri totali nella riga
Percentuale--> 6*100=600/16 = 37.5%

se w=40.0 allora ci restituisce false la funzione.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define n 3
#define m 4

bool percentuale(char* S[n][m],char* C,float w){
    char* parola; //mi serve solo per rendere il codice più leggibile
    int lungezza_array_c=strlen(C); //posso usare questa funzione anche se C è un array di caratteri
    int lunghezza_parola;// per riuscire a trovarmi quanto è lungha una stringa della matrice
    int parole_trovate;//numero di caratteri chestanno sia nella stringa che in C
    int lunghezza_parole_righe; // mi serve perchè devo trovare quanti caratteri in intere righe(stessa cosa per lunghezza_parole_colonne)
    int lunghezza_parole_colonne;
    //Calcolo per le righe
    for(int i=0;i<n;i++){
        lunghezza_parole_righe=0;// inizializzo qui perchè ogni volta che la riga si aggiorna c'è bisogno di rimettere a 0
        parole_trovate=0;
        for(int j=0;j<m;j++){           
            if(S[i][j]){ // Controlliamo che la cella non sia NULL
                parola=S[i][j];
                lunghezza_parola=strlen(parola);
                lunghezza_parole_righe+=lunghezza_parola;// Aggiungiamo la lunghezza alla somma totale per la riga (per ogni stringa nella riga devo fare questa cosa)
                for(int k=0;k<lungezza_array_c;k++){
                    for(int t=0;t<lunghezza_parola;t++){
                        if(parola[t]==C[k]){
                            parole_trovate+=1;
                        }
                    }
                }
            }
        }
        parole_trovate*=100;
        if(((float)(parole_trovate/lunghezza_parole_righe)>w) && lunghezza_parole_righe!=0 ){ //aggiungo un controllo in più per evitare che divido per 0
            return true;
        }
    }
    //calcolo per le colonne (effettuiamo la stessa cosa fatta per le righe)
    for(int j=0;j<m;j++){
        parole_trovate=0;
        lunghezza_parole_colonne=0;
        for(int i=0;i<n;i++){
            if(S[i][j]){
                parola=S[i][j];
                lunghezza_parola=strlen(parola);
                lunghezza_parole_colonne+=lunghezza_parola;
                for(int k=0;k<lungezza_array_c;k++){
                    for(int t=0;t<lunghezza_parola;t++){
                        if(parola[t]==C[k]){
                            parole_trovate+=1;
                        }
                    }
                }
            }
        }
        parole_trovate*=100;
        if(((float)(parole_trovate/lunghezza_parole_colonne)>w) && lunghezza_parole_colonne!=0 ){ //aggiungo un controllo in più per evitare che divido per 0
            return true;
        }
    }
    

    return false;
}


int main() {
    // Esempio di matrice
    char* matrice[n][m] = {
        {"hello", "world", "abc", "def"},
        {"ghi", "jkl", "mno", "pqr"},
        {"stu", "vwxyz", NULL, NULL}
    };

    char caratteri[] = "aeiou";
    float soglia = 40.0;

    if (percentuale(matrice, caratteri, soglia)) {
        printf("Esiste almeno una riga o colonna con una percentuale maggiore di %.2f%%.\n", soglia);
    } else {
        printf("Non esiste alcuna riga o colonna con una percentuale maggiore di %.2f%%.\n", soglia);
    }

    return 0;
}
