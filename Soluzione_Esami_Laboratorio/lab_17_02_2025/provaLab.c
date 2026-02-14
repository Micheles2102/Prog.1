#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
#define LEN 100

typedef struct {
    char input_filename[LEN];
    char output_filename[LEN];
} Record;

typedef struct {
    char* nome;
    char* cognome;
    int eta;
    float altezza;
} Persona;

// Funzione per liberare la memoria di un array di strutture Persona
void freePersone(Persona* array, int n) {
    if (array == NULL) return;
    for (int i = 0; i < n; i++) {
        free(array[i].nome);
        free(array[i].cognome);
    }
    free(array);
}

Record decodeParameters(int argc, char* argv[]) {
    Record record;
    if (argc != 3) {
        fprintf(stderr, "Errore: il numero dei parametri non e' corretto\n");
        exit(EXIT_FAILURE);
    }

    int len1 = strlen(argv[1]);
    int len2 = strlen(argv[2]);

    // Sicurezza: controllo lunghezza minima per estensione .txt
    if (len1 < 4 || strcmp(argv[1] + len1 - 4, ".txt") != 0) {
        fprintf(stderr, "Errore: il file_1 '%s' non e' in formato .txt\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (len2 < 4 || strcmp(argv[2] + len2 - 4, ".txt") != 0) {
        fprintf(stderr, "Errore: il file_2 '%s' non e' in formato .txt\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    strncpy(record.input_filename, argv[1], LEN - 1);
    record.input_filename[LEN - 1] = '\0';
    strncpy(record.output_filename, argv[2], LEN - 1);
    record.output_filename[LEN - 1] = '\0';

    return record;
}

int readHeader(FILE* file) {
    int n;
    if (fscanf(file, "%d", &n) != 1) {
        fprintf(stderr, "Errore nella lettura della dimensione n\n");
        return -1;
    }
    return n;
}

Persona* readFile(FILE* file, int n) {
    Persona* array = (Persona*)malloc(n * sizeof(Persona));
    if (!array) {
        perror("Errore nell'allocazione dell'array di strutture\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        array[i].nome = (char*)malloc(MAX * sizeof(char));
        array[i].cognome = (char*)malloc(MAX * sizeof(char));
        
        if (!array[i].nome || !array[i].cognome) {
            perror("Errore nell'allocazione di nome o cognome\n");
            // Libero il parzialmente allocato prima di uscire
            freePersone(array, i); 
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%s %s %d %f", array[i].nome, array[i].cognome, &array[i].eta, &array[i].altezza) != 4) {
            fprintf(stderr, "Errore nel formato dei dati alla riga %d\n", i + 2);
            freePersone(array, n);
            exit(EXIT_FAILURE);
        }
    }

    return array;
}

int* extractAges(Persona* array, int n) {
    int* array_z = (int*)malloc(n * sizeof(int));
    if (!array_z) {
        perror("Errore nell'allocazione di array_Z\n");
        return NULL;
    }

    printf("L'array prima dell'ordinamento: ");
    for (int i = 0; i < n; i++) {
        array_z[i] = array[i].eta;
        printf("%d ", array_z[i]);
    }
    printf("\n");
    return array_z;
}

int sortArray(int* array_z, int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array_z[i] > array_z[j]) {
                temp = array_z[i];
                array_z[i] = array_z[j];
                array_z[j] = temp;
            }
        }
    }

    printf("L'array dopo l'ordinamento: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array_z[i]);
    }
    printf("\n");

    return array_z[n / 2];
}

float calculateAverageHeight(Persona* array, int mediana, int n) {
    float somma_altezze = 0.0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (array[i].eta > mediana) {
            somma_altezze += array[i].altezza;
            count++;
        }
    }

    if (count == 0) return 0.0;
    return somma_altezze / count;
}

int writeOutput(FILE* file, Persona* array, float media, int n) {
    for (int i = 0; i < n; i++) {
        if (array[i].altezza > media) {
            if (fprintf(file, "%s %s, Età: %d, Altezza: %.2f\n", 
                array[i].nome, array[i].cognome, array[i].eta, array[i].altezza) < 0) {
                perror("Errore nella scrittura del file output\n");
                return -1;
            }
        }
    }
    return 0;
}

int main(int argc, char* argv[]) {
    Record parametri = decodeParameters(argc, argv);
    printf("Input: %s | Output: %s\n", parametri.input_filename, parametri.output_filename);

    FILE* file_input = fopen(parametri.input_filename, "r");
    if (!file_input) {
        fprintf(stderr, "Errore nell'apertura del file di input '%s'\n", parametri.input_filename);
        exit(EXIT_FAILURE);
    }

    int n = readHeader(file_input);
    if (n <= 0) {
        fprintf(stderr, "Dimensione n non valida o file vuoto.\n");
        fclose(file_input);
        exit(EXIT_FAILURE);
    }
    printf("Dimensione array: %d\n", n);

    Persona* persone = readFile(file_input, n);
    fclose(file_input);

    printf("Dati letti:\n");
    for (int i = 0; i < n; i++) {
        printf("- %s %s, %d anni, %.2f m\n", persone[i].nome, persone[i].cognome, persone[i].eta, persone[i].altezza);
    }

    int* array_z = extractAges(persone, n);
    if (!array_z) {
        freePersone(persone, n);
        exit(EXIT_FAILURE);
    }

    int mediana = sortArray(array_z, n);
    printf("Età mediana: %d\n", mediana);

    float media = calculateAverageHeight(persone, mediana, n);
    printf("Altezza media (> mediana): %.2f\n", media);

    FILE* file_output = fopen(parametri.output_filename, "w");
    if (!file_output) {
        fprintf(stderr, "Errore nell'apertura del file di output '%s'\n", parametri.output_filename);
        free(array_z);
        freePersone(persone, n);
        exit(EXIT_FAILURE);
    }

    if (writeOutput(file_output, persone, media, n) != 0) {
        fclose(file_output);
        free(array_z);
        freePersone(persone, n);
        exit(EXIT_FAILURE);
    }

    printf("Risultati scritti in %s correttamente.\n", parametri.output_filename);

    // Cleanup finale
    fclose(file_output);
    free(array_z);
    freePersone(persone, n);

    return 0;
}
