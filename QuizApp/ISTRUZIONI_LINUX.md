# Guida all'Avvio per Linux
## ATTENZIONE: In questa guida troverete alcuni metodi su come avviare e risolvere dei problemi comuni. Nonostante ciò, ci potrebbero essere dei problemi che devo ancora risolvere. Sto lavorando per creare un file docker o un AppImage per potere risolvere ma per adesso dovreste potere comunque riuscire, per lo meno, a potere fare alcuni test prima di riscontrare dei problemi.Nel caso doveste trovare altri problemi, ho lasciato aperto nella sezione Issues.

Questa applicazione è distribuita come eseguibile standalone.L'ho testato su Ubuntu e con wsl fatemi sapere se funziona per altri sistemi operativi Linux.

## Come Avviare l'App

1.  Scarica il file.
2.  Apri il terminale nella cartella del download.
3.  Rendi il file eseguibile (necessario solo la prima volta):
    ```bash
    chmod +x C_Quiz_App_Linux
    ```
4.  Avvia l'app:
    ```bash
    ./C_Quiz_App_Linux
    ```

## Problemi Comuni

Se l'app non si avvia o mostra errori relativi a `tkinter`, potresti dover installare un pacchetto di base che spesso è già presente ma a volte manca:

```bash
sudo apt install python3-tk
```
Nel caso una volta avviato ci dovessero esserci problemi di librerie ulteriori durante i test usare provare ad usare:

```bash
export LD_LIBRARY_PATH=/usr/lib:/usr/lib64 ./C_Quiz_App_Linux
```
Questo è l'unico requisito di sistema che potrebbe servire.
