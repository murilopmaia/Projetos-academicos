int main(void){

    int medidas;
    int auxiliar;
    int auxiliar2;
    char ponto = '*';


    printf("informe as medidas\n");
    scanf("%d",&medidas);


    for(auxiliar = 1;auxiliar <= medidas;auxiliar = auxiliar +1){

        for(auxiliar2 = 1;auxiliar2 <= medidas;auxiliar2 = auxiliar2 +1){
        printf(" %c",ponto);
        }
        printf("\n");
    }


    return 0;
}
