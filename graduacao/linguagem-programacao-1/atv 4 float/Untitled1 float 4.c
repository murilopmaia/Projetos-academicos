/* Murilo Patricio Maia
   Questão 4 */

int main (void) {

    float INSS;
    float horas_trab;
    float horas_valor;
    float salario_bruto;
    float salario_liq;
    float desconto;

    printf("informe quantas horas voce trabalha, o valor ganho por hora e o desconto no INSS , em porcentagem\n");
    scanf("%f %f %f",&horas_trab, &horas_valor, &INSS);

    salario_bruto = horas_trab * horas_valor;

    desconto = (float)(salario_bruto * INSS) / 100;

    salario_liq = salario_bruto - desconto;

    printf("\no salario liquido sera de %.2f R$\n",salario_liq);

    return 0;

}

