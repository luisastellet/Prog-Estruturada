#include <stdio.h>

void primos(int qtd);

int main(void){
    int n;
    
    while(n>0){
        printf("Escreva um numero: ");
        scanf("%d", &n);
        primos(n);
        printf("\n");
    }

    return 0;
}

void primos(int qtd){
    int cont=0, numero=qtd+1, status=0;

    while(cont < qtd){
        if(numero >= 2) status = 1; // o primeiro primo é o 2
        for(int divisor=2; divisor<numero; divisor++){  //divisor começa em 2 pq eu sei q todo mundo divide por 1 e o divisor tem q ser menor que o numero pq eu sei q o numero divide por ele mesmo
            if(numero % divisor == 0){
                status = 0;
                break;
            }
        }

        if (status){ //status for verdadeiro, status=1 (primo)
            printf("%d ", numero);
            cont++; // o cont só aumenta se eu encontrei um primo, para bater com a qtd digitada
        }
        numero++;
        
    }
}
