# 📊 Guida agli Algoritmi di Ordinamento (Sorting)

Questa guida spiega i tre algoritmi di ordinamento principali richiesti, con un focus sulla logica di funzionamento e sull'analisi delle prestazioni (complessità).

---

## 🧼 1. Bubble Sort (Ordinamento a Bolle)

**Come funziona:**
È l'algoritmo più semplice. Scorre l'array ripetutamente e confronta coppie di elementi adiacenti. Se sono nell'ordine sbagliato, li scambia. Ad ogni "giro", l'elemento più grande "risale" come una bolla verso la fine dell'array.

*   **Visualizzazione:** [Guarda Bubble Sort su VisuAlgo](https://visualgo.net/en/sorting?algo=bubble)

### 📈 Complessità
| Tipo | Valore | Perché? |
| :--- | :--- | :--- |
| **Tempo (Worst/Avg)** | **O(n²)** | Abbiamo due cicli annidati: per ogni elemento ($n$), dobbiamo potenzialmente scorrere tutto l'array ($n$). |
| **Spazio** | **O(1)** | È un algoritmo "in-place": lo scambio avviene direttamente nell'array originale senza bisogno di memoria extra. |

---

## 🃏 2. Insertion Sort (Ordinamento per Inserimento)

**Come funziona:**
Simile a come ordineresti un mazzo di carte in mano. Prendi un elemento alla volta e lo "inserisci" nella posizione corretta all'interno della parte dell'array che hai già ordinato (spostando a destra gli elementi più grandi).

*   **Visualizzazione:** [Guarda Insertion Sort su VisuAlgo](https://visualgo.net/en/sorting?algo=insertion)

### 📈 Complessità
| Tipo | Valore | Perché? |
| :--- | :--- | :--- |
| **Tempo (Worst/Avg)** | **O(n²)** | Anche qui abbiamo due cicli: uno per scegliere l'elemento e uno per trovare dove inserirlo spostando gli altri. |
| **Tempo (Best Case)** | **O(n)** | Se l'array è già ordinato, fa solo un controllo per ogni elemento senza spostare nulla. |
| **Spazio** | **O(1)** | Anche questo lavora "in-place", usando solo una variabile temporanea per lo scambio. |

---

## ⚡ 3. Merge Sort (Ordinamento per Fusione)

**Come funziona:**
Usa la tecnica "Divide et Impera" (Dividi e Conquista). 
1. **Divide:** Divide l'array a metà finché non ottiene array da un solo elemento.
2. **Impera:** Unisce (merge) le metà in ordine, risalendo fino ad avere l'array completo e ordinato.

*   **Visualizzazione:** [Guarda Merge Sort su VisuAlgo](https://visualgo.net/en/sorting?algo=merge)

### 📈 Complessità
| Tipo | Valore | Perché? |
| :--- | :--- | :--- |
| **Tempo (Sempre)** | **O(n log n)** | La divisione crea una struttura ad albero profonda $\log n$, e per ogni livello dell'albero facciamo un lavoro di fusione proporzionale a $n$. È molto più veloce di $O(n^2)$ per array grandi. |
| **Spazio** | **O(n)** | Per fondere due metà, il Merge Sort ha bisogno di un "array di appoggio" temporaneo grande quanto l'array originale. |

---

## 💡 Tabella Comparativa

| Algoritmo | Caso Peggiore | Spazio Extra | Ideale per... |
| :--- | :--- | :--- | :--- |
| **Bubble** | $O(n^2)$ | $O(1)$ | Scopo didattico, array piccolissimi. |
| **Insertion** | $O(n^2)$ | $O(1)$ | Array quasi già ordinati. |
| **Merge** | $O(n \log n)$ | $O(n)$ | Grandi quantità di dati (molto stabile). |

> [!TIP]
> Per l'esame di Prog1, ricorda che **Merge Sort** è efficiente ma "costoso" in termini di memoria, mentre **Insertion** e **Bubble** sono lenti ma non sprecano spazio.
