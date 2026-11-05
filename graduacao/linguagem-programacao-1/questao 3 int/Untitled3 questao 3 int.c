int main (void) {

    int numero1;
    int numero2;
    int soma;
    int subtracao;
    int divisao;
    int multiplicacao;

    printf("escreva o numero\n");
    scanf("%d %d",&numero1, &numero2);

    soma = numero1 + numero2;
    subtracao = numero1 - numero2;
    divisao = numero1/numero2;
    multiplicacao = numero1 * numero2;

    printf(" a soma deles eh = %d\n\n a subtracão eh = %d\n\n a divisao eh = %d \n\n a multiplicacao eh = %d \n", soma, subtracao, divisao, multiplicacao);

    return 0;

}


