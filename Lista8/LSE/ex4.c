#include "alm.c"

/*(d) escreva uma função que receba uma pilha e retire todos os elementos pares desta pilha. A
função deve obedecer o seguinte protótipo: void retira_pares (TPilha *p);*/

void retira_pares (TP *p){
    //pilha que irá guardar somente os ímpares
    TP * pilha_aux = TP_inicializa();
    while(p->topo){
        //se for par só dá pop
        if(p->topo->info % 2 == 0){
            int x = TP_pop(p);
        }
        //se for ímpar dá pop e dá push na auxiliar
        else{
            int x = TP_pop(p);
            TP_push(pilha_aux, x);
        }
    }
    //retornando os ímpares para a filha original
    while(pilha_aux->topo){
        int x = TP_pop(pilha_aux);
        TP_push(p, x);
    }

    //liberanod a pilha auxiliar que criei
    TP_libera(pilha_aux);

    return;
}

int main(void){
    TP *p = TP_inicializa();
    printf("p:\n");
    int n;
    while(1){
      scanf("%d", &n);
      if(n < 0) break;
      TP_push(p, n);
    }

    //printando a pilha original
    printf("A pilha original: \n");
    TP_imprime(p);
    printf("\n");

    //chamando a função
    retira_pares(p);

    //printando a pilha final
    printf("A pilha pos funcao criada: ");
    printf("\n");
    TP_imprime(p);
    TP_libera(p);

  return 0;
}
