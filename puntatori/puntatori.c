#include <stdio.h>

int main(int argc, char* argv[]) {
    int x = 3;
    int y = 4;

    // 1) Inizializzazione di un puntatore
    // Tipologia dell'elemento che si sta puntando, deferenziatore (*) e nome puntatore = indirizzo di memoria della variabile
    int* ptr = &x; // all'inizio dobbiamo dire che il valore che ptr contiene deve essere l'indirizzo di x successivamente con *ptr andremmo a prendere IL CONTENUTO DI QUEL'INDIRIZZO
    printf("Il valore puntato da ptr è: %d\n", *ptr);

    // 2) Modifica del valore dell'elemento puntato
    *ptr = 5;  // Modifica il valore di x attraverso il puntatore
    printf("Il nuovo valore puntato da ptr è: %d\n", *ptr);

    // 3) Connessione tra puntatore ed elemento puntato
    printf("Il valore di x è: %d\n", x);
    *ptr = 8;
    printf("Dopo modifica tramite ptr, il valore di x è: %d\n", x);
    x = 12;
    printf("Dopo modifica diretta, il valore puntato da ptr è: %d\n", *ptr);

    // 4) Modifica dell'elemento puntato dal puntatore
    ptr = &y;  // Ora ptr punta a y
    printf("Il valore di x è: %d\n", x);
    printf("Il valore di y è: %d\n", y);
    *ptr = 7;  // Modifica il valore di y attraverso ptr
    printf("Dopo modifica tramite ptr, il valore di y è: %d\n", y);

    // 4.1) Puntatore nullo (NULL)
    // Un puntatore nullo è un puntatore che non punta a nessuna locazione di memoria valida.
    // In altre parole, un puntatore nullo è un puntatore che contiene l'indirizzo speciale 'NULL'.Punta a niente che è stato inizializzato.
    // È importante utilizzare i puntatori nulli per evitare errori di memoria e per indicare che un puntatore non è ancora stato inizializzato.

    int* ptrNull = NULL; // Puntatore nullo, non punta a nessuna variabile
    if (ptrNull == NULL) {
        printf("ptrNull è un puntatore nullo.\n");  // Mostra che ptrNull è nullo
    }

    // ATTENZIONE IMPORTANTE:
    //Non tentare mai di dereferenziare un puntatore nullo.
    // Se proviamo a dereferenziare ptrNull, il programma darà un errore (segmentation fault).
    // *ptrNull = 10; // ERRORE: Non è possibile dereferenziare un puntatore nullo! Bisogna prima fallo referenziare a qualcosa.
    // Attenzione quando si ha un puntatore costante ad un NULL (Quindi non possiamo modifica a ciò che il puntatore punta come vedremo in seguito)


    // 5) Puntatore a costante
    // Puntatore a costante: il valore puntato non può essere modificato
    const int* p = &x;
    // *p = 2; // ERRORE: non si può modificare il valore puntato
    p = &y;  // Si può cambiare l'indirizzo di memoria puntato
    printf("Puntatore a costante: il valore puntato è: %d\n", *p);

    // 6) Puntatore costante a una variabile
    // Puntatore costante: il puntatore non può cambiare indirizzo
    int* const prova = &x;
    *prova = 20;  // Modifica il valore di x
    printf("Puntatore costante: il valore di x è: %d\n", *prova);
    // prova = &y; // ERRORE: non si può cambiare l'indirizzo del puntatore

    // 7) Puntatore costante a una costante
    // Puntatore costante a una costante: né il valore puntato né l'indirizzo possono essere modificati
    const int* const finale = &x;
    printf("Puntatore costante a una costante: il valore puntato è: %d\n", *finale);
    // *finale = 30; // ERRORE: non si può modificare il valore puntato
    // finale = &y;  // ERRORE: non si può modificare l'indirizzo del puntatore

    // 8) Cenni sul passaggio per riferimento a una funzione
    // Il passaggio per riferimento permette di modificare i valori delle variabili direttamente all'interno della funzione.
    // Esempio completo nel file funzioni.c

    return 0;
}
