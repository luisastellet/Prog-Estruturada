#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TLSE.c"

// Q11) Defina uma função em C que, dada uma lista l qualquer, ordene os elementos de l
// em uma outra lista de saída. Portanto, a lista de entrada não pode ser alterada. O
// protótipo da função desta função é o seguinte: TLSE * ordena (TLSE* l).

TLSE * ordena (TLSE* l){
    //vou achar o menor, colocar no fim da ord, achar o menor, colocar no fim da ord...
    TLSE * ord = NULL;
    TLSE * p_ord = ord;

    //l é o inicio da lista orginal 
    //ord é o início da lista q será ordenada
    //p_orde é o ponteiro que vou usar pra fazer comparações

    //povoando a lista ord na mesma ordem da original;
    for(TLSE * p = l; p; p=p->prox){
        if(!p_ord){
            p_ord = TLSE_insere(p_ord, p->info);
            ord = p_ord;
        }
        else{
            p_ord -> prox = TLSE_insere(NULL, p->info);
            p_ord = p_ord->prox;
        }
    }

    for(TLSE * p = ord; p; p=p->prox){
        //menor sempre vai guardar a "posição", o ponteiro do menor da rodada
        TLSE * menor = p;
        for(TLSE * q = p->prox; q; q=q->prox){
            if(q->info < menor->info) menor = q;
        }
        int tmp = p->info;
        p->info = menor -> info;
        menor -> info = tmp;
    }
    return ord;
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

  TLSE * rsp = ordena(l);
  printf("Agora o resultado da funcao criada: ");
  TLSE_imprime(rsp);

  TLSE_libera(rsp);
  TLSE_libera(l);


  return 0;
}