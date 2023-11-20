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
  int cont=0, cont_voltando=0;

//percorrendo a lista toda pra ver quantos elementos temos 
  while(p){
    cont++; //total de elementos
    p = p -> prox;
  }

  p = l;
  int posicao = 1;
  while(p){

    int cont_aux = posicao;
    TLSE * final = p;


    while(cont_aux < cont){
      final = final -> prox;
      cont_aux++;
    }

    if(cont_aux > cont) break; // para não fazer trocas por si mesmo

    //fazendo as trocas
    int tmp = p -> info;
    p -> info = final -> info;
    final -> info = tmp;


    cont--;
    posicao++;
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
  TLSE_libera(l);
  return 0;
}

