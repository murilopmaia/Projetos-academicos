int main(void){
    int cont ;
    int cont2;
    char linha = '-';
    int auxiliar;

    printf("    ");
    for(cont = 0;cont<10 ; cont++)
        printf("%d  ",cont);

    printf("\n");

    printf("   ");
    for(cont = 0;cont<30;cont++)
        printf("%c",linha);

    printf("\n");

    for(cont = 0; cont<10;cont++){
        printf("%d|",cont);
        for(cont2 = 0;cont2<10;cont2++){
            auxiliar = cont * cont2;
            if(auxiliar >= 10){
                printf(" %d",auxiliar);;
            }
            else{
                printf("  %d",auxiliar);;
            }
        }
        printf("\n");
    }

    return 0;

}
