
# Esercizi in C 

Questo repository contiene  esercizi di programmazione in C che lavorano con matrici di stringhe,funzioni,puntatori,allocazioni. Di seguito vengono descritti gli esercizi e l'idea dietro ciascuno.

## ATTENZIONE: prima di vedere come sono stati svolti gli esercizi, provate a farli da voi o per lo meno di sviluppare una logica dietro l'esercizio. Comprendete il codice ma soprattutto la logica che c'è dietro.
Ogni codice sarà commentato con spiegazioni sulle varie linee di codice; qui nel README troverete solo versioni grezze senza commenti.

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

## Esercizio 4: Media Aritmetica Tra Due Matrici, Una Di Interi Ed Una Di Double

### Descrizione dell'esercizio:
Codificare una funzione in C che prenda in input un parametro
formale matrice A di interi di dimensioni n × m di elementi distinti ed
una matrice B di double di dimensioni k × n, e restituisca un array di
n interi nel quale lo i-esimo elemento sia uguale alla media
aritmetica degli elementi presenti sia nella riga i-esima di A che
nella colonna i-esima di B. NB: per decidere se un elemento int
della matrice A e uguale ad un elemento double della matrice B si
calcoli l’approssimazione all’intero piu vicino di quest’ultimo.

Note: 
Per arrotondare si utilizza la funzione round che è presente in math.h, ma poi bisogna castare ad int in quanto quest'ultimo ritorna un double:
esempio:
(int) round(0.60)--> avviene round(0.60)=1.00 --> che col cast (int)1.00 ritorna 1

### Soluzione:
1. **Effettuare il cast degli elementi nella matrice B**
2. **prendere gli elementi comuni tra le due matrici**
3. **Creare ed inserire la media dentro un array**

### Funzioni C:
```c
/* Esercizio:
Codificare una funzione in C che prenda in input un parametro
formale matrice A di interi di dimensioni n × m di elementi distinti ed
una matrice B di double di dimensioni k × n, e restituisca un array di
n interi nel quale lo i-esimo elemento sia uguale alla media
aritmetica degli elementi presenti sia nella riga i-esima di A che
nella colonna i-esima di B. NB: per decidere se un elemento int
della matrice A `e uguale ad un elemento double della matrice B si
calcoli l’approssimazione all’intero pi`u vicino di quest’ultimo.

Note: 
Per arrotondare si utilizza la funzione round che è presente in math.h, ma poi bisogna castare ad int in quanto quest'ultimo ritorna un double:
esempio:
(int) round(0.60)--> avviene round(0.60)=1.00 --> che col cast (int)1.00 ritorna 1

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define n 3
#define m 4
#define k 2

int* media_aritmetica(int A[n][m],double B[k][n]){
    int somma_elementi;
    int elementi_trovati;
    int valore_castato=0;
    int* array=(int*)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++){
        elementi_trovati=0;
        somma_elementi=0;
        for(int j=0;j<m;j++){
            for(int t=0;t<k;t++){
                valore_castato=(int)round(B[t][i]);
                if(A[i][j] == valore_castato){  // qui controlliamo che l'elemento sia identico sia in A che in B dove l'elemento in B è stata castato a int
                    somma_elementi+=valore_castato;
                    elementi_trovati+=1;
                }
            }
        }
        if(elementi_trovati!=0){//preveniamo  il fatto che si effettui una divisione per 0
            array[i]=somma_elementi/elementi_trovati;
        }
        else{
            array[i]=0; // nel caso in cui non ci siano elementi comuni non posso lasciare un inizializzazione casuale dell'elemento nella posizione i-esima. Lo imposto manualmente a 0
        }
    }

    return array;
}

```
### Esempio di matrice:
```c
int main() {
   int A[n][m] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    double B[k][n] = {{1.1, 5.2, 9.3}, {2.9, 6.1, 10.8}};
}
```

# Verifica di Righe e Colonne con Stringhe Brevi

## Descrizione dell'Esercizio

Codificare una funzione in C che prenda in input:
- Una matrice `S` di puntatori a carattere di dimensioni `n × m` (quindi contenente stringhe),
- Un valore intero `w`,
- Un valore intero `k`,

e restituisca il valore booleano `true` (1) se in `S` sono presenti:
1. Almeno una riga con almeno `w` stringhe di lunghezza minore di `k`, **e**
2. Almeno una colonna con almeno `w` stringhe di lunghezza minore di `k`.

## Soluzione in C

### Codice della Funzione
```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define n 3
#define m 4

bool stringhe_minori(char* S[n][m], short w, short k) {
    int lunghezza_parola = 0;
    int stringhe_trovate;
    bool trovate = 0;

    // Controlla se esiste almeno una riga che soddisfa la condizione
    for (int i = 0; i < n; i++) {
        stringhe_trovate = 0;
        for (int j = 0; j < m; j++) {
            if (S[i][j]) {
                lunghezza_parola = strlen(S[i][j]);
                if (lunghezza_parola < k) {
                    stringhe_trovate++;
                }
            }
        }
        if (stringhe_trovate >= w) {
            trovate = 1;
            break;
        }
    }

    if (trovate) {
        // Controlla se esiste almeno una colonna che soddisfa la condizione
        trovate = 0;
        for (int j = 0; j < m; j++) {
            stringhe_trovate = 0;
            for (int i = 0; i < n; i++) {
                if (S[i][j]) {
                    lunghezza_parola = strlen(S[i][j]);
                    if (lunghezza_parola < k) {
                        stringhe_trovate++;
                    }
                }
            }
            if (stringhe_trovate >= w) {
                trovate = 1;
                break;
            }
        }
    }

    return trovate;
}
```

### Codice di Test
```c
int main() {
    char* S[n][m] = {
        {"ciao", "a", "tutti", "oggi"},
        {"sono", "qui", "per", "voi"},
        {"e", "voi", "con", "me"}
    };

    printf("Test con w=2 e k=4: %d\n", stringhe_minori(S, 2, 4)); // Output atteso: 1 (true)

    char* S2[n][m] = {
        {"ciao", "a", "tutti", "oggi"},
        {"sono", "qui", "per", "voi"},
        {"lunghissima", "stringa", "con", "me"}
    };

    printf("Test con w=2 e k=4 (nessuna colonna): %d\n", stringhe_minori(S2, 2, 4)); // Output atteso: 1 (true)

    char* S3[n][m] = {
        {"ciao", "abcd", "tutti", "oggi"},
        {"sono", "quis", "personaggio", "voi"},
        {"etanolo", "a", "constantino", "merenda"}
    };

    printf("Test con w=3 e k=4 (nessuna riga): %d\n", stringhe_minori(S3, 3, 4)); // Output atteso: 0 (false)

    return 0;
}
```

## Spiegazione del Codice
1. **Verifica delle Righe**:
   - Per ogni riga della matrice, viene calcolato il numero di stringhe con lunghezza minore di `k`.
   - Se almeno una riga contiene almeno `w` stringhe brevi, si passa al controllo delle colonne.

2. **Verifica delle Colonne**:
   - Per ogni colonna della matrice, viene calcolato il numero di stringhe con lunghezza minore di `k`.
   - Se almeno una colonna contiene almeno `w` stringhe brevi, la funzione restituisce `true`.

3. **Gestione di Valori Nulli**:
   - Si controlla che ogni elemento della matrice non sia `NULL` prima di calcolare la lunghezza della stringa, per evitare errori.

## Output Atteso
### Input 1:
```c
w = 2, k = 4
S = {
    {"ciao", "a", "tutti", "oggi"},
    {"sono", "qui", "per", "voi"},
    {"e", "voi", "con", "me"}
}
```
**Output**: `1 (true)`

### Input 2:
```c
w = 2, k = 4
S = {
    {"ciao", "a", "tutti", "oggi"},
    {"sono", "qui", "per", "voi"},
    {"lunghissima", "stringa", "con", "me"}
}
```
**Output**: `1 (true)`

### Input 3:
```c
w = 3, k = 4
S = {
    {"ciao", "abcd", "tutti", "oggi"},
    {"sono", "quis", "personaggio", "voi"},
    {"etanolo", "a", "constantino", "merenda"}
}
```
**Output**: `0 (false)`

# Esercizio: Sequenze Monotone Crescenti in Matrici

## Descrizione dell'esercizio:
Scrivere una funzione in C che prenda in input:
- una matrice \( A \) di interi con dimensioni \( n \times m \),
- uno short \( k \) che rappresenta la lunghezza minima di una sequenza monotona crescente,
- uno short \( w \) che rappresenta il numero minimo di colonne che devono contenere almeno una sequenza valida.

La funzione deve restituire il valore booleano `true` (1) se almeno \( w \) colonne della matrice contengono almeno una sequenza monotona crescente di lunghezza maggiore o uguale a \( k \). In caso contrario, restituisce `false` (0).

## Dettagli:
- **Input**: Matrice \( A \) di dimensioni \( n \times m \), interi \( k \) e \( w \).
- **Output**: Valore booleano \( true \) (1) o \( false \) (0).
- **Definizione di sequenza monotona crescente**:
  Una sequenza di interi è monotona crescente se ogni elemento è maggiore o uguale al precedente.
  Esempio: \( 1, 2, 2, 3, 4, 5 \).

## Soluzione:
Per ogni colonna della matrice \( A \):
1. Iterare attraverso le righe della colonna per identificare sequenze monotone crescenti.
2. Contare la lunghezza della sequenza attuale e resettarla se la monotonia viene interrotta.
3. Se una sequenza valida (lunghezza \( \geq k \)) viene trovata, incrementare il conteggio delle colonne valide.
4. Restituire `true` se il numero di colonne valide è maggiore o uguale a \( w \), altrimenti `false`.

---

## Implementazione in C:
```c
#include <stdio.h>
#include <stdbool.h>

#define n 3
#define m 4

bool sequenza_monotona(int A[n][m], short w, short k) {
    int colonne_valide = 0; // Conta le colonne con almeno una sequenza valida

    for (int j = 0; j < m; j++) { // Itera sulle colonne
        int lunghezza = 1; // Ogni sequenza inizia con almeno un elemento
        for (int i = 1; i < n; i++) { // Itera sulle righe della colonna
            if (A[i][j] >= A[i-1][j]) { // Verifica la monotonia crescente
                lunghezza++;
            } else {
                lunghezza = 1; // Reset della lunghezza della sequenza
            }

            // Controlla se la lunghezza della sequenza soddisfa il requisito
            if (lunghezza >= k) {
                colonne_valide++;
                break; // Passa alla prossima colonna
            }
        }

        // Interrompe il ciclo se abbiamo trovato abbastanza colonne valide
        if (colonne_valide >= w) {
            return true;
        }
    }

    return false; // Restituisce false se non ci sono abbastanza colonne valide
}
```
# Esercizio: Ricerca di stringhe in una matrice

## Descrizione dell'Esercizio
Codificare una funzione in C che:
- Prenda in input:
  - Una matrice `A` di stringhe di dimensione `n × m`.
  - Una stringa `s` da cercare.
- Restituisca `true` (1) se esistono **almeno due stringhe diverse** in `A` che:
  1. Contengano la stringa `s`.
  2. Abbiano **differenti indici di riga e di colonna**.

## Dettagli
- La funzione deve utilizzare la funzione di libreria `strstr()` per verificare se la stringa `s` è contenuta all'interno di una stringa.
- La matrice di input `A` è costituita da puntatori a stringhe.

## Implementazione

### Funzione C:
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define n 3
#define m 4

bool stringa_contenuta(char* A[n][m], char* s) {
    int stringhe_trovate = 0;
    int riga = -1, colonna = -1; // Inizializzati a -1 per evitare conflitti

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (strstr(A[i][j], s) != NULL) {
                if (stringhe_trovate == 0) {
                    riga = i;
                    colonna = j;
                } else if (i != riga || j != colonna) {
                    return true; // Trovate due stringhe valide in posizioni diverse
                }
                stringhe_trovate++;
            }
        }
    }
    return false; // Meno di due stringhe trovate
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

    if (stringa_contenuta(matrice1, stringa_da_cercare)) {
        printf("Matrice 1: Trovate almeno due stringhe diverse con \"%s\"\n", stringa_da_cercare);
    } else {
        printf("Matrice 1: Non trovate almeno due stringhe diverse con \"%s\"\n", stringa_da_cercare);
    }

    if (stringa_contenuta(matrice2, stringa_da_cercare)) {
        printf("Matrice 2: Trovate almeno due stringhe diverse con \"%s\"\n", stringa_da_cercare);
    } else {
        printf("Matrice 2: Non trovate almeno due stringhe diverse con \"%s\"\n", stringa_da_cercare);
    }

    if (stringa_contenuta(matrice3, stringa_da_cercare)) {
        printf("Matrice 3: Trovate almeno due stringhe diverse con \"%s\"\n", stringa_da_cercare);
    } else {
        printf("Matrice 3: Non trovate almeno due stringhe diverse con \"%s\"\n", stringa_da_cercare);
    }

    return 0;
}
```

## Spiegazione del Codice
1. **Definizione della funzione `stringa_contenuta`:**
   - Esamina ogni stringa nella matrice `A`.
   - Utilizza `strstr()` per verificare se `s` è contenuta in ciascuna stringa.
   - Tiene traccia della posizione della prima stringa trovata.
   - Restituisce `true` se viene trovata una seconda stringa con indici di riga e colonna diversi.

2. **Funzione `main`:**
   - Esegue il test della funzione `stringa_contenuta` su tre diverse matrici di esempio.
   - Stampa il risultato per ogni matrice.

## Esempio di Output
```
Matrice 1: Trovate almeno due stringhe diverse con "mondo"
Matrice 2: Non trovate almeno due stringhe diverse con "mondo"
Matrice 3: Trovate almeno due stringhe diverse con "mondo"
```
# Concatenazione di Stringhe in Matrice basata su Lunghezze

## Descrizione dell'esercizio

Scrivere una funzione in C che prenda in input due matrici:
1. **A**: una matrice di stringhe di dimensione \( n \times m \).
2. **B**: una matrice di numeri short di dimensione \( n \times m \).

La funzione deve restituire un array di \( n \) stringhe. Per ogni riga \( i \) della matrice \( A \), il corrispondente elemento nell'array risultante è la concatenazione di tutte le stringhe della riga \( i \) che hanno una lunghezza maggiore o uguale al valore nella stessa posizione della matrice \( B \).

### Dettagli
- **Confronto**: La stringa \( A[i][j] \) viene inclusa nella concatenazione se la sua lunghezza (\`strlen(A[i][j])\`) è maggiore o uguale al valore corrispondente \( B[i][j] \).
- **Concatenazione**: La concatenazione delle stringhe viene effettuata usando la funzione `strcat()` di C.

---

## Funzionamento della Soluzione

### Input:
1. Matrice di stringhe \( A \) di dimensione \( n \times m \).
2. Matrice di numeri short \( B \) di dimensione \( n \times m \).

### Output:
Un array di \( n \) stringhe, ciascuna rappresentante la concatenazione filtrata della rispettiva riga di \( A \).

---

## Soluzione in C

La funzione è implementata nel seguente modo:
1. **Determinare la lunghezza massima necessaria per l'allocazione**:
   - Per ogni riga della matrice \( A \), calcolare la somma delle lunghezze di tutte le stringhe che soddisfano la condizione \( \text{strlen}(A[i][j]) \geq B[i][j] \).
2. **Allocare memoria dinamica**:
   - Allocare memoria per ogni elemento dell'array risultante in base alla lunghezza massima calcolata.
3. **Concatenare le stringhe**:
   - Usare `strcat()` per concatenare le stringhe che soddisfano la condizione.
4. **Restituire l'array risultante**.

---

## Esempio di Utilizzo

### Codice del Main:
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 3
#define m 4

int main() {
    char* A[n][m] = {
        {"ciao", "cane", "abc", "test"},
        {"stringa", "lunga", "gatto", "ok"},
        {"hello", "no", "prova", "fine"}
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

    // Libero la memoria allocata
    for (int i = 0; i < n; i++) {
        free(risultato[i]);
    }
    free(risultato);

    return 0;
}
```

### Output:
Per i dati di input:
- **A**:
  ```
  {{"ciao", "cane", "abc", "test"},
   {"stringa", "lunga", "gatto", "ok"},
   {"hello", "no", "prova", "fine"}}
  ```
- **B**:
  ```
  {{2, 5, 3, 4},
   {7, 4, 6, 1},
   {5, 3, 2, 3}}
  ```

Il risultato sarà:
```
Riga 0: ciaoabctest
Riga 1: stringalungaok
Riga 2: helloprova
```

---

## Funzioni Utilizzate

### concatenazione_stringhe
```c
char** concatenazione_stringhe(char* A[n][m], short B[n][m]) {
    char** array = malloc(sizeof(char*) * n);

    for (int i = 0; i < n; i++) {
         //per riuscire ad allocare con successo dobbiamo prima capire qual'è la massima dimensione che possiamo trovare             come concatenazione di stringhe per quella colonna(Senza questa parte di codice,strcat potrebbe poratre a problemi)
        int lunghezza_massima = 0;
        for (int j = 0; j < m; j++) {
            if (strlen(A[i][j]) >= B[i][j]) {
                lunghezza_massima += strlen(A[i][j]);
            }
        }
       // finiamo di allocare (ricordando che stiamo allocando un array di puntatori a caratteri)
        array[i] = malloc(lunghezza_massima + 1);//Importante ricordarsi di aggiungere +1 per il carattere nullo.
        array[i][0] = '\0';

        for (int j = 0; j < m; j++) {
            if (strlen(A[i][j]) >= B[i][j]) {
                strcat(array[i], A[i][j]);
            }
        }
    }

    return array;
}
```

---

## Note
1. **Funzioni Standard Usate**:
   - `strlen()`: Per calcolare la lunghezza di una stringa.
   - `strcat()`: Per concatenare stringhe.
2. **Allocazione Dinamica**:
   - La memoria per ogni elemento del risultato viene allocata dinamicamente.
   - È importante liberare la memoria allocata una volta che non serve più.


---

# Conteggio Stringhe Inizio-Fine in Matrice

## Descrizione dell'esercizio

Scrivere una funzione in C che prenda in input:
1. **S**: una matrice di stringhe di dimensione \( n \times m \).
2. **C**: un array di caratteri di dimensione \( n \).
3. **D**: un array di caratteri di dimensione \( n \).

La funzione deve restituire un array di short nel quale il generico elemento di indice \( i \) contiene il numero di stringhe nella riga \( i \) della matrice \( S \) che iniziano con il carattere \( C[i] \) e terminano con il carattere \( D[i] \).

---

## Funzionamento della Soluzione

### Input:
1. **S**: Matrice di stringhe di dimensione \( n \times m \).
2. **C**: Array di caratteri di dimensione \( n \).
3. **D**: Array di caratteri di dimensione \( n \).

### Output:
Un array di short di dimensione \( n \), dove ogni elemento \( i \) rappresenta il conteggio delle stringhe che rispettano i criteri descritti nella riga \( i \) di \( S \).

---

## Soluzione in C

La funzione è implementata nel seguente modo:
1. **Iterare sulla matrice**:
   - Per ogni riga \( i \), scorrere le stringhe della matrice \( S[i][j] \).
2. **Controllare i criteri**:
   - Verificare se la stringa \( S[i][j] \) inizia con il carattere \( C[i] \) e termina con il carattere \( D[i] \).
3. **Aggiornare il conteggio**:
   - Incrementare il contatore per la riga \( i \) se entrambi i criteri sono soddisfatti.

---

## Esempio di Utilizzo

### Codice del Main:
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 3
#define m 4

int main() {
    char* S[n][m] = {
        {"casa", "albero", "chitarra", "ok"}, 
        {"camera", "topo", "uccello", "prova"}, 
        {"sole", "luna", "salame", "mouse"}
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
```

### Output:
Per i dati di input:
- **S**:
  ```
  {{"casa", "albero", "chitarra", "ok"},
   {"camera", "topo", "uccello", "prova"},
   {"sole", "luna", "salame", "mouse"}}
  ```
- **C**:
  ```
  {'c', 't', 's'}
  ```
- **D**:
  ```
  {'a', 'o', 'a'}
  ```

Il risultato sarà:
```
Riga 0: 2 stringhe
Riga 1: 1 stringhe
Riga 2: 2 stringhe
```

---

## Funzioni Utilizzate

### inizio_fine_stringa
```c
short* inizio_fine_stringa(char* S[n][m], char C[n], char D[n]) {
    short* array = (short*)malloc(sizeof(short) * n);
    char* parola;

    for (int i = 0; i < n; i++) {
        array[i] = 0;
        for (int j = 0; j < m; j++) {
            parola = S[i][j];
            if (parola[0] == C[i] && parola[strlen(parola) - 1] == D[i]) {
                array[i] += 1;
            }
        }
    }
    return array;
}
```

---

## Note
1. **Funzioni Standard Usate**:
   - `strlen()`: Per calcolare la lunghezza di una stringa.
2. **Allocazione Dinamica**:
   - La memoria per l'array di risultati viene allocata dinamicamente. È essenziale liberare la memoria dopo l'uso per evitare fughe di memoria.
3. **Assenza di Controlli di Errore**:
   - Non sono stati implementati controlli per verificare che la matrice \( S \), l'array \( C \) e l'array \( D \) siano validi (ad esempio, verificare la presenza di valori nulli o dimensioni corrette).
   - Questi controlli dovrebbero essere aggiunti in un'applicazione reale.

---


# Trova Colonna con Maggiori Corrispondenze in Matrice

## Descrizione dell'Esercizio

L'obiettivo di questo esercizio è scrivere una funzione in C che:
1. Prende in input:
   - Una matrice \( A \) di numeri `double` di dimensioni \( n \times k \).
   - Un array \( B \) di numeri interi di dimensione \( n \).
2. Restituisce:
   - L'indice della colonna di \( A \) che contiene il maggior numero di elementi che, approssimati al numero intero più vicino, corrispondono ai valori nell'array \( B \).

### Logica
Per ogni colonna della matrice \( A \):
1. Approssimare ciascun elemento di indice \( (i, j) \) al numero intero più vicino usando `round()`.
2. Confrontare l'elemento approssimato con il valore \( B[i] \).
3. Contare il numero di corrispondenze per ciascuna colonna.
4. Restituire l'indice della colonna con il maggior numero di corrispondenze.

---

## Soluzione in C

### Input:
1. Matrice di `double` \( A \) di dimensioni \( n \times k \).
2. Array di interi \( B \) di dimensione \( n \).

### Output:
L'indice della colonna \( j \) con il maggior numero di corrispondenze.

---

## Funzionamento del Codice

1. **Ciclo su ogni colonna**:
   - Itera attraverso tutte le colonne della matrice \( A \).
   - Conta il numero di elementi che soddisfano la condizione \( \\text{round}(A[i][j]) == B[i] \).

2. **Aggiornamento dell'indice**:
   - Memorizza l'indice della colonna con il maggior numero di corrispondenze.

3. **Restituzione del risultato**:
   - L'indice della colonna con il massimo numero di corrispondenze.

---

## Codice

### Funzione Principale: `trova_colonna_maggiore`
```c
int trova_colonna_maggiore(double A[n][k], int B[n]) {
   int colonna_maggiore_numero = -1;
   int numero_elementi_attuali;
   int numero_elementi_precedenti = 0;
   int numero_castato;

   for (int j = 0; j < k; j++) {
       numero_elementi_attuali = 0;
       for (int i = 0; i < n; i++) {
           numero_castato = (int)round(A[i][j]);
           if (numero_castato == B[i]) {
               numero_elementi_attuali++;
           }
       }

       if (numero_elementi_attuali > numero_elementi_precedenti) {
           colonna_maggiore_numero = j;
           numero_elementi_precedenti = numero_elementi_attuali;
       }
   }

   return colonna_maggiore_numero;
}
```
# Codice del Main:
```c
int main() {
    double A[n][k] = {
        {1.2, 2.8}, 
        {3.5, 2.3}, 
        {4.9, 5.6}
    };
    int B[n] = {1, 2, 5};

    int colonna_max = trova_colonna_maggiore(A, B);
    if (colonna_max != -1) {
        printf("La colonna con il maggior numero di corrispondenze e': %d\\n", colonna_max);
    } else {
        printf("Errore: indice fuori dai limiti\\n");
    }

    return 0;
}
```

### Output:
Per i dati di input:
- **A**:
  ```
  {{1.2, 2.8},
  {3.5, 2.3},
  {4.9, 5.6}}
  ```
- **B**:
  ```
  {1, 2, 5}
  ```


Il risultato sarà:
```
La colonna con il maggior numero di corrispondenze e': 0
```


## Conclusioni

Gli esercizi presentano diverse tecniche di programmazione in C, tra cui:
- Manipolazione di matrici di stringhe.
- Controllo delle condizioni sulle righe e colonne.
- Uso di cicli annidati e stringhe per confronti di caratteri.

