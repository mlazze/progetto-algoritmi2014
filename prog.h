//contiene la libreria e le inclusioni dell'intero progetto, oltre alle operazioni che riguardano più componenti del progetto
//gestisce direttamente le funzioni: nuovo_esperimento, prepara_esperimento, Esperimento, enzimi,energia,similarità
#ifndef PROG_H
#define PROG_H
#include "bistenz.h"
#include "libenz.h"
#include "graph.h"
#include "stack.h"
#include "pqueue.h"


typedef struct esperimento Esperimento;

struct esperimento {
	Benznode *alberoenzimi;
	Bframmnode *grafo;
};

//crea una nuova struttura esperimento e inserisce in alberoenzimi il nodo contenente l'enzima "nullo"
//funzione richiesta
Esperimento *crea_nuovo();

//ricrea la struttura di base e inserisce frammenti e enzimi presi dai due file
//funzione richiesta
void prepara_esperimento(Esperimento *esp, char *f_file, char *e_file);

//applica ad ogni frammento in esp -> grafo gli enzimi di alberoenzimi inserendo i nuovi lati e i nuovi frammenti
//funzione ausiliaria
void esp(Esperimento *esp, int tempo);

//stampa il risultato finale di esp(tempo)
//funzione richiesta
void Esp(Esperimento *esp, int tempo);

//albero binario di ricerca usato da Dijkstra per restituire il risultato
struct bist_dij {
    int costo;
    char *frammento; //la chiave
    char *precedente;
    char *nome_lato_prec;
    struct bist_dij *sin;
    struct bist_dij *des;
};

typedef struct bist_dij Bist_dij;

//prende in ingresso un puntatore a funzione che determina il peso dei lati, il grafo e il nodo sorgente e restituisce un albero binario di ricerca ris contenente per ogni nodo v costo del cammino minimo dal nodo sorgente s a v, il predecessore di v in tale cammino e il nome del lato che collega v al suo predecessore
//funzione ausiliaria
Bist_dij *Dijkstra(Bframmnode *grafo, int *(*funct)(char *), Bframmnode *s, Pqueue *ris);

//prende in ingresso il frammento di origine f, quello di destinazione g e il tempo, oltre ai riferimenti al grafo e all'albero degli enzimi da utilizzare. Stampa il cammino minimo da f a g data la funzione peso che restituisce 1 per ogni enzima
//funzione richiesta
void Enzimi(Bframmnode *grafo, Benznode *enzimi, char *f, char *g, int tempo);

//prende in ingresso il frammento di origine f, quello di destinazione g e il tempo, oltre ai riferimenti al grafo e all'albero degli enzimi da utilizzare. Stampa il cammino minimo da f a g data la funzione peso energia_enzimi
//funzione richiesta
void Energia(Bframmnode *grafo, Benznode *enzimi, Esperimento *esp, char *f, char *g, int tempo);

//stampa la massima sequenza di coppie di caratteri appaiati tra f e g
//funzione richiesta
void similarita(char *f, char *g);
#endif