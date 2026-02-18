# 🚢 Battaglia Navale – Implementazione in C

## 📌 Descrizione del Progetto

Questo progetto rappresenta un'implementazione del gioco della **Battaglia Navale** sviluppata in linguaggio C.

L'applicazione gestisce completamente la logica del gioco tramite interfaccia a riga di comando (CLI), includendo:

- Posizionamento delle navi
- Validazione delle coordinate
- Gestione degli attacchi
- Aggiornamento dello stato della griglia
- Determinazione automatica della vittoria

Il progetto è stato sviluppato con approccio procedurale, organizzando la logica in funzioni modulari per garantire leggibilità e manutenibilità.

---

## 🛠 Tecnologie Utilizzate

- Linguaggio C
- Programmazione procedurale
- Array bidimensionali
- Gestione input/output da terminale

---

## 🏗 Struttura del Progetto

```text
Battaglia-Navale---C/
├── src/
│   └── main.c
├── README.md
└── Makefile   (opzionale)
```

- `src/` → contiene il codice sorgente principale  
- `main.c` → punto di ingresso del programma  

---

## ▶️ Compilazione ed Esecuzione

### Compilazione con GCC

```bash
gcc -Wall -Wextra -O2 src/main.c -o battleship
```

### Esecuzione

```bash
./battleship
```

---

## 🎮 Funzionalità Principali

- Creazione e gestione di una griglia bidimensionale
- Inserimento coordinate per attacco e validazione input
- Controllo colpi (acqua / nave colpita) e aggiornamento dinamico della mappa di gioco
- Gestione dei turni e verifica condizione di fine partita
- **Attacco avversario con AI**: selezione di coordinate evitando di ripetere colpi già effettuati

---

## 🎯 Competenze Dimostrate

Questo progetto evidenzia competenze in:

- Modellazione logica di un sistema a stati
- Gestione di strutture dati (array 2D)
- Validazione input utente
- Organizzazione modulare del codice
- Problem solving algoritmico

---

## 👨‍💻 Autore

Vincenzo Digioia  
Junior Software Engineer  
GitHub: https://github.com/enzodig11
