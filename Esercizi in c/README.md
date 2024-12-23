
# README: Esercizi in C - 

Questo repository contiene  esercizi di programmazione in C che lavorano con matrici di stringhe,funzioni,puntatori,allocazioni. Di seguito vengono descritti gli esercizi e l'idea dietro ciascuno.

## ATTENZIONE: prima di vedere come sono stati svolti gli esercizi, provate a farli da voi o per lo meno di sviluppare una logica dietro l'esercizio. Comprendete il codice ma soprattutto la logia che c'è dietro

## Esercizio 1: Verifica della presenza di una colonna con lo stesso numero di stringhe palindrome di una riga

### Descrizione dell'esercizio:
L'obiettivo di questo esercizio è scrivere una funzione che prenda in input una matrice di stringhe (dimensione `n × m`) e restituisca `true` (1) se esiste almeno una colonna nella matrice che contiene lo stesso numero di stringhe palindrome di una delle righe. Una stringa è palindroma se può essere letta allo stesso modo sia da sinistra a destra che da destra a sinistra.

### Dettagli:
- **Input**: una matrice `M` di stringhe.
- **Output**: `true` se almeno una colonna ha lo stesso numero di stringhe palindrome di una riga, altrimenti `false`.

### Soluzione:
1. **Conta le stringhe palindrome per ogni riga e per ogni colonna**.
   - Per ogni stringa nella matrice, verificare se è palindroma.
2. **Confronta i numeri di stringhe palindrome** nelle righe con quelli nelle colonne.
   - Se il numero di palindromi in una riga coincide con quello in una colonna, la funzione restituisce `true`, altrimenti `false`.

### Funzione C:
```c
bool palindrome(char* M[n][m]) {
    int count_row[n] = {0}; // Contatore per le righe
    int count_col[m] = {0}; // Contatore per le colonne
    bool palindroma = 0;
    
    // Conta le stringhe palindrome in righe e colonne
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (M[i][j]) {
                char* parola = M[i][j];
                int len = strlen(parola);
                for (int k = 0; k < len / 2; k++) {
                    if (parola[k] != parola[len - k - 1]) {
                        palindroma = 0;
                        break;
                    }
                    palindroma = 1;
                }
                if (palindroma) {
                    count_row[i]++;
                    count_col[j]++;
                }
            }
        }
    }
    
    // Verifica se esiste una corrispondenza tra righe e colonne
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (count_row[i] == count_col[j]) {
                return true;
            }
        }
    }

    return false;
}
```

### Esempio di matrice:
```c
char* matrice[n][m] = {
    {"anna", "casa", "non", "cane"},
    {"otto", "gatto", "oro", NULL},
    {"pippo", "radar", NULL, NULL}
};
```

Nel caso di esempio sopra, la funzione restituirà `true` poiché esiste almeno una colonna che ha lo stesso numero di stringhe palindrome di una delle righe.

---

## Esercizio 2: Verifica della percentuale di caratteri di un array in una matrice

### Descrizione dell'esercizio:
In questo esercizio, dobbiamo scrivere una funzione che prenda in input:
- una matrice di stringhe `S` di dimensioni `n × m`,
- un array di caratteri distinti `C`,
- un valore `w` che rappresenta una soglia di percentuale.

La funzione deve restituire `true` se esiste almeno una riga o una colonna della matrice in cui la percentuale di caratteri di `C` presenti è maggiore di `w`.

### Dettagli:
- **Input**: una matrice `S` di stringhe, un array di caratteri `C`, una soglia `w`.
- **Output**: `true` se almeno una riga o colonna ha una percentuale di caratteri di `C` maggiore di `w`, altrimenti `false`.

### Come calcolare la percentuale:
Per ciascuna riga o colonna:
1. **Conta i caratteri di `C` che appaiono nelle stringhe**.
2. **Calcola la percentuale** come:  
   \[
   	ext{percentuale} = \left( rac{	ext{numero di caratteri trovati}}{	ext{numero totale di caratteri}} 
ight) 	imes 100
   \]
3. Se la percentuale è maggiore di `w`, restituisce `true`.

### Funzione C:
```c
bool percentuale(char* S[n][m], char* C, float w) {
    int lunghezza_array_c = strlen(C);
    int lunghezza_parola, parole_trovate;
    int lunghezza_parole_righe, lunghezza_parole_colonne;

    // Calcolo per le righe
    for (int i = 0; i < n; i++) {
        lunghezza_parole_righe = 0;
        parole_trovate = 0;
        for (int j = 0; j < m; j++) {
            if (S[i][j]) {
                char* parola = S[i][j];
                lunghezza_parola = strlen(parola);
                lunghezza_parole_righe += lunghezza_parola;
                for (int k = 0; k < lunghezza_array_c; k++) {
                    for (int t = 0; t < lunghezza_parola; t++) {
                        if (parola[t] == C[k]) {
                            parole_trovate++;
                        }
                    }
                }
            }
        }
        if (lunghezza_parole_righe > 0 && (float)(parole_trovate * 100) / lunghezza_parole_righe > w) {
            return true;
        }
    }

    // Calcolo per le colonne
    for (int j = 0; j < m; j++) {
        parole_trovate = 0;
        lunghezza_parole_colonne = 0;
        for (int i = 0; i < n; i++) {
            if (S[i][j]) {
                char* parola = S[i][j];
                lunghezza_parola = strlen(parola);
                lunghezza_parole_colonne += lunghezza_parola;
                for (int k = 0; k < lunghezza_array_c; k++) {
                    for (int t = 0; t < lunghezza_parola; t++) {
                        if (parola[t] == C[k]) {
                            parole_trovate++;
                        }
                    }
                }
            }
        }
        if (lunghezza_parole_colonne > 0 && (float)(parole_trovate * 100) / lunghezza_parole_colonne > w) {
            return true;
        }
    }

    return false;
}
```

### Esempio di matrice:
```c
char* matrice[n][m] = {
    {"hello", "world", "abc", "def"},
    {"ghi", "jkl", "mno", "pqr"},
    {"stu", "vwxyz", NULL, NULL}
};
```

In questo esempio, la funzione restituirà `false` poiché la percentuale di caratteri dell'array `C` nella matrice non supera la soglia `w`.

---

## Esercizio 3: Rapporto tra somme di righe di A e prodotti di colonne di B
## Descrizione dell'esercizio:
Scrivere una funzione che prenda in input due matrici di interi positivi: A (n × m) e B (k × n). La funzione deve restituire un array C di double di dimensione n, dove l'i-esimo elemento di C è il rapporto tra la somma degli elementi della riga i-esima di A e il prodotto degli elementi della colonna i-esima di B.

## Dettagli:
Input: matrici A (n × m) e B (k × n).
Output: array C di double di dimensione n.
## Soluzione:
Per ogni riga i di A:
Calcolare la somma degli elementi.
Per ogni colonna i di B:
Calcolare il prodotto degli elementi.
Calcolare il rapporto tra la somma della riga i di A e il prodotto della colonna i di B e memorizzarlo in C[i].
Gestire il caso in cui il prodotto delle colonne di B sia 0

### Funzione C:
```c 

    #include <stdio.h>
    #include <stdlib.h>
    #include <float.h>

    double* rapporto_tra_matrici(int **A, int n, int m, int **B, int k) {
       double* rapporto = (double*)malloc(sizeof(double) * n);
       if (rapporto == NULL) {
         perror("Errore allocazione rapporto");
         exit(EXIT_FAILURE);
       }

       for (int i = 0; i < n; i++) {
           int somma_righe = 0;
           int prodotto_colonne = 1;

        for (int j = 0; j < m; j++) {
            somma_righe += A[i][j];
        }

        for (int t = 0; t < k; t++) {
            prodotto_colonne *= B[t][i];
        }

        if (prodotto_colonne == 0) {
            fprintf(stderr, "Errore: prodotto della colonna %d di B è zero.\n", i);
            rapporto[i] = DBL_MAX; //assegno il valore massimo per rappresentare l'infinito
            continue; //passa alla prossima iterazione
        }

        rapporto[i] = (double)somma_righe / prodotto_colonne;
    }
    return rapporto;
}
```
## Esempio di utilizzo (in main()):
```c

    int main() {
       //Allocazione dinamica delle matrici A e B
       int** A = (int**)malloc(n * sizeof(int*));
       int** B = (int**)malloc(k * sizeof(int*));


       //(allocazione e inizializzazione di A e B)
   
       double* D = rapporto_tra_matrici(A, n, m, B, k);

       //(stampa e deallocazione di D, A e B)

       return 0;
    }
```
## Conclusioni

Gli esercizi presentano diverse tecniche di programmazione in C, tra cui:
- Manipolazione di matrici di stringhe.
- Controllo delle condizioni sulle righe e colonne.
- Uso di cicli annidati e stringhe per confronti di caratteri.

