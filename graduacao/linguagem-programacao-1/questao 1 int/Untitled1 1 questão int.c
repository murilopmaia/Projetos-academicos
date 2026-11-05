
#include <math.h>

int main(void) {
    int numero;
    int resultado;

    printf("Digite o numero\n");
    scanf("%d",&numero);

    resultado = pow(numero,2);

    printf("o quadrado de %d eh %d\n",numero ,resultado);

    return 0;

}
