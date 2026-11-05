#define menor 5
#define maior 20
int main(void){
    int numero,i,j,auxiliar,auxiliar2 = 0;

    do{
        printf("informe o tamanho da matriz quadrada (entre 5 e 20)");
        scanf("%d",&numero);
        scanf("%*[^\n]");
        scanf("%*c");
        if(numero<menor || numero > maior){
            printf("por favor digite corretamente\n\n");
        }
    }
    while(numero<menor || numero > maior);

    int matriz[numero][numero];

    auxiliar = numero-1;

    for(i=0;i<numero;i++){
        for(j=0;j<numero;j++){
            if(i==auxiliar2 && j== auxiliar){
                printf("2 ");
                auxiliar2++;
                auxiliar--;
            }
            else
                if(i==j){
                    printf("0 ");
                }
                else
                    if(i == 0 || j == numero-1 || j == 0 || i == numero-1){
                        printf("1 ");
                    }
                    else{
                        printf("3 ");
                    }

        }
        printf("\n");
    }

    return 0;
}
