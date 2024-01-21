
#include "TLSE.c"

// Nessa questão a minha ideia foi criar uma expressão que me desse a quantidade de nós 
// que eu teria no final (seria esse cont += (x-1)*2 + 1 em casos de x e apenas cont += 1 
// em casos de não x). Depois disso eu ajusto a ordem correta na minha lista auxiliar 
// deixando-a com todos os termos necessários. Por fim preciso retornálos à lista antiga, 
// reaproveito os nós já existentes, apenas atualizando o info e insiro novos nós no final 
// da lista se fosse necessário. 

// Poderia olhar com mais carinho pra essa questão? Minha lógica funciona tão bonitinho, na 
// prova eu cheguei até a ordem dos termos, só não consegui terminar, acabei priorizando a 
// questão 4 pra não ficar em branco.

void misc(TLSE * l, int x){
    if(x < 2 || !l) return;
    TLSE * aux = NULL;
    int cont = 0;
    TLSE * p = l; 
    while(p){
        if (p->info == x) cont += (x-1)*2 + 1;
        else cont++;
        //esqueci de incrementar o ponteiro
        p = p->prox;
    }

    for(int i=0; i<cont; i++) aux = TLSE_insere(aux, 0);
    p = l;
    TLSE * p_aux = aux;
    while (p){
        if(p->info == x){
            for(int i=1; i<x; i++){
                p_aux -> info = i;
                p_aux = p_aux -> prox;
            }
            p_aux -> info = x;
            p_aux = p_aux -> prox;
            for(int i=1; i<x; i++){
                p_aux -> info = i;
                p_aux = p_aux -> prox;
            }
        }else{
            p_aux -> info = p->info;
            p_aux = p_aux->prox;
        }
        p = p->prox;
    }

    //até aqui já tenho uma lista auxiliar toda montada nas ordens certinhas
    //na prova não consegui retornar pra lista original, faltou esse trecho:
    p = l;
    p_aux = aux;
    while(p_aux){
        if(!p -> prox && p_aux->prox) p -> prox = TLSE_insere(NULL, 0);
        p->info = p_aux -> info;
        p = p->prox;
        p_aux = p_aux-> prox;
    }

    //retornando pro código que estava na prova
    TLSE_libera(aux);
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

    printf("Digite o x: ");
    scanf("%d", &n);
    misc(l, n);
    TLSE_imprime(l);
    printf("\n");

    TLSE_libera(l);
    return 0;
}