int main (void){

    struct registro{
        int matricula;
        char nome[50];
        float notas[3];
        float media;
    }aluno;
    int i,soma=0;

    printf("informe o nome do aluno ");
    scanf("%[^\n]s",aluno.nome);
    scanf("%*[^\n]");
    scanf("%*c");

    printf("\ninforme a matricula do aluno ");
    scanf("%d",&aluno.matricula);
    scanf("%*[^\n]");
    scanf("%*c");

    for(i=0;i<3;i++){
        do{
            printf("\ninforme a %d nota do aluno %s ",i+1,aluno.nome);
            scanf("%f",&aluno.notas[i]);
            scanf("%*[^\n]");
            scanf("%*c");
        }
        while(aluno.notas[i]>10 || aluno.notas[i]<0);
        soma = soma + aluno.notas[i];

    }

    aluno.media = (float)soma/3;

    system("clear||cls");

    printf("\n---------------------------------------tabela-----------------------------------");

    if(aluno.media >= 7){
        printf("\n\n%s com matricula %d passou com media de %.2f\n",aluno.nome,aluno.matricula,aluno.media);
    }
    else{
        printf("\n\n%s com matricula %d nao passou com media de %.2f\n",aluno.nome,aluno.matricula,aluno.media);

    }
    return 0;
}
