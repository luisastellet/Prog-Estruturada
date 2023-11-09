#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Dada uma matriz quadrada de dimensão 9, com valores de 1 a 9 em suas posições, escreva
// um programa que verifique se esta matriz é uma solução válida para o Sudoku (isto é, uma
// solução é válida no Sudoku se cada linha, cada coluna e cada bloco contém os números de 1 a 9
// somente uma vez).

//Função de contar os elementos
int contar_digitos(int **matriz){
    int contador[9] = {0,0,0,0,0,0,0,0,0};

    //Aumentando os contadores conforme lê a matriz
    for(int lin=0; lin<9; lin++){
        for(int col=0; col<9; col++){
            contador[matriz[lin][col]-1] += 1;
        }
    }

    //Verificando os contadores do vetor
    for(int i=0; i<9; i++){
        if(contador[i] != 9) return 0;
    }
    return 1;
}

//Criando a função sum() para linhas
int sum_linha(int *vetor){
    int soma = 0;
    
    for(int i=0; i<9; i++){
        soma += vetor[i];
    }

    return soma;
}

//Criando a função sum() para colunas
int sum_coluna(int **matriz, int col){
    int soma = 0;
    
    for(int lin=0; lin<9; lin++){
        soma += matriz[lin][col];
    }

    return soma;
}

//Função de fazer a soma de cada matrizinha
int soma_45(int **matriz){
    int i;

    //somando as linhas
    for(i=0; i<9; i++){
        if(sum_linha(matriz[i]) != 45) return 0;
    }

    //somando as colunas
    for(i=0; i<9; i++){
        if(sum_coluna(matriz, i) != 45) return 0;
    }

    return 1;
}

int main(){
    int i, j;

    //Alocando a matriz dinamicamente
    int **mat = (int**)malloc(sizeof(int*)*9);

    for(i=0; i<9; i++){
        mat[i] = (int*)malloc(sizeof(int)*9);
    }

    //Recebendo os valores da matriz
    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    
    //Analisando os retornos da função contar_digitos
    if(contar_digitos(mat)){
        //Chamando a função soma_45
        int resp = soma_45(mat);
        if(resp) printf("Essa solucao e valida!");
        else printf("Essa solucao NAO e valida!");
    }else printf("Essa solucao NAO e valida!");

    //Desalocando
    for(i=0; i<9; i++) free(mat[i]);

    free(mat);

}