#include <stdio.h>
#include <stdlib.h>

int main(void){

    int ele_matriz[3][3];
    int soma_linha = 0;
    int soma_coluna = 0;
    int soma_diagonal = 0;
    int soma_diagonal_sec = 0;
    int nao;


    for(int x = 0;x<=2;x++){
        for(int y = 0;y<=2;y++){
            printf("informe o elemento A%d%d \n",x+1,y+1);
            scanf("%d",&ele_matriz[x][y]);
            scanf("%*[^\n]");
            scanf("%*c");
        }
    }

    system("clear||cls");

    for(int x = 0;x<=2;x++){
        for(int y = 0;y<=2;y++){
            printf("%d ",ele_matriz[x][y]);
        }
        printf("\n");
    }

    for(int x = 0;x<=2;x++){
        for(int y = 0;y<=2;y++){
            if(x==y){
                soma_diagonal += ele_matriz[x][y];
            }
            if(x+y == 2){
                soma_diagonal_sec += ele_matriz[x][y];
            }

        }
    }
    if(soma_diagonal != soma_diagonal_sec){
        nao = 1;
    }

    for(int x = 0;x<=2;x++){

        soma_linha = 0;
        for(int y = 0;y<=2;y++){
            soma_linha += ele_matriz[x][y];
        }
        if(soma_linha != soma_diagonal){
            nao = 1;
            break;
        }
    }

     for(int x = 0;x<=2;x++){
        soma_coluna = 0;
        for(int y = 0;y<=2;y++){
            soma_coluna += ele_matriz[y][x];
        }
        if(soma_coluna != soma_diagonal){
            nao = 1;
            break;
        }
     }

    if(nao == 1){
        printf("\n\tnao eh um quadrado magico\n");
    }
    else{
        printf("\n\teh um quadrado magico\n");
    }

    return 0;
}

