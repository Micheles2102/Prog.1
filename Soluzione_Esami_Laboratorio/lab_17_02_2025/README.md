Si scriva un programma C che:

1. Prenda in input da riga di comando due parametri stringa: 
o input_filename: nome di un file di input contenente i dati (ad
esempio persone.txt).
o output_filename: nome di un file di output in cui scrivere i risultati.
Il programma deve controllare che entrambi i file abbiano estensione .txt. Se i parametri non
rispettano i requisiti richiesti, il programma deve stampare un messaggio di errore sullo
standard error e terminare l’esecuzione con un appropriato codice di terminazione.
Si stampino a schermo i valori dei parametri presi in input.

2. Si assuma che il file di input contenga del testo. La prima riga del file indicato 
da input_filename contiene un intero n che rappresenta la dimensione dell’array. Le
successive n righe contengono ciascuna quattro valori separati da spazi:
o Nome (stringa, massimo 50 caratteri)
o Cognome (stringa, massimo 50 caratteri)
o Età (intero)
o Altezza (float).
Il programma deve leggere l’intero n dalla prima riga e creare un array dinamico di strutture
di dimensione n. Ciascun elemento dell’array sarà una struttura di tipo Persona contenente i
valori letti dal file. Si stampino a schermo i valori letti e il contenuto dell’array di strutture.

3. Crei un array Z di interi contenente tutte le età presenti nelle strutture. Ordini 
l’array Z utilizzando un algoritmo di ordinamento a scelta. Si determini l’età mediana come il
valore centrale dell’array ordinato (si assuma che l’array abbia sempre una lunghezza dispari).
Si stampino a schermo l’array Z prima e dopo l’ordinamento, oltre al valore della mediana.

4. Calcoli l’altezza media delle persone che hanno un’età superiore alla mediana.
Il programma deve stampare il valore calcolato con due cifre decimali.

5. Scriva nel file di output indicato da output_filename le strutture relative alle
persone con un’altezza superiore alla media calcolata al punto 4. Ogni riga del file deve essere
formattata come segue:
Nome Cognome, Età: <età>, Altezza: <altezza>

Nota: gestire opportunamente i casi in cui i file non possono essere correttamente aperti in lettura o
scrittura stampando un errore sullo standard error e terminando l’esecuzione del programma.

Specifiche:
Il programma potrà essere articolato in un unico file sorgente, ma dovrà contenere almeno le seguenti
funzioni con opportuni parametri formali:
* decodeParameters: funzione che prende in input il numero argc e il vettore argv ricevuti
dalla funzione main(), controlla la presenza e i requisiti degli argomenti e li inserisce in un
record (struct) da restituire allo user code (funzione main). Deve gestire correttamente gli
errori relativi a input non corretti.
* readHeader: funzione che legge il valore n dalla prima riga del file.
* readFile: funzione che legge i contenuti delle successive n righe del file e restituisce un array
dinamico di strutture.
* extractAges: funzione che crea l’array Z con le età.
* sortArray: funzione che ordina l’array Z con un algoritmo a scelta e restituisce la mediana.
* calculateAverageHeight: funzione che calcola l’altezza media delle persone con età
superiore alla mediana.
* writeOutput: funzione che scrive nel file di output i dati delle strutture con altezza superiore
alla media.
