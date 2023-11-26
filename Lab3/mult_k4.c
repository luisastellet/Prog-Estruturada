#include "TF.c"

/*(3) retirar todos os múltiplos de k:
-> void mult_k(TP *p, int k);
-> TP* mult_k2(TP *p, int k);
-> void mult_k3(TF *f, int k);
-> TF* mult_k4(TF *f, int k);
-> void mult_k5(TLSE *l, int k);
-> TLSE* mult_k6(TLSE *l, int k);*/

TF* mult_k4(TF *f, int k){
    TF * aux = TF_inicializa();

    while(!TF_vazia(f)){
        int x = TF_retira(f);
        if(x % k != 0) TF_insere(aux, x);
    }

    return aux;
}

int main(void){
    TF* f = TF_inicializa();
    int n, k;
    printf("Qual o k? ");
    scanf("%d", &k);
    printf("f:\n");
    while(1){
      scanf("%d", &n);
      if(n < 0) break;
      TF_insere(f, n);
    }
    printf("A fila original eh: \n");
    TF_imprime(f);
    printf("\n");

    TF* resp = mult_k4(f, k);
    printf("A fila sem os multiplos de k eh: \n");
    TF_imprime(resp);
    printf("\n");

    TF_libera(f);
    TF_libera(resp);

  return 0;
}