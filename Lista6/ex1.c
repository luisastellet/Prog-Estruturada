// Considere a existência de uma estrutura que representa um ponto no espaço 2D. Escreva
// uma função que indique se um ponto p está dentro de um retângulo, retornando um e, zero, caso
// contrário. O retângulo é definido com dois vértices: o inferior esquerdo e o superior direito. O
// protótipo desta função é o seguinte: int dentroRet (TPTO2D *inf, TPTO2D *sup,TPTO2D *p).

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//declarando a struct
typedef struct retangulo{
    int x, y;
}TPTO2D;

//criando a função
int dentroRet (TPTO2D *inf, TPTO2D *sup, TPTO2D *p){
    if((p -> x) >= (inf -> x) && (p -> x) <= (sup -> x) && (p -> y) >= (inf -> y) && (p -> y) <= (sup -> y)) return 1;
    return 0;
}

//criando a main
int main(void){

TPTO2D inf, sup, p;

printf("Digite o X e o Y da posicao inferior: ");
scanf("%d%d", &inf.x, &inf.y);

printf("Digite o X e o Y da posicao superior: ");
scanf("%d%d", &sup.x, &sup.y);

printf("Digite o X e o Y do ponto desejado: ");
scanf("%d%d", &p.x, &p.y);

if(dentroRet(&inf, &sup, &p)) printf("Esta dentro!");
else printf("NAO esta dentro!");

    

}