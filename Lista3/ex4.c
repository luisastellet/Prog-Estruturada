#include <stdio.h>
#include <stdlib.h>

int contador(int tamanho, int *vet){
    int contadorzao=0;
    for(int i=0; i<tamanho; i++){
        int cont=0;
        if(vet[i] != -1){
            for(int j=i+1; j<tamanho; j++){
                if(vet[j] != -1){
                    if(vet[i] == vet[j]){
                        cont++;
                        vet[j] = -1;
                    }
                }
            }
            vet[i] = -1;
        }
        if (cont > 0) contadorzao++;
    }
    return contadorzao;
}

int main(void){
    int originais, pessoas_presentes, x;

    scanf("%d", &originais);
    scanf("%d", &pessoas_presentes);

    while(originais != 0 || pessoas_presentes !=0){

        int *vetor = (int*)malloc(sizeof(int)*pessoas_presentes);
        int x;

        for(int i=0; i<pessoas_presentes; i++){
            scanf("%d", &vetor[i]);
        }
        
        x = contador(pessoas_presentes, vetor);
        if(x !=0) printf("%d\n", x);


        free(vetor);

        scanf("%d", &originais);
        scanf("%d", &pessoas_presentes);

    }

    return 0;
}