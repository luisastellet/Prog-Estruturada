#include "alm.c"

/*(c) escreva uma função que, dadas duas filas f1 e f2, retorne uma fila, contendo todos os
elementos de f1 seguidos pelos elementos de f2, e obedecendo a ordem de entrada dos
inteiros nas filas de entrada. Além disso, as filas de entrada devem permanecer inalteradas. A
função deve obedecer ao seguinte protótipo: TFila* Junta_Filas (TFila *f1, TFila *f2);*/

TF* Junta_Filas (TF *f1, TF *f2){
    TF * resp = TF_inicializa();
    TLSE * p_f1 = f1->ini;
    TLSE * p_f2 = f2->ini;

    while(p_f1){
        int x = p_f1->info;
        TF_insere(resp, x);
        p_f1 = p_f1->prox;
    }

    while(p_f2){
        int x = p_f2->info;
        TF_insere(resp, x);
        p_f2 = p_f2->prox;
    }

    return resp;
}

int main(void){

    TF *f1 = TF_inicializa();
    printf("f:\n");
    int n,m;
    while(1){
    scanf("%d", &n);
    if(n < 0) break;
    TF_insere(f1, n);
    }
    printf("f:\n");

    TF *f2 = TF_inicializa();
    while(1){
    scanf("%d", &m);
    if(m < 0) break;
    TF_insere(f2, m);
    }
    printf("A fila original 1 eh: ");
    TF_imprime(f1);
    printf("\n");

    printf("A fila original 2 eh: ");
    TF_imprime(f2);
    printf("\n");

    TF* resp = Junta_Filas(f1,f2);
    printf("A fila gerada eh: \n");
    TF_imprime(resp);

    TF_libera(resp);
    TF_libera(f1);
    TF_libera(f2);
    return 0;
}