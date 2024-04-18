#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct aluno{
    char nome[31], mat[10], email[31];
    float p1, p2;
}TALUNO;

//TALUNO *turma[50];
//descrescente de média maior->menor
//crescente de nome menor->maior
//crescente de matrícula menor->maior

int compara(const void *a, const void *b){

    TALUNO **aluno1 = (TALUNO**) a;
    TALUNO **aluno2 = (TALUNO**) b;

    TALUNO *a1 = (*aluno1);
    TALUNO *a2 = (*aluno2);

    //ordenar médias
    if((a1->p1 + a1->p2)/2 > (a2->p1 + a2->p2)/2) return -1;
    if((a1->p1 + a1->p2)/2 < (a2->p1 + a2->p2)/2) return 1;
    
    //ordenar nome
    if(strcmp(a1->nome,a2->nome) < 0) return -1;
    if(strcmp(a1->nome,a2->nome) > 0) return 1;

    //ordenar matrícula
    if(strcmp(a1->mat,a2->mat) < 0) return -1;
    return 1;
}

void ordena(TALUNO **turma, int n){
    qsort(turma, n, sizeof(*turma), compara);
}