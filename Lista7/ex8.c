#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TLSE.c"

// Q8) Escreva uma função em C que, dadas duas listas l1 e l2 encadeadas, verifique se l1
// e l2 são iguais. As listas l1 e l2 devem permanecer inalteradas. Esta função retorna 1 se
// as listas são iguais e 0, caso contrário. O protótipo desta função é o seguinte: int igual
// (TLSE *l1, TLSE *l2).

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
    TLSE_imprime(i_p(l));
    return 0;
}