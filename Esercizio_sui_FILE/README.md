
# Esercizio: Gestione di matrici e operazioni su file

## Descrizione del programma

Questo programma in C implementa diverse funzioni per gestire matrici di numeri reali (di tipo `double`), eseguendo operazioni di lettura, scrittura e calcolo della trasposta. Il programma comprende:

1. La generazione di una matrice di dimensione **N x M** con valori casuali.
2. La scrittura di questa matrice su un file di testo, dove vengono salvate anche le dimensioni **N** e **M** della matrice.
3. La lettura di una matrice da un file di testo.
4. Il calcolo della **matrice trasposta**, che inverte le righe e le colonne della matrice originale.
5. La scrittura della matrice trasposta su un altro file di testo.

## Cos'è una matrice trasposta?

Una matrice trasposta è una matrice ottenuta scambiando le righe e le colonne della matrice originale. Se una matrice **A** ha dimensioni **N x M**, la sua trasposta **A^T** avrà dimensioni **M x N**. 

Ad esempio, consideriamo la seguente matrice **A** di dimensioni 2x3:

```
A = [ 1  2  3 ]
    [ 4  5  6 ]
```

La sua matrice trasposta **A^T** avrà dimensioni 3x2 e sarà:

```
A^T = [ 1  4 ]
       [ 2  5 ]
       [ 3  6 ]
```

Come puoi vedere, le righe di **A** diventano le colonne di **A^T** e viceversa.

## Funzionamento del programma

### 1. Creazione della matrice
La matrice viene generata randomicamente, con valori compresi tra 0 e 25. Le dimensioni **N** e **M** sono impostate rispettivamente a 3 e 2 (puoi cambiarle nel codice modificando i valori delle costanti `N` e `M`).

### 2. Scrittura della matrice su un file
La matrice generata viene scritta su un file di testo, con le dimensioni **N** e **M** nella prima riga, seguite dai valori della matrice.

### 3. Lettura della matrice da un file
Il programma legge una matrice da un file di testo, ricostruendo la matrice a partire dalle dimensioni **N** e **M**.

### 4. Calcolo della matrice trasposta
Il programma calcola la trasposta della matrice letta, scambiando le righe con le colonne.

### 5. Scrittura della matrice trasposta su un altro file
La matrice trasposta viene scritta su un file di testo, utilizzando la stessa struttura di salvataggio della matrice originale.

## Codice del programma

```c
#include <stdio.h>
#include <stdlib.h>
#define N 3
#define M 2

int creazione_file(double R[N][M], const char *nome_file) {
    FILE *file = fopen(nome_file, "w");
    if (file == NULL) {
        perror("Il file non si è aperto correttamente");
        return 1;
    }
    fprintf(file, "%d %d
", N, M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            fprintf(file, "%lf ", R[i][j]);
        }
        fprintf(file, "
");
    }

    fclose(file);
    return 0;
}

int creazione_file_dinamico(double **R, const char *nome_file) {
    FILE *file = fopen(nome_file, "w");
    if (file == NULL) {
        perror("Il file non si è aperto correttamente");
        return 1;
    }
    fprintf(file, "%d %d
", M, N);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            fprintf(file, "%lf ", R[i][j]);
        }
        fprintf(file, "
");
    }

    fclose(file);
    return 0;
}

double** matrice_letta_da_file(char *nome_file) {
    FILE *file = fopen(nome_file, "r");
    if (file == NULL) {
        perror("Il file non si è aperto correttamente");
        return NULL;
    }

    int n, m;
    if (fscanf(file, "%d %d
", &n, &m) != 2) {
        fprintf(stderr, "Errore lettura dimensioni matrice
");
        fclose(file);
        return NULL;
    }

    double **matrice_nuova = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrice_nuova[i] = (double *)malloc(m * sizeof(double));
        for (int j = 0; j < m; j++) {
            fscanf(file, "%lf ", &matrice_nuova[i][j]);
        }
    }

    fclose(file);
    return matrice_nuova;
}

double **calcola_trasposta(double **matrice) {
    double **trasposta = (double **)malloc(M * sizeof(double *));
    for (int i = 0; i < M; i++) {
        trasposta[i] = (double *)malloc(N * sizeof(double));
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            trasposta[j][i] = matrice[i][j];
        }
    }

    return trasposta;
}

int main() {
    double matrice[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrice[i][j] = (double)rand() / RAND_MAX * 25.0;
        }
    }

    if (creazione_file(matrice, "matrice.txt") != 0) {
        return 1;
    }

    double **matrice_letta = matrice_letta_da_file("matrice.txt");
    if (matrice_letta == NULL) {
        perror("errore nella creazione della matrice da file");
        return 1;
    }

    double **trasposta = calcola_trasposta(matrice_letta);
    if (trasposta == NULL) {
        for (int k = 0; k < N; k++) {
            free(matrice_letta[k]);
        }
        free(matrice_letta);
        return 1;
    }

    if (creazione_file_dinamico(trasposta, "trasposta.txt") != 0) {
        for (int k = 0; k < N; k++) {
            free(matrice_letta[k]);
        }
        free(matrice_letta);
        for (int k = 0; k < M; k++) {
            free(trasposta[k]);
        }
        free(trasposta);
        return 1;
    }

    for (int i = 0; i < N; i++) {
        free(matrice_letta[i]);
    }
    free(matrice_letta);
    for (int i = 0; i < M; i++) {
        free(trasposta[i]);
    }
    free(trasposta);

    printf("Operazioni completate.
");

    return 0;
}
```

## Compilazione e Esecuzione

Per compilare ed eseguire il programma:

1. Compila il codice con il comando:

   ```bash
   gcc -o matrice_programma matrice_programma.c
   ```

2. Esegui il programma con il comando:

   ```bash
   ./matrice_programma
   ```

Il programma genererà due file di testo: `matrice.txt` e `trasposta.txt`. Il file `matrice.txt` contiene la matrice originale, mentre `trasposta.txt` contiene la sua matrice trasposta.

## Note

- Le dimensioni della matrice **N** e **M** sono fisse nel codice, ma possono essere modificate modificando le costanti `N` e `M`.
- I valori all'interno della matrice sono generati casualmente tra 0 e 25.
