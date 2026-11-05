int main (void) {

    int folhas;
    float custo;

    printf("informe o total de folhas\n");
    scanf("%d",&folhas);

    if (folhas <= 100){

        custo = folhas * 0.25;

        printf("\no custo total sera de = %.2f\n",custo);


    }
    else{

        custo = folhas * 0.20;

        printf("\no custo total sera de = %.2f\n",custo);
    }

    return 0;

}
