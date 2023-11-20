#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TLSE.c"

// Q6) Defina uma função em C que, dada uma lista l qualquer, retorne, numa lista de saída,
// os elementos ímpares e os elementos pares da lista l, na ordem em que os elementos
// aparecem em l. Ao final da execução desta função, a lista resultante terá todos os
// elementos da lista l (primeiro os ímpares, depois os pares, na ordem em que eles
// aparecem em l), e a lista l continuará contendo os seus elementos. O protótipo da função
// é o seguinte: TLSE* i_p (TLSE *l).

TLSE* i_p (TLSE *l){
    TLSE * par = TLSE_inicializa();
    TLSE * impar = TLSE_inicializa();
    TLSE * resultado = TLSE_inicializa();

    TLSE * p = l, * p_par = par, * p_impar = impar;
    //preenchendo as listas impar e par
    while(p){
        if(p->info % 2 == 0) {
            if(!par){
                par = TLSE_insere(par, p->info);
                p_par = par;
            }
            else{
                p_par ->prox  = TLSE_insere(NULL, p->info);
                p_par = p_par ->prox;
            }
            
        }else{
            if(!impar){
                impar = TLSE_insere(impar, p->info);
                p_impar = impar;
            }
            else{
                p_impar->prox = TLSE_insere(NULL, p->info);
                p_impar = p_impar->prox;
            }
        }
        p = p->prox;
    }

    p_impar = impar;
    while(p_impar -> prox){
        p_impar = p_impar -> prox;
    }
    p_impar -> prox = par;
    return impar;
}

int main(void){
    TLSE *l = TLSE_inicializa();
    int x;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLSE_insere(l, x);
    }while(1);
    printf("A lista original: ");
    TLSE_imprime(l);
    printf("\n");

    printf("Agora o resultado da funcao criada: ");
    TLSE * resp = i_p(l);
    TLSE_imprime(resp);
    return 0;
}