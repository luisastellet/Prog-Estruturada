#include "TLSE.c"

// na prova eu já tinha pego a ideia de um ponteiro incrementando de um em um e outro 
// ponteiro incrementando de dois em dois, mas acabei crianod mais um também que não 
// precisava

TLSE * meio (TLSE * l, int * pos){
    TLSE * ant = l;
    (*pos) = 0;
    if(!l) return l;
    if(l && !l -> prox){
        (*pos) = 1;
        return l;
    }
    if(l && l->prox && ! l->prox->prox){
        (*pos) = 2;
        return l->prox;
    }
    ant = l;
    TLSE * m = l->prox;
    int ind = 1;

    // TLSE * p = m->prox;

    //ajustei a condição do while
    while (m -> prox){
        ind += 1;
        ant = ant->prox;
        m = m -> prox -> prox;
        
        //para não dar erro de null->prox, erro de segmentação que só vi rodando no pc
        if(!m) break;
    }
    (*pos) = ind;
    return ant;
}


int main(void){
    TLSE *l = NULL;
    int n;
    do{
        scanf("%d", &n);
        if(n < 0) break;
        l = TLSE_insere(l, n);
    }while(1);
    int pos;
    TLSE *resp = meio(l, &pos);
    if(resp) 
    printf("O elemento do meio da lista (info: %d) esta na pos %d\n", resp->info, pos); 
    TLSE_libera(l);
    return 0;
}