int main (void){

    float media;
    float nota1;
    float nota2;
    float nota3;
    float nota4;


    printf("informe as 4 notas do aluno\n");
    scanf("%f %f %f %f",&nota1 , &nota2, &nota3, &nota4);

    media = (float) (nota1 + nota2 + nota3 + nota4)/4;

    switch ((int)media){

        case 0 ... 6: printf("o aluno foi reprovado com media de = %.2f",media); break;
        case 7 ... 10 : printf("o aluno foi aprovado com media de %.2f",media);break;

    }

    return 0;

}
