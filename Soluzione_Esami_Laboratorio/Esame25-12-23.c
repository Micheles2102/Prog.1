#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> //per potere utilizzare ispunct()
#define LUNGHEZZA_MASSIMA_STRINGA 20

typedef struct{
    char file_input[12];
    char file_output[12];
} NomiFile;

typedef struct{
    char* key;
    int len;
} Record;

NomiFile readInput(int argc,char* argv[]){
   
    if(argc!=3){
        perror("Errore, il numero di file passati è sbagliato");
        exit(1);//o EXIT_FAILURE
    }

    int len1=strlen(argv[1]);
    if(strncmp(argv[1]+len1-4,".txt",4)!=0){
        perror("Errore, il primo file passato non è txt");
        exit(2);
    }

    int len2=strlen(argv[2]);
    if(strncmp(argv[2]+len2-4,".bin",4)!=0){
        perror("Errore, il secondo file passato non è bin");
        exit(3);
    }

    NomiFile file;
    strncpy(file.file_input,argv[1],sizeof(argv[1])+2);
    strncpy(file.file_output,argv[2],sizeof(argv[2])+2);
   return file;
}

Record* buildArray(FILE* file){
    Record* array=(Record*) malloc(200 * sizeof(Record));
    if(!array){
        perror("Errore,creazione dell'array non riuscita");
        exit(4);
    }
    for(int i=0;i<200;i++){
        array[i].key=(char*) malloc(sizeof(char)* LUNGHEZZA_MASSIMA_STRINGA);
        if (!array[i].key) {
            perror("Errore allocazione memoria per array[i].key");
            exit(5);
        }
    }
    
    int i=0;
    while(i<200 && (fscanf(file,"%s",array[i].key)!=EOF)){
        array[i].len=strlen(array[i].key);
        i++;
    }

    while(i!=200){ //inizializzo i rimanenti elementi a -1. Se fscanf finisce prima di i<200 allora i restanti i elementi possono essere inizializzati a -1
        array[i].len=-1;
        i++;
    }

    return array;
}

int filter(Record* array){// si nota dal testo che le punteggiature sono sempre all'ultimo posto tranne ' che non è stata richiesta da togliere
    int i=0;
    printf("%d" ,array[i].len);
    while((array[i].len)!=-1){
        if(ispunct( array[i].key[array[i].len-1] )){
            array[i].key[array[i].len-1]='\0';
            array[i].len=strlen(array[i].key);
        }
        i++;
    }
    return i; //ci prendiamo quanti elementi ci sono in totale che sono parole (len!=)-1;
}

void createSet(Record* array,int parole_valide){
    int i=0;
    while(i!=parole_valide){
        for(int j=i+1;j<parole_valide;j++){//è più corretto fallo con due for in quanto sappiamo la dimensione ma mi volevo divertire(non cambia nulla )
            if(array[i].len!=-1){ //array[i].len!=-1 importante inserirlo per evitare che si elimino tutti le parole  
                if(strcmp(array[i].key,array[j].key)==0 ){
                    array[j].len=-1;
                }
            }
        }
        i++;
    }
}

void printArray(Record* array,int parole_valide){
    for(int i=0;i<parole_valide;i++){
        if(array[i].len!=-1){
         printf(" %s ",array[i].key);
        }
    }
    printf("\n");
}

int save(FILE* output,Record* array,int parole_valide){
    for(int i=0;i<200;i++){
        if (array[i].len != -1) {
            if(fwrite(array[i].key,sizeof(char), array[i].len + 1,output)!= array[i].len + 1){
                return -1;
            }
        } 
    }
    return 0;
}

int read(const char* output,int parole_valide){
    FILE* file= fopen(output,"rb");
    if(!file){
        return -1;
    }

    char buffer[LUNGHEZZA_MASSIMA_STRINGA];
    while (fread(buffer, sizeof(char),LUNGHEZZA_MASSIMA_STRINGA , file) > 0) {
        printf("%s ", buffer);
    }
    printf("\n");
    fclose(file);
    return 0;
}

int main(int argc,char* argv[]){
    NomiFile file_letti=readInput(argc,argv);
    printf("%s ,  %s", file_letti.file_input,file_letti.file_output);

    FILE* input=fopen(file_letti.file_input,"r");
    if(!input){
        fprintf(stderr,"Errore nell'apertura del file");
        return EXIT_FAILURE;
    }

    Record* array=buildArray(input);
    // for(int i=0;i<200;i++){
    //     printf(" %s ",array[i].key);
    // }

    int parole_valide=filter(array);
    // printf("\n");
    // printf("\n");
    // printf("\n");
    // for(int i=0;i<200;i++){
    //     printf(" %s ",array[i].key);
    //     printf(" %d ",array[i].len);
    // }

    createSet(array,parole_valide);
    printArray(array,parole_valide);

    FILE* output= fopen(file_letti.file_output,"wb");
    if(!output){
        fprintf(stderr,"Errore nell'apertura del file di output");
        fclose(input);
        for(int i=0;i<200;i++){
            free(array[i].key);
        }
        free(array);
        EXIT_FAILURE;
    }

    if(save(output,array,parole_valide)==-1){
        fprintf(stderr,"Errore nell'apertura del file di output 2.0");
        fclose(input);
        for(int i=0;i<200;i++){
            free(array[i].key);
        }
        free(array);
        EXIT_FAILURE;
    }

    if(read(file_letti.file_output,parole_valide)==-1){
        fprintf(stderr,"Errore nell'apertura del file di output 3.0");
        fclose(input);
        for(int i=0;i<200;i++){
            free(array[i].key);
        }
        free(array);
        EXIT_FAILURE;
    }
    fclose(input);
    for(int i=0;i<200;i++){
        free(array[i].key);
    }
    free(array);
}
