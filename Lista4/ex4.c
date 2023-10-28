#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void retira_fim_n (char *str, int n){
    int indice = 0;
    if(strlen(str) >= n){
        str[strlen(str)-n] = '\0';
        printf("%s", str);
    }
    else printf("Erro!");

}   

int main(void){
    char palavra[50]; int n;

    printf("Digite o n: ");
    scanf("%d", &n);

    printf("Digite a string: ");
    scanf("%s", palavra);

    retira_fim_n(palavra, n);
}
