//la coda di priorità usata dalla procedura dijkstra per cercare l'elemento con il costo minimo
#ifndef PQUEUE_H
#define PQUEUE_H
//define item
struct dij_item {
    int costo;
    char *frammento; //la chiave
};

//define 1st element pointer
typedef struct dij_item *Dij_item;
typedef struct dij_item *Heap;

struct pqueue {
    Heap h;
    int size, count;
};

typedef struct pqueue *Pqueue;

/* inserts item i in pqueue */
void pqueue_insert(Pqueue p, Dij_item i);


/* extracts min item in p */
Dij_item pqueue_extract_min(Pqueue p);

/* returns min element */
Dij_item pqueue_min(Pqueue p);


Pqueue pqueue_new(int n);


void pqueue_destroy (Pqueue p);


//funzioni ausiliarie
int pqueue_count(Pqueue p);

int pqueue_size(Pqueue p);

int father(int i);

int cmp(Dij_item i1, Dij_item i2);

Dij_item key(Dij_item i);

void swap(Pqueue p, int i, int j);

void heapify_up(Pqueue p, int k);

void heapify_down(Pqueue p, int k, int n);





#endif