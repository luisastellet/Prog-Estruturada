#include <stdio.h>

int binario(int num){
    int quociente;
    do{
        quociente = num / 2;
        printf("%d", num % 2); //vai printar um grudado no outro, mas na ordem padrão, deveria ser ao contrário
        num /= 2;

    }while (num >= 1);
}

int main(void){
    int n;
    do{
        scanf("%d", &n);
        if (n >= 0){
            binario(n);
            printf("\n"); //pular linha a cada número
        }

    }while(n >= 0); //o exercício que deu esse critério de parada

    return 0;
}