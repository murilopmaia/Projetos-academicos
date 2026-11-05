/* Murilo Patricio Maia
   Questão 8 */

#include <math.h>

int main (void) {

    float peso;
    float altura;
    float IMC;

    printf("informe seu peso e sua altura\n");
    scanf("%f %f", &peso, &altura);

    IMC = (float) peso / pow(altura,2);

    printf("\no seu IMC eh de %.2f\n", IMC);

    return 0;

}
