#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TLSE.c"

// Q9) Implemente uma função em C que, dadas duas listas, faça a concatenação das
// mesmas ao final de l1. O protótipo da função é o seguinte: TLSE* junta_listas (TLSE*
// l1, TLSE* l2).


TLSE* junta_listas (TLSE* l1, TLSE* l2){
    TLSE *fim_l1 = l1;
    while(fim_l1 -> prox) fim_l1 = fim_l1->prox;
    fim_l1->prox = l2;

    return l1;
}

int main(void){
    TLSE *l1 = TLSE_inicializa();
    TLSE *l2 = TLSE_inicializa();

    int x;
    printf("Preencha a lista 2: ");
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l1 = TLSE_insere(l1, x);
    }while(1);

    printf("Preencha a lista 2: ");
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l2 = TLSE_insere(l2, x);
    }while(1);
    
    printf("A lista 1: ");
    TLSE_imprime(l1);
    printf("\n");
    printf("A lista 2: ");
    TLSE_imprime(l2);
    printf("\n");

    printf("Agora o resultado da funcao criada: ");
    TLSE * rsp = junta_listas(l1, l2);
    TLSE_imprime(rsp);

    TLSE_libera(rsp);
    return 0;
}