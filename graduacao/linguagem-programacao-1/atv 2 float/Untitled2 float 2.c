/* Murilo Patricio Maia
   Questão 2 */

int main (void) {

    float valor1;
    float valorFinal;
    float lucro;

    printf("informe o valor depositado\n");
    scanf("%f", &valor1);

    lucro = valor1 * 0.70;
    valorFinal = valor1 + lucro ;

    printf("\n o valor com rendimento apos um mes sera de %.2f \n", valorFinal);

    return 0;

}
