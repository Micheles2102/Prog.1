#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RECORDS 200
#define MAX_STR_LEN 20
#define PATH_LEN 100

typedef struct {
    char file_input[PATH_LEN];
    char file_output[PATH_LEN];
} NomiFile;

typedef struct {
    char key[MAX_STR_LEN + 1];
    int len;
} Record;

// A. Gestisce argc e argv, verifica i parametri e restituisce i nomi dei file
NomiFile readInput(int argc, char* argv[]) {
    NomiFile files;
    if (argc != 3) {
        fprintf(stderr, "Errore: specificare <input.txt> <output.bin>\n");
        exit(EXIT_FAILURE);
    }

    int len1 = strlen(argv[1]);
    int len2 = strlen(argv[2]);

    if (len1 < 4 || strcmp(argv[1] + len1 - 4, ".txt") != 0) {
        fprintf(stderr, "Errore: il file di input deve avere estensione .txt\n");
        exit(EXIT_FAILURE);
    }
    if (len2 < 4 || strcmp(argv[2] + len2 - 4, ".bin") != 0) {
        fprintf(stderr, "Errore: il file di output deve avere estensione .bin\n");
        exit(EXIT_FAILURE);
    }

    strncpy(files.file_input, argv[1], PATH_LEN - 1);
    files.file_input[PATH_LEN - 1] = '\0';
    strncpy(files.file_output, argv[2], PATH_LEN - 1);
    files.file_output[PATH_LEN - 1] = '\0';

    return files;
}

// B. Legge le stringhe dal file e le memorizza in un array di 200 record
void buildArray(FILE* file, Record* array) {
    int i = 0;
    char buffer[100]; // Buffer temporaneo per leggere parole potenzialmente lunghe

    while (i < MAX_RECORDS && fscanf(file, "%s", buffer) != EOF) {
        // Tronchiamo la parola se supera i 20 caratteri come da specifica
        strncpy(array[i].key, buffer, MAX_STR_LEN);
        array[i].key[MAX_STR_LEN] = '\0';
        array[i].len = (int)strlen(array[i].key);
        i++;
    }

    // I record in eccesso devono essere inizializzati con length = -1
    while (i < MAX_RECORDS) {
        array[i].len = -1;
        array[i].key[0] = '\0';
        i++;
    }
}

// C. Elimina la punteggiatura (,, ;, :, .) dalle parole e aggiorna il campo length
void filter(Record* array) {
    for (int i = 0; i < MAX_RECORDS; i++) {
        if (array[i].len > 0) {
            int write_idx = 0;
            for (int read_idx = 0; array[i].key[read_idx] != '\0'; read_idx++) {
                char c = array[i].key[read_idx];
                if (c != ',' && c != ';' && c != ':' && c != '.') {
                    array[i].key[write_idx++] = c;
                }
            }
            array[i].key[write_idx] = '\0';
            array[i].len = write_idx;
            
            // Se dopo il filtro la parola è vuota, la consideriamo nulla
            if (array[i].len == 0) array[i].len = -1;
        }
    }
}

// D. Elimina i record duplicati valorizzando length = -1
void createSet(Record* array) {
    for (int i = 0; i < MAX_RECORDS; i++) {
        if (array[i].len <= 0) continue;

        for (int j = i + 1; j < MAX_RECORDS; j++) {
            if (array[j].len > 0 && strcmp(array[i].key, array[j].key) == 0) {
                array[j].len = -1;
            }
        }
    }
}

// E. Stampa a video tutti i record "non vuoti" (con length > 0)
void printArray(Record* array) {
    printf("\n--- Visualizzazione Record Validi (len > 0) ---\n");
    for (int i = 0; i < MAX_RECORDS; i++) {
        if (array[i].len > 0) {
            printf("[%s, %d] ", array[i].key, array[i].len);
        }
    }
    printf("\n");
}

// F. Salva i record nel file binario utilizzando fwrite()
int save(Record* array, const char* nome_file) {
    FILE* file = fopen(nome_file, "wb");
    if (!file) return -1;

    for (int i = 0; i < MAX_RECORDS; i++) {
        if (array[i].len > 0) {
            // Scacciamo l'intera struct per garantire la simmetria di lettura
            if (fwrite(&array[i], sizeof(Record), 1, file) != 1) {
                fclose(file);
                return -1;
            }
        }
    }
    fclose(file);
    return 0;
}

// G. Legge il file binario e ne stampa il contenuto (deve essere identico all'output E)
int read(const char* nome_file) {
    FILE* file = fopen(nome_file, "rb");
    if (!file) return -1;

    printf("\n--- Contenuto letto dal File Binario (G) ---\n");
    Record temp;
    while (fread(&temp, sizeof(Record), 1, file) == 1) {
        printf("[%s, %d] ", temp.key, temp.len);
    }
    printf("\n");

    fclose(file);
    return 0;
}

int main(int argc, char* argv[]) {
    // A. Analisi Input
    NomiFile files = readInput(argc, argv);
    printf("Input: %s | Output: %s\n", files.file_input, files.file_output);

    FILE* file_in = fopen(files.file_input, "r");
    if (!file_in) {
        fprintf(stderr, "Errore: Impossibile aprire il file di input '%s'\n", files.file_input);
        exit(EXIT_FAILURE);
    }

    Record array[MAX_RECORDS];

    // B. Costruzione Array
    buildArray(file_in, array);
    fclose(file_in);

    // C. Filtro Punteggiatura
    filter(array);

    // D. Rimozione Duplicati
    createSet(array);

    // E. Stampa a video
    printArray(array);

    // F. Salvataggio Binario
    if (save(array, files.file_output) != 0) {
        fprintf(stderr, "Errore: Fallimento durante il salvataggio in %s\n", files.file_output);
        exit(EXIT_FAILURE);
    }

    // G. Lettura Binaria e verifica
    if (read(files.file_output) != 0) {
        fprintf(stderr, "Errore: Fallimento durante la lettura di %s\n", files.file_output);
        exit(EXIT_FAILURE);
    }

    return 0;
}
