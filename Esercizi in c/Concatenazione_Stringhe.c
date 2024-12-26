/* Esercizio:
Codificare una funzione in C che prenda in input due parametri
formali: una matrice A di stringhe (puntatori a caratteri) ed una
matrice B di short, entrambe di dimensioni n × m. Il metodo
restituisca un array di n stringhe nel quale il generico elemento di
indice i sar`a uguale alla concatenazione delle sole stringhe della
riga i-esima di A che hanno lunghezza pari o maggiore del
corrispondente numero in B (cio`e bisogna confrontare la lunghezza
della stringa aij con il numero bij .

Note: Per potere svolgere questo esercizio ho utilizzato due funzioni della libreria string.h:
strlen(stringa) -->ritorna quanto è lunga la stringa
strcat( stringa_dove_concatenare , stringa_da_concatenare)---> per concatenare le stringhe senza problemi
Importantissimo è da considerare che se:
in strcat la stringa_dove_concatenare deve essere abbastanza grande da potere contenere la concatenazione.
PS: IN QUESTO CODICE NON HO AGGIUNTO CONTROLLI, RICORDATE DI INSERIRLI SEMPRE( non li ho inseriti solamente perchè ho creato io personalmente il main)
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 3
#define m 4

char** concatenazione_stringhe(char* A[n][m], short B[n][m]) {
    char** array = malloc(sizeof(char*) * n);

    for (int i = 0; i < n; i++) {
        //per riuscire ad allocare con successo dobbiamo prima capire qual'è la massima dimensione che possiamo trovare come concatenazione di stringhe per quella colonna(Senza questa parte di codice,strcat potrebbe poratre a problemi)
        int lunghezza_massima= 0;
        for (int j = 0; j < m; j++) {
            if (strlen(A[i][j]) >= B[i][j]) {
                lunghezza_massima += strlen(A[i][j]);
            }
        }

        // finiamo di allocare (ricordando che stiamo allocando un array di puntatori a caratteri)
        array[i] = malloc(lunghezza_massima + 1); //Importante ricordarsi di aggiungere +1 per il carattere nullo.
        array[i][0] = '\0'; 

        for (int j = 0; j < m; j++) {
            if (strlen(A[i][j]) >= B[i][j]) {
                strcat(array[i], A[i][j]);
            }
        }
    }

    return array;
}

int main() {
     char* A[n][m] = {
        {"ciao", "cane", "abc", "test"},  //non deve essere concatenata cane
        {"stringa", "lunga", "gatto", "ok"},//non deve essere concatenato gatto
        {"hello", "no", "prova", "fine"}//non deve essere concatenato no
    };

    short B[n][m] = {
        {2, 5, 3, 4},
        {7, 4, 6, 1},
        {5, 3, 2, 3}
    };

    char** risultato = concatenazione_stringhe(A, B);

    printf("Risultato:\n");
    for (int i = 0; i < n; i++) {
        printf("Riga %d: %s\n", i, risultato[i]);
    }

    // Libero la memoria allocata (RICORDARSI DI FARLO)
    for (int i = 0; i < n; i++) {
        free(risultato[i]);
    }
    free(risultato);

    return 0;
}

