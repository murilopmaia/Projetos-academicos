int main (void){

    int numero;
    int auxiliar;
    int resultado = 0;

    printf("qual o numero?");
    scanf("%d",&numero);

    do{
        auxiliar = numero%10;
        numero = numero/10;
        resultado += auxiliar ;

    }
    while(numero>0);

    printf("%d",resultado);

    return 0;

}
