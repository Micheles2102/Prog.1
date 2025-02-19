#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 20
#define MAX 50

typedef struct{
    char input_filename[LEN];
    char output_filename[LEN];
}Record;

typedef struct{
    char* nome;
    char* cognome;
    int eta;
    float altezza;
}Persona;


Record decodeParameters(int argc, char* argv[]){
    Record record;
    if(argc!=3){
        perror("Errore: il numero dei parametri non e' corretto\n");
        exit(1);
    }
    //if()

    int len1=strlen(argv[1]);
    int len2=strlen(argv[2]);

    if((strcmp(argv[1]+len1-4, ".txt"))!=0){
        perror("Errore: il file_1 non e' in formato .txt\n");
        exit(2);
    }
    if((strcmp(argv[2]+len2-4, ".txt"))!=0){
        perror("Errore: il file_2 non e' in formato .txt\n");
        exit(3);
    }

    strncpy(record.input_filename, argv[1], len1+1);
    strncpy(record.output_filename, argv[2], len2+1);

    return record;
}


int readHeader(FILE* file){
    char buffer[5];
    fgets(buffer, 5, file);
    int n=atoi(buffer);
    return n;
}

Persona* readFile(FILE* file, int n){
    Persona* array=(Persona*)malloc(n*sizeof(Persona));
    if(!array){
        perror("Errore nell'allocazione dell'array di strutture\n");
        exit(4);
    }

    for(int i=0; i<n; i++){
        array[i].nome=(char*)malloc(MAX*sizeof(char));
        if(!array[i].nome){
            perror("Errore nell'allocazione del nome\n");
            exit(5);
        }
        array[i].cognome=(char*)malloc(MAX*sizeof(char));
        if(!array[i].cognome){
            perror("Errore nell'allocazione del cognome\n");
            exit(6);
        }
    }

    int i=0;
    while(i<n && fscanf(file, "%s %s %d %f", array[i].nome, array[i].cognome, &array[i].eta, &array[i].altezza)!=EOF){
        i++;
    }

    return array;
}


int* extractAges(Persona* array, int n){
    int* array_Z=(int*)malloc(n*sizeof(int));
    if(!array_Z){
        perror("Errore nell'allocazione di array_Z\n");
        exit(7);
    }

    printf("L'array prima dell'ordinamento: ");
    for(int i=0; i<n; i++){
        array_Z[i]=array[i].eta;
        printf("%d ", array_Z[i]);
    }

    return array_Z;
}

int sortArray(int* array_z, int n){
    int variabile_moment=0;
    printf("\nL'array dopo l'ordinamento: ");

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(array_z[i]>array_z[j]){
                variabile_moment=array_z[i];
                array_z[i]=array_z[j];
                array_z[j]=variabile_moment;
            }
        }
        printf("%d ", array_z[i]);
    }
    
    
    return array_z[n/2];
}


float calculateAverageHeight(Persona* array, int mediana, int n){
    float Altezza=0.0;
    int count=0;
    float altezza_media=0.0;

    for(int i=0; i<n; i++){
        if(array[i].eta>mediana){
            Altezza+=array[i].altezza;
            count++;
        }
    }
    altezza_media=Altezza/count;

    return altezza_media;
}


int writeOutput(FILE* file,Persona* array, float media, int n){
    for(int i=0; i<n; i++){
        if(array[i].altezza>media){
            if(fprintf(file, "%s %s, Eta: <%d>, Altezza: <%.2f>\n", array[i].nome, array[i].cognome, array[i].eta, array[i].altezza)<0){
                perror("Errore nella scrittura del file output\n");
                return 1;
            }
        }
    }
    return 0;
}


int main(int argc, char* argv[]){
    Record parametri=decodeParameters(argc, argv);
    printf("%s %s\n", parametri.input_filename, parametri.output_filename);

    FILE* file_input=fopen(parametri.input_filename, "r");
    if(!file_input){
        fprintf(stderr, "Errore nell'apertura del file di input\n");
        EXIT_FAILURE;
    }
    int n=readHeader(file_input);
    printf("%d\n", n);

    Persona* persone=readFile(file_input, n);
    for(int i=0; i<n; i++){
        printf("%s %s %d %.2f\n", persone[i].nome, persone[i].cognome, persone[i].eta, persone[i].altezza);
    }

    int* array_Z=extractAges(persone, n);

    int mediana=sortArray(array_Z, n);
    printf("\nLa mediana e': %d\n", mediana);

    float media=calculateAverageHeight(persone, mediana, n);
    printf("L'altezza media e' di: %.2f\n", media);

    FILE* file_output=fopen(parametri.output_filename, "w");
    if(!file_output){
        fprintf(stderr, "Errore neòò'apertura del file di output\n");
        free(array_Z);

        for(int i=0; i<n; i++){
            free(persone[i].nome);
            free(persone[i].cognome);
        }
        free(persone);

        fclose(file_input);
        EXIT_FAILURE;
    }
    

    int output_controllo=writeOutput(file_output, persone, media, n);
    if(output_controllo==1){
        fclose(file_output);
        free(array_Z);
        
        for(int i=0; i<n; i++){
            free(persone[i].nome);
            free(persone[i].cognome);
        }
        free(persone);
    
        fclose(file_input);
        EXIT_FAILURE;
    }

    fclose(file_output);
    free(array_Z);

    for(int i=0; i<n; i++){
        free(persone[i].nome);
        free(persone[i].cognome);
    }
    free(persone);

    fclose(file_input);

    return 0;
}
