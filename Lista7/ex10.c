#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TLSE.c"

// Q10) Escreva uma função em C que, dadas duas listas l1 e l2 encadeadas, verifique se l1
// é a inversão de l2. As listas l1 e l2 devem permanecer inalteradas. Esta função retorna 1
// se as listas estão invertidas e 0, caso contrário. O protótipo desta função é o seguinte: int
// Contrario (TLSE *l1, TLSE *l2).

int Contrario (TLSE *l1, TLSE *l2){
    int cont1=0, cont2=0;
    TLSE * p1=l1;
    TLSE * p2=l2;

    for(p1; p1; p1=p1->prox) cont1++;
    for(p2; p2; p2=p2->prox) cont2++;
    if (cont1 != cont2) return 0;

    //podia inverter a l1 ou a l2
    TLSE * l1_inv = TLSE_inicializa();
    p1=l1; p2=l2;
    while(p1){
        l1_inv = TLSE_insere(l1_inv, p1->info);
        p1 = p1->prox;
    }

    //comparar a l1 invertida com a l2
    p1 = l1_inv;
    while(p1){
        if(p1->info != p2->info){
            //precisa liberar aqui pq ela não vai pra main
            TLSE_libera(l1_inv);
            return 0;
        }
        p1 = p1->prox;
        p2 = p2->prox;
    }

    TLSE_libera(l1_inv);
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
    printf("*** %d ***", Contrario(l1, l2));
    TLSE_libera(l1);
    TLSE_libera(l2);
    return 0;
}