#include "TLSE.h"

int main(void){
  TLSE *l = TLSE_inicializa();
  int x;
  do{
    scanf("%d", &x);
    if(x < 0) break;
    l = TLSE_insere(l, x);
  }while(1);
  TLSE_imprime(l);
  printf("\n");

  return 0;
}

int main(void){
  TLSE *l = TLSE_inicializa();
  int x;
  do{
    scanf("%d", &x);
    if(x < 0) break;
    l = TLSE_insere(l, x);
  }while(1);
  printf("A lista original: ");
  TLSE_imprime(l);
  printf("\n");

  printf("Agora o resultado da funcao criada: ");
  //TLSE_imprime(CHAMAR A FUNÇÃO AQUI);
  TLSE_libera(l);

  return 0;
}