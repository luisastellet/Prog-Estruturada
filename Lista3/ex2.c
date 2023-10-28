#include <stdio.h>
#include <stdlib.h>


//AJUSTARRRRRRRRR


/*Q2) Implemente um programa que integre e derive polinômios. Cada polinômio é definido por um
vetor que contém seus coeficientes. Por exemplo, o polinômio de grau dois 3x2

+ 2x + 12 terá um
vetor de coeficientes v = {12,2,3}. Sua integral será I = {0, 12, 1, 1}, equivalente ao polinômio x 3
+

x
2
+ 12x, e sua derivada será D = {2, 6}, equivalendo ao polinômio 6x + 2. O programa deve,
infinitamente: (a) receber o valor do maior grau g do polinômio, seguido de (g + 1) coeficientes; (b)
calcular qual é a integral e a derivada do polinômio informado; e (c) imprimir os novos polinômios
na tela. Este programa para somente quando o grau g do polinômio for menor ou igual a zero.*/



int *derivada(int *grau, int *vet){
    int cont_zero=0, indice=0;
    for(int i=0; i<(*grau)+1; i++){
        vet[i] *= i;
        if(vet[i] == 0) cont_zero++;
    }

    //o problema está aqui!!!
    int *novo = (int*)malloc(sizeof(int)*((*grau)+1-cont_zero));
    for(int i=0; i<(*grau)+1-cont_zero; i++){
        if(vet[i] != 0){
            novo[indice] = vet[i];
            indice++;
        }
    }

    for(int i=0; i<(*grau)+1; i++){
            printf("%d ", novo[i]);
        }

    (*grau) -= cont_zero+1;

    return novo;

}

int main(void){
    
    int maior_grau;

    do{
        printf("Digite o maior grau do polinomio: ", maior_grau);
        scanf("%d", &maior_grau);

        int *vetor = (int*)malloc(sizeof(int)*(maior_grau+1));

        printf("Digite os coeficientes do polinomio: ");
        for(int i=0; i<maior_grau+1; i++){
            scanf("%d", &vetor[i]);
        }

        int *resp = derivada(&maior_grau, vetor);

        for(int i=0; i<maior_grau; i++){
            printf("%d ", resp[i]);
        }
        
        printf("\n");

        free(vetor);

    }while(maior_grau>0);

    return 0;
}