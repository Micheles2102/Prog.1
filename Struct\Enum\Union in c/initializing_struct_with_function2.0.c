/* Estendere l’esercizio initializing_struct_with_function.c con la definizione di una struttura
data che contenga un intero chiamato ID, ed un campo di tipo record definito
nel precedente esercizio (struttura annidata). ID andr`a inizializzato sempre con
numeri positivi.
All’interno della funzione main(), creare un un array di N elementi di tipo data,
ed inizializzare un numero k ≤ N di elementi di tale array, con k a piacere.
L’elemento successivo al k-esimo elemento dello array (se k < N), ovvero il
primo elemento “vuoto” sar`a distinguibile dagli altri perch`e ID == −1.
Codificare una funzione di inizializzazione che prenda in input l’indirizzo di un
elemento data, che faccia uso della funzione definita nel precedente esercizio, e
che sia in grado di assegnare ID univoci ad ogni elemento data.

Note: Ho lasciato i commenti dell'esercizio precedente ma vi consiglio di visionarlo da solo prima andando a vederlo.
*/


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
