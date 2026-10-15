# Osservazioni — Esercitazione 0

Gruppo: C8

Componenti (nome, cognome e username GitHub di entrambi): Agnese Lauriente agneselauriente, Maria Camilla Gina Montefusco camilla062

URL del repository condiviso: https://github.com/agneselauriente/esercitazione-0-template.git

Chi ha usato la tastiera nello step 1 e nello step 2: Agnese Lauriente ha usato la tastiera nello step 1 e Maria Camilla Gina Montefusco nello step 2 

Compilate insieme le osservazioni e discutete le risposte: entrambi dovete
saper spiegare le prove svolte.

## Step 1 — Hello World: compilazione ed esecuzione

Comando di compilazione: gcc -std=c17 -Wall -Wextra -Wpedantic hello.c -o hello

Comando di esecuzione e risultato osservato: ./hello

Che cosa ho capito su sorgente ed eseguibile: il file sorgente è il testo scritto in C mentre l'eseguibile è il file tradotto dal compilatore 

Output richiesto e comportamento del programma prima della modifica: era richiesto che il programma stampasse il messaggio "Hello, computational physics!", ma compilandolo non succedeva nulla

Esito dopo la modifica e spiegazione della correzione: abbiamo aggiunto la riga di testo printf("Hello, computational physics!\n") e compilato il file, in questo modo il programma stampava corettamente il testo seguito da una nuova riga

## Step 1 — Git

Quali file ho incluso nel commit e perché: abbiamo incluso hello.c perchè abbiamo modificato il codice e osservazioni.md perchè abbiamo risposto alle domande dello step 1

Come ho verificato che la versione provata sia presente su GitHub: ho ricaricato la pagina del repository e ho controllato che i file cotenessero le mie ultime modifiche e che il commit fosse presente nella cronologia

Che cosa ho osservato prima e dopo `git pull`, e perché non serve un nuovo clone: prima del comando la modifica aggiunta dal browser non era presente, dopo il file si è aggiornato. Non serve un nuovo clone perchè la cartella è già collegata al repository remoto

## Step 2 — Eco: prima prova

Argomenti passati, comando e risultato:
* Comando: ./eco ciao 12 3.5 > eco.txt seguito da echo $ e da cat eco.txt
* Argomenti passati: tre argomenti validi — "ciao", "12", "3.5".
* Risultato nel file (cat eco.txt): ciao 12 3.500000
* Codice di uscita (echo $?): 0

Che cosa posso concludere: Gli argomenti inseriti da riga di comando vengono ricevuti come stringhe in argv. Le funzioni atoi e atof convertono i caratteri nei rispettivi tipi numerici (int e double). La redirezione > invia tutto ciò che viene stampato su stdout dentro il file eco.txt invece che a terminale, e il programma termina con successo (return 0).

## Step 2 — Eco: seconda prova

Argomenti passati, comando e risultato:
* Comando: ./eco ciao dodici 3.5 > eco.txt seguito da echo $ e da cat eco.txt
* Argomenti passati: "ciao", "dodici" (non numerico), "3.5".
* Risultato nel file (cat eco.txt): ciao 0 3.500000
* Codice di uscita (echo $?): 0

Che cosa ho capito su testo, conversioni e stampa: atoi non valida il formato dell'input: incontrando caratteri alfabetici non convertibili all'inizio della stringa, restituisce 0 senza segnalare errori o interrompere il programma. La printf riceve regolarmente il valore 0 e lo scrive nel file. Il programma arriva a fine esecuzione restituendo comunque 0 (successo), rendendo impossibile distinguere un fallimento di conversione dall'inserimento effettivo della cifra zero.

## Step 2 — Risultato ed errori

Previsioni per l'esecuzione con argomenti validi e per quella con `dodici`: 
* Per gli argomenti validi: esecuzione corretta, output scritto dentro eco.txt, terminale vuoto e codice di uscita 0.
* Per la prova con dodici: teoricamente ci si aspetterebbe un blocco con messaggio di errore su stderr ed exit code diverso da zero; con l'uso reale di atoi, invece, la conversione fallisce silenziosamente trasformando "dodici" in 0, senza bloccare l'esecuzione.

Contenuto di `eco.txt`, messaggi nel terminale e codici di uscita osservati: 
* Con ./eco ciao 12 3.5 > eco.txt:
* Nel terminale non compare nulla.
* echo $? restituisce 0.
* eco.txt contiene ciao 12 3.500000.


* Con ./eco ciao dodici 3.5 > eco.txt:
* Nel terminale non compare alcun messaggio di errore.
* echo $? restituisce 0.
* eco.txt contiene ciao 0 3.500000.
(il messaggio di errore su stderr e l'exit code 2 si osservano solo se si omettono argomenti, es. ./eco ciao 12).

Come un controllo automatico può riconoscere un errore: Un controllo automatico verifica l'*exit status* del comando memorizzato nella variabile $?. Se il valore è 0 considera il test superato, mentre se riceve un valore diverso da zero (come il return 2; impostato in caso di argomenti mancanti) rileva il fallimento e interrompe la sequenza automatica.

## Step 2 — Parametri e calcolo fisico

Quando serve ricompilare e quando basta cambiare gli argomenti: La ricompilazione del codice sorgente è necessaria unicamente quando si modificano le istruzioni del programma o l'algoritmo all'interno dei file .c. Al contrario, se l'obiettivo è variare i parametri di input o i dati di una simulazione, non è necessario ricompilare: è sufficiente passare argomenti differenti direttamente da riga di comando.

## Step 2 — Git

Come riconosco nella cronologia i commit dei due step: Posso distinguere i commit eseguendo git log --oneline, che mostra l'hash univoco e i messaggi descrittivi associati a ciascun commit per i due differenti step.

Come ho verificato che la versione finale sia presente su GitHub: Dopo aver eseguito git push e aver controllato con git status che non ci fossero modifiche locali pendenti, ho verificato sulla pagina GitHub del repository che l'ultimo commit e il tag di consegna (submit/consegna-1) fossero presenti e corretti.
