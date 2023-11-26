#include "TLSEV.c"

TNO* meio(TLSEV *l, int *pos){
    int indice = l->prim;
    int limitador_meio = l->num_elem / 2;

    //percorrendo o vetor (quero a posição do meio - 1 -> indice)
    for(int j = 0; j < limitador_meio; j++){

        //ini guarda a posição do primeiro elemento no vetor e tem q ir ajustando pra próxima inserção, para eu saber em qual posição do vetor eu to (como se fosse um ->prox na LSE)
        //prox_no tá acessando o próximo índice que recebeu um número
        indice = l -> vet_elem[indice] -> prox_no;

        //usa conteúdo pq pos guarda endereço
        //passando o índice do vetor aonde está o elemento do meio
        (*pos) = indice;
    }

    //retorna o ponteiro da posição do meio
    TNO * numero = l->vet_elem[indice];

    return numero;
}

int main(void){
    int n;
    scanf("%d", &n);
    if(n <= 0) return 0;
    TLSEV *l = TLSEV_inicializa(n);
    int i;
    int mat;
    float nota;
    char nome[31];
    for(i = 0; i < n; i++){
    scanf("%d%f", &mat, &nota);
    scanf(" %30[^\n]", nome);
    TLSEV_insere_inicio(l, mat, nota, nome);
    }
    printf("Lista:\n");
    TLSEV_imprime(l);
    int pos = -1;
    TNO *elem_meio;
    elem_meio = meio(l, &pos);
    if(pos != -1){
    printf("Elemento do meio esta na posicao %d: ", pos);
    printf("%d %.1f %s\n", elem_meio->mat, elem_meio->nota, elem_meio->nome);
    }
    TLSEV_libera(l);
    return 0;  
}