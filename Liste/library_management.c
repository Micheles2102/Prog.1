/**
 * SISTEMA DI GESTIONE BIBLIOTECA (LINKED LIST)
 * --------------------------------------------
 * In questo esempio usiamo una lista collegata per gestire una collezione di libri.
 * Ogni libro è un nodo della lista.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char title[100];
    char author[100];
    struct Book* next;
} Book;

// Funzione per aggiungere un libro alla biblioteca (in testa)
void add_book(Book** library, const char* title, const char* author) {
    Book* new_book = (Book*)malloc(sizeof(Book));
    strcpy(new_book->title, title);
    strcpy(new_book->author, author);
    new_book->next = *library;
    *library = new_book;
    printf("Aggiunto: '%s' di %s\n", title, author);
}

// Funzione per rimuovere un libro per titolo
void remove_book(Book** library, const char* title) {
    Book *current = *library, *prev = NULL;

    // Se il libro da rimuovere è la testa
    if (current != NULL && strcmp(current->title, title) == 0) {
        *library = current->next;
        free(current);
        printf("Rimosso: '%s'\n", title);
        return;
    }

    // Cerca il libro nella lista
    while (current != NULL && strcmp(current->title, title) != 0) {
        prev = current;
        current = current->next;
    }

    // Se il libro non è stato trovato
    if (current == NULL) {
        printf("Libro '%s' non trovato in biblioteca.\n", title);
        return;
    }

    // Sgancia il nodo dalla lista
    prev->next = current->next;
    free(current);
    printf("Rimosso: '%s'\n", title);
}

// Funzione per visualizzare tutti i libri
void display_library(Book* library) {
    printf("\n--- 📚 BIBLIOTECA ATTUALE ---\n");
    if (library == NULL) {
        printf("La biblioteca è vuota.\n");
        return;
    }
    
    Book* current = library;
    int count = 1;
    while (current != NULL) {
        printf("%d. \"%s\" - %s\n", count++, current->title, current->author);
        current = current->next;
    }
    printf("-----------------------------\n");
}

void free_library(Book* library) {
    Book* current = library;
    while (current != NULL) {
        Book* tmp = current;
        current = current->next;
        free(tmp);
    }
}

int main() {
    Book* my_library = NULL;

    add_book(&my_library, "Il C. Linguaggio di programmazione", "Kernighan & Ritchie");
    add_book(&my_library, "I Promessi Sposi", "Alessandro Manzoni");
    add_book(&my_library, "1984", "George Orwell");

    display_library(my_library);

    remove_book(&my_library, "I Promessi Sposi");
    
    display_library(my_library);

    remove_book(&my_library, "Harry Potter"); // Esempio non trovato

    free_library(my_library);
    return 0;
}
