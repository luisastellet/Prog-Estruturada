#include "TF.c"

/*(3) retirar todos os múltiplos de k:
-> void mult_k(TP *p, int k);
-> TP* mult_k2(TP *p, int k);
-> void mult_k3(TF *f, int k);
-> TF* mult_k4(TF *f, int k);
-> void mult_k5(TLSE *l, int k);
-> TLSE* mult_k6(TLSE *l, int k);*/

void mult_k3(TF *f, int k){
    TF * aux = TF_inicializa();

    while(!TF_vazia(f)){
        int x = TF_retira(f);
        if(x % k != 0) TF_insere(aux, x);
    }

    while(!TF_vazia(aux)){
        int y = TF_retira(aux);
        TF_insere(f, y);
    }

    TF_libera(aux);
    return;
}

int main(void){
    int k;
    printf("Qual o k? ");
    scanf("%d", &k);
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

    mult_k3(f,k);
    printf("A fila sem os multiplos de k eh: \n");
    TF_imprime(f);
    printf("\n");

    TF_libera(f);

  return 0;
}