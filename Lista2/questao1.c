#include <stdio.h>

int teste (int n);

int main (void){
    int num;
    scanf("%d", &num);
    while (num != -1){
        if (teste(num)) printf("%d\n", 1);
        else printf("%d\n", 0);
        scanf("%d", &num);
    }
}

int teste(int n){
    int res_esperado, res_obtido, primeiros, aux=n;

    while (aux/100 >= 1){
        primeiros = aux%100; 
        aux = aux / 10; //meu número atualizando
    }
    
    primeiros = aux; //isso ocorre pq na ultima interação o valor q eu quero fica em aux, não em primeiros como eu queria
    /*
    203 (dividindo por 100 fica maior q 1 então entra no while)
    aux = 203
    primeiros = 03
    aux = 20
    
    20 (dividindo por 100 fica menor q 1 então não entra no while)
    aux ficou com 20 e priemiros com 03, preciso de primeiros com o valor de aux
    */

    res_esperado = (primeiros*100 + n%100);
    res_obtido = (n%100 + primeiros)*((n%100 + primeiros));
    printf("aux=%d\tprimeiros=%d\tesperado=%d\tobtido=%d\n",aux,primeiros,res_esperado,res_obtido);
    //tem q multiplicar um pelo outro pq não tem ao quadrado
    //n % 100 são os últimos


    if (res_esperado == res_obtido) return 1;
    else return 0;
    
    /*
    se funcionar return 1
    se não funccionar return 0
    se digitar -1 para de rodar while*/
}