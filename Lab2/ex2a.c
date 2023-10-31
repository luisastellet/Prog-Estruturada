#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct prod{
  char misc[51];
  float preco;
}TPROD;

int compara(const void *a, const void *b){
    //ajustando a função
    TPROD ** pont_a = (TPROD **) a;
    TPROD ** pont_b = (TPROD **) b;
    // TPROD *x = (TPROD **) (*a);
    TPROD * prod_a = (*pont_a);
    TPROD * prod_b = (*pont_b);

    if(strcmp(&prod_a->misc[8], &prod_b->misc[8]) < 0) return -1;
    if(strcmp(&prod_a->misc[8], &prod_b->misc[8]) > 0) return 1;
    //else
    if(strcmp(&prod_a->misc[4], &prod_b->misc[4]) < 0) return -1;
    if(strcmp(&prod_a->misc[4], &prod_b->misc[4]) > 0) return 1;
    //else
    if(strcmp(&prod_a->misc[2], &prod_b->misc[2]) < 0) return -1;
    if(strcmp(&prod_a->misc[2], &prod_b->misc[2]) > 0) return 1;
    //else
    if(strcmp(prod_a->misc, prod_b->misc) < 0) return -1; //por ser o primeiro, não precisa do & e nem da posição 0
    if(strcmp(prod_a->misc, prod_b->misc) > 0) return 1;
    //else
    if((prod_a->preco) > (prod_b -> preco)) return -1;
    return 1;
}

void ordena_a(TPROD **vet, int n){
    qsort(vet, n, sizeof(TPROD*), compara);
}

int main(void){
  int n;
  do{
    scanf("%d", &n);
    if(n > 0)break;
  }while(1);

  TPROD **vet = (TPROD **) malloc(sizeof(TPROD *) * n);
  int i;
  for(i = 0; i < n; i++){
    vet[i] = (TPROD *) malloc(sizeof(TPROD));
    scanf(" %50[^\n]", vet[i]->misc);
    scanf("%f", &vet[i]->preco);
  }
  ordena_a(vet, n);
  for(i = 0; i < n; i++){
    printf("%s\t%f\n", vet[i]->misc, vet[i]->preco);
    free(vet[i]);
  }
  free(vet);

  return 0;
}

