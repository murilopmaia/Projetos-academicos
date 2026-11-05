
/* Murilo Patricio Maia
   Questão 5 */

int main (void) {

    float flo;

    printf("informe o numero\n");
    scanf("%f",&flo);

    printf("parte inteira = %d, parte decimal = %f",(int)flo,(flo - ((int)flo)));

    return 0;
}
