
#define linha 2
#define coluna 4
#define NOTAS 3



int main (void){
    char alunos [linha][coluna][100];
    float notas[linha][coluna][NOTAS];
    int i,j,s,cont;
    float maior, menor , medio ,media_parcial, media_final, media_parcialB, media_finalB;

    for(i = 0; i<linha;i++){

        for(j = 0;j<coluna;j++){
            printf("informe o nome do aluno %d da turma %d ",j+1,i+1);
            scanf("%s",alunos[i][j]);
            scanf("%*[^\n]");
            scanf("%*c");
            printf("\n");
            cont = 0;
            media_parcial = 0;
            media_parcialB = 0;

            for(s=0;s<NOTAS;s++){
                do{
                    printf("informe a %d nota ",s+1);
                    scanf("%f",&notas[i][j][s]);
                    scanf("%*[^\n]");
                    scanf("%*c");
                    printf("\n");
                    if(notas[i][j][s]<0 || notas[i][j][s]>10){
                        printf("\tfavor digitar corretamente\n\n");
                    }
                }
                while(notas[i][j][s]<0 || notas[i][j][s]>10);
                media_parcial += notas[i][j][s];

                if(cont == 0){
                maior = notas[i][j][0];
                menor = notas[i][j][0];
                }
                cont++;

                if(maior <= notas[i][j][s]){

                    maior = notas[i][j][s];
                }
                if(menor >= notas[i][j][s]){
                    menor = notas[i][j][s];



                }

            }
            medio = notas[i][j][0];
            for(s=0;s<NOTAS;s++){
                if(notas[i][j][s] != maior && notas[i][j][s] != menor){
                    medio = notas[i][j][s];
                }
            }
            media_parcialB = (maior + medio);

            media_finalB = (float)media_parcialB/2;

            media_final = (float)media_parcial/NOTAS;

            printf("-------------------------Resultado de %s------------------------------\n\n",alunos[i][j]);

            printf("a media do aluno com todas as notas seria =  %.2f\n",media_final);
            printf("a media do aluno com as 2 maiores notas será = %.2f\n",media_finalB);
            printf("a menor nota do aluno foi = %.2f\n\n",menor);



        }
    }

    return 0;}
