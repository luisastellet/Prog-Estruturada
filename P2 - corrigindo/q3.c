#include "TLSE.c"

void ret_nao_mult_N(TLSE * l, int n){
    
    if((!l) || (n<=1) || (l->info % n == 0 && !l->prox)) return;
    if(l->info % n != 0 && !l->prox) {
        //adicionando isso pro ultimo receber null
        l = l->prox;
        return;
    }
    TLSE * ant = l, * p = l -> prox;
    if(ant->info % n != 0){
        ant -> info = p -> info;
        TLSE * tmp = p;
        p = p -> prox;
        free(tmp);
        ant -> prox = p;
        ret_nao_mult_N(l, n);
    } 
    //adicionei a chamada no else como anotado na prova
    else ret_nao_mult_N(l->prox, n); 
    return;
}

int main(void){
    TLSE *l = NULL;
    int n;
    do{
        scanf("%d", &n);
        if(n < 0) break;
        l = TLSE_insere(l, n);
    }while(1);
    printf("Digite o n: ");
    scanf("%d", &n);
    ret_nao_mult_N(l, n);
    TLSE_imprime(l);
    printf("\n");

    TLSE_libera(l);
    return 0;
}