#include "TLSE.c"

/*(3) retirar todos os múltiplos de k:
-> void mult_k(TP *p, int k);
-> TP* mult_k2(TP *p, int k);
-> void mult_k3(TF *f, int k);
-> TF* mult_k4(TF *f, int k);
-> void mult_k5(TLSE *l, int k);
-> TLSE* mult_k6(TLSE *l, int k);*/

TLSE* mult_k6(TLSE *l, int k){
    TLSE * aux = TLSE_inicializa();
    TLSE * resp = TLSE_inicializa();
    TLSE * p = l;

    while(p){
        int x = p->info;
        if(x % k != 0) aux = TLSE_insere(aux, x);
        p = p->prox;
    }

    p = aux;
    while(p){
        int x = p->info;
        resp = TLSE_insere(resp, x);
        p = p->prox;
    }


    TLSE_libera(aux);
    return resp;
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

  TLSE* resp = mult_k6(l, k);
  printf("A lista sem os multiplos de k eh: \n");
  TLSE_imprime(resp);
  printf("\n");

  TLSE_libera(l);
  TLSE_libera(resp);

  return 0;
}