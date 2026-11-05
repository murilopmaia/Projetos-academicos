/* Murilo Patricio Maia
   Questão 3 */


int main (void) {

    float nota1, nota2, nota3, nota4;
    float media;

    printf("informe as 4 notas\n");
    scanf("%f %f %f %f",&nota1, &nota2, &nota3, &nota4);

    if (nota1 >= 0 && nota2 >= 0 && nota3 >= 0 && nota1 >= 0 && nota1 <= 10 && nota2 <= 10 && nota3 <= 10 && nota4 <= 10 ) {

    media = (float)(nota1 + nota2 + nota3 + nota4)/4;

    printf("\na media final do aluno foi de %.2f\n",media);
    }

    else
        printf("\npreencha corretamente\n");

    return 0;

}
