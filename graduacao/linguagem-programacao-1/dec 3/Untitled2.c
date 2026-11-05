int main (void){

    int numero;
    int divisor = 2147483647 ;

    printf("informe um numero\n");
    scanf("%d",&numero);

    while(numero>0){

        if (numero%divisor == 0){

            printf("%d eh divisor de %d \n\n",divisor,numero);
        }

        divisor = divisor - 1;



    }

    return 0;

}
