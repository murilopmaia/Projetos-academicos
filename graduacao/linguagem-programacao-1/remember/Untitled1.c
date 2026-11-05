int main (void){

    int largura;
    int altura;
    int auxiliar;

    do{
        printf("informe a altura do retangulo");
        scanf("%d",&altura);

        printf("informe a largura do retangulo");
        scanf("%d",&largura);
    }
    while(altura <= 0 && largura <= 0);

    auxiliar = largura;

    for(;altura > 0 ; altura--){
        for(;largura > 0;largura--){

            printf("*");
        }
        printf("\n");
        largura = auxiliar;
    }

    return 0;

}




