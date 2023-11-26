/*(4) Escreva versões iterativa e recursiva para as seguintes funções:
-> verificar se os elementos que estão nas posições pares e ímpares são pares e ímpares, respectivamente:
int misc (TLSE *l);*/
#include "TLSE.c"

int misc (TLSE *l){
    //considerei nó 1, nó 2, nó 3 ....
    int cont=0;
    TLSE * p = l;
    while(p){
        cont++;
        if(cont % 2 == 0){
            if(p->info % 2 != 0) return 0;
        }else{
            if(cont % 2 == 0) return 0;
        }
        p = p->prox;
    }

    return 1;
}

int main(void){
    TLSE* l = TLSE_inicializa();
    int n;
    printf("l:\n");
    while(1){
        scanf("%d", &n);
        if(n < 0) break;
        l = TLSE_insere(l, n);
    }
    printf("A lista original eh: \n");
    TLSE_imprime(l); 
    printf("\n");
;
    printf("A resposta eh: *** %d *** \n", misc(l));
    printf("\n");

    TLSE_libera(l);

    return 0;
}