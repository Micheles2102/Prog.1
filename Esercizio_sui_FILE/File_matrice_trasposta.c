/*  
1) Si generi una matrice di dimensione N × M – con N ed M a piacere –
di numeri double.
2) Si codifichi una funzione che prenda in input la matrice e crei un file
contenente tale matrice in formato testo. In particolare, la prima riga di
tale file dovr`a contenere i due numeri N ed M.
3) Si codifichi una funzione in grado di leggere un file come quello creato
al punto precedente e quindi di caricare una tale matrice in memoria.
4) Si codifichi una ulteriore funzione che, data una matrice N × M, ne
calcoli la sua trasposta.
5) Si usi infine la funzione codificata al punto due per salvare tale
matrice trasposta su file.

*/

#include <stdio.h>
#include <stdlib.h>
#define N 3
#define M 2

int creazione_file(double R[N][M],const char *nome_file){
    FILE *file=fopen(nome_file,"w");//apriamo il file in modalità scrittura
    if(file==NULL){ //controlliamo che si è aperto correttamente
      perror("Il file non si è aperto correttamento");
      return 1;
    }
    fprintf(file,"%d %d\n",N,M);//questo permette di scrivere N e M sulla prima riga

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            fprintf(file, "%lf ", R[i][j]); // questo invece permette di scrivere all'inerno del file la matrice
        }
        fprintf(file, "\n");//per scriverla ordinata
    }

    fclose(file); //ricordiamo di chiudere sempre un file che viene aperto
    return 0;
}

//questa funzione è uguale a quella sopra ma con la differenza che questa prende R allocata dinamicamente
//ATTENZIONE ESSENDO CHE QUEST'ULTIMA é USATA NELLA TRASPOSTA BISOGNA INVERTIRE N CON M SE NO SEGMENTATION FAULT
int creazione_file_dinamico(double **R,const char *nome_file){
    FILE *file=fopen(nome_file,"w");//apriamo il file in modalità scrittura
    if(file==NULL){ //controlliamo che si è aperto correttamente
      perror("Il file non si è aperto correttamento");
      return 1;
    }
    fprintf(file,"%d %d\n",M,N);//questo permette di scrivere N e M sulla prima riga

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            fprintf(file, "%lf ", R[i][j]); // questo invece permette di scrivere all'inerno del file la matrice
        }
        fprintf(file, "\n");//per scriverla ordinata
    }

    fclose(file); //ricordiamo di chiudere sempre un file che viene aperto
    return 0;
}

double** matrice_letta_da_file(char *nome_file){
    FILE *file=fopen(nome_file,"r");
    if(file==NULL){ //controlliamo che si è aperto correttamente
      perror("Il file non si è aperto correttamento");
      return NULL;
    }

    int n, m;
    if (fscanf(file, "%d %d\n", &n, &m) != 2) { //fscanf prende il file legge i dati e li memorizza nelle variabili passate(in questo caso n e m)(!=2 serve a verifiare la lettura di due esatti valori)
        fprintf(stderr,"Errore lettura dimensioni matrice\n");
        fclose(file);
        return NULL;
    }
    
    //inizio ad allocare la matrice(ovviamente con allocazione dinamica se no non potrò usarla nel main)
    //non ho posto controlli ma verificate sempre che crei nell'effettivo degli elementi non NULL 
    double **matrice_nuova=(double **)malloc(n*sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrice_nuova[i] = (double *)malloc(m * sizeof(double));
        for (int j = 0; j < m; j++) {
            fscanf(file, "%lf ", &matrice_nuova[i][j]);
        }
    }
    
    fclose(file);
    return matrice_nuova;
}

// Funzione per calcolare la trasposta
double **calcola_trasposta(double **matrice) {
    //anche in questo caso alloco dinamicamente
    double **trasposta = (double **)malloc(M * sizeof(double *));
    for (int i = 0; i < M; i++) {
        trasposta[i] = (double *)malloc(N * sizeof(double));
        if (trasposta[i] == NULL) { //in questo caso ho lasciato un esempio di controllo 
            perror("Errore allocazione riga trasposta");
            for(int k=0; k<i; k++){
                free(trasposta[k]);
            }
            free(trasposta);
            return NULL;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            trasposta[j][i] = matrice[i][j]; //guardare il file readme per sapere meglio che cos'è una matrice trasposta
        }
    }
    return trasposta;
}


//Nel main ho lasciato i controlli per maggiore sicurezza e per fare vedere esempi di controllo
int main(){

  double matrice[N][M];
  for (int i = 0; i < N; i++) {
       for (int j = 0; j < M; j++) {
           matrice[i][j] = (double)rand() / RAND_MAX * 25.0; 
       }
   }
     if ( creazione_file(matrice,"matrice.txt") != 0) {  // Gestisci l'errore se la scrittura su file fallisce
        return 1;
    }

    double **matrice_letta = matrice_letta_da_file("matrice.txt");
    if(matrice_letta == NULL){
        perror("errore nella creazione della matrice da file");
        return 1;
    }

    double **trasposta = calcola_trasposta(matrice_letta);
    if(trasposta==NULL){
        for(int k=0; k<N; k++){
                free(matrice_letta[k]);
            }
            free(matrice_letta);
        return 1;
    }

    if(creazione_file_dinamico(trasposta, "trasposta.txt") != 0) {
        // Gestisci l'errore se la scrittura su file fallisce
         for(int k=0; k<N; k++){
                free(matrice_letta[k]);
            }
            free(matrice_letta);
        for(int k=0; k<M; k++){
                free(trasposta[k]);
            }
            free(trasposta);
        return 1;
    }

    // Liberiamo la memoria di tutti gli elementi allocati fino ad adesso
    for (int i = 0; i < N; i++) {
        free(matrice_letta[i]);
    }
    free(matrice_letta);
    for(int i=0; i<M; i++){
        free(trasposta[i]);
    }
    free(trasposta);

    printf("Operazioni completate.\n");

    return 0;
}
