#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TLSE.c"

// Q1) Considerando as seguintes declarações de lista encadeada:

// typedef struct lista{
// int info;
// struct lista *prox;
// }TLSE;

// Escreva uma função em C que, dada uma lista l qualquer, inverta os elementos de l. O
// protótipo da função de inversão é o seguinte: void inverte (TLSE* l).

void inverte (TLSE* l){
    TLSE * p = l;
    int cont = 0;
    for(p=l;p;p=p->prox) cont++;

    int fim = cont-1;
    p = l;
    for(int i=0; i<cont/2; i++){
      TLSE * q = p;
      for(int j=0; j<fim;j++) q = q ->prox;
      int tmp = p->info;
      p ->info = q->info;
      q->info = tmp;

      fim -= 2;
      p = p->prox;
    }

    return;
    
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

  inverte(l);
  printf("Agora o resultado da funcao criada: ");
  TLSE_imprime(l);

  return 0;
}
