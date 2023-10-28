#include <stdio.h>

void primos(int qtd); 

int main(void){
    int n;
    
    while(n > 0){
        printf("Escreva um numero: ");
        scanf("%d", &n);
        primos(n);
        printf("\n");
    }

    return 0;
}

void primos(int qtd){
    int cont=0, numero=2, status=0;

    while(cont < qtd){
        if(numero >= 2) status = 1; //testando se os números são maiores que 2
        for (int divisor=2; divisor<numero; divisor++){ //pula a divisão por 1 e pelo próprio número, se achar algm é pq n é primo
            if(numero % divisor == 0){
                status = 0; //não é primo
                break;
            }
        }
        
        if(status){ //status = 1 (é primo)
            printf("%d ", numero);
            cont++;
        }
        
        numero++;
    }
}