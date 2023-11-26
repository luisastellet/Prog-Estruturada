#include "TP.c"

/*(3) retirar todos os múltiplos de k:
-> void mult_k(TP *p, int k);
-> TP* mult_k2(TP *p, int k);
-> void mult_k3(TF *f, int k);
-> TF* mult_k4(TF *f, int k);
-> void mult_k5(TLSE *l, int k);
-> TLSE* mult_k6(TLSE *l, int k);*/

TP* mult_k2(TP *p, int k){
    if(TP_vazia(p)) exit(1);
    TP * aux = TP_inicializa();
    TP * resp = TP_inicializa();

    while(!TP_vazia(p)){
        int x = TP_pop(p);
        if (x % k != 0) TP_push(aux, x);
    }

    while(!TP_vazia(aux)){
        int y = TP_pop(aux);
        TP_push(resp, y);
    }

    TP_libera(aux);
    return resp;
}

int main(void){
    TP *p = TP_inicializa();
    int n, k;
    printf("Qual o k? ");
    scanf("%d", &k);
    printf("p:\n");
    while(1){
        scanf("%d", &n);
        if(n < 0) break;
        TP_push(p, n);
    }
    printf("A pilha original eh: \n");
    TP_imprime(p);
    printf("\n");

    TP* resp = mult_k2(p, k);
    printf("A pilha sem os multiplos de k eh: \n");
    TP_imprime(resp);
    printf("\n");
    TP_libera(resp);
    TP_libera(p);

    return 0;
}
