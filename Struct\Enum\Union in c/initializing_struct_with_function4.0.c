/* Estendere il precedente esercizio con la modifica del tipo data in modo che
includa anche un campo di tipo union di nome FLAG DATA. La union
(assegnare al tipo union un nome a piacere) sar`a composta di un campo
unsigned short ed un campo char.
Codificare una opportuna funzione che prenda in input l’array di elementi di
tipo data per modificare ognuno di questi nel seguente modo: se
FLAG=VOWELS, allora pone in FLAG DATA la prima vocale presente nel campo S,
altrimenti se FLAG=THREE pone in FLAG DATA il primo numero divisibile per tre
presente nel campo W.



Note: Ho lasciato i commenti dell'esercizio precedente ma vi consiglio di visionarlo da solo prima andando a vederlo.
Note: Ho applicato nella funzione inizializzazioneData un piccolo trick con l'uso della tabella ascii infatti, W è una stringa che va da 0 a 9 
nell if sottraggo '0' che rappresenta in ASCII il valore 48.
W avrà al suo interno vari valori come ad esempio il 9 che risulta essere il 57 dunque facendo:
ptr->RecordPrincipale.W[i] - '0'
sto praticamente facendo 57-48=9 e controllo se quest'ultimo è divisibile per tre
//ATTENZIONE nella funzione inizializzazioneData nel primo_numero_divisibile ho considerato l'ipotesi in cui non trovi un numero divisibile come =2 in quanto essendo 
unsigned short non potevo mettere valori come -1 (lo si può mettere ma otteniamo 65536 come valore fisso).Inoltre essendo che deve tornare il primo numero divisibile per tre
questo ci dirà che non esistono numeri divisibili per tre(basti guardare l'if nel main nella stampa di FLAG_DATA)
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

union nome2{
    unsigned short t;
    char q;
};


typedef struct data{
    int ID;
    struct record RecordPrincipale;
    enum nome FLAG;
    union nome2 FLAG_DATA;
}Data;

//Modifico la precedente funzione inizializzazioneData
void inizializzazioneData(struct data *ptr,int i){
    ptr->ID=i;
    inizializzazione(&ptr->RecordPrincipale);//PRIMA FACCIAMO ALLOCARE W E S SE NO ANDREBBE IN SEGMENTATION FAULT
    int elementi_divisibili=0;
    unsigned short primo_numero_divisibile=2;//lo pongo a 2 per segnalare quando non ci sono numeri divisibili per 3
    for(int i=0;i<strlen(ptr->RecordPrincipale.W);i++){
       if ((ptr->RecordPrincipale.W[i] - '0') % 3 == 0) { //controlla se è divisibile per 3 (ho applicato un trick con la conversione ascii)
           if(primo_numero_divisibile==2){primo_numero_divisibile=ptr->RecordPrincipale.W[i] - '0';;}
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
        ptr->FLAG_DATA.q=ptr->RecordPrincipale.S[0];
    }
    else{ptr->FLAG=THREE;ptr->FLAG_DATA.t=primo_numero_divisibile;}

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
            printf("x = %f, c = %c, W = %s, S = %s, FLAG = %s, FLAG_DATA = ",
                   array[i].RecordPrincipale.x, array[i].RecordPrincipale.c,
                   array[i].RecordPrincipale.W, array[i].RecordPrincipale.S,
                   array[i].FLAG == VOWELS ? "VOWELS" : "THREE");

            if (array[i].FLAG == VOWELS) {
                printf("%c\n", array[i].FLAG_DATA.q); // Stampa il carattere
            } else {
                if(array[i].FLAG_DATA.t==2){
                    printf("(Nessun elemento divisibile per tre)\n");
                }
                else
                    printf("%d\n", array[i].FLAG_DATA.t); // Stampa il numero
            }
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
