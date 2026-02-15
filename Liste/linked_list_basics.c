/**
 * SPIEGAZIONE DELLE LISTE COLLEGATE (LINKED LISTS)
 * -----------------------------------------------
 * Una lista collegata è una collezione lineare di elementi chiamati "nodi".
 * A differenza degli array, gli elementi non sono memorizzati in posizioni di memoria contigue.
 * Ogni nodo è composto da due parti:
 * 1. Dati (es. un intero, una stringa, etc.)
 * 2. Un puntatore al prossimo nodo della lista.
 * 
 * VANTAGGI: Inserimento e rimozione veloci (O(1) se conosciamo la posizione).
 * SVANTAGGI: Accesso casuale lento (O(n)), bisogna scorrere la lista dall'inizio.
 */

#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura di un nodo
typedef struct Node {
    int data;           // Il valore contenuto nel nodo
    struct Node* next;  // Puntatore al prossimo nodo
} Node;

// Funzione per creare un nuovo nodo
Node* create_node(int value) {
    // Allochiamo memoria nel HEAP usando malloc
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Errore: allocazione memoria fallita!\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL; // Per ora non punta a nulla
    return new_node;
}

// Funzione per inserire in testa alla lista
// Usiamo Node** per poter modificare il puntatore 'head' originale nel main
void insert_at_head(Node** head_ref, int value) {
    Node* new_node = create_node(value);
    new_node->next = *head_ref; // Il nuovo nodo punta alla vecchia testa
    *head_ref = new_node;       // La testa ora è il nuovo nodo
}

// Funzione per stampare la lista
void print_list(Node* head) {
    Node* current = head;
    printf("Lista: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Funzione per liberare la memoria (molto importante in C!)
void free_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* next_node = current->next;
        free(current);
        current = next_node;
    }
}

int main() {
    Node* head = NULL; // Lista inizialmente vuota

    printf("--- Esempio Base: Liste Collegate ---\n");
    
    insert_at_head(&head, 30);
    insert_at_head(&head, 20);
    insert_at_head(&head, 10);
    
    print_list(head);
    
    printf("Liberazione memoria...\n");
    free_list(head);
    
    return 0;
}
