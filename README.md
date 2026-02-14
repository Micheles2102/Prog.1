# 📘 Raccolta di Esercizi e Concetti Fondamentali in C

Questa repository contiene una selezione di esercizi e implementazioni in linguaggio C, pensata per consolidare i concetti fondamentali come puntatori, funzioni, gestione della memoria e preparazione agli esami di laboratorio.  
Per qualsiasi dubbio, puoi contattarmi su Telegram: [@Sbracato](https://t.me/Sbracato)

---

## 📁 Struttura della Repository

La repository è organizzata in cartelle tematiche per una navigazione semplice e mirata:

### 🔧 [Funzioni](Funzioni/)

Contiene esempi pratici di definizione, prototipazione e implementazione di funzioni in C, con un'architettura modulare e pulita.

- `definizioni.c`: Implementazione di tutte le funzioni.
- `prototipi.h`: Dichiarazione dei prototipi e costanti di progetto.
- `funzioni.c`: Punto di ingresso (`main`) con test delle funzionalità.
- `README.md`: Guida dettagliata all'uso delle funzioni con esempi visivi.

---

### 🧠 [Puntatori](puntatori/)

Una guida completa all'uso dei puntatori, dal passaggio per valore/riferimento alla gestione di array e matrici dinamiche.

- `01_functions_value.c`: Differenza tra parametri formali e attuali (passaggio per valore).
- `02_pointers_reference.c`: Uso dei puntatori per modificare variabili (passaggio per riferimento).
- `03_arrays.c`: Relazione tra array e memoria.
- `04_matrices.c`: Gestione di matrici e l'uso dei Variable Length Arrays (VLA).
- `05_advanced_pointers.c`: Puntatori a puntatori e uso di `const`.
- `README.md`: Spiegazione teorica e diagrammi Mermaid sul funzionamento della memoria.

---

### 📝 Test a Risposta Multipla

Contiene esempi di test universitari con domande a risposta multipla e relative soluzioni interattive.

- `Test di programmazione 1 - [3 Febbraio 2023] [Canale A-E].pdf`: Test ufficiale.
- `Test di programmazione 1 - [3 Febbraio 2023] [Canale A-E].ipynb`: Soluzione interattiva commentata.

---

### 🎓 Soluzioni Esami Laboratorio

Soluzioni complete di prove d'esame di laboratorio in C, utili per comprendere la struttura richiesta in fase d'esame.

---

## ▶️ Come Compilare

Per compilare i progetti modulari (come nella cartella Funzioni):

```bash
gcc funzioni.c definizioni.c -o programma
./programma
```

Per i singoli file nella cartella Puntatori:

```bash
gcc nome_file.c -o output
./output
```
