#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * codifica (char *str){
    char *nova_str = (char*)malloc(sizeof(char)*(strlen(str)+1)); //tem que deixar o espaço para o '/0' do final

    for(int i=0; i < strlen(str); i++){
        if ((int)str[i] == 65 || (int)str[i] == 97 || (int)str[i] == 69 || (int)str[i] == 101 || (int)str[i] == 73 || (int)str[i] == 105 || (int)str[i] == 79 || (int)str[i] == 111 || (int)str[i] == 85 || (int)str[i] == 117)
            nova_str[i] = (char)63;
        else
            nova_str[i] = str[i];
    }

    nova_str[strlen(str)] = '\0'; //ajustando pra o último caractere de nova_str não ser impresso
    
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