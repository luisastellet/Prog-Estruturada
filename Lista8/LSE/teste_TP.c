int main(void){
    TP *p = TP_inicializa();
    printf("p:\n");
    int n;
    while(1){
      scanf("%d", &n);
      if(n < 0) break;
      TP_push(p, n);
    }
    TP_imprime(p);
    printf("\n");
    TP_libera(p);

  return 0;
}
