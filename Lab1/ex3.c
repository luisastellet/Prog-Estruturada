/*(3) Retirar todos os múltiplos de k de um vetor de inteiros. Se o seu vetor é 
composto por {2, 3, 5, 4, 6, 8, 7, 9, 1}, com tamanho 9, e k = 2, seu vetor deve se 
transformar em {3, 5, 7, 9, 1}, com tamanho igual a 5.  O protótipo dessa função é 
o que segue: void retira_mult_k(int *vet, int *novo_tam_vet, int k). NÃO PODEMOS 
CRIAR VETORES AUXILIARES PRA RESOLVER ESSA QUESTÃO: USE SOMENTE ÍNDICES!!!*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void retira_mult_k(int *vet, int *novo_tam_vet, int k){
    int tam_novo=0; //índice do "vetor novo"

    for(int i=0; i<(*novo_tam_vet); i++){
        if (vet[i] % k != 0){
            vet[tam_novo] = vet[i];
            tam_novo++;
        }
    }

    (*novo_tam_vet) = tam_novo;

    // realloc(vet, sizeof(int)*(*novo_tam_vet));

    // for(int i =0; i<(*novo_tam_vet); i++){ //isso faz com que apenas os desejados sejam printados, mas o vetor continua com os valores errados
    //     printf("%d ", vet[i]);
    // }
}

int main(void){
    int tamanho, k, novo_tamanho;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    printf("Digite o valor de referencia: ");
    scanf("%d", &k);

    printf("Digite o vetor: ");
    for(int i=0; i<tamanho; i++){
        scanf("%d", &vetor[i]);
    } 

    novo_tamanho = tamanho;

    retira_mult_k(vetor, &novo_tamanho, k);
    
    for(int i=0; i<novo_tamanho; i++){
        printf("%d ", vetor[i]);
    } 
    
    return 0;
}