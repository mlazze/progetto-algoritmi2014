//gestisce l'albero binario di ricerca dei frammenti e le varie liste di adiacenza. E' quindi il file che gestisce il grafo ordinato.
//gestisce le funzioni: nuovo_Frammento
#ifndef GRAPH_H
#define GRAPH_H

typedef struct bistframm_node Bframmnode;
typedef struct l_ad L_ad;

struct l_ad {
	struct l_ad *next;
	Bframmnode *dest;
	char *nome_enzima;
};

struct bistframm_node {
	struct bistenz_node *sin;
	struct bistenz_node *des;
	char *frammento;
	int attivo;
	L_ad *lista;
};


//gestione Lista di adiacenza
//inserisce nella lista di adiacenza di nodo l'elemento formato dall'etichetta nome_ebzima e che punta a dest
//funzione ausiliaria
void ins_lato(Bframmnode *nodo, Bframmnode *dest, char *nome_enzima);

//elimina la lista di adiacenza ricorsivamente a partire da el
//funzione ausiliaria
void elimina_list(L_ad *el);


//gestione Albero binario di ricerca frammenti
//cerca nell'albero binario di ricerca se esiste un nodo con chiave item, se lo trova restituisce 1 e ris punterà a tale nodo, se non lo trova restituisce 0 e ris punterà al nodo il cui figlio destro o sinistro potrà contenere il nodo cercato 
//funzione ausiliaria
int bistframm_cerca(Bframmnode *radice, char *frammento, Bframmnode *ris);

//inserisce un nuovo nodo se non è già presente
//funzione richiesta
void nuovo_frammento(Bframmnode *radice, char *frammento);

//inserisce un nuovo nodo se non è già presente e lo marchia come "da visitare al prossimo "tempo"" (1)
//funzione ausiliaria
void nuovo_frammento_vis(Bframmnode *radice, char *frammento);

//cancella un nodo
//funzione ausiliaria
void bistframm_cancellanodo(Bframmnode *nodo);

//cancella un intero albero a partire dalla radice rad
//funzione ausiliaria
void cancella_framm(Bframmnode *rad);

#endif