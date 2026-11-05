int main (void) {

    int numero;
    int divisor = 0;
    int auxiliar = 0;

    printf("informe um numero");
    scanf("%d",&numero);

    do{

        divisor = divisor + 1;

        if(numero%divisor == 0){

            auxiliar = auxiliar + 1;

        }


    }
    while(divisor <= numero);

    if(auxiliar == 2){

        printf("%d eh um numero primo",numero);
    }

    else{

        printf("%d nao eh um numero primo",numero);

    }

    return 0;

}
