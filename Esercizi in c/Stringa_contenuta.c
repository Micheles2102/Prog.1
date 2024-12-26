/* Esercizio:
Codificare una funzione in C che prenda in input un parametro
formale A matrice di stringhe di dimensione n × m, ed una stringa
s. Il metodo restituisca true se esistono almeno due stringhe in A
che contengono la stringa s e che abbiano differenti indici di riga e
di colonna.

Note:
Per risolvere in maniera veloce il problema basta che ci si ricorda della funzione strstr()
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define n 3
#define m 4

bool stringa_contenuta(char* A[n][m],char* s){
    int stringhe_trovate=0;
    int riga,colonna=-1;//devo inizializzarli a -1 per evitare problemi dentro all'if
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((strstr(A[i][j],s)!= NULL )){ // se ritorna 1 ha trovato una sottostringa : strstr( stringa dove cercare,stringa da cercare)
                stringhe_trovate++;
                riga=i;
                colonna=j;
                break;
            }
        }
    }
    return stringhe_trovate>=2;
}


int main() {
    char *matrice1[n][m] = {
        {"ciao mondo", "test", "esempio", "prova"},
        {"mondo", "ciao", "test", "esempio"},
        {"prova", "esempio mondo", "ciao", "test"}
    };

    char *matrice2[n][m] = {
        {"ciao", "test", "esempio", "prova"},
        {"mondo", "ciao", "test", "esempio"},
        {"prova", "ciao", "ciao", "test"}
    };
    char *matrice3[n][m] = {
        {"ciao", "test", "esempio", "prova"},
        {"mondo", "test", "test", "esempio"},
        {"prova", "test", "test", "mondo"}
    };

    char *stringa_da_cercare = "mondo";

    if ( stringa_contenuta(matrice1, stringa_da_cercare)) {
        printf("Matrice 1: Trovate almeno due stringhe diverse con \"%s\"\n", stringa_da_cercare);
    } else {
        printf("Matrice 1: Non trovate almeno due stringhe diverse con \"%s\"\n", stringa_da_cercare);
    }
        if ( stringa_contenuta(matrice2, stringa_da_cercare)) {
        printf("Matrice 2: Trovate almeno due stringhe diverse con \"%s\"\n", stringa_da_cercare);
    } else {
        printf("Matrice 2: Non trovate almeno due stringhe diverse con \"%s\"\n", stringa_da_cercare);
    }
        if ( stringa_contenuta(matrice3, stringa_da_cercare)) {
        printf("Matrice 3: Trovate almeno due stringhe diverse con \"%s\"\n", stringa_da_cercare);
    } else {
        printf("Matrice 3: Non trovate almeno due stringhe diverse con \"%s\"\n", stringa_da_cercare);
    }

    return 0;
}
