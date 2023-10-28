#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void retira_inicio_n (char *str, int n){
    int indice = 0;
    for(int i=0; i<strlen(str); i++){
        if(i >= n){
            str[indice] = str[i];
            indice++;
        }
    }
    str[strlen(str)-n] = '\0';
}

int main(void){
    char palavra[50]; int n;
    
    printf("Digite o n: ");
    scanf("%d", &n);

    printf("Digite a string: ");
    scanf("%s", palavra);

    if(strlen(palavra) >= n){
        retira_inicio_n(palavra, n);
        printf("%s", palavra);
    }
    else printf("Erro!"); 

    return 0;
}
