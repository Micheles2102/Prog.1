
# Descrizione del Programma

Questo programma in C legge un file di testo contenente delle parole, esegue una serie di elaborazioni su di esse e le salva in un file binario. In seguito, il programma legge nuovamente il file binario e stampa il contenuto. Le principali operazioni svolte dal programma sono:

1. **Lettura di un file di testo** con una lista di parole.
2. **Pulizia delle parole** per rimuovere caratteri speciali come virgole, punti, punti e virgola.
3. **Creazione di un set**: rimozione dei duplicati, lasciando solo le parole uniche.
4. **Salvataggio del set** in un file binario.
5. **Lettura e stampa del file binario** contenente le parole uniche.

---

## Struttura del Programma

Il programma è diviso in diverse funzioni, ognuna con un ruolo specifico. Ecco un elenco delle funzioni principali:

1. **`readInput(int argc, char *argv[])`**:
   - Questa funzione gestisce i parametri passati via riga di comando. Si aspetta due argomenti: il nome del file di input (in formato testo) e il nome del file di output (in formato binario).
   - Se il numero di argomenti non è corretto, il programma termina con un messaggio di errore.
   - Restituisce una struttura `NomiFile` contenente i nomi dei file.

2. **`buildArray(FILE *file, Record *array)`**:
   - Questa funzione legge il contenuto del file di input riga per riga e costruisce un array di strutture `Record`. Ogni struttura contiene una parola (stringa) e la sua lunghezza.
   - Utilizza `fgets` per leggere le righe e rimuove i caratteri di nuova riga (`\n`) alla fine di ogni parola.

3. **`filter(Record array)`**:
   - La funzione `filter` elimina i caratteri speciali dalle parole, come virgole, punti e altri caratteri non alfanumerici.
   - Viene effettuata una scansione della parola e ogni carattere speciale viene rimosso, aggiornando la lunghezza della parola.

4. **`createset(Record *array, int parole_lette)`**:
   - Rimuove i duplicati nell'array di parole.
   - Per ogni parola, confronta tutte le altre parole e, se una parola è duplicata, la sua lunghezza viene impostata a -1 per "annullarla".

5. **`printArray(Record *array, int parole_lette)`**:
   - Stampa tutte le parole uniche presenti nell'array.

6. **`save(Record *array, int parole_lette, char *nomefilebin)`**:
   - Salva l'array di parole uniche in un file binario. Ogni `Record` viene scritto nel file utilizzando la funzione `fwrite`.

7. **`read(char *filebin)`**:
   - Legge il file binario e stampa le parole salvate.

---

## Funzionamento del Programma

1. **Input e Output**:
   - Il programma prende due argomenti dalla riga di comando: il nome di un file di input (testo) e il nome di un file di output (binario).
   - Il file di input è un file di testo che contiene una lista di parole (una per riga).
   - Il programma salva le parole uniche (dopo aver rimosso i caratteri speciali e i duplicati) in un file binario. Successivamente, il programma legge e stampa il contenuto di questo file binario.

2. **Esempio di Input**:
   Se il file di input (es. `input.txt`) contiene le seguenti parole:
