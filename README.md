# C Programming Quiz GUI App

Una moderna applicazione desktop per testare le tue conoscenze su Funzioni e Puntatori in C, basata sugli argomenti ufficiali di Programmazione 1.

## 🚀 Come avviare l'applicazione

L'app è disponibile come file eseguibile per Windows, quindi non serve installare Python per usarla:

1. Vai nella cartella `dist`.
2. Fai doppio clic su `C_Quiz_App.exe`.
3. Il quiz si aprirà in una finestra dedicata con interfaccia grafica moderna.

## 🛠️ Sviluppo e Modifiche (Ambiente UV)

Se desideri modificare il codice, il progetto è gestito con `uv`:

1. Assicurati di avere `uv` installato.
2. Sincronizza l'ambiente:
   ```bash
   uv sync
   ```
3. Avvia l'app in modalità sviluppo:
   ```bash
   uv run python app.py
   ```

## 🏗️ Generazione dell'Eseguibile

Se modifichi il codice e vuoi rigenerare l'app:
```powershell
.\build_exe.ps1
```

## 📊 Algoritmi di Ordinamento (Sorting)
Oltre al quiz, la repository include ora una sezione dedicata agli algoritmi di ordinamento richiesti per l'esame:

1.  **[Guida Completa ai Sorting](SORTING_GUIDE.md)**: Una spiegazione dettagliata della logica e della complessità di ogni algoritmo.
2.  **Codice Sorgente in C**:
    *   [bubble_insertion_sort.c](bubble_insertion_sort.c): Implementazione di Bubble Sort e Insertion Sort.
    *   [selection_sort.c](selection_sort.c): Implementazione di Selection Sort.
    *   [merge_sort.c](merge_sort.c): Implementazione di Merge Sort (O(n log n)).

## 📚 Argomenti Trattati
Il quiz copre i 10 punti fondamentali della repository:
1. Cos'è una funzione
2. Struttura e definizione
3. Invocazione
4. Prototipi
5. Parametri Formali vs Attuali
6. Passaggio per valore/indirizzo
7. Allocazione dinamica/automatica
8. Passaggio di Array
9. Array Multidimensionali
10. Accesso a indirizzi e valori
