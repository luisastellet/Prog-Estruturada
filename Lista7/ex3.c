#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TLSE.c"

// Q3) Escreva uma função em C que, dada uma lista l qualquer, desloque uma vez os
// elementos de l, de acordo com n. Se n é ímpar, o elemento que está na última posição
// passa a ser o primeiro quando a lista é deslocada. Senão, o elemento que está na
// primeira posição passa a ser o último. O protótipo desta função é o seguinte: TLSE*
// desloca (TLSE* l, int n).

TLSE * desloca (TLSE* l, int n){
  if (!l || !l->prox) return l; //se for null ou só tiver 1 elemento, retorna o l pq nada será feito
  TLSE * p = l; //ponteiro que vai andar na lista
  if(n % 2 == 0){ // se n for par
      int x = p -> info; //guarda o primeiro valor que entra na última posição
      while (p -> prox){
          p -> info = p -> prox -> info;
          p = p-> prox;
      }
      p -> info = x;
  }
  else{ // se n for ímpar
      int atual=l->info, anterior=l->info; // primeiro começa guardando os primeiros valores
      while(p){
          if(p != l){
              atual = p->info;
              p->info = anterior;
              anterior = atual;
          }
          p = p->prox;
      }

      l->info = atual;
  }
  return l;
}

int main(void){
  TLSE *l = TLSE_inicializa();
  int x, n;
  do{
    scanf("%d", &x);
    if(x < 0) break;
    l = TLSE_insere(l, x);
  }while(1);
    printf("Digite o n: ");
    scanf("%d", &n);

  printf("\nA lista original: ");
  TLSE_imprime(l);
  printf("\n");

  printf("Agora o resultado da funcao criada: ");
  TLSE_imprime(desloca(l, n));
  TLSE_libera(l);


  return 0;
}