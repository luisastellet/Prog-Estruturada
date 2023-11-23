#include "alm.c"

/*(e) escreva uma função que, dada uma pilha p, retorne uma fila, contendo todos os elementos
de p, e obedecendo a ordem de entrada dos inteiros em p, isto é, o primeiro inteiro que sair da
pilha p deve ser o primeiro inteiro a sair da fila. Não é possível alterar a ordem dos elementos
da pilha de entrada. A função deve obedecer o seguinte protótipo: TFila* p2f (TPilha *p).*/

TF* p2f (TP *p){
    TF * fila = TF_inicializa();
    while(p->topo){
        int x = TP_pop(p);
        TF_insere(fila, x);
    }

    return fila;
}


int main(void){
    TP *p = TP_inicializa();
    printf("p:\n");
    int n;
    while(1){
      scanf("%d", &n);
      if(n < 0) break;
      TP_push(p, n);
    }

    //printando a pilha original
    printf("A pilha original: \n");
    TP_imprime(p);
    printf("\n");

    //chamando a função
    TF * filinha = p2f(p);

    //printando a pilha final
    printf("A fila pos funcao criada: ");
    TF_imprime(filinha);
    printf("\n");

    //liberações
    TF_libera(filinha);
    TP_libera(p);

  return 0;
}