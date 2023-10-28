#include <stdio.h>

int palindromo(int num){
    //inverso seria o número de trás pra frente
    int inverso, cont=0, aux=num;

    //contando os digitos
    while(aux/10 > 0){
        cont++;

        
        aux /= 10;
    }

    if (num == inverso) return 1; //resultado da função, se é palíndromo ou não
    else return 0;

}


int main(void){
    int n;
    scanf("%d", &n);
    while(n >= 0){
        if (palindromo(n)) printf("VERDADEIRO");
        else printf("FALSO");
    }
}

/*



*/