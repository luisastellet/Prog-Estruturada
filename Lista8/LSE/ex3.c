#include "alm.c"

/*(c) escreva uma função que, dadas duas filas f1 e f2, retorne uma fila, contendo todos os
elementos de f1 seguidos pelos elementos de f2, e obedecendo a ordem de entrada dos
inteiros nas filas de entrada. Além disso, as filas de entrada devem permanecer inalteradas. A
função deve obedecer ao seguinte protótipo: TFila* Junta_Filas (TFila *f1, TFila *f2);*/

TF* Junta_Filas (TF *f1, TF *f2){
    TF * resp = TF_inicializa();
    TF * f1_aux = TF_inicializa();
    TF * f2_aux = TF_inicializa();

    while(!TF_vazia(f1)){
        int x = TF_retira(f1);
        TF_insere(f1_aux, x);
        TF_insere(resp, x);
    }

    while(!TF_vazia(f1_aux)){
        int y = TF_retira(f1_aux);
        TF_insere(f1, y);
    }

    TF_libera(f1_aux);

    while(!TF_vazia(f2)){
        int x = TF_retira(f2);
        TF_insere(f2_aux, x);
        TF_insere(resp, x);
    }

    while(!TF_vazia(f2_aux)){
        int y = TF_retira(f2_aux);
        TF_insere(f2, y);
    }

    TF_libera(f2_aux);

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