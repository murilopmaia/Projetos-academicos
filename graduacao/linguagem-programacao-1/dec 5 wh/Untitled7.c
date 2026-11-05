int main (void){

    int numero;
    int divisor = 0;
    int auxiliar = 0;

    printf("informe um numero");
    scanf("%d",&numero);

    while(divisor <= numero){

        divisor = divisor + 1;

        if(numero%divisor == 0){

            auxiliar = divisor + 1;
        }
    }

    if(auxiliar == 2){
        printf("%d é um numero primo",numero);
    }
    else{
        printf("%d nao é um numero primo",numero);
    }

    return 0;

}
