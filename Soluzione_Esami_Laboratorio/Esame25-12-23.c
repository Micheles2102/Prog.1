#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define Lunghezza_massima 20

//creazione record
typedef struct record{
    char key[Lunghezza_massima+1]; //si aggiunge il +1 per il terminatore
    int length;
}Record;


// Struttura per contenere i nomi dei file
typedef struct {
    char input_filename[40];
    char output_filename[40];
} NomiFile;

NomiFile readInput(int argc, char *argv[]) {
    NomiFile filenames;

    // Inizializzazione per evitare valori non definiti , memset( cosa vogliamo inizializzare, il valore da inizializzare, la lunghezza del tipo)
    memset(&filenames, 0, sizeof(NomiFile));

    if (argc != 3) {
        fprintf(stderr, "Errore: numero di argomenti errato.\n");
        fprintf(stderr, "Utilizzo: %s <file_input.txt> <file_output.bin>\n", argv[0]);
        exit(EXIT_FAILURE); // Uscita con codice di errore
    }

    // Copia i nomi dei file nella struttura, con controllo di overflow
    if (strlen(argv[1]) >= 40) {
        fprintf(stderr, "Errore: nome del file di input troppo lungo.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(filenames.input_filename, argv[1]);

    if (strlen(argv[2]) >= 40) {
        fprintf(stderr, "Errore: nome del file di output troppo lungo.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(filenames.output_filename, argv[2]);

    return filenames;
}

//Funzione che legge il testo contenuto nel file e crea l'array
int buildArray(FILE *file,Record *array){
    //siccome ora vogliamo leggere le stringhe contenute usando fgets alloco un buffer ( richiesto da fgets)
    char buffer[Lunghezza_massima+1];
    int parole_lette=0;
    
    while (fgets(buffer,sizeof(buffer),file)!= NULL){
        //se è presente eliminiamo il carattere per andare a capo con uno di terminazione 
        int len=strlen(buffer);
        if(len>0 && buffer[len-1]=='\n'){
            buffer[len - 1] = '\0';
        }
        strcpy(array[parole_lette].key,buffer);//in questa maniera copio la stringa 
        array[parole_lette].length=strlen(buffer);//cosi copio la lunghezza (sovrascrivendo dove necessario il -1)
        parole_lette++;
    }
    return parole_lette;
}
//funzione per pulire l'array(attenzione passo elemento per elemento quindi richiamo gli elementi di array con l'operatore .)
void filter(Record array){//ATTENZIONE vi pososno essere varie ottimizzazioni  ho cercato di prendere quella più semplice,un altra posisbilità è creare una copia della stringa e lavorare su quella
    int i,j=0;
    char c;//utile solo per rendere il codice più leggibile
    for(int i=0; array.key[i]!='\0';i++){ //fino a quando non trova un carattere di terminazione (potremmo andare anche con strlen(array[i].key))
        c=array.key[i];
        if(c!=',' && c!=';' && c!=':' && c!='.'){array.key[j++]=array.key[i];} //"sovrascrive " il vecchio valore se risulta essere un carattere speciale
    }
    array.key[j]='\0';
    array.length=strlen(array.key);
}

void createset(Record *array,int parole_lette){// uso parole_lette per indicare quelle che hanno length diverso da -1
    char buffer[20];
    for(int i=0;i<parole_lette;i++){
        strcpy(buffer,array[i].key);
        for(int j=0;j<parole_lette;j++){
            if(i==j){}//ovviamente togliamo il caso in cui si trova la stringa che si è utilizzata
            else{
                if(strcmp(buffer,array[j].key)==0){
                    array[j].length=-1;
                }
            }
        }
    }
    
}

void printArray(Record *array,int parole_lette){
    for(int i=0;i<parole_lette;i++){
        printf("%s\n",array[i].key);
    }
}

void  save(Record *array,int parole_lette,char *nomefilebin){
    FILE *fp = fopen(nomefilebin, "wb");
    if (fp == NULL) {
        perror("Errore nell'apertura del file");
        return;
    }

    for (int i = 0; i < parole_lette; i++) {
        if (fwrite(&array[i], sizeof(Record), 1, fp) != 1) {
            perror("Errore durante la scrittura sul file");
            fclose(fp);
            return;
        }
    }

    fclose(fp);
}

void read(char *filebin){
    FILE *fp = fopen(filebin, "rb");
    if (fp == NULL) {
        perror("Errore nell'apertura del file");
        return;
    }

    Record record;
    while (fread(&record, sizeof(Record), 1, fp) == 1) {
        printf("%s\n", record.key);
    }

    fclose(fp);
}

//prende in input : input.txt e elab.bin
int main(int argc,char* argv[]){

    NomiFile nomifile=readInput(argc,argv);  

    FILE *file=fopen(nomifile.input_filename,"r");
    if(file==NULL){
        perror("errore nell'apertura del file");
        return 1;
    }

    FILE *output_file = fopen(nomifile.output_filename, "wb"); // "wb" viene usato per scrittura binaria
    if (output_file == NULL) {
        perror("Errore apertura file di output");
        fclose(file); //chiudo il file txt
        return 1;
    }

    Record array[200];

    // Inizializzo la lunghezza di tutti a -1 poi modificherò quella opportuna quando troverà una stringa
    for (int i = 0; i < 200; i++) {
        array[i].length = -1; 
    }

    int parole_lette=buildArray(file,array);

    for(int i=0;i<parole_lette;i++){
        filter(array[i]);
    }
    createset(array,parole_lette);

    printArray(array,parole_lette);

    save(array,parole_lette,output_file);
    
    read(output_file);
    fclose(file);
    fclose(output_file);
    return 0;
}
