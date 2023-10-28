#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// min -> (max - 32) == 64 -> 90
// max -> (min + 32) == 96 -> 122

void shift_troca_string (char *str){
    for(int i =0; i< strlen(str); i++){
        int calculo = 0;
        //se for maiúscula
        if(65 <= (int)str[i] && (int)str[i] <= 90){
            calculo = (int)str[i] + 32;

            if(calculo - 1 == 96) 
                str[i] = (char)122;
            else 
                str[i] = (char)(calculo-1);

        //se for minúscula
        }else if(97 <= (int)str[i] && (int)str[i] <= 122){
            calculo = (int)str[i] - 32;

            if(calculo -1 == 64) 
                str[i] = (char)90;
            else 
                str[i] = (char)(calculo-1);
        }else{
            str[i] = (char)33;
        }
        calculo =0;
    }
}

int main(void){
    char palavra[50];

    printf("Digite a string: ");
    scanf("%s", palavra);

    shift_troca_string(palavra);

    printf("%s", palavra);
    return 0; 
}