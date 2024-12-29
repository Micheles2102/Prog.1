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
