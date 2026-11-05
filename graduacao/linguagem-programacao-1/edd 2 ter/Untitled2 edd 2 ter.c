int main (void){

    float media;
    float nota1;
    float nota2;
    float nota3;
    float nota4;
    float resultado;


    printf("informe as 4 notas do aluno\n");
    scanf("%f %f %f %f",&nota1 , &nota2, &nota3, &nota4);

    media = (float) (nota1 + nota2 + nota3 + nota4)/4;

    resultado = (media >= 7)? printf("o aluno foi aprovado com media de %.2f",media) : printf("o auno foi reprovado com media de %.2f",media);

    return 0;

}


