#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TLSE.c"

int main(){
    TLSE * lista = TLSE_inicializa();
    lista = TLSE_insere(lista, 1);
    lista = TLSE_insere(lista, 2);
    lista = TLSE_insere(lista, 3);
    lista = TLSE_insere(lista, 4);
    TLSE_imprime(lista);
    TLSE * p = lista;
    printf("\n");
    printf("%d \n",p->prox->prox->prox->info);
    
    return 0;
}

//Pode usar p->prox->prox->prox...