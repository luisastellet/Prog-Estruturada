//implementação de vetor estático
#include "TP.h"
#include "TLSE.c"

TP * TP_inicializa (void){
    //se o p-> topo for 0, significa que tá vazia
    TP * p = (TP*)malloc(sizeof(TP));
    //posição livre é índice 0
    p->topo = 0;
    //quantos elementos tem no vetor
    p->n = 0;
    return p;
}

void TP_push (TP *p, int elem){

    if(p->n == 5){ // ou p->topo == 5
        printf("O vetor esta cheio, nao e possivel inserir um elemento!");
        exit(1);
    }
    p->vet[p->topo++] = elem;
    p->n++;
    return;
}

int TP_pop (TP *p){
    if(TP_vazia(p)) exit(1);
    int x = p->vet[--p->topo];
    p->n--;
    return x;
}

void TP_libera (TP *p){
    //por ser vetor estático, não receber free
    //liberamos apenas o p
    free(p);
    return;
}

int TP_vazia (TP *p){
    if(p->n == 0) return 1;
    return 0;
}

void TP_imprime(TP *p){
    if(TP_vazia(p)) return;
    for(int i=p->topo-1; i>=0; i--) printf("%d\n", p->vet[i]); //p->n ou p->topo pq o índice 0 do vetor sempre estará preenchido
    return;
}