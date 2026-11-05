int main(void) {

    int numero;
    int resultado = 0;
    int auxiliar;

    printf("informe um numero");
    scanf("%d",&numero);

    for(;numero>0;numero = numero/10){

            auxiliar = numero%10;
            resultado += auxiliar;

    }

    printf("%d",resultado);

    return 0;

}
