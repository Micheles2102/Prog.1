#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Struct --> composto di un insieme di dati comunemente detti record, contenenti variabili di tipo diverso
// In questo caso sono definite globalmente (DA EVITARE, vedi spiegazione nel main)

// ATTENZIONE: GLI ELEMENTI NELLA STRUCT NON DEVONO ESSERE INIZIALIZZATI NELLA DEFINIZIONE DELLA STRUCT, MA SOLO QUANDO LA SI RICHIAMA
struct esame {
    char* nome;
    short voto;
    char* data;
    struct esame *next; // POSSO AUTORICHIAMARE LA STRUCT (TRUCCHETTO USATO AD ESEMPIO PER USARE STRUTTURE DATI COLLEGATE, come le liste concatenate)
} prog1, prog2, strutture; // Dichiarazione di variabili globali di tipo struct esame (SCONSIGLIATO)

// Guardare il main fino a riga 57 prima di leggere le seguenti struct e puntatore a funzione
struct macchina {
    char* modello;
    int (*chilometri)(struct macchina *car); // Attenzione: *chilometri risulta essere il nome del puntatore a funzione
};
// Attenzione: la struct e la funzione devono avere lo stesso tipo di ritorno

int giri_motore(struct macchina *car) {
    if (strcmp(car->modello, "Ferrari") == 0) {
        return 10000; // Valore di esempio
    }
    return 0;
}

// Crea una struct come se fosse un tipo primitivo (con typedef)
typedef struct esami {
    struct esame *esame1;
    struct esame *esame2;
    struct esame *esame3;
    int x;
} Esami_universita; // In questo modo ho creato un alias di tipo, quindi basterà richiamare il nome Esami_universita

// Un'enumerazione o enum è un tipo di dato che assume un valore tra un insieme di nomi definiti in essa:
// La cosa fantastica dell'enum è che il suo scope si "unisce" a quello dove è stata dichiarata
enum Materie_da_dare {
    Algoritmi,          // NON SI POSSONO CREARE DUE ENUM CON DATI ANALOGHI, SI ANDREBBE IN NAME CLASH (conflitto di nomi)
    Strutture,
    Reti,
    Sistemi_operativi,
};
// Posso anche definire da quale valore partono
enum Materie_da_dare2 {
    Prog1 = 3,          // NON SI POSSONO CREARE DUE ENUM CON DATI ANALOGHI, SI ANDREBBE IN NAME CLASH (conflitto di nomi)
    Prog2,              // 4
    Ottimizazione,      // 5
    Fondamenti = 23,
    Analisi1,           // 24
};

// UNION
// La Union permette di risparmiare spazio in memoria: a un record possono essere indirizzati diversi valori, ma esso ne conterrà solo uno alla volta.
union Rinuncia {
    char* rinuncia;
    char* ci_sto;
    int tasse;
};
// Da notare la separazione mediante ; e non , come nell'enum

int main(int argc, char* argv[]) {
    // Esistono 3 modi per poter inizializzare la struttura

    struct esame strutture = {0}; // Tutto a zero. Ovviamente nelle stringhe significherà stringa vuota (NULL)
    struct esame prog2 = {"Prog2", 29, "25/07/2099", NULL}; // Inizializzazione completa, incluso next a NULL
    struct esame algoritmi = {.nome = "algoritmi", .voto = 30}; // Si adopera l'operatore . (inizializzazione designata)
    // Nel caso in cui creiamo la struct strutture = {0} per poi inizializzare i vari valori, usiamo sempre l'operatore .
    strutture.voto = 23;
    strutture.data = "23/2/2145";
    strutture.nome = "Strutture";

    // ATTENZIONE: QUI STO INIZIALIZZANDO LA STRUCT *INTERNA* (next), MA NON HO ALLOCATO LA MEMORIA PER ESSA! QUESTO CAUSERÀ UN ERRORE (Segmentation fault)
    // strutture.next->data = "23/3/2148"; // ERRORE!

    // Esempio corretto con allocazione dinamica:
    strutture.next = (struct esame*)malloc(sizeof(struct esame));
    if (strutture.next == NULL) { // Controllo se l'allocazione è andata a buon fine
        perror("Errore nell'allocazione di memoria");
        return 1; // Esci dal programma con codice di errore
    }
    strutture.next->data = "23/3/2148";

    // Si noti che dall'esempio precedente il puntatore alla struttura successiva viene inizializzato passando dalla prima struct e usando l'operatore ->
    // Se provate ad usare strutture.next.data noterete che il secondo punto lo convertirà da solo in -> (se non lo fa, probabilmente è legato a qualche estensione - imparate bene questa cosa)
    // COSA MOLTO IMPORTANTE:
    // Nel nostro esempio ho usato una struct nel data (quindi globale), ma possiamo creare una struct pure dentro le funzioni ad esempio (ovviamente l'accessibilità di quest'ultima è racchiusa nello stack della funzione)
    struct puntatori {
        int x;
        float y;
    };
    // In caso di dubbi sull'allocazione dinamica vedere file allocazioni.c
    // In questo caso ovviamente dobbiamo castare al tipo, che risulta essere nell'effettivo struct puntatori
    struct puntatori *ptr = (struct puntatori*)malloc(sizeof(struct puntatori));
        if (ptr == NULL) { // Controllo se l'allocazione è andata a buon fine
        perror("Errore nell'allocazione di memoria");
        return 1; // Esci dal programma con codice di errore
    }
    // Per accedere utilizzeremo l'operatore ->
    ptr->x = 3;
    ptr->y = 2.3;

    // PROVIAMO A COLLEGARE DUE STRUCT usando puntatori a funzione....

    struct macchina ferrari;
    ferrari.modello = "Ferrari";
    ferrari.chilometri = giri_motore; // Imposto i chilometri di ferrari con la funzione (quindi il puntatore a funzione racchiuso nella struct "richiamerà la funzione e gli affiderà un valore")
    int giri = ferrari.chilometri(&ferrari); // In questo modo mi stampo il valore (ricordando che stiamo richiamando un puntatore a funzione, dovremmo pure passare l'indirizzo della struct che ci interessa)

    // Studio della typedef struct
    Esami_universita esami_catania; // Sto creando una variabile col nome esami_catania di tipo Esami_università
    // ATTENZIONE: anche qui, esami_catania.esame1 non è stato allocato!
    esami_catania.esame1 = (struct esame*)malloc(sizeof(struct esame));
        if (esami_catania.esame1 == NULL) { // Controllo se l'allocazione è andata a buon fine
        perror("Errore nell'allocazione di memoria");
        return 1; // Esci dal programma con codice di errore
    }
    esami_catania.esame1->data = "3/8/2923"; // Ora è corretto

    // Usiamo l'enum (buon uso nello switch)
    enum Materie_da_dare reti = Reti;
    reti = Algoritmi;
    // Attenzione: l'enum può convertire da int alla tipologia adeguata. Ad esempio, se dovessi chiamare
    enum Materie_da_dare strutture_dio = 1; // ATTENZIONE: PARTE DA 0, quindi strutture sarà al posto 1 (corretto)
    int materia_che_mi_danna = strutture_dio; // Posso passarglielo
    printf("Valore di strutture_dio: %d\n", materia_che_mi_danna);

    // ATTENZIONE: NEL CASO IN CUI AVESSIMO DUE STRUCT ED USIAMO LA CONVERSIONE IMPLICITA, IL COMPILATORE NON DARÀ WARNING, MA POTREBBERO ESSERCI PROBLEMI IN QUANTO NON CAPISCE SE uno 0 è RIFERITO AD UNA ENUM O AD UN'ALTRA (è meglio evitare conversioni implicite tra enum e int, usare sempre il cast esplicito se necessario)


 union Rinuncia ci_provo;

    ci_provo.ci_sto="DAI";// ATTENZIONE in QUESTO CASO HA PRESO il char ci 
    ci_provo.tasse=30;//in queto caso la union è un int non sarà un char esisterà solo questo 
    ci_provo.rinuncia="haahahahscherzavo";
    ci_provo.tasse=0;//stessa cosa ma risparmiamo

}
