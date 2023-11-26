#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int **aloca(int lin, int col){
  int **resp = (int **) malloc(sizeof(int *) * lin), i;
  for(i = 0; i < lin; i++)
    resp[i] = (int *) malloc(sizeof(int) * col);
  return resp; 
}

void desaloca(int **mat, int lin){
  int i;
  for(i = 0; i < lin; i++) free(mat[i]);
  free(mat);
}

//minha função
//int * tam foi um ajuste pedido na aula de lab, o mesmo do miguel
int *misc(int **mat, int linha, int coluna, int*tam){
    int *aux = (int*)malloc(sizeof(int)*5);
    for(int i=0; i<5; i++) aux[i] = 0;
    int ver=1, cont=0, soma=0;

    for(int i=0; i<linha; i++){
        soma =0;
        for(int j=0; j<coluna; j++){
            soma += mat[i][j];
        }
        //tinha colocado soma == 3 (confundi com o exemplo)
        if(soma == coluna){
            ver = 0;
            break;
        }
    }
    if (ver){
        aux[1] = 1;
        cont++;
    }

    ver = 1;
    for(int i=0; i<linha; i++){
        soma =0;
        for(int j=0; j<coluna; j++){
            soma += mat[j][i];
        }
        if(soma == 0){
            ver = 0;
            break;
        }
    }
    if (ver){
        aux[2] = 2;
        cont++;
    }

    ver = 1;
    for(int i=0; i<linha; i++){
        soma =0;
        for(int j=0; j<coluna; j++){
            soma += mat[j][i];
        }
        //antes tava soma == 3 (confundi com o exemplo)
        if(soma == linha){
            ver = 0;
            break;
        }
    }
    if (ver){
        aux[3] = 3;
        cont++;
    }

    ver = 1;
    for(int i=0; i<linha; i++){
        soma =0;
        for(int j=0; j<coluna; j++){
            soma += mat[i][j];
        }
        if(soma == 0){
            ver = 0;
            break;
        }
    }
    if (ver){
        aux[4] = 4;
        cont++;
    }
    
    int indice=0;
    aux[0] = cont;

    //coloquei o vetor de resposta menor que o aux (cont+1)
    int * resp = (int*)malloc(sizeof(int)*(cont+1));
    
    for(int i=0; i<5; i++){
        if(aux[i] != 0){
            resp[indice] = aux[i];
            indice++;
        }
    }

    free(aux);

    //ajuste pedido no lab
    (*tam) = cont;

    return resp;
}

//main
int main(void){
  int n, m;
  while(1){
    scanf("%d%d", &n, &m);
    if((n <= 0) && (m <= 0)) return 0;
    if((n < 2) || (m < 2)) continue;

    int **mat = aloca(n, m), i, j;
    for(i = 0; i < n; i++)
      for(j = 0; j < m; j++) scanf("%d", &mat[i][j]);

    
    int tam, *resp; 
    resp = misc(mat, n, m, &tam);
    for(i = 0; i < tam+1; i++) printf("%d ", resp[i]);
    printf("\n");
    free(resp); 
    
    desaloca(mat, n);
  } 
}
