#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TLSE.c"

// Q8) Escreva uma função em C que, dadas duas listas l1 e l2 encadeadas, verifique se l1
// e l2 são iguais. As listas l1 e l2 devem permanecer inalteradas. Esta função retorna 1 se
// as listas são iguais e 0, caso contrário. O protótipo desta função é o seguinte: int igual
// (TLSE *l1, TLSE *l2).


int igual (TLSE *l1, TLSE *l2){
    TLSE * p1 = l1, * p2 = l2;
    int cont1=0, cont2=0;
    while (p1){
        cont1++;
        p1 = p1->prox;
    }
    while (p2){
        cont2++;
        p2 = p2->prox;
    }
    if(cont1 != cont2) return 0; //já sei que tem a mesma quantidade de termos
    p1 = l1; p2 = l2;
    while(p1){
        if(p1->info != p2->info) return 0;
        p1 = p1->prox;
        p2 = p2->prox;
    }
    return 1;
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
    printf("*** %d ***", igual(l1, l2));
    TLSE_libera(l1);
    TLSE_libera(l2);
    return 0;
}