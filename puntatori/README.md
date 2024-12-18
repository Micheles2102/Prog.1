
# 📘 Guida ai Puntatori in C - Programmazione 1

Questa repository è pensata per aiutare gli studenti di **Programmazione 1** a comprendere i puntatori in C in modo chiaro ed efficace.  
Ogni sezione è accompagnata da esempi pratici e immagini che spiegano concetti complessi in maniera visiva.

---

## 🔍 **Introduzione ai Puntatori**
Un **puntatore** è una variabile che contiene l'indirizzo di memoria di un'altra variabile.  
Grazie ai puntatori è possibile manipolare direttamente il contenuto delle variabili in memoria.

### **Esempio Visivo**
Nell'immagine seguente puoi vedere come funziona un puntatore:

![Esempio Puntatore](puntatore.png)


- `x` è una variabile con un valore (`42`) e un indirizzo (`0x7ffeab00`).
- `ptr` è il puntatore che **contiene l'indirizzo di x** (`0x7ffeab00`).
- Utilizzando `*ptr`, possiamo accedere al valore contenuto in `x`.

---

## 🗂️ **Argomenti Trattati**
Ecco un elenco delle sezioni presenti nel codice:

| **#** | **Argomento**                                |
|-------|--------------------------------------------|
| 1     | Inizializzazione di un puntatore            |
| 2     | Modifica del valore dell'elemento puntato   |
| 3     | Connessione tra puntatore ed elemento       |
| 4     | Modifica dell'elemento puntato              |
| 5     | Puntatore a costante                        |
| 6     | Puntatore costante a una variabile          |
| 7     | Puntatore costante a una costante           |
| 8     | Passaggio per riferimento a una funzione    |

---

## 💻 **Codice Esempio**
```c
#include <stdio.h>

int main() {
    int x = 3;
    int y = 4;

    // 1) Inizializzazione di un puntatore
    int* ptr = &x;
    printf("Valore puntato: %d\n", *ptr);

    // 2) Modifica del valore dell'elemento puntato
    *ptr = 5;
    printf("Nuovo valore puntato: %d\n", *ptr);

    // 3) Connessione tra puntatore ed elemento puntato
    printf("Valore di x: %d\n", x);
    *ptr = 8;
    printf("Valore di x dopo modifica: %d\n", x);

    // 4) Modifica dell'elemento puntato dal puntatore
    ptr = &y;
    *ptr = 7;
    printf("Valore di y: %d\n", y);

    // 5) Puntatore a costante
    const int* p = &x;
    p = &y;

    // 6) Puntatore costante a una variabile
    int* const prova = &x;
    *prova = 20;

    // 7) Puntatore costante a una costante
    const int* const finale = &x;

    return 0;
}
```

---

## 📚 **Spiegazione Approfondita**

### **1) Inizializzazione di un Puntatore**
- Un puntatore viene inizializzato con l'indirizzo di una variabile usando l'operatore `&`.

| Variabile | Contenuto | Indirizzo   |
|-----------|-----------|------------|
| `x`       | 42        | 0x7ffeab00 |
| `ptr`     | 0x7ffeab00| 0x7ffeab10 |

---

### **2) Modifica del Valore Puntato**
- Usando `*ptr`, possiamo **modificare il valore** della variabile puntata.

```c
*ptr = 5;  // Cambia il valore di x
```

---

### **3) Connessione tra Puntatore e Variabile**
- Cambiare il valore attraverso il puntatore modifica anche la variabile originale.

---

## 📝 **Nota Importante**
Utilizza l'immagine fornita (`image.png`) insieme al codice per visualizzare la connessione tra variabili e puntatori.

---

## 🚀 **Buono Studio e Buona Programmazione!**

