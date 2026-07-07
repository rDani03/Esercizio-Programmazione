# Esercizio-Programmazione
Traccia di Elementi di Programmazione


Definisce una struttura in cui salvare

Sviluppare in linguaggio C sottoprogrammi diversi per:
•	Leggere le dimensioni e i valori reali di una matrice
•	Calcolare la media di tutte le colonne e di tutte le righe della matrice
•	Ordinare un array di strutture definite come sopra per valori della media crescente.
Ogni strutture possiede come campi: una media, un a lettera che specifica se la somma si riferisce alla colonna o alla una riga (‘r’,’c’) di una matrice, un intero che identificala riga o la colonna corrispondente
•	Salvare l’array di strutture in un file “output.bin”

struct Mystruct
{
float avg;
char id;
int rc;
};

Il programma dichiara l’array di strutture e le inizializza utilizzando i sottoprogrammi sopra elencati.

Esempio:
        4 2 1 1 
M =     0 3 2 1 
        2 1 1 0 
        1 0 0 1 
media righe: 2.0,1.5,1.0,0.5
media colonne: 1.75,1.5,1.0,0.75
Array strutture:
0.5,’r’, 3
0.75,’c’,3
1.0,’r’,2
1.0,’c’,2
1.5,’r’,1
1.5,’c’,1
1.75,’c’,0
2.0,’r’,0


