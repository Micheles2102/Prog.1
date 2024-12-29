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
