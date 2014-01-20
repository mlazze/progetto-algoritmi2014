#ifndef STACK_H
#define STACK_H
//Prototipi di funzioni per uno stack

//definizione tipo stack
typedef struct stack Stack;

//crea un nuovo stack e ne restituisce un puntatore
Stack *stack_new();

//distrugge lo stack
void stack_destroy(Stack *st);

//svuota uno stack
void stack_make_empty(Stack *st);

//restituisce 1 se lo stack è vuoto, 0 altrimenti
int stack_is_empty(Stack *st);

//restituisce l'elemento in cima alla pila, senza eliminarlo
Item stack_top(Stack *st);

//toglie l'elemento in cima alla pila
void stack_pop(Stack *st);

//inserisce l'elemento nella pila
void stack_push(Stack *st, Item n);
#endif