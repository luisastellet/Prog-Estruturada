#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// (b) mesmos critérios de (a): void ordena_b(TPROD *vet, int n);

typedef struct prod{
    char misc[51]; //8 primeiros ddmmaaaa e 42 nome
    float preco;
}TPROD;

int compara(const void *a, const void *b){
    //ajustando a função
    TPROD * prod_a = (TPROD *) a;
    TPROD * prod_b = (TPROD *) b;

    //Compara nome
    if(strcmp(&prod_a->misc[8], &prod_b->misc[8]) < 0) return -1;
    if(strcmp(&prod_a->misc[8], &prod_b->misc[8]) > 0) return 1;

    //Compara ano
    if(strcmp(&prod_a->misc[4], &prod_b->misc[4]) < 0) return -1;
    if(strcmp(&prod_a->misc[4], &prod_b->misc[4]) > 0) return 1;

    //Compara mês
    if(strcmp(&prod_a->misc[2], &prod_b->misc[2]) < 0) return -1;
    if(strcmp(&prod_a->misc[2], &prod_b->misc[2]) > 0) return 1;

    //Compara o dia
    if(strcmp(prod_a->misc, prod_b->misc) < 0) return -1; //por ser o primeiro, não precisa do & e nem da posição 0
    if(strcmp(prod_a->misc, prod_b->misc) > 0) return 1;
    
    //else
    if((prod_a->preco) > (prod_b -> preco)) return -1;
    return 1;
}

void ordena_b(TPROD *vet, int n){
    qsort(vet, n, sizeof(TPROD), compara);
}

int main(void){
  int n;
  do{
    scanf("%d", &n);
    if(n > 0)break;
  }while(1);

  TPROD *vet = (TPROD *) malloc(sizeof(TPROD) * n);
  int i;
  for(i = 0; i < n; i++){
    scanf(" %50[^\n]", vet[i].misc);
    scanf("%f", &vet[i].preco);
  }
  ordena_b(vet, n);
  for(i = 0; i < n; i++){
    printf("%s\t%f\n", vet[i].misc, vet[i].preco);
  }
  free(vet);

  return 0;
}