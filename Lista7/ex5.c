#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TLSE.c"

// Q5) Crie uma função em C que remova todas as ocorrências de um elemento numa lista.
// Seu protótipo O protótipo desta função é o seguinte: TLSE* rto (TLSE* l, int elem).

TLSE* rto (TLSE* l, int elem){
    //preciso garantir que terá mais de 1 elemento, ent faço esses ifs
    if(!l || (!l->prox && l->info != elem)) return l; 
    if(!l -> prox && l->info == elem) return NULL;

    TLSE * p = l;

    //achando o primeiro termo que irá substituir l
    while(p){
        if(p->info == elem){
            p = p->prox;
            l = p;
        }else break;
    }

    //agora l já está certo, só preciso percorrer normal

    TLSE * ant = l;
    p = p-> prox;

    while(p){
        if(p->info == elem){
            ant -> prox = p -> prox;
            p = ant ->prox;
        }else{
            ant = p;
            p = p->prox;
        }
    }
    free(p);
    return l;
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

    int elem;
    printf("Digite o elemento: ");
    scanf("%d", &elem);
    printf("Agora o resultado da funcao criada: ");
    TLSE * resp = rto(l, elem);
    TLSE_imprime(resp);
    TLSE_libera(resp);

    return 0;
}