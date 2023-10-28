#include <stdio.h>
#include <string.h>

void ordena(char *str) {
    int n = strlen(str);
    int i, j;
    for (i = 0; i < n - 1; i++) {
        printf("str[i=%d] = %c\n",i,str[i]);
        for (j = 0; j < n - i - 1; j++) {
            printf("str[j=%d] = %c\n",j,str[j]);
            if (str[j] > str[j + 1]) {
                // Troca os caracteres usando XOR bit a bit para não usar uma variável auxiliar
                // printf("%c = %c ^ %c --> %c \n",str[j],str[j],str[j+1], str[j] ^ str[j + 1]);
                // printf("%c = %c ^ %c --> %c \n",str[j+1],str[j],str[j+1], str[j] ^ str[j + 1]);
                // printf("%c = %c ^ %c --> %c \n",str[j],str[j],str[j+1], str[j] ^ str[j + 1]);
                printf("trocou = %c  %c\n",str[j],str[j+1]);
                str[j] = str[j] ^ str[j + 1];
                str[j + 1] = str[j] ^ str[j + 1];
                str[j] = str[j] ^ str[j + 1];
                printf("palavra em atual = %s\n", str);
                
                
            }
        }
    }
}

int main() {
    char str[] = "amoR";
    printf("String original: %s\n", str);
    ordena(str);
    printf("String ordenada: %s\n", str);
    return 0;
}