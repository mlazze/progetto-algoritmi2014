//funzioni per la gestione dell'albero degli enzimi inseriti nell'esperimento
//gestisce le funzioni: nuovo_enzima,elimina_enzima
#ifndef BISTENZ_H
#define BISTENZ_H

struct bistenz_node {
	struct bistenz_node *sin;
	struct bistenz_node *des;
	char *nome;
	int attivo;
};

typedef struct bistenz_node Benznode;

//cerca nell'albero binario di ricerca se esiste un nodo con chiave item, se lo trova restituisce 1 e ris punterà a tale nodo, se non lo trova restituisce 0 e ris punterà al nodo il cui figlio destro o sinistro potrà contenere il nodo cercato 
//funzione ausiliaria
int bistenz_cerca(Benznode *radice, char *enzima, Benznode *ris);

//inserisce un nuovo nodo se non è già presente, se è presente lo riattiva
//funzione richiesta
void nuovo_enzima(Benznode *radice, char *enzima);

//cancella un nodo
//funzione ausiliaria
void bistenz_cancellanodo(Benznode *nodo);

//cancella un intero albero a partire dalla radice rad
//funzione ausiliaria
void cancella_enz(Benznode *rad);

//cerca e inibisce l'enzima se è presente
//funzione richiesta
void elimina_enzima(Benznode *radice,char *enzima);

#endif