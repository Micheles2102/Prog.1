/* Esercizio:
Codificare una funzione C che prenda in input un parametro
formale matrice M di dimensioni n × m di stringhe (puntatori a
caratteri), e che restituisca il valore true (1) se esiste almeno una
colonna in M che abbia un egual numero di stringhe palindrome di
una delle righe di M.

Termini: Palindroma -> una parola che può essere letta da destra verso sinistra e viceversa senza cambiare; nel main trovate degli esempi
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define n 3
#define m 4

// Funzione principale per verificare la condizione richiesta
bool palindrome(char* M[n][m]) {
    int count_row[n] = {0}; // Contatore per capire quante stringhe palindrome ci sono in una riga: count_row[n]={4,2,3}  ad esempio, quindi che nella prima riga ci sono 4 stringhe palindrome, nella seconda 2 e nella 3 tre
    int count_col[m] = {0}; // Contatori per colonne che fa la stessa cosa di count_row ma per le colonne
    bool palindroma=0;
    // Conta le stringhe palindrome in righe e colonne
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (M[i][j] ) {
                char* parola=M[i][j];
                int len = strlen(parola);
                for (int i = 0; i < len / 2; i++) {
                    if (parola[i] == parola[len - i - 1]) {
                        palindroma=1;
                    }
                    else{
                        palindroma=0;
                        break; //---> questo break è importantissimo se no il codice non funzionerebbe correttamente in quanto basterebbe che l'ultimo confronto sia uguale per rendere la parola palindroma( ovviamente sbagliato)
                    }
                }
                
                if(palindroma){
                 count_row[i]++;
                 count_col[j]++;
                }
            }
        }
    }

    // Confronta i contatori di righe con quelli di colonne
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (count_row[i] == count_col[j]) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    // Esempio di matrice
    char* matrice[n][m] = {
        {"anna", "casa", "non", "cane"},
        {"otto", "gatto", "oro", NULL},
        {"pippo", "radar", NULL, NULL}
    };

    if (palindrome(matrice)) {
        printf("Esiste una colonna con lo stesso numero di stringhe palindrome di una riga.\n");
    } else {
        printf("Non esiste alcuna corrispondenza tra righe e colonne per le stringhe palindrome.\n");
    }

    return 0;
}
