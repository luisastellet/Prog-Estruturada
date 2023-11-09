#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compara (const void *a, const void *b){
    int *n1 = (int*)a;
    int *n2 = (int*)b;
    
    if((*n1) < (*n2)) return -1;
    return 1;
}

void ordena(int **matriz, int linha, int coluna){
    int *vetor = (int*)malloc(sizeof(int)*linha*coluna);
    int indice_vetor = 0;

    //De matriz para vetor (mat2vet)
    for(int i=0; i<linha; i++){
        for(int j=0; j<coluna; j++){
            vetor[indice_vetor] = matriz[i][j];
            indice_vetor++;
        }
    }

    qsort(vetor, linha*coluna, sizeof(int), compara);

    //De vetor para matriz (vet2mat)
    indice_vetor = 0;
    for(int i=0; i<linha; i++){
        for(int j=0; j<coluna; j++){
            matriz[i][j] = vetor[indice_vetor];
            indice_vetor++;
        }
    }

    free(vetor);
}

int main(){
    int linha, coluna;

    printf("Digite a qtd de linhas: ");
    scanf("%d", &linha);

    printf("Digite a qtd de colunas: ");
    scanf("%d", &coluna);

    int **matriz = (int**)malloc(sizeof(int*)*linha);

    for(int i=0; i<linha; i++){
        matriz[i] = (int*)malloc(sizeof(int)*coluna);
    }

    printf("Digite a matriz: ");
    for(int i=0; i<linha; i++){
        for(int j=0; j<coluna; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    ordena(matriz, linha, coluna);

    printf("A matriz ordenada eh:\n");
    for(int i=0; i<linha; i++){
        for(int j=0; j<coluna; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

}