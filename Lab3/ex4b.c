/*-> dados dois números N1 e N2, a cada par de N1 e N2 (ou N2 e N1), troque-os de lugar:
void troca (TLSE *l, int N1, int N2);*/

#include "TLSE.c"

void troca (TLSE *l, int N1, int N2){
    TLSE * copia = TLSE_inicializa();
    TLSE * p_original = l;
    TLSE * p_copia = copia;

    //fazendo a primeira inserção no início
    copia = TLSE_insere(copia, l->info);
    p_original= p_original->prox;
    p_copia = copia;

    //fiz a cópia já, inserindo no fim
    while(p_original){
        p_copia->prox = TLSE_insere(NULL, p_original->info);
        p_copia = p_copia->prox;
        p_original = p_original->prox; 
    }

    p_original = l; p_copia = copia;
    TLSE * q_original;
    TLSE * q_copia;
    while(p_original){
        if(p_copia->info == N1){
            q_original = p_original->prox;
            q_copia = p_copia->prox;
            while(q_copia){
                if(q_copia->info == N2){
                    int tmp = q_original->info;
                    q_original->info = p_original->info;
                    p_original->info = tmp;
                    q_copia->info = N1+N2;
                    p_copia->info = -1; 
                    //já achei o n2 para esse n1
                    break;
                }else{
                    q_original = q_original->prox;
                    q_copia = q_copia->prox;
                }
            } 
        }else if(p_copia->info == N2){
            q_original = p_original->prox;
            q_copia = p_copia->prox;
            while(q_copia){
                if(q_copia->info == N1){
                    int tmp = q_original->info;
                    q_original->info = p_original->info;
                    p_original->info = tmp;
                    q_copia->info = -1;
                    p_copia->info = -1; 
                    //já achei o n2 para esse n1
                    break;
                }else{
                    q_original = q_original->prox;
                    q_copia = q_copia->prox;
                }
            }
        }
        p_copia = p_copia->prox;
        p_original = p_original->prox;
    }

    // TLSE_libera(copia);
    return;
}

int main(void){
    TLSE* l = TLSE_inicializa();
    int n, n1, n2;
    printf("Digite N1: ");
    scanf("%d", &n1);
    printf("Digite o N2: ");
    scanf("%d", &n2);

    printf("l:\n");
    while(1){
        scanf("%d", &n);
        if(n < 0) break;
        l = TLSE_insere(l, n);
    }

    printf("A lista original eh: \n");
    TLSE_imprime(l); 
    printf("\n");

    printf("A lista pos trocas eh: ");
    troca(l, n1, n2);
    TLSE_imprime(l);
    printf("\n");

    TLSE_libera(l);

    return 0;
}