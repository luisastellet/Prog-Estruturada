//implementação de vetor estático
#include "TF.h"
#include "TLSE.c"

TF *TF_inicializa(void){
    //alocando o discritor
    TF * f = (TF*)malloc(sizeof(TF));
    f->n = 0;
    f->inicio = 0;
    return f;
}

void TF_insere(TF *f, int elem){
    //se o vetor tá cheio não tem como inserir
    if(f->n == 5){
        printf("O vetor esta cheio, nao e possivel inserir um elemento!");
        exit(1);
    }
    //se o início está diferente de zero, copio todo mundo pro início
    if(f->inicio != 0){
        for(int i=0; i<f->n; i++) f->vet[i] = f->vet[f->inicio++];
        f->inicio = 0;
    }
    f->vet[f->n] = elem;
    f->n++;
    return;
}

int TF_retira(TF *f){
    //retira sempre do início
    if(TF_vazia(f)) exit(1);
    int x = f->vet[f->inicio++];
    f->n--;
    return x;
    //não tem problema a primeira posição ficar vazia, pq se eu for inserir alguém depois, a função insere ajusta isso
}

void TF_libera(TF *f){
    //como o vetor é estático, só liberamos o descritor
    free(f);
    return;
}

int TF_vazia(TF *f){
    //n é o número de elementos já no vetor
    if(f->n == 0) return 1;
    return 0;
}

void TF_imprime(TF *f){
    if(TF_vazia(f)) return;
    for(int i=f->inicio; i<(f->inicio + f->n); i++) printf("%d ", f->vet[i]);
    return;
}