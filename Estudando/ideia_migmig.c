#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *slice(char *str1,int tamanho, int k){
    char *str_slice = (char*)malloc(sizeof(char)*(tamanho+1));
    for(int i=0; i<tamanho; i++){
        str_slice[i] = str1[k];
        k++;
    }
    str_slice[tamanho] = '\0';

    return str_slice;
}

int sins(char *str1, char *str2){
    int cont = 0;
    int limite = strlen(str1) -(strlen(str2)) ;
    for(int i = 0; i <= limite; i++){
        if(strcmp(str2,slice(str1,strlen(str2),i)) == 0){
            cont++;
        }
    }
    return cont;
}

int main(){
    char str1[51], str2[31];
    printf("Digite a string grande: ");
    scanf("%s", str1);

    printf("Digite a string pequena: ");
    scanf("%s", str2);

    printf("Tem %d substrings.", sins(str1, str2));

}