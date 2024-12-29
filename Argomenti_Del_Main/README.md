# Utilizzo degli Argomenti del Main in C (`argc` e `argv`)

Questo esempio dimostra come utilizzare gli argomenti passati al programma da riga di comando in C, tramite i parametri `argc` e `argv` della funzione `main`.

## Concetti Chiave

*   `argc` (argument count): Un intero che rappresenta il numero di argomenti passati al programma. Questo numero *include sempre* il nome del programma stesso.
*   `argv` (argument vector): Un array di puntatori a caratteri (stringhe). Ogni elemento di `argv` contiene un argomento passato al programma. `argv[0]` contiene sempre il nome del programma eseguito.

## Codice di Esempio

```c
#include <stdlib.h>
#include <stdio.h>

//il main è possibile vederlo come una funzione speciale e come tale vi sono dei parametri che possono essergli passati
//ma quali sono questi parametri? sono passati dal terminale quando eseguiamo il (nome_del_file).exe 

//int argc---> indica quanti elementi sono stati passati dal main( attenzione che il file stesso viene considerato)
//char* argv[]---> array di stringhe spesos usato per passare ad esempio nomi di file su cui bisogna lavorare(anche in questo caso il file stesso.exe viene considerato come prima stringa)

//facciamo finta di passare da terminale 2 5 "cartone"
//per compilare:
// gcc argomenti_main.c -o argomenti
// .\argomenti.exe 2 5 "cartone"
int main(int argc,char* argv[]){
    //verifichiamo che abbiamo passato un numero di elementi pari a quelli che volevamo (quindi 3)
    if(argc!=4){//ho detto 3 ma qui controlliamo per 4 in quanto dobbiamo considerare il nome_file.exe come primo valore
        perror("Errore nel passaggio dei valori"); 
        return 1;
    }    
    int variabili_passati=argc;

    //mettiamo caso che vogliamo sommare i primi due numeri
    int primo_argomento= atoi(argv[1]); // RICORDO CHE argv[0] ci restituisce argomenti.exe
    int secondo_argomento=atoi(argv[2]);

    printf("La somma dei due argomenti e':%d",primo_argomento+secondo_argomento);

    //mettiamo caso di volere creare un file con il nome che abbiamo passato

    FILE *file=fopen(argv[3],"w");
    if (file == NULL) {
    perror("Errore nell'apertura del file");
     return 1;
    }
    //faccio quello che devo fare ....
    fclose(file);
return 0;
}
