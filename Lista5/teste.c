#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//criando matriz
int main(){
    int linhas, colunas;

    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &linhas);

    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &colunas);

    int **matriz = (int**)malloc(sizeof(int*)*linhas); 

    for(int i=0; i<linhas; i++) matriz[i] = (int*)malloc(sizeof(int)*colunas);

    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            scanf("%d", &matriz[i][j]);
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

}