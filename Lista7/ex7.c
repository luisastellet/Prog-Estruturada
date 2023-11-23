#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TLSE.c"

// Q7) Refaça Q6, alterando a lista passada como parâmetro. O protótipo desta função é o
// seguinte: void i_p (TLSE *l).

void i_p (TLSE *l){
    TLSE * p = l;

    while(p){
        if (p->info % 2 ==0) p=p->prox;
        else break;
    }
    //p sai guardando o ponteiro do primeiro ímpar da lista, logo o primeiro elemento da lista
    TLSE *p_impar = p->prox; //sai do primeiro ímpar
    while(p_impar->prox){
        if(p_impar-> info % 2 != 0){ //é ímpar
            p->prox = p_impar;
            p = p_impar;
        }
        p_impar = p_impar->prox;
    }
    //p sai apontando pro último ímpar e p_impar sai apontando pra null;

    // !!! l = p; isso tem q vir depois, pra n perder quem veio antes

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
    i_p(l);
    TLSE_imprime(l);
    TLSE_libera(l);

    return 0;
}