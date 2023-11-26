/*Questão 2
Tenho uma pilha, e é passado um n qualquer. Dado este n, tenho que manter minha pilha original inalterada 
(com mesma ordem de elementos), e criar uma nova pilha (copia), onde a toda vez que encontrar o n, retirar o 
antecessor e predecessor desta copia, mantendo a ordem como fosse a pilha original, somente retirado os 
elementos pela regra do antecessor e sucessor.
*/
#include "TP.c"

TP * retira_n(TP * p, int n){
    TP * copia = TP_inicializa();
    TP * aux = TP_inicializa();

    while(!TP_vazia(p)){
        int x = TP_pop(p);
        TP_push(aux, x);
    }

    while(!TP_vazia(aux)){
        int y = TP_pop(aux);
        TP_push(p, y),
        TP_push(copia, y);
    }

    //agora a p está igual antes, a cópia está igual a p e aux está vazia
    int ver = 1;
    while(!TP_vazia(copia)){
        if(ver){
            int x = TP_pop(copia);
            if(x == n){
                if(!TP_vazia(aux)){
                    int w = TP_pop(aux);
                }
                ver = 0;
            }
            TP_push(aux, x);
        }else{
            int z = TP_pop(copia);
            ver = 1;
        }
    }

    //passando de aux para copia
    while(!TP_vazia(aux)){
        int s = TP_pop(aux);
        TP_push(copia, s);
    }

    TP_libera(aux);
    return copia;
}

int main(void){
    TP *p = TP_inicializa();
    int x;
    printf("Digite o numero: ");
    scanf("%d", &x);
    printf("p:\n");
    int n;
    while(1){
      scanf("%d", &n);
      if(n < 0) break;
      TP_push(p, n);
    }
    printf("A pilha original eh: \n");
    TP_imprime(p);
    printf("\n");

    printf("A pilha sem os antecessores e sucessores de n eh: \n");
    TP * cop = retira_n(p, x);
    TP_imprime(cop);
    printf("\n");

    TP_libera(cop);
    TP_libera(p);

  return 0;
}
