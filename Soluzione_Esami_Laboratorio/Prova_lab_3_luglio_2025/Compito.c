#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct{
    char file_input[20];
    char file_output[20];
    int k;
}Argomenti_main;

typedef struct{
    char codiceEvento[31]; //sapendo che il numero max di caratteri è 30 dobbiamo allocare pure per il carattere di terminazione '/0'
    char nomeLuogo[31];
    int CapienzaMax;
}Record;

typedef struct Nodo{
    Record record;
    struct Nodo* succ;
}Nodo;

Argomenti_main Readinput(char* argv[],int argc){    //funzione che effettua tutto i controlli necessari

    //importante: questo if deve essere primo se no si avrebbe un conflitto con gli altri argomenti qual'ora si passino meno argomenti
    if(argc!=4){ //controlliamo che stiamo effettivamente passando 4 elementi 
        perror("il numero di parametri passato e' diverso da quello richiesto per il funzionamento del programma");
        exit(4);
    }

    if(strcmp(argv[1],"data.bin")!=0){// controlla se il primo file risulta essere data.bin
        perror("Errore file .bin errato");
        exit(1);
    }

    if(strcmp(argv[2],"output.txt")!=0){//controlla se il secondo file risulta essere input.txt
        perror("Errore file .txt errato");
        exit(2);
    }
    
    for(int i=0;i<strlen(argv[3]);i++){ //strlen conta i caratteri prima del terminatore nullo quindi perfetto (controlliamo che k sia un intero)
        if(!isdigit(argv[3][i])){
            perror("Il valore k inserito risulta non essere un valore numerico o risulta essere diverso da un intero");
            exit(3);
        }
    }

    Argomenti_main argomenti_appoggio;
    strcpy(argomenti_appoggio.file_input,argv[1]);
    strcpy(argomenti_appoggio.file_output,argv[2]);
    argomenti_appoggio.k=atoi(argv[3]);

    return argomenti_appoggio;
}

Nodo* creazione_nodo(Record record){
    Nodo* nuovo=malloc(sizeof(Nodo));
    if(!nuovo){
        perror("errore nella creazione del nuovo nodo");
        exit(5);
    }
    nuovo->record=record;
    nuovo->succ=NULL;
    return nuovo;
}

Nodo* aggiungi_alla_lista(Nodo* lista,Record record){

    Nodo* nuovo=creazione_nodo(record);
    //se la lista non ha elementi o se codiceEvento è lessicamente più piccolo dell'elemento nella lista(in testa)
    if(!lista || strcmp(record.codiceEvento,lista->record.codiceEvento)<0){
        nuovo->succ=lista;
        return nuovo;//nuovo è come se diventasse la nuova lista ossia va in testa: nuovo -> lista 
    }
    
    Nodo* curr=lista;
    while(curr->succ && strcmp(record.codiceEvento,curr->record.codiceEvento)>0){
        curr=curr->succ;
    }
    nuovo->succ=curr->succ;
    curr->succ=nuovo;
    return lista;
}
//per leggere da un file binario utilizziamo fread e non fscanf che invece legge da file .txt ( legge file di tipo ASCI)
//size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
// //ptr → indirizzo del buffer (o struttura) dove verranno copiati i dati letti.

// size → dimensione in byte di ogni elemento da leggere.

// nmemb → numero di elementi da leggere.

// stream → puntatore al file aperto (FILE*), ottenuto con fopen.
Nodo* InsertRecord(char* file_input){
    FILE* file=fopen(file_input,"rb");
    if(!file){
        perror("Errore nell'apertura del fine di input");
        exit(5);
    }

    Nodo* lista=NULL;
    Record r;
    while(fread(&r,sizeof(r),1,file)==1){
        lista=aggiungi_alla_lista(lista,r);
    }
    fclose(file);
    return lista;
    
}

void printList(Nodo* lista){
    Nodo* curr=lista;
    while(curr){
        printf("%s %s %d\n",curr->record.codiceEvento,curr->record.nomeLuogo,curr->record.CapienzaMax);
        curr=curr->succ;
    }
}

void elab(char* file_output,Nodo* lista,int k){
    FILE* file=fopen(file_output,"w");
    if(!file){
        perror("Errore nell'apertura del fine di output");
        exit(6);
    }
    while(lista){
        if(lista->record.CapienzaMax>=k){
            fprintf(file,"%s %s %d\n",lista->record.codiceEvento,lista->record.nomeLuogo,lista->record.CapienzaMax);
        }
        lista=lista->succ;
    }
    fclose(file);
}

void liberaLista(Nodo* lista) {
    while (lista) {
        Nodo* temp = lista;
        lista = lista->succ;
        free(temp);
    }
}

int main(int argc,char* argv[]){
    
    Argomenti_main argomenti=Readinput(argv,argc);
    Nodo* lista=InsertRecord(argomenti.file_input);
    printf("** PrintList() **\n");
    printList(lista);
    elab(argomenti.file_output,lista,argomenti.k);
    liberaLista(lista);
    return 0;
}
