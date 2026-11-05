int main (void) {

    int numero;
    int divisor = 1;
    int auxiliar = 0;

    printf("informe um numero");
    scanf("%d",&numero);

    for(;divisor<=numero;divisor = divisor + 1){

        if(numero%divisor == 0){
            auxiliar = auxiliar + 1;
        }
    }

    if(auxiliar == 2){

        printf("%d eh um numero primo",numero);
    }

    else{

        printf("%d nao eh um numero primo",numero);
    }

    return 0;

}
