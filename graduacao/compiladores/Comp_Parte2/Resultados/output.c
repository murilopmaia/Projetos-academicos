#include <stdio.h>
#include <stdlib.h>

int main() {
    float var1, var2;
    float soma, sub, mult, div, expr;
    scanf("%f", &var1);
    scanf("%f", &var2);
    soma = (var1 + var2);
    sub = (var1 - var2);
    mult = (var1 * var2);
    div = (var1 / var2);
    expr = (var1 + 10.00 + 20.00 + (10.00 - 20.00 - (var2 * 2.00)));
    expr = (expr / 2.00);
    printf("Var1: ");
    printf("%f", var1);
    printf("\n");
    printf("Var2: ");
    printf("%f", var2);
    printf("\n");
    printf("Soma: ");
    printf("%f", soma);
    printf("\n");
    printf("Subtracao: ");
    printf("%f", sub);
    printf("\n");
    printf("Multiplicacao: ");
    printf("%f", mult);
    printf("\n");
    printf("Divisao: ");
    printf("%f", div);
    printf("\n");
    printf("Expressao: ");
    printf("%f", expr);
    printf("\n");
    return 0;
}
