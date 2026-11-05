/* Murilo Patricio Maia
   Questão 7 */

int main (void) {

    float celsius;
    float fahrenheit;


    printf("qual o valor em Celsius desejas converter?\n");
    scanf("%f", &celsius);

    fahrenheit = (float)(9 * celsius + 160) / 5;

    printf("\n%.2f graus celsius em fahrenheit eh %.2f\n",celsius,fahrenheit);

    return 0;

}
