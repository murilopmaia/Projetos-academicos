int main(void) {

    short int anos;
    short int por_dia;
    float preco;
    float resultado;

    do{

        printf("informe quantos a quantos anos fumas");
        scanf("%hd",&anos);

        printf("informe quantos cigarros fumas por dia");
        scanf("%hd",&por_dia);

        printf("informe o preco de uma carteira de cigarro");
        scanf("%f",&preco);
    }
    while(anos < 0 || por_dia < 0 || preco <= 0);

    resultado = ((365 * por_dia * anos)/20) * preco;

    printf("voce ja gastou aproximadamente R$ %.2f fumando",resultado);

    return 0;

}
