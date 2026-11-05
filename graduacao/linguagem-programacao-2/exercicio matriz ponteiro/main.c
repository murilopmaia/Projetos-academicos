
void alocar_coluna(int **matriz, int tam){
    for(int x = 0; x<tam;x++){
        matriz[x] = (int*)malloc(tam * sizeof(int));
    }
}

void limpar_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
}

void leitura_matriz(int **matriz ,int tamN , int tamM){
    for(int x = 0 ; x<tamN;x++){
        for(int y = 0; y<tamM;y++){
            printf("\ninforme o elemento A[%d,%d]: " ,x+1,y+1);
            scanf("%d",&matriz[x][y]);
            limpar_buffer();
        }
    }
}
void transposta(int **matriz,int **matriz_transposta,int tamN, int tamM){
    for(int x = 0;x<tamM;x++){
        for(int y = 0 ;y<tamN;y++){
            matriz_transposta[x][y] = matriz[y][x];
        }
    }
}

void printar_matriz(int **matriz, int tamN , int tamM){
    for(int x = 0;x<tamN;x++){
        for(int y = 0 ;y<tamM;y++){
            printf("%5d ",matriz[x][y]);
        }
        printf("\n");
    }
}

#include <limits.h>

void maiores_numeros(int **matriz,int tamN, int tamM , int quantidade_maiores){
    int tam = quantidade_maiores;
    int maior[tam];
    int indx[tam];
    int indy[tam];
    int x =0,y=0,z=0;

    maior[0] = INT_MIN;

    for(;x<tamN;x++){
        for(y=0;y<tamM;){

            if(maior[z]<matriz[x][y] ){
                for(int w=tam-1;w>z;w--){
                    indx[w] = indx[w-1];
                    indy[w] = indy[w-1];
                    maior[w] = maior[w-1];
                }
                indx[z] = x;
                indy[z] = y;

                maior[z] = matriz[x][y];

                z = 0;
                y++;
            }
            else{
                z++;
                if(z == tam){
                    y++;
                    z=0;
                }
            }
        }
    }

    for(x=0;x<tam;x++){
        printf("\no %d maior termo eh : %d na posicao: %d,%d ",(x+1),maior[x],(indx[x]+1),(indy[x]+1));
    }


    /*int maior1,maior2=0,maior3=0;

    int local_x[3];
    int local_y[3];
    int y=0,x=0;

    maior1 = matriz[x][y];
    local_x[0] = x;
    local_y[0] = y;

    for(x ;x<tamN;x++){
        for( y = 0 ;y<tamM;y++){
            if(maior1 < matriz[x][y]){
                local_x[2] = local_x[1];
                local_y[2] = local_y[1];

                local_x[1] = local_x[0];
                local_y[1] = local_y[0];

                local_x[0] = x;
                local_y[0] = y;

                maior3 = maior2;
                maior2 = maior1;
                maior1 = matriz[x][y];
            }
            else
            if((maior2 < matriz[x][y]) && (matriz[x][y] != maior1)){
                local_x[2] = local_x[1];
                local_y[2] = local_y[1];
                local_x[1] = x;
                local_y[1] = y;

                maior3 = maior2;
                maior2 = matriz[x][y];
            }
            else
            if((maior3 < matriz[x][y]) && (matriz[x][y] != maior2) && (matriz[x][y] != maior1)){
                local_x[2] = x;
                local_y[2] = y;

                maior3 = matriz[x][y];
            }
        }
    }

    printf(" o maior elemento eh: %d A[%d,%d]\n o segundo maior elemento eh: %d A[%d,%d] \n o terceiro maior elemento eh: %d A[%d,%d] \n",maior1, local_x[0] +1,local_y[0] +1,maior2,local_x[1]+1,local_y[1]+1,maior3,local_x[2]+1,local_y[2]+1);
    */
}

void liberar(int **matriz, int tam){
    for(int x = 0;x<tam;x++){
            free(matriz[x]);
    }
    free(matriz);
}

int main(){
    int m,n;
    int maior;
    int **matriz;
    int **matriz_transposta;

    printf("informe a quantidade de linhas da matriz ");
    scanf("%d",&m);
    limpar_buffer();

    printf("informe a quantidade de colunas da matriz ");
    scanf("%d",&n);
    limpar_buffer();

    matriz = (int**)malloc(m * sizeof(int*));
    matriz_transposta = (int**)malloc(n * sizeof(int*));
    alocar_coluna(matriz_transposta,m);
    alocar_coluna(matriz,n);

    leitura_matriz(matriz,n,m);
    transposta(matriz,matriz_transposta,n,m);
    printf("\n\n");

    printar_matriz(matriz,n,m);
    printf("\n\n");

    printar_matriz(matriz_transposta,m,n);
    printf("\n\n");

    do{
    printf("\ninforme a quantidade de maiores numeros ");
    scanf("%d",&maior);
    limpar_buffer();

    if(maior > (n*m)){
        printf("\n\ninforme uma quantidade dentro do tamanho da matriz\n\n");
    }
    }
    while(maior > (n*m));


    maiores_numeros(matriz,n,m,maior);
    printf("\n\n");

    liberar(matriz,m);
    liberar(matriz_transposta,n);
    return 0;
}
