#include "TLSE.c"

/*(3) retirar todos os múltiplos de k:
-> void mult_k(TP *p, int k);
-> TP* mult_k2(TP *p, int k);
-> void mult_k3(TF *f, int k);
-> TF* mult_k4(TF *f, int k);
-> void mult_k5(TLSE *l, int k);
-> TLSE* mult_k6(TLSE *l, int k);*/

void mult_k5(TLSE *l, int k){
    if(!l) return;
    TLSE * aux = TLSE_inicializa();
    TLSE * p = l;

    //vamos ajustar o primeiro número fora do agortimo ja q n podemos mudar o l, ent só coloco o primeiro não multiplo na posição do l 
    while(p){
        if(p->info % k != 0){
            int tmp = l->info;
            l->info = p->info;
            p->info = tmp;
            break;
        }
        p = p->prox;
    }

    TLSE* ant = l;
    p = ant->prox;

    while(p){
        if(p->info % k == 0){
            TLSE * temp = p;
            ant->prox = p->prox;
            p = p->prox;
            free(temp);
        }else{
            ant = p;
            p = p->prox;
        }
    }

    return;
}

int main(void){
    TLSE* l = TLSE_inicializa();
    int n, k;
    printf("Qual o k? ");
    scanf("%d", &k);
    printf("l:\n");
    while(1){
        scanf("%d", &n);
        if(n < 0) break;
        l = TLSE_insere(l, n);
    }
    printf("A lista original eh: \n");
    TLSE_imprime(l); 
    printf("\n");

    mult_k5(l, k);
    printf("A lista sem os multiplos de k eh: \n");
    TLSE_imprime(l);
    printf("\n");

    TLSE_libera(l);

    return 0;
}