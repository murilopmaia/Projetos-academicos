#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define linha 5
#define coluna 3

int main(void){
    int notas[linha][coluna], i, i2, media_parcial = 0;
    float mediavet[linha], media = 0;
    char alunos[linha][100];

    for(i=0;i<linha;i++){
        printf("informe o nome do aluno %d ",i+1);
        scanf("%[^\n]s%*c",alunos[i]);
        printf("\n");
        for(i2=0;i2<coluna;i2++){
            printf("informe a nota %d ",i2+1);
            scanf("%d%*c",&notas[i][i2]);
            media_parcial = media_parcial + notas[i][i2];
            media = (float)media_parcial/3;
            printf("media parcial = %.2f\n",media);
            printf("\n");
        }
        mediavet[i] = media;
        media_parcial = 0;
        printf("\n");
    }

    printf("--------------------------------------Resultado-------------------------------------\n\n");
    for(i=0;i<linha;i++){
        printf("Nome: %s\t\t",alunos[i]);
        for(i2=0;i2<coluna;i2++){
            printf("Nota %d: %d \t", i2+1, notas[i][i2]);
        }
        printf("Media Final= %0.2f",mediavet[i]);
        printf("\n\n");
    }

    return 0;
}

