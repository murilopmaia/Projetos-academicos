/* Murilo Patricio Maia
    Questão 1 */

int main (void) {

    float comprimento;
    float largura;
    float preco;
    float custo;


    printf("informe o valor do comprimentro e da largura da sala, alem do preco do metro quadrado\n");
    scanf("%f %f %f",&comprimento, &largura, &preco);

    if (comprimento > 0 && largura > 0 && preco > 0) {

    custo = comprimento * largura * preco;

    printf("\no custo total sera de %.2f R$\n",custo);
    }

    else
        printf("preencha corretamente");

    return 0;

}
