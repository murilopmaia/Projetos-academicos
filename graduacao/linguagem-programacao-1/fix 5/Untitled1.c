int main (void){

    float razao;
    float termo1;
    int n_termos;
    char escolha;

    do{
    printf("escolha:\n 1.P.A\n 2.P.G\n");
    scanf("%d",&escolha);
    }
    while(escolha != 1 && escolha != 2);

    if (escolha == 1){

        printf("informe a razão\n");
        scanf("%f",&razao);

        printf("informe o numero de termos\n");
        scanf("%d",&n_termos);

        printf("informe o primeiro termo\n");
        scanf("%f",&termo1);

        for(;n_termos > 0;n_termos = n_termos - 1){

            printf("%.2f ",termo1);
            termo1 = termo1 + razao;
        }
    }
    else {
        printf("informe a razao\n");
        scanf("%f",&razao);

        printf("informe o numero de termos\n");
        scanf("%d",&n_termos);

        printf("informe o primeiro termo\n");
        scanf("%f",&termo1);

        for(;n_termos > 0;n_termos = n_termos - 1){

            printf("%.2f ",termo1);
            termo1 = termo1 * razao;
        }
    }

    return 0;

}




