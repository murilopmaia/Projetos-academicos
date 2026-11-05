int main (void){

    int numero;
    int auxiliar = 1;
    int auxiliar2;
    int auxiliar3;
    int linha;
    int linha2 = 0;
    int espaco = ' ';

    do{
        printf("informe um numero impar");
        scanf("%d",&numero);

    }
    while(numero%2 == 0 || numero == 0);

    for(auxiliar2 = 0;auxiliar2<= numero;auxiliar2 = auxiliar2 + 1){

        auxiliar3 = auxiliar;
        numero = numero - 1;


        for(;auxiliar <= numero + 1;auxiliar = auxiliar + 1){

            printf("%d",auxiliar);
        }
        printf("\n");
        auxiliar = auxiliar3 + 1;

        for(linha=0;linha<=linha2;linha = linha + 1 ){

            printf("%c",espaco);
        }

        linha2 = linha2 + 1;

        }

        return 0;

}



