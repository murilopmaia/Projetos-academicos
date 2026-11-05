int main (void){

    int num1;
    int num2;
    int quociente;
    int resto;

    printf("informe um numero inteiro");
    scanf("%d",&num1);

    printf("informe um numero para dividir o numero anterior");
    scanf("%d",&num2);

    quociente = num1/num2;

    resto = num1%num2;

    printf("o quociente de %d e %d eh %d , o resto deles eh %d",num1,num2,quociente,resto );

    return 0;

}



