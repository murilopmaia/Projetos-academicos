int main (void){

    int numero;
    int auxiliar;
    int resultado = 0;

    printf("qual o numero?");
    scanf("%d",&numero);

    while(numero>0){
        auxiliar = numero%10;
        numero = numero/10;
        resultado = resultado + auxiliar ;
    }

    printf("%d",resultado);

    return 0;
}
