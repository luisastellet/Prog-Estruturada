#include <stdlib.h>
#include <stdio.h>

/*Q1) Uma forma simples e eficiente de calcular todos os números primos até um 
certo valor n é o método da Peneira de Eratosthenes. O processo é simples: 
escrevem-se todos os valores entre 2 e n (limite máximo). Em seguida, faz-se um 
círculo em volta do 2, marcando como primo e riscam-se todos os seus múltiplos. 
Continua-se a fazer círculos em volta do menor inteiro que se encontra, eliminando 
todos os seus múltiplos. Quando não restarem números sem terem círculos à volta ou 
traços por cima, os números com círculos à volta representam todos os primos até n. 
A figura seguinte apresenta o método para n = 40.*/

int main(void){
    int n;
    int *vetor = (int*)malloc(sizeof(int)*(n-1));

    printf("Digite o numero: ");
    scanf("%d", &n);

    for(int i=2; i<n; i++) vetor[i-2] = i;

    for(int i=0; i<n-1; i++){
        if(vetor[i] != 1){
            for(int j=i+1; j<n-1; j++){
                if(vetor[j] % vetor[i] == 0) vetor[j] = 1;
            }
        }
    }

    for(int i=0; i<n-1; i++){
        if(vetor[i] != 1){
            printf("%d ", vetor[i]);
        }
    }

    free(vetor);
    
    return 0;
}