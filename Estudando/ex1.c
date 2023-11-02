// (Q1) Implemente uma função em C que receba uma string como parâmetro e substitua todas as suas
// letras por predecessoras do alfabeto, trocando maiúsculas por minúsculas. Por exemplo, a string
// “Amor” seria alterada para “zLNQ”. Esta função deve obedecer o seguinte protótipo: void
// shift_troca_string (char *str). A letra ‘a’ deve ser substituída por ‘Z’ (e ‘A’ por ‘z’). Caracteres que não
// forem letras devem ser substituídos por ‘!’. Sabe-se que A = 65, Z = 90, a = 97 e z = 122.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//se ta entre 65 e 90 soma 31
//se ta entre 97 e 122 diminui 33
//se for 65, vira 122
//se for 97 vira 90
//(int)letra - 1

void shift_troca_string (char *str){
    
    for(int i=0; i<strlen(str); i++){
        if(str[i] == 'A') str[i] = 'z';
        else if (str[i] == 'a') str[i] = 'Z';
        else if ((int)str[i] > 65 && (int)str[i] <= 90) str[i] = (char)((int)str[i]+31);
        else if ((int)str[i] > 97 && (int)str[i] <= 122) str[i] = (char)((int)str[i]-33);
        else str[i] = '!';
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