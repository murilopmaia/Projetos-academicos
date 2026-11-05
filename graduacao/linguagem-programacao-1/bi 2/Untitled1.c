#include <stdlib.h>
#include <stdio.h>
#define linha 3
#define coluna 3

int main(void){

    int matriz[linha][coluna], i, i2, maior, menor, mediap=0, traco=0;
    float media;

    printf("informe os elementos da matriz: \n\n");
    for(i=0;i<linha;i++){
        for(i2=0;i2<coluna;i2++){
            scanf("%d%*c",&matriz[i][i2]);
        }
    }

    printf("---------------Matriz--------------\n\n");
    for(i=0;i<linha;i++){
        printf("\t\t");
        for(i2=0;i2<coluna;i2++){
            printf(" %d ",matriz[i][i2]);
        }
        printf("\n");
    }

    maior = matriz[0][0];
    menor = matriz[0][0];

     for(i=0;i<linha;i++){
        for(i2=0;i2<coluna;i2++){
            if(maior < matriz[i][i2])
                maior = matriz[i][i2];
            if(menor > matriz[i][i2])
                menor = matriz[i][i2];
            mediap = mediap + matriz[i][i2];
            if(i == i2)
                traco = traco + matriz[i][i2];
        }
    }

    media = (float)mediap/9;

    printf("\n\n---------------Detalhes--------------\n\n");
    printf("o maior termo da matriz eh %d\n",maior);
    printf("o menor termo da matriz eh %d\n",menor);
    printf("a media dos termos da matriz eh %.2f\n",media);
    printf("o traco da matriz eh %d\n",traco);

    return 0;
}
