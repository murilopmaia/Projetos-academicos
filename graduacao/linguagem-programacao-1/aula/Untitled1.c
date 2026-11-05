
int main (void){

    int perguntas;
    int valor_parcial = 100;
    long long int valor_total = 0;

    do{
        printf("quantas perguntas acertou?\n\t");
        scanf("%d",&perguntas);

        if (perguntas < 0 || perguntas > 30){

            printf("digite valores validos\n\n");
        }
    }
    while(perguntas < 0 || perguntas > 30);

    for(;perguntas >= 1;perguntas--){

        valor_total  += valor_parcial;
        valor_parcial *=  2;
    }

    printf("valor ganho de = %Ld",valor_total);



    return 0;


}


