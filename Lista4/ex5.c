#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void minusculo(char *str){
    for(int i=0; i<strlen(str); i++){
        if((int)str[i] >= 65 && (int)str[i] <= 90) str[i] = (char)((int)str[i]+32);
    }
}

int cic (char *str1, char *str2){
    minusculo(str1);
    minusculo(str2);
    int inicio = -1;

    for(int i=0; i<strlen(str2); i++){
        int ver=1;
        if(str2[i] == str1[0]){
            inicio=i+1;
            for(int j=1; j<strlen(str2); j++){ //indice da pequena
                if((int)str1[j] != (int)str2[inicio]){
                    ver = 0; //deu merda
                    break;
                }
                inicio++;
            }
            if(ver==1) return 1;
        } 
    }
    return 0;
}

int main(){
    char string1[20], string2[20];
    printf("Digite a string 1: ");
    scanf("%s", string1);
    printf("Digite a string 2: ");
    scanf("%s", string2);

    printf("%d", cic(string1, string2));

}