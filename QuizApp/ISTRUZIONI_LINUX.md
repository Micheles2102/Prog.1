# Guida all'Avvio per Linux

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

Questo è l'unico requisito di sistema che potrebbe servire.
