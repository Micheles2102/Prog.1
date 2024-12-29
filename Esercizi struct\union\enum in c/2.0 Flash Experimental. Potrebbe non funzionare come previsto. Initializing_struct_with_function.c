/* Definire una struttura (struct) record che contenga un numero in virgola
mobile, un carattere e due puntatori a caratteri S ed W (due stringhe).
Codificare una funzione che prenda in input un puntatore ad una tale struttura
e che sia in grado di inizializzare la struttura con elementi pseudo-casuali. In
particolare il campo W dovr`a essere inizializzato con caratteri appartenenti
all’insieme [0-9], il campo S con caratteri in nell’insieme [a-z].
Invocare opportunamente la funzione all’interno della funzione main.

Note: Per potere svolgere questo esercizio è buona norma conoscere un tantino la codifica ASCII 
Ps: si richiede che S e W siano stringhe io le ho allocate come se fossero di lunghezza 2
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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


int main (){

    srand(time(0));
    struct record rec;
    inizializzazione(&rec);
    printf("Il valore di x in record e': %f\n", rec.x);
    printf("Il valore di c in record e': %c\n", rec.c);
    printf("Il valore di W in record e': %s\n", rec.W);
    printf("Il valore di S in record e': %s\n", rec.S);
    //ricordiamoci di libierare la memoria usata
    free(rec.W);
    free(rec.S);
    
    return 0;
}
