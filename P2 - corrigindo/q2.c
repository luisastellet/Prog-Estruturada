#include "TP.c"
#include <limits.h>

// Basicamente no meu algoritmo eu crio um novo vetor de pilhas (vet_aux) e percorro todas 
// as pilhas no primeiro for procurando o menor valor (tirando e botando pra não alterar as 
// pilhas) depois eu uso o segundo for para retirar somente o menor valor, insiro ele na 
// pilha resp e coloco no vetor auxiliar pra guardar todos os números. Depois que eu faço 
// isso, o meu vetor de pilhas originais fica vazio, o vetor auxiliar recebe todos os valores 
// e a pilha resp fica ordenada de forma descrescente (ainda não é o desejado). Por fim, eu 
// devolvo todos os valores do vet_aux para o vet original como solicitado. No final apenas 
// jogo tudo da pilha resp pra pilha resp_ord, ficando em ordem crescente. Pontos que podem 
// ter ficado confusos: Eu uso o int_max a cada rodagem das n pilhas, para achar o menor 
// valor. O inteiro vazia que eu criei acrescenta em um cada vez que uma pilha fica vazia, 
// para não ter problemas de fazer o pop em pilhas já vaia, o que daria erro.

// na hora da prova não vi a função inicializa, por isso usei null algumas vezes e entendo 
// que não serve, me confundi com a inicialização de uma lista, corrigi isso.

// escrevi vet em alguns momentos na prova mas era vetp (na pressa não me toquei, foi um 
// erro de ortografia mesmo)

TP * merge(TP ** vetp, int n){
    TP * resp = TP_inicializa();
    int menor = TP_pop(vetp[0]);
    int vazia = 0;
    TP_push(vetp[0], menor);

    TP ** vet_aux = (TP**)malloc(sizeof(TP*)*n);
    for(int i = 0 ; i<n; i++){
        vet_aux[i] = TP_inicializa();
    }

    while(vazia != n){
        for(int i = 0; i < n; i++){
            if(!TP_vazia(vetp[i])){
                int x = TP_pop(vetp[i]);
                if(x <= menor) menor = x;
                TP_push(vetp[i], x);
            }else continue;
        }
        for(int i=0; i<n; i++){
            if(!TP_vazia(vetp[i])){
                int y = TP_pop(vetp[i]);
                if(y == menor){
                    TP_push(resp, y);
                    TP_push(vet_aux[i], y);
                    if(TP_vazia(vetp[i])) vazia++;
                    break;
                }
                TP_push(vetp[i], y);
            }else continue;
        }
        //nao era pra inicializar a variável, apenas atualizar, tirei o "int"
        menor = INT_MAX;
    }
    vazia = 0;
    //tinha colocado vazia != 0, era vazia != n 
    while(vazia != n){
        for(int i =0; i<n; i++){
            if(!TP_vazia(vet_aux[i])){
                int x = TP_pop(vet_aux[i]);
                TP_push(vetp[i], x);
                if(TP_vazia(vet_aux[i])) vazia++;
            }

        }
    }
    for(int i=0; i<n; i++){
        TP_libera(vet_aux[i]);
    }
    free(vet_aux);

    TP * resp_ord = TP_inicializa();
    while(!TP_vazia(resp)){
        int x = TP_pop(resp);
        TP_push(resp_ord, x);
    }
    TP_libera(resp);
    return resp_ord;
}

int main(void){
  int n;
  printf("Digite o numero de pilhas... ");
  scanf("%d", &n);
  if(n <= 0) return 0;
  
  TP **vetp = (TP **) malloc(sizeof(TP*) * n);
  int i;
  for(i = 0; i < n; i++) vetp[i] = TP_inicializa();

  i = 0;
  while(i < n){
    printf("Digite a pilha %d em ordem decrescente... Quando for fornecido um elemento fora de ordem, a pilha nao recebera mais elementos...\n", i + 1);
    int ant;
    scanf("%d", &ant);
    TP_push(vetp[i], ant);
    while(1){
      int aux;
      scanf("%d", &aux);
      if(aux > ant) break;
      TP_push(vetp[i], aux);
      ant = aux;
    }
    i++;
  }

  TP *resp = merge(vetp, n);
  TP_imprime(resp);
  TP_libera(resp);
  for(i = 0; i < n; i++) TP_libera(vetp[i]);
  free(vetp);
  return 0;
}