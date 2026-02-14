# 🏥 Soluzione Esame di Laboratorio - 25/12/2023 (Esempio)

Questa cartella contiene la soluzione completa e rifattorizzata per la prova di laboratorio di **Programmazione 1**. Il codice è stato scritto seguendo le specifiche tecniche e i requisiti di memoria richiesti dalla traccia ufficiale.

---

## 📝 Traccia Ufficiale (UniCT)

Scrivere un programma in C che esegua le seguenti operazioni:

1. **Input**: Accetti da riga di comando il nome di un file di testo di input (es: `input.txt`) e il nome di un file binario di output (es: `elab.bin`). Le stringhe nel file di input hanno lunghezza non superiore a 20 caratteri.
2. **Caricamento**: Legga le stringhe dal file e le memorizzi in un array di **200 record (struct)**. Ogni record ha un campo `key` (parola) e un campo `len` (lunghezza). I record inutilizzati devono avere `len = -1`.
3. **Filtro**: Elimini la punteggiatura (`,`, `;`, `:`, `.`) dalle parole e aggiorni il campo `len`.
4. **Set**: Elimini i duplicati: solo la prima istanza di una parola viene mantenuta, le altre vengono annullate con `len = -1`.
5. **Stampa**: Stampi a video tutti i record con `len > 0`.
6. **Salvataggio**: Salvi i dati in un file binario utilizzando `fwrite()`.
7. **Verifica**: Legga il file binario appena creato e ne stampi il contenuto. L'output finale dell'array e quello del file binario devono risultare identici.

---

## 🛠️ Struttura del Codice

Il programma è organizzato nelle seguenti funzioni obbligatorie:

- `readInput()`: Gestisce `argc` e `argv`, valida le estensioni `.txt` e `.bin`.
- `buildArray()`: Popola l'array di struct leggendo dal file.
- `filter()`: Pulisce le parole dalla punteggiatura in modo iterativo.
- `createSet()`: Implementa la logica di deduplicazione.
- `printArray()`: Visualizza i risultati validi a schermo.
- `save()`: Esegue l'I/O binario simmetrico.
- `read()`: Verifica l'integrità del file binario salvato.

---

## 🚀 Come Compilare ed Eseguire

Assicurati di avere un file di testo (es. `input.txt`) nella stessa cartella.

1. **Compilazione**:
   ```bash
   gcc Esame25-12-23.c -o esame
   ```

2. **Esecuzione**:
   ```bash
   ./esame input.txt elab.bin
   ```

---

## 💡 Note Tecniche
- **Sincronizzazione Binaria**: La funzione `save` scrive l'intera struttura `Record`. Questo garantisce che la lettura (`read`) sia perfettamente allineata, risolvendo il problema delle stringhe a lunghezza variabile.
- **Robustezza**: Aggiunti controlli di sicurezza sulla lunghezza dei nomi dei file e sulla validità dei puntatori ai file.
