#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TLSE.c"

// Q2) Refaça a Q1, escrevendo uma função em C que, dada uma lista l qualquer, inverta os
// elementos de l em uma outra lista de saída. Portanto, a lista de entrada não pode ser
// alterada. O protótipo da função de inversão é o seguinte: TLSE* inverte (TLSE* l).

//CRIANDO TLSE NOVA
TLSE* inverte (TLSE* l){
    TLSE * laux = TLSE_inicializa(); // guarda a 1° posição da auxiliar
    TLSE * p1 = l; //p1 vai percorrer a lista original

    //preenchendo a lista auxiliar de forma reversa
    while(p1){
        laux = TLSE_insere(laux, p1 -> info);
        p1 = p1 -> prox;
    }

    return laux;
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
  TLSE * laux = inverte(l);
  TLSE_imprime(laux);
  TLSE_libera(l);
  TLSE_libera(laux);


  return 0;
}