#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH_WORD 21
typedef struct 
{
    char input[11];
    char output[11];
}NomiFile;

typedef struct
{
    char key[MAX_LENGTH_WORD];
    int length;
}Record;


NomiFile readInput(int argc,char** argv){

    if(argc!=3){
        perror("Errore: Numeri di parametri passati");
        exit(1);
    }
    int len=strlen(argv[1]);
    if(len<1 && strcmp(argv[1]+strlen(argv[1])-4,".txt")!=0){ //argv[1] contiene il nome,sommando la lunghezza e sottraendo 4 andiamo a fare puntare al carattere . e controllerà tutti i caratteri
        perror("Errore: Il primo parametro passato non è un file .txt");
        exit(2);
    }
    len=strlen(argv[2]);
    if(len<1 && strcmp(argv[2]+strlen(argv[2])-4,".bin")!=0){
        perror("Errore: Il primo parametro passato non è un file .bin");
        exit(3);
    }

    NomiFile nomi_dei_file;
    strcpy(nomi_dei_file.input,argv[1]);
    strcpy(nomi_dei_file.output,argv[2]);

    return nomi_dei_file;
}

Record* buildArray(const char *input){

    FILE *fp = fopen(input, "r");
    if (fp == NULL) {
        perror("Errore apertura file input");
        exit(EXIT_FAILURE);
    }

    Record* array=(Record*) malloc(sizeof(Record)*200);
    if(array==NULL){
        perror("Errore durante la creazione dell'array");
        exit(5);
    }

    int i=0;
    while(i<200 && fscanf(fp,"%20s",array[i].key)==1){
        array[i].length=strlen(array[i].key);
        i++;
    }

    return array;
}

void filter(Record *array) {
    int j = 0;
    for (int i = 0; array->key[i] != '\0'; i++) {
        if (!ispunct(array->key[i])) { 
            array->key[j++] = array->key[i];
        }
    }
    array->key[j] = '\0';
    array->length = strlen(array->key);
}

void createSet(Record* array){
    for(int i=0;i<200;i++){
        if(array[i].length!=-1){
            for(int j=i+1;j<200;j++){
                if(strcmp(array[i].key,array[j].key)==0){
                    array[j].length=-1;
                }
            }
        }
    }
}

void printArray(Record *array) {
    for (int i = 0; i < 200; i++) {
        if (array[i].length > 0) {
            printf("%s ", array[i].key);
        }
    }
    printf("\n"); 
}

void save(char* file_bin,Record* array){
    FILE *file = fopen(file_bin, "wb");
    if (file == NULL) {
        perror("Errore nell'apertura del file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 200; i++) {
        if(array[i].length>0){
            if (fwrite(&array[i], sizeof(Record), 1, file) != 1) {
                perror("Errore durante la scrittura sul file");
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
    }
    fclose(file);
}

void read(const char* output){
    FILE *fp = fopen(output, "rb"); // Apertura in lettura binaria
    if (fp == NULL) {
        perror("Errore nell'apertura del file binario per la lettura");
        exit(EXIT_FAILURE);
    }
    Record record;
    while (fread(&record, sizeof(Record), 1, fp) == 1) {
        printf("%s ", record.key);
    }
    printf("\n");
    fclose(fp);
}

int main(int argc,char* argv[]){

    NomiFile nomi_file=readInput(argc,argv);

    Record* array_dati=buildArray(nomi_file.input);

    for(int i=0;i<200;i++){
        filter(&array_dati[i]);
        array_dati[i].length=strlen(array_dati[i].key);
    }
    
    createSet(array_dati);
    printArray(array_dati);
    int parole_non_eliminate=0;

    save(nomi_file.output,array_dati);

    read(nomi_file.output);
    
    free(array_dati);
}
