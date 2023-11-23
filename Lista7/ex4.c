#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TLSE.c"

// Q4) Implemente uma função que copie uma lista. A lista original deve permanecer
// inalterada. O protótipo da função é o seguinte: TLSE *copia (TLSE *l).

TLSE * insere_fim(TLSE *l, int x){
  TLSE * novo = (TLSE*)malloc(sizeof(TLSE));
  
  novo -> info = x;
  novo -> prox = NULL;
  return novo;
}

TLSE *copia (TLSE *l){
  if(!l) return l;
  TLSE * copia = TLSE_inicializa();
  TLSE * p_original = l;

  copia = TLSE_insere(copia, p_original -> info); //o primeiro termo já foi, agr copia n é vazio
  p_original = p_original->prox;
  TLSE * p_copia = copia;

  while(p_original){
      p_copia -> prox = insere_fim(p_copia, p_original->info);
      
      p_original = p_original->prox;
      p_copia = p_copia->prox;
  }
  free(p_original);
  return copia;
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
  TLSE * cop = copia(l);
  TLSE_imprime(cop);
  TLSE_libera(l);

  return 0;
}