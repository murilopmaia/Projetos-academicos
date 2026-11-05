#include <stdlib.h>
#include <stdio.h>
#define linha 2
#define coluna 2

int main(void){

    int matrizA[linha][coluna];
    int matrizB[linha][coluna];
    int resultado[linha][coluna];
    int i;
    int i2;
    int ia;
    int i2a = 0;
    int ib = 0;
    int i2b = 0;
    int resultadop;
    int resultados = 0;

    printf("informe os elementos da matriz A\n\n");
    for(i=0;i<linha;i++){
        for(i2=0;i2<coluna;i2++){
            scanf("%d%*c",&matrizA[i][i2]);
        }
    }

    printf("informe os elementos da matriz B\n\n");
    for(i=0;i<linha;i++){
        for(i2=0;i2<coluna;i2++){
            scanf("%d%*c",&matrizB[i][i2]);
        }
    }

    for(i=0;i<2;i++){
        for(i2a = 0;i2a < 2 ; i2a++){
            i2 = 0;
            for(ia = 0; ia < 2 ;ia++ ){
                resultadop = matrizA[i][i2] * matrizB[ia][i2a];
                resultados = resultados + resultadop;
                i2 ++;
            }
        resultado[ib][i2b] = resultados;
        i2b++;
            if(i2b == 2){
                i2b = 0;
                ib++;
            }
        resultados = 0;
        }
    }

    printf("----------------Resultado--------------------\n");
   for(ib=0;ib<linha;ib++){
        printf("\t\t");
       for(i2b=0;i2b<coluna;i2b++){
            printf("  %d  ",resultado[ib][i2b]);
        }
        printf("\n");
   }
    return 0;
}
