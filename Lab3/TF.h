#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
    int vet[5];
    int inicio;
    int n;
}TF;

void TF_insere(TF *f, int elem);
int TF_vazia(TF *f);
void TF_libera(TF *f);
TF *TF_inicializa(void);
int TF_retira(TF *f);
void TF_imprime(TF *f);