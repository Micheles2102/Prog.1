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

bool stringa_contenuta(char* A[n][m], char* s) {
    for (int i1 = 0; i1 < n; i1++) {
        for (int j1 = 0; j1 < m; j1++) {
            if (strstr(A[i1][j1], s) != NULL) { // Prima stringa trovata. se ritorna 1 ha trovato una sottostringa : strstr( stringa dove cercare,stringa da cercare)
                for (int i2 = 0; i2 < n; i2++) {
                    for (int j2 = 0; j2 < m; j2++) {
                        if ((i1 != i2 || j1 != j2) && strstr(A[i2][j2], s) != NULL) {// se ritorna 1 ha trovato una sottostringa : strstr( stringa dove cercare,stringa da cercare)
                            // Seconda stringa trovata in posizione diversa
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false; 
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
