#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    int vet[5];
    int topo; //indice do topo
    int n; //número de elementos
}TP;

TP * TP_inicializa (void);
void TP_push (TP *p, int elem);
int TP_pop (TP *p);
void TP_libera (TP *p);
int TP_vazia (TP *p);
void TP_imprime(TP *p);