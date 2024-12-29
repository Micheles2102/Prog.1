# Esempi Struct/Enum/Union in c
Questo repository contiene  esercizi di programmazione in C che lavorano con struct,enum,union,puntatori,allocazioni. Di seguito vengono descritti gli esercizi e l'idea dietro ciascuno.

## ATTENZIONE: prima di vedere come sono stati svolti gli esercizi, provate a farli da voi o per lo meno di sviluppare una logica dietro l'esercizio. Comprendete il codice ma soprattutto la logica che c'è dietro.
Ogni codice sarà commentato con spiegazioni sulle varie linee di codice; qui nel README troverete solo versioni grezze senza commenti.


# Inizializzazione di una Struttura con Elementi Pseudo-Casuali in C

Questo repository contiene un esempio di codice in linguaggio C che illustra come inizializzare una struttura utilizzando dati pseudo-casuali. L'esempio mostra anche l'uso di puntatori, allocazione dinamica e funzioni per manipolare i dati della struttura.

---

## Dettagli del Codice

### Descrizione dell'Esercizio
L'obiettivo di questo esercizio è definire una struttura (struct) chiamata `record`, che contiene:
- Un numero in virgola mobile (`float`).
- Un carattere (`char`).
- Due puntatori a caratteri (`char*`), indicanti due stringhe chiamate `S` e `W`.

Il codice include una funzione che:
1. Prende in input un puntatore a una struttura `record`.
2. Inizializza i campi della struttura con valori pseudo-casuali:
   - Il campo `x` è un numero casuale tra `0.0` e `7.0`.
   - Il campo `c` è un carattere casuale tra `'a'` e `'z'`.
   - La stringa `W` contiene due caratteri numerici casuali (tra `'0'` e `'9'`).
   - La stringa `S` contiene due caratteri alfabetici casuali (tra `'a'` e `'z'`).

Infine, la funzione viene chiamata dal `main`, che stampa i valori generati e libera la memoria allocata dinamicamente per le stringhe.

---

## Codice

### Implementazione
Ecco il codice completo:

```c
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct record {
    float x;
    char c;
    char* S;
    char* W;
};

void inizializzazione(struct record *ptr) {
    ptr->x = (float) rand() / RAND_MAX * 7.0; // Numero casuale tra 0.0 e 7.0
    ptr->c = rand() % 26 + 'a'; // Carattere casuale tra 'a' e 'z'

    // Allocazione dinamica per la stringa W
    ptr->W = (char*) malloc(3 * sizeof(char));
    ptr->W[0] = (rand() % 10) + '0';
    ptr->W[1] = (rand() % 10) + '0';
    ptr->W[2] = '\0'; // Terminatore di stringa

    // Allocazione dinamica per la stringa S
    ptr->S = (char*) malloc(3 * sizeof(char));
    ptr->S[0] = (rand() % 26) + 'a';
    ptr->S[1] = (rand() % 26) + 'a';
    ptr->S[2] = '\0'; // Terminatore di stringa
}

int main() {
    srand(time(0)); // Inizializzazione del seed per numeri casuali

    struct record rec;
    inizializzazione(&rec);

    // Stampa dei valori della struttura
    printf("Il valore di x in record e': %f\n", rec.x);
    printf("Il valore di c in record e': %c\n", rec.c);
    printf("Il valore di W in record e': %s\n", rec.W);
    printf("Il valore di S in record e': %s\n", rec.S);

    // Liberazione della memoria allocata dinamicamente
    free(rec.W);
    free(rec.S);

    return 0;
}
```

---

## Funzionamento del Codice

1. **Struttura `record`**:
   - Contiene quattro campi, di cui due sono puntatori a stringhe allocate dinamicamente.

2. **Funzione `inizializzazione`**:
   - Utilizza la libreria `stdlib.h` per generare numeri casuali.
   - Converte i numeri casuali in valori specifici (caratteri o stringhe) utilizzando la codifica ASCII.
   - Alloca memoria dinamica per i campi stringa (`W` e `S`).

3. **Funzione `main`**:
   - Inizializza il seed della funzione `rand`.
   - Crea un'istanza della struttura `record` e la passa alla funzione `inizializzazione`.
   - Stampa i valori inizializzati e libera la memoria dinamica.

---

## Note Importanti

- **Gestione della Memoria**:
  Ricordarsi di liberare la memoria allocata dinamicamente con `free` per evitare fughe di memoria (memory leaks).

- **Codifica ASCII**:
  La conversione dei numeri casuali in caratteri alfabetici o numerici si basa sulla codifica ASCII.

- **Riproducibilità**:
  Il seed di `rand` può essere inizializzato con un valore fisso per ottenere sempre la stessa sequenza di numeri casuali (ad esempio, durante il debug).

---


## Estensione dell'Esercizio: Inizializzazione di una Struttura con Elementi Pseudo-Casuali mediante Struttura Annidata
In questo esercizio, estenderemo la struttura precedente creando una nuova struttura chiamata `data` che contiene:
- Un intero `ID`.
- Un campo di tipo `record` definito nel precedente esercizio (struttura annidata).

### Dettagli del Codice

L'esercizio prevede di:
- Inizializzare l'array di strutture `data`, con un numero `k` di elementi inizializzati e il resto degli elementi con `ID = -1`.
- Ogni elemento di tipo `data` ha un ID univoco, e per ogni elemento, viene inizializzato il campo `RecordPrincipale` utilizzando la funzione di inizializzazione del primo esercizio.

### Codice

```c

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 5
#define k 3

struct record{
    float x;
    char c;
    char* S;
    char* W;
};

void inizializzazione(struct record *ptr){
    ptr->x=(float) rand()/RAND_MAX*7.0; //numero casuale tra 0.0 e 7.0 (dobbiamo castare a float poichè rand ritorna un int)
    ptr->c=rand()%(26)+'a';
    //per quanto riguarda le due stringhe dobbiamo allocare la memoria opportuna
    ptr->W=(char*) malloc(3*sizeof(char));
    ptr->W[0] = (rand() % 10) + '0'; // Carattere numerico casuale tra [0-9] dove ovviamente 0 deve essere posto come stringa
    ptr->W[1]= (rand() % 9) + '0'; //ho diminuito solo per avere numeri diversi(non volevo modificare il seed)
    ptr->W[2] = '\0'; // Terminatore di stringa
    //alloco per S
    ptr->S=(char*) malloc(3*sizeof(char));
    ptr->S[0] = (rand() % 26) + 'a'; // Carattere numerico casuale tra [a-z] dove ovviamente min ='a';
    ptr->S[1] = (rand() % 27) + 'a';
    ptr->S[2] = '\0'; // Terminatore di stringa

}

typedef struct data{
    int ID;
    struct record RecordPrincipale;
}Data;

void inizializzazioneData(struct data *ptr,int i){
    ptr->ID=i;
    inizializzazione(&ptr->RecordPrincipale);
}

int main (){
    srand(time(0));

    Data array[N];

    for(int i=0;i<k;i++){
        inizializzazioneData(&array[i],i);
    }
    for(int i=k;i<N;i++){//tutti i valori successivi a k dovranno avere ID = -1 
        inizializzazioneData(&array[i],-1);
    }

    // Stampo l'array per verificare l'inizializzazione
    for (int i = 0; i < N; i++) {
        printf("Elemento %d: ID = %d, ", i, array[i].ID);
        if (array[i].ID != -1) {
            printf("x = %f, c = %c, W = %s, S = %s\n", array[i].RecordPrincipale.x,
                   array[i].RecordPrincipale.c, array[i].RecordPrincipale.W, array[i].RecordPrincipale.S);
        } else {
            printf("(Elemento non inizializzato)\n");
        }
    }

    // Libero la memoria allocata dinamicamente
    for (int i = 0; i < k; i++) {
        free(array[i].RecordPrincipale.W);
        free(array[i].RecordPrincipale.S);
    }

    return 0;
}
```

---

## Funzionamento del Codice

1. **Struttura `record`**:
   - La struttura contiene i campi `x`, `c`, `S`, e `W`, con i primi tre campi inizializzati a valori casuali.

2. **Struttura `data`**:
   - La struttura `data` contiene un intero `ID` e una struttura `record` annidata. L'ID è univoco per ogni elemento e viene inizializzato tramite la funzione `inizializzazioneData`.

3. **Funzione `inizializzazioneData`**:
   - La funzione assegna un ID all'elemento `data` e poi inizializza il campo `RecordPrincipale` usando la funzione di inizializzazione `inizializzazione`.

4. **Funzione `main`**:
   - Inizializza un array di `N` elementi di tipo `data` e popola i primi `k` elementi con valori univoci. Gli elementi successivi sono contrassegnati con `ID = -1` per indicare che non sono stati inizializzati.

---

## Note Importanti

- **Gestione della Memoria**:
  Ricordarsi di liberare la memoria allocata dinamicamente con `free` per evitare fughe di memoria (memory leaks).

- **Codifica ASCII**:
  La conversione dei numeri casuali in caratteri alfabetici o numerici si basa sulla codifica ASCII.

- **Riproducibilità**:
  Il seed di `rand` può essere inizializzato con un valore fisso per ottenere sempre la stessa sequenza di numeri casuali (ad esempio, durante il debug).

## Estensione dell'Esercizio: Inizializzazione di una Struttura con Elementi Pseudo-Casuali mediante Struttura Annidata con un campo flag e Enumerazioni
In questa estensione, il tipo data viene modificato per includere un campo aggiuntivo FLAG che prende i valori definiti da un'enumerazione. La funzione successiva verifica la condizione tra il numero di vocali in S e il numero di numeri divisibili per tre in W per determinare quale valore assegnare a FLAG.

## Dettagli dell'Esercizio
1) Modifica il tipo data per includere un campo FLAG definito tramite una enumerazione che ha due possibili valori:

   VOWELS
   THREE
2) Crea una funzione che prenda in input l'array di elementi di tipo data e aggiorni FLAG in base a:

Se il numero di vocali presenti nella stringa S è maggiore del numero di valori divisibili per tre in W, allora FLAG deve essere VOWELS.
Altrimenti, FLAG deve essere THREE.
### Codice

```c
/* Estendere il precedente esercizio con la modifica del tipo data in modo che
includa anche un campo FLAG che prenda valori definiti in una enumerazione
(assegnare alla enumerazione un nome a piacere): la enumerazione avr`a
possibili valori VOWELS e THREE.
Codificare una opportuna funzione che prenda in input l’array di elementi di
tipo data per modificare ognuno di questi nel seguente modo: se il numero di
vocali presenti nel campo S `e maggiore del numero di elementi divisibili per tre
del campo W, allore FLAG=VOWELS, altrimenti FLAG=THREE.


Note: Ho lasciato i commenti dell'esercizio precedente ma vi consiglio di visionarlo da solo prima andando a vederlo.
Note: Ho applicato nella funzione inizializzazioneData un piccolo trick con l'uso della tabella ascii infatti, W è una stringa che va da 0 a 9 
nell if sottraggo '0' che rappresenta in ASCII il valore 48.
W avrà al suo interno vari valori come ad esempio il 9 che risulta essere il 57 dunque facendo:
ptr->RecordPrincipale.W[i] - '0'
sto praticamente facendo 57-48=9 e controllo se quest'ultimo è divisibile per tre
*/


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#define N 5
#define k 3

struct record{
    float x;
    char c;
    char* S;
    char* W;
};

enum nome{
    VOWELS,
    THREE,
};

void inizializzazione(struct record *ptr){
    ptr->x=(float) rand()/RAND_MAX*7.0; //numero casuale tra 0.0 e 7.0 (dobbiamo castare a float poichè rand ritorna un int)
    ptr->c=rand()%(26)+'a';
    //per quanto riguarda le due stringhe dobbiamo allocare la memoria opportuna
    ptr->W=(char*) malloc(3*sizeof(char));
    ptr->W[0] = (rand() % 10) + '0'; // Carattere numerico casuale tra [0-9] dove ovviamente 0 deve essere posto come stringa
    ptr->W[1]= (rand() % 9) + '0'; //ho diminuito solo per avere numeri diversi(non volevo modificare il seed)
    ptr->W[2] = '\0'; // Terminatore di stringa
    //alloco per S
    ptr->S=(char*) malloc(3*sizeof(char));
    ptr->S[0] = (rand() % 26) + 'a'; // Carattere numerico casuale tra [a-z] dove ovviamente min ='a';
    ptr->S[1] = (rand() % 27) + 'a';
    ptr->S[2] = '\0'; // Terminatore di stringa

}

typedef struct data{
    int ID;
    struct record RecordPrincipale;
    enum nome FLAG;
}Data;

void inizializzazioneData(struct data *ptr,int i){
    ptr->ID=i;
    inizializzazione(&ptr->RecordPrincipale);//PRIMA FACCIAMO ALLOCARE W E S SE NO ANDREBBE IN SEGMENTATION FAULT
    int elementi_divisibili=0;
    for(int i=0;i<strlen(ptr->RecordPrincipale.W);i++){
       if ((ptr->RecordPrincipale.W[i] - '0') % 3 == 0) { //controlla se è divisibile per 3 (ho applicato un trick con la conversione ascii)
            elementi_divisibili++;
        }
    }
    int contatore=0;
    for (int i = 0; i < strlen(ptr->RecordPrincipale.S); i++) {
        char c=ptr->RecordPrincipale.S[i];
        // Usando switch:
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                contatore++;
                break;
            default:
                break; // Non è una vocale
        }
    }

    if(contatore>elementi_divisibili){
        ptr->FLAG=VOWELS;
    }
    else{ptr->FLAG=THREE;}

}

int main (){
    srand(time(0));

    Data array[N];

    for(int i=0;i<k;i++){
        inizializzazioneData(&array[i],i);
    }
    for(int i=k;i<N;i++){//tutti i valori successivi a k dovranno avere ID = -1 
        inizializzazioneData(&array[i],-1);
    }

    // Stampo l'array per verificare l'inizializzazione
    for (int i = 0; i < N; i++) {
        printf("Elemento %d: ID = %d, ", i, array[i].ID);
        if (array[i].ID != -1) {
            printf("x = %f, c = %c, W = %s, S = %s, FLAG = %s\n",
                   array[i].RecordPrincipale.x, array[i].RecordPrincipale.c,
                   array[i].RecordPrincipale.W, array[i].RecordPrincipale.S,
                   array[i].FLAG == VOWELS ? "VOWELS" : "THREE");
        } else {
            printf("(Elemento non inizializzato)\n");
        }
    }

    // Libero la memoria allocata dinamicamente
    for (int i = 0; i < k; i++) {
        free(array[i].RecordPrincipale.W);
        free(array[i].RecordPrincipale.S);
    }

    return 0;
}
```
## Funzionamento del Codice
Il programma definisce una struttura data con un campo FLAG di tipo enumerato (enum nome), che può essere VOWELS o THREE.
La funzione inizializzazioneData prende un puntatore a data e inizializza i valori di x, c, S e W. In seguito, confronta il numero di vocali in S con i numeri divisibili per tre in W, assegnando il valore appropriato al campo FLAG.
La funzione main crea un array di data, inizializza i primi k elementi e stampa il risultato.

## Estensione dell'Esercizio: Inizializzazione di una Struttura con Elementi Pseudo-Casuali mediante Struttura Annidata e Unione per FLAG_DATA

Questo progetto estende un programma che gestisce una struttura dati `Data`, aggiungendo una **union** per memorizzare due tipi di dati diversi all'interno dello stesso campo. Il programma esegue la gestione di flag per determinare se la struttura `Data` debba contenere la prima vocale di una stringa o il primo numero divisibile per tre da un'altra stringa numerica.

## Struttura del Codice

### 1. **Struttura `record`**

La struttura `record` contiene i seguenti campi:
- `x` (float): Un numero casuale tra 0.0 e 7.0.
- `c` (char): Un carattere casuale tra 'a' e 'z'.
- `S` (char*): Una stringa di 2 caratteri alfabetici casuali.
- `W` (char*): Una stringa di 2 numeri casuali.

### 2. **Enumerazione `nome`**

L'enumerazione `nome` definisce due valori:
- `VOWELS`: Indica che il campo `FLAG_DATA` contiene una vocale.
- `THREE`: Indica che il campo `FLAG_DATA` contiene un numero divisibile per 3.

### 3. **Union `nome2`**

La **union** `nome2` può contenere due tipi di dati:
- `t` (unsigned short): Un numero intero.
- `q` (char): Un carattere.

### 4. **Tipo `Data`**

La struttura `Data` contiene i seguenti campi:
- `ID` (int): Un identificativo per la struttura.
- `RecordPrincipale` (struct record): Una variabile di tipo `record`.
- `FLAG` (enum nome): Un flag che può essere `VOWELS` o `THREE`.
- `FLAG_DATA` (union nome2): Contiene una vocale o un numero divisibile per 3, in base al valore di `FLAG`.

### 5. **Funzioni**

#### `inizializzazione(struct record *ptr)`

Questa funzione inizializza i campi della struttura `record`:
- `x`: Un numero casuale tra 0.0 e 7.0.
- `c`: Un carattere casuale tra 'a' e 'z'.
- `W`: Una stringa di due numeri casuali.
- `S`: Una stringa di due caratteri alfabetici casuali.

#### `inizializzazioneData(struct data *ptr, int i)`

Questa funzione inizializza la struttura `Data`:
- Imposta l'ID della struttura a `i`.
- Chiama la funzione `inizializzazione` per inizializzare i campi di `RecordPrincipale`.
- Conta il numero di vocali in `S` e il numero di numeri divisibili per 3 in `W`.
- Se il numero di vocali è maggiore di quello dei numeri divisibili per 3, imposta `FLAG` a `VOWELS` e `FLAG_DATA` con la prima vocale.
- Se il numero di numeri divisibili per 3 è maggiore, imposta `FLAG` a `THREE` e `FLAG_DATA` con il primo numero divisibile per 3.

#### `main()`

La funzione `main` gestisce l'array di strutture `Data`:
- Chiama `inizializzazioneData` per inizializzare le prime `k` strutture.
- Per le restanti strutture, imposta l'ID a `-1`, indicando che non sono inizializzate.
- Stampa il contenuto dell'array, mostrando i valori di `ID`, `x`, `c`, `S`, `W`, `FLAG` e `FLAG_DATA`.

### 6. **Output**

L'output del programma visualizza per ogni elemento dell'array:
- `ID`: L'identificativo dell'elemento.
- `x`: Il numero casuale generato.
- `c`: Il carattere casuale generato.
- `W`: La stringa numerica generata.
- `S`: La stringa alfabetica generata.
- `FLAG`: Mostra "VOWELS" o "THREE" a seconda del flag.
- `FLAG_DATA`: Se il flag è `VOWELS`, mostra la prima vocale trovata. Se il flag è `THREE`, mostra il primo numero divisibile per 3. Se non ci sono numeri divisibili per 3, mostra un messaggio che indica l'assenza di numeri divisibili per 3.

### 7. **Gestione della Memoria**

Il programma alloca dinamicamente la memoria per le stringhe `S` e `W` utilizzando `malloc` e la libera alla fine del programma con `free`.

### 8. **Codice Completo**

```c
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#define N 5
#define k 3

struct record {
    float x;
    char c;
    char* S;
    char* W;
};

enum nome {
    VOWELS,
    THREE,
};

union nome2 {
    unsigned short t;
    char q;
};

typedef struct data {
    int ID;
    struct record RecordPrincipale;
    enum nome FLAG;
    union nome2 FLAG_DATA;
} Data;

void inizializzazione(struct record *ptr) {
    ptr->x = (float) rand() / RAND_MAX * 7.0; // Numero casuale tra 0.0 e 7.0
    ptr->c = rand() % 26 + 'a';
    
    // Allocazione dinamica per W
    ptr->W = (char*) malloc(3 * sizeof(char));
    ptr->W[0] = (rand() % 10) + '0';
    ptr->W[1] = (rand() % 9) + '0';
    ptr->W[2] = '\0'; // Terminatore di stringa

    // Allocazione dinamica per S
    ptr->S = (char*) malloc(3 * sizeof(char));
    ptr->S[0] = (rand() % 26) + 'a';
    ptr->S[1] = (rand() % 27) + 'a';
    ptr->S[2] = '\0'; // Terminatore di stringa
}

void inizializzazioneData(struct data *ptr, int i) {
    ptr->ID = i;
    inizializzazione(&ptr->RecordPrincipale);
    int elementi_divisibili = 0;
    unsigned short primo_numero_divisibile = 2; // Inizializzato a 2 per segnalare assenza di numeri divisibili per 3
    
    for (int i = 0; i < strlen(ptr->RecordPrincipale.W); i++) {
        if ((ptr->RecordPrincipale.W[i] - '0') % 3 == 0) {
            if (primo_numero_divisibile == 2) {
                primo_numero_divisibile = ptr->RecordPrincipale.W[i] - '0';
            }
            elementi_divisibili++;
        }
    }

    int contatore = 0;
    char prima_vocale = '\0';
    for (int i = 0; i < strlen(ptr->RecordPrincipale.S); i++) {
        char c = ptr->RecordPrincipale.S[i];
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                contatore++;
                if (prima_vocale == '\0') prima_vocale = c;
                break;
            default:
                break;
        }
    }

    if (contatore > elementi_divisibili) {
        ptr->FLAG = VOWELS;
        ptr->FLAG_DATA.q = prima_vocale;
    } else {
        ptr->FLAG = THREE;
        ptr->FLAG_DATA.t = primo_numero_divisibile;
    }
}

int main() {
    srand(time(0));

    Data array[N];

    for (int i = 0; i < k; i++) {
        inizializzazioneData(&array[i], i);
    }
    for (int i = k; i < N; i++) {
        inizializzazioneData(&array[i], -1);
    }

    // Stampa dell'array
    for (int i = 0; i < N; i++) {
        printf("Elemento %d: ID = %d, ", i, array[i].ID);
        if (array[i].ID != -1) {
            printf("x = %f, c = %c, W = %s, S = %s, FLAG = %s, FLAG_DATA = ",
                   array[i].RecordPrincipale.x, array[i].RecordPrincipale.c,
                   array[i].RecordPrincipale.W, array[i].RecordPrincipale.S,
                   array[i].FLAG == VOWELS ? "VOWELS" : "THREE");

            if (array[i].FLAG == VOWELS) {
                printf("%c\n", array[i].FLAG_DATA.q); // Stampa la vocale
            } else {
                if (array[i].FLAG_DATA.t == 2) {
                    printf("(Nessun elemento divisibile per tre)\n");
                } else {
                    printf("%d\n", array[i].FLAG_DATA.t); // Stampa il numero
                }
            }
        } else {
            printf("(Elemento non inizializzato)\n");
        }
    }

    // Libera la memoria allocata
    for (int i = 0; i < k; i++) {
        free(array[i].RecordPrincipale.W);
        free(array[i].RecordPrincipale.S);
    }

    return 0;
}

