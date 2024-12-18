# 📘 Guida alle Funzioni in C - Programmazione 1

Questa repository è pensata per aiutare gli studenti di **Programmazione 1** a comprendere le funzioni in C in modo chiaro ed efficace.  
Ogni sezione è accompagnata da esempi pratici e immagini che spiegano concetti complessi in maniera visiva.

---

## 🔍 **Introduzione alle Funzioni**

Una **funzione** è un blocco di codice che esegue un'operazione specifica e che può essere riutilizzato in diverse parti di un programma.  
Le funzioni permettono di strutturare il codice in modo modulare, facilitandone la comprensione, manutenzione e riutilizzo.

---

## 🗂️ **Argomenti Trattati**

Ecco un elenco delle sezioni presenti:

| **#** | **Argomento**                                   |
|-------|-----------------------------------------------|
| 1     | Che cos'è una funzione                      |
| 2     | Definizione e struttura di una funzione       |
| 3     | Invocazione di una funzione                  |
| 4     | Definizione vs Prototipo                     |
| 5     | Parametri attuali vs Parametri formali       |
| 6     | Passaggio mediante indirizzo e per valore    |
| 7     | Allocazione automatica, dinamica, statica    |
| 8     | Passaggio di array a funzioni                |
| 9     | Passaggio di array multidimensionali         |
| 10    | Accesso ad indirizzi e valori con array multidimensionali |

---

## 📚 **Spiegazione Approfondita**

### **1) Che cos'è una Funzione**
Una funzione è un blocco di codice riutilizzabile, progettato per eseguire un'operazione specifica. Le funzioni possono:
- Ricevere dati in ingresso (parametri).
- Restituire un valore (opzionale).

### **2) Definizione e Struttura di una Funzione**
La struttura di una funzione include:
- **Tipo di ritorno**: indica il tipo di valore restituito dalla funzione.
- **Nome della funzione**: rappresenta il suo identificativo.
- **Parametri**: specificano i dati in ingresso.
- **Corpo della funzione**: contiene le istruzioni eseguite.

Esempio:
```c
int somma(int a, int b) {
    return a + b;
}
```

### **3) Invocazione di una Funzione**
Per utilizzare una funzione, è necessario invocarla specificandone il nome e i parametri richiesti.

Esempio:
```c
int risultato = somma(3, 5);
```

### **4) Definizione vs Prototipo**
- **Prototipo**: è una dichiarazione della funzione senza il corpo. Serve per indicare al compilatore la sua esistenza.
  ```c
  int somma(int a, int b); // Prototipo
  ```
- **Definizione**: include il corpo della funzione con le istruzioni da eseguire.
  ```c
  int somma(int a, int b) {
      return a + b;
  }
  ```

### **5) Parametri Attuali vs Parametri Formali**
- **Parametri Formali**: definiti nella dichiarazione della funzione e agiscono come variabili locali.
  ```c
  int somma(int a, int b) { ... }
  ```
- **Parametri Attuali**: valori effettivi passati alla funzione al momento dell'invocazione.
  ```c
  somma(3, 5); // 3 e 5 sono i parametri attuali
  ```

### **6) Passaggio Mediante Indirizzo e per Valore**
- **Per Valore**: viene passato alla funzione una copia del valore originale.
  - Esempio:
    ```c
    void incrementa(int x) { x = x + 1; }
    ```
- **Per Indirizzo**: viene passato l'indirizzo della variabile, permettendo di modificarne il valore originale.
  - Esempio:
    ```c
    void incrementa(int* x) { *x = *x + 1; }
    ```

### **7) Allocazione Automatica, Dinamica, Statica**
- **Automatica**: variabili create automaticamente all'interno di una funzione.
- **Dinamica**: memoria allocata esplicitamente durante l'esecuzione del programma (es. con `malloc`).
- **Statica**: memoria riservata per tutta la durata del programma.

### **8) Passaggio di Array a Funzioni**
Gli array possono essere passati come parametri utilizzando il loro nome, che rappresenta l'indirizzo del primo elemento.

Esempio:
```c
void stampaArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
```

### **9) Passaggio di Array Multidimensionali**
Anche gli array multidimensionali possono essere passati a funzioni, specificando le loro dimensioni:
```c
void stampaMatrice(int mat[][3], int righe) {
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", mat[i][j]);
        }
    }
}
```

### **10) Accesso ad Indirizzi e Valori con Array Multidimensionali**
Con array multidimensionali, possiamo accedere direttamente agli indirizzi e ai valori:
- **Indirizzi**: `&mat[i][j]`.
- **Valori**: `mat[i][j]`.

---

## 📝 **Nota Importante**
Utilizza immagini e diagrammi per comprendere meglio il flusso dei dati nelle funzioni, soprattutto con parametri e array.

---

## 🚀 **Buono Studio e Buona Programmazione!**
