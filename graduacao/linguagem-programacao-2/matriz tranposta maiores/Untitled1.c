
//para alocar as colunas na alocação dinâmica
void alocar_coluna(int **matriz, int tam){
    for(int x = 0; x<tam;x++){
        matriz[x] = (int*)malloc(tam * sizeof(int));
    }
}

//para limpar o buffer do teclado
void limpar_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
}

//para ler os elementos da matriz, que será dado pelo usuário
void leitura_matriz(int **matriz ,int tamN , int tamM){
    for(int x = 0 ; x<tamN;x++){
        for(int y = 0; y<tamM;y++){
            printf("\ninforme o elemento A[%d,%d]: " ,x+1,y+1);
            scanf("%d",&matriz[x][y]);
            limpar_buffer();
        }
    }

}

//para criar a matriz transposta 
void transposta(int **matriz,int **matriz_transposta,int tamN, int tamM){
    for(int x = 0;x<tamM;x++){
        for(int y = 0 ;y<tamN;y++){
            matriz_transposta[x][y] = matriz[y][x];
        }
    }
}

//para printar as 2 matrizes
void printar_matriz(int **matriz, int tamN , int tamM){
    for(int x = 0;x<tamN;x++){
        for(int y = 0 ;y<tamM;y++){
            printf("%5d ",matriz[x][y]);
        }
        printf("\n");
    }
}

#include <limits.h>

//optei em deixar o usuário escolher a quantidade de numéros maiores que ele deseja ver, fiz assim para poder treinar
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

}

//para liberar espaço para as duas matrizes
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

    if(maior > (n*m) || maior<0){
        printf("\n\ninforme uma quantidade dentro do tamanho da matriz\n\n");
    }
    }
    while(maior > (n*m) || maior<0);


    maiores_numeros(matriz,n,m,maior);
    printf("\n\n");

    liberar(matriz,m);
    liberar(matriz_transposta,n);
    return 0;
}
