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

  //PROBLEMAS: descobrir qual o elemento da vez e o ponteiro dele
  //cont_indo vai percorrer a lista toda sempre até chegar no elemento que eu quero (ultimo, penultimo,...)
  //cont_voltando vai ser o meu controle que me diz qual o elemento da vez, o último, o penúltimo...
  int cont_indo=0, cont_voltando;

  //percorrendo a lista toda pra ver quantos elementos temos 
  while(p){
    cont_indo++;
    p = p -> prox;
  }

  cont_voltando = cont_indo; //colocando o cont_voltando no final da lista, igualando ao total de nós

//agora cont_indo vai andar até achar o termo final e posição_troca vai ajustar o termo do início
  cont_indo = 1; 
  int posicao_troca = 1; //foi necessário para eu seguir a minha lógica de 1° nó, 2° nó... 
  
  for(p = l; p; p = p -> prox){
    TLSE * q = p;

    //chegando na posição final
    while (cont_indo < cont_voltando){
      q = q -> prox;
      cont_indo++;
    }

    //trocando o da posição p com o da posição q
    int tmp = p -> info;
    p -> info = q -> info;
    q -> info = tmp;

    //ajustes para a próxima troca
    cont_voltando--;
    posicao_troca++;
    cont_indo = posicao_troca;
  }
  free(p);
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

