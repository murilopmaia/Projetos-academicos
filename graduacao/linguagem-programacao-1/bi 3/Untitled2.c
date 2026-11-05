#include <stdlib.h>
#include <stdio.h>
#define linha 3
#define coluna 4

int main(void){

    int matriz[linha][coluna];
    int i;
    int i2;

    printf("informe os elementos da matriz\n\n");
    for(i=0;i<linha;i++){
        for(i2=0;i2<coluna;i2++){
            scanf("%d%*c",&matriz[i][i2]);
        }
    }

    printf("---------------Matriz--------------\n\n");
    for(i=linha-1;i>=0;i--){
        printf("\t");
        for(i2=coluna-1;i2>=0;i2--){
            printf(" %d ",matriz[i][i2]);
        }
        printf("\n");
    }
    printf("---------------Matriz transposta--------------\n\n");

    for(i2=0;i2<4;i2++){
        printf("\t");
        for(i=0;i<3;i++){
            printf(" %d ",matriz[i][i2]);
        }
        printf("\n");
    }
    return 0;
}
