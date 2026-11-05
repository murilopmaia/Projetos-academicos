int main(void){

    int dec;
    int auxiliar1;
    int contador = 1;
    int auxiliar2;
    int resultado= 0;

    printf("informe o numero decimal");
    scanf("%d",&dec);



    for(;(int)dec > 0; dec = (int)dec/2){

        auxiliar1 = (int)dec%2;
        auxiliar2 = auxiliar1 * contador;
        resultado = resultado + auxiliar2;
        contador = contador * 10;
        printf("%d",resultado);

    }
    return 0;

}

