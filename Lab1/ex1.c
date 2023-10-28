/*(1) Inserir o elemento (x - 1) antes e o elemento (x + 1) depois de cada ocorrência de x dentro de um vetor de resposta. Se o seu vetor original é formado pelos elementos {1, 3, 1, 5, 1} (com o tamanho n igual a 5), e se x for igual a 1, seu vetor de resposta será {0, 1, 2, 3, 0, 1, 2, 5, 0, 1, 2}, com tamanho igual a 11. O protótipo dessa função é o que segue: 
int* ins_antes_depois_x(int *vet, int n, int *tam_vet_resposta).*/

#include <stdio.h>
#include <stdlib.h>

int* ins_antes_depois_x(int *vet, int n, int x, int *tam_vet_resposta){

    for(int j=0; j<n; j++){
        if (vet[j] == x){
            (*tam_vet_resposta) += 2;
        }
    }
    printf("Tamanho novo: %d\n", *tam_vet_resposta);
    
    int *vet_novo = (int*)malloc(sizeof(int)*(*tam_vet_resposta));// corrigi o ponteiro
    
    int j=0;
    for(int i=0; i<*tam_vet_resposta; i++){
        if (vet[i] != x){
            vet_novo[j] = vet[i];
        }else{
            vet_novo[j] = (x-1);
            vet_novo[j+1] = x;
            vet_novo[j+2] = (x+1);
            j += 2;
        }
        j++;// incrementa j somente no final, e nao no incio, vc tava pulando a primeira casa
    }
    return vet_novo;
}

int main(){
    int numero, x;

    printf("Digite o tamanho do vetor original: ");
    scanf("%d", &numero);
    
    if(numero > 0){
        int vetor[numero];
        
        printf("Digite o vetor original: ");
        for(int i=0; i<numero; i++){
            scanf("%d", &vetor[i]);
        }
        
        printf("Digite o X: ");
        scanf("%d", &x);
        
        int tam_novo = numero;
        
        int *resp = ins_antes_depois_x(vetor, numero, x, &tam_novo);
        
        // depois de já ter o vetor novo
        
        for(int i=0; i<tam_novo; i++){
            printf("%d ", resp[i]);
        }
        
        free(resp);
    }
}