
/* Murilo Patricio Maia
   Questão 9 */

int main (void) {

    float horas;
    float minutos;
    float bits;
    float velocidade;
    float tempo;

    printf("informe o tamanho do arquivo e a velocidade da internet\n");
    scanf("%f %f", &bits, &velocidade);

    tempo = (float) bits/velocidade;

    if (tempo > 60 && tempo < 3600) {

        minutos = (float) tempo/60;

        printf("\nvai demorar %.2f minutos\n", minutos);

    }

    else {

        if (tempo > 3600){

            horas = tempo/3600;

            printf("\nvai demorar %.2f horas\n",horas);

        }

        else {

            printf("\nvai demorar %.2f segundos\n", tempo);

        }
    }
}
