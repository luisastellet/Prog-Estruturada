// (1) Escreva uma função em C que transforme uma matriz num vetor: 
// int *mat2vet(int **mat, int lin, int col);

#include <stdlib.h>
#include <stdio.h>

int *mat2vet(int **mat, int lin, int col){
    int i,j, indice=0; //indice vai até lin*col

    //criar vetor final com lin*col elementos
    int *vetor = (int*)malloc(sizeof(int)*lin*col);

    //for pra percorrer a matriz
    for(i=0; i<lin; i++){
        for(j=0; j<col; j++){
            vetor[indice] = mat[i][j];
            indice++;
        }
    }
    return vetor;
}

int main(void){
    int lin=2, col=3;
    int **matriz = (int**)malloc(sizeof(int*)*lin);

    for(int i=0; i<lin; i++){
        matriz[i] = (int*)malloc(sizeof(int)*col);
    }
    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    int *resp = mat2vet(matriz,lin,col);
    for(int i=0; i<lin*col; i++) printf("%d ", resp[i]);

}




//linhas* colunas -> elementos
