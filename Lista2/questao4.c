#include <stdio.h>

int main(void){
    int n;

    scanf("%d", &n);
    while (n > 0){
        int maiorzao=0, maior=0, atual=0, pos_maior=0, pos_maiorzao=0;
        for (int i = 1; i <= n; i++){
            scanf("%d", &atual);

            if (atual > maiorzao){
                pos_maior = pos_maiorzao;
                pos_maiorzao = i;
                maior = maiorzao;
                maiorzao = atual;

            }else if (atual > maior){
                maior = atual;
                pos_maior = i;

            }else continue;
        }

        printf("%d\n", pos_maior);

        scanf("%d", &n);
    }
}

/*
pos = 1
maiorzao = 3
maior = 0
*/