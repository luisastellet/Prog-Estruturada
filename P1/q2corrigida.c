#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//OK

int main(void){
    int n, atual, cont=1, anterior, maior=0;
    scanf("%d", &n);

    //na prova tinha entendido que parava com -1 ai coloquei n>=0 (por causa de outros exercícios já estava condicionada a pensar nisso, n prestei mt atenção)
    while(n > 0){
        for(int i=0; i<n; i++){
            scanf("%d", &atual);
            if(i==0) anterior = atual;
            else{
                if(atual > anterior) cont++;
                else{
                    //na prova coloquei o cont=1 antes, o que faz maior sempre receber 1, dá erro
                    if(cont > maior) maior = cont;
                    cont = 1;
                }
            }
            anterior = atual;
        }

        //faltou conferir a última sequência, pq ela pode ser a maior
        if(cont > maior) maior = cont;

        //faltou printar, viajei 
        printf("A maior sequencia crescente e %d\n", maior);
        
        //como é infinito, tem q reiniciar algumas variáveis
        cont = 1;
        maior = 0;

        scanf("%d", &n);
    }

    return 0;
}