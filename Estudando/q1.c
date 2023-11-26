/*Questao 1
Se x for par:
quando encontrar o x na lista encadeada, retiro imediatamente o seu proximo 
se x for impar:
quando encontarr o x na lista encadeada, retiro imediatamente o seu anterior
*/
#include "TLSE.c"
TLSE* retira (TLSE * l, int x){

    //com lista vazia ou somente 1 elemento, não deve fazer nada
    if(!l || (l && !l->prox)) return l;

    TLSE * ant = l;
    TLSE * p = ant->prox;

    if(x % 2 == 0){ //tirar o proximo
        //resolvendo o primeiro fora do while
        if(l->info == x){
            TLSE * tmp = p;
            p = p->prox;
            ant->prox = p;
            free(tmp);
        }
        while(p->prox){
            if(p->info == x){
                ant = ant->prox;
                p = p->prox;
                TLSE * tmp = p;
                p = p-> prox;
                ant->prox = p;
                free(tmp);
            }else{
                ant = ant->prox;
                p = p->prox;
            }
        }
    }
    else{ //tirar o anterior
        //resolvendo o primeiro caso
        while(p->info == x){
            TLSE * tmp = ant;
            ant = ant->prox;
            p = p->prox;
            l = ant;
            free(tmp);
        }
        while(p->prox){
            if(p->prox->info == x){
                TLSE * tmp = p;
                p = p->prox;
                ant->prox = p;
                free(tmp);
            }else{
                ant = ant->prox;
                p = p->prox;
            }
        }
    }

    return l;
}

int main(void){
    int x;
    printf("Digite o n: ");
    scanf("%d", &x);
    TLSE *l = TLSE_inicializa();
    int n;
    do{
        scanf("%d", &n);
        if(n < 0) break;
        l = TLSE_insere(l, n);
    }while(1);
    printf("A lista original: ");
    TLSE_imprime(l);
    printf("\n");

    printf("A lista pos funcao: ");
    retira(l, x);
    TLSE_imprime(l);

    TLSE_libera(l);
    return 0;
}