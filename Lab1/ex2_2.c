#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordena(char *str){
    int tamanho=0;
    //descobrir o tamanho da string
    for(int i=0; str[i] != '\0'; i++){
        tamanho++;
    }
    for(int i=0; i<tamanho; i++){
        int menor=i;
        for(int j=i+1; j<tamanho; j++){
            if(str[menor] > str[j]){
                menor = j;
            }
        }
        if(menor != i){
            char temp = str[menor];
            str[menor] = str[i];
            str[i] = temp;
        }
    }

    a m o R

int main(){
    char palavra[50]; 
    //recebendo a string
    printf("Digite a string: ");
    scanf("%s", palavra);
    printf("Antes: %s\n", palavra);
    ordena(palavra);
    printf("Depois: %s", palavra);
    return 0;
}