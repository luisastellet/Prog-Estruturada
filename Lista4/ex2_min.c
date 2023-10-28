#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * codifica (char *str){
    char *nova_str = (char*)malloc(sizeof(char)*(strlen(str)+1)); 

    for(int i=0; i < strlen(str); i++){
        if ((int)str[i] >= 97 && (int)str[i] <= 122)
            nova_str[i] = (char)63;
        else
            nova_str[i] = str[i];
    }

    nova_str[strlen(str)] = '\0'; //o novo_str já foi iniciado com mais um espaço para o \o, além disso o strlen(str) devolveria 5 por exemplo em um vetor de index 0 to 4, então 5 seria o index do \0

    return nova_str;
}

int main(void){
    char *string = (char*)malloc(sizeof(char)*50);

    scanf("%s", string);

    char *codificada = codifica(string);

    printf("%s\n", codificada);

    free(string);
    free(codificada);
    return 0;
}