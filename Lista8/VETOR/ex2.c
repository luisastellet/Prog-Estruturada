#include "alm.c"

/*(b) uma função que, dada uma fila f, retorne uma nova fila, com todos os elementos de f,
porém invertida em relação a fila f. Não é possível alterar a ordem dos elementos da fila de
entrada. A função deve obedecer o seguinte protótipo: TFila* inv_fila (TFila *f);*/

TF* inv_fila (TF *f){
    //Criando pilha auxiliar e fila final
    TP * pilha_aux = TP_inicializa();
    TF * fila_final = TF_inicializa();

    while(f->n >0){
        int x = TF_retira(f);
        TP_push(pilha_aux,x);
    }

    while(pilha_aux->topo){
        int x = TP_pop(pilha_aux);
        TF_insere(fila_final, x);
    }

    TP_libera(pilha_aux);

    return fila_final;
}

int main(void){
    TF *f = TF_inicializa();
    printf("f:\n");
    int n;
    while(1){
        scanf("%d", &n);
        if(n < 0) break;
        TF_insere(f, n);
    }
    printf("A fila original eh: \n");
    TF_imprime(f);
    printf("\n");

    TF* resp = inv_fila(f);
    printf("A fila gerada eh: \n");
    TF_imprime(resp);
    TF_libera(f);

    return 0;
}