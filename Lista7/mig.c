/*Q3) Escreva uma função em C que, dada uma lista l qualquer, desloque uma vez os
elementos de l, de acordo com n. Se n é ímpar, o elemento que está na última posição
passa a ser o primeiro quando a lista é deslocada. Senão, o elemento que está na
primeira posição passa a ser o último. O protótipo desta função é o seguinte: TLSE*
desloca (TLSE* l, int n).*/
#include<stdio.h>
#include<stdlib.h>
#include"TLSE.c"

void desloca (TLSE* l, int n){
    //Caso ímpar
    if(n % 2 != 0){
        //Vamos descobrir o último elemento da lista para salvá-lo
        TLSE* penultimo = l;
        TLSE* ultimo = penultimo->prox;
        while(ultimo->prox){
            ultimo = ultimo ->prox;
            penultimo = penultimo ->prox;
        }
        printf("%d", ultimo->info);

        //Agora basta indicar criar um novo nó que será encaixado no começo
        TLSE* novo = (TLSE*)malloc(sizeof(TLSE));
        novo ->info = ultimo->info;
        novo ->prox = l;
        l = novo;

        //Vamos dar free no ultimo nó para faze-lo deixar de existir
        free(ultimo);
        
        //E então o antigo penultimo apontar para null
        penultimo ->prox = NULL;

        //E finalmente retornar a deslocada para direita
        return l;
    }
}

int main(void){
  TLSE *l = TLSE_inicializa();
  int x,n;
  printf("Digite o tamanho da lista que sera inserida: ");
  scanf("%d", &n);
  do{
    scanf("%d", &x);
    if(x < 0) break;
    l = TLSE_insere(l, x);
  }while(1);
  printf("A lista original: ");
  TLSE_imprime(l);
  printf("\n");

  TLSE* deslocada = desloca(l,n);
  printf("Agora o resultado da funcao criada: ");
  TLSE_imprime(deslocada);

  TLSE_libera(l);
  TLSE_libera(deslocada);

  return 0;
}