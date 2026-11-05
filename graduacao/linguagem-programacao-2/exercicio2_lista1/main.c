void limpa_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
}

int **criar_matriz(int **matrizinha,int n,int m){
    matrizinha = (int**)malloc(n*sizeof(int*));
    for(int i = 0;i<n;i++){
        matrizinha[i] = (int*)malloc(m*sizeof(int));
    }

    return matrizinha;
}

void elemento_matriz(int **matrizinha,int n,int m){
    printf("n\nMatriz:\n\n");
    for(int i = 0;i<n;i++){
        for(int y = 0;y<m;y++){
            printf("\nElemento A[%d,%d] ",i+1,y+1);
            scanf("%d",&matrizinha[i][y]);
            limpa_buffer();
        }
        
    }
}

void printa_matriz(int **matrizinha,int n,int m){
    printf("n\nMatriz:\n\n");
    for(int i = 0;i<n;i++){
        for(int y = 0;y<m;y++){
            printf(" %5.d ",matrizinha[i][y]);
        }
        printf("\n");
    }
}

void fim_matriz(int **matriz,int n){
    for(int i = 0;i<n;i++){
        free(matriz[i]);
    }
    free(matriz);
}


int main(){
    int **matriz;
    int tamanho_n;
    int tamanho_m;
    printf("\nInforme o tamanho n da matriz ");
    scanf("%d",&tamanho_n);
    limpa_buffer();

    printf("\nInforme o tamanho m da matriz ");
    scanf("%d",&tamanho_m);
    limpa_buffer();

    matriz = criar_matriz(matriz,tamanho_n,tamanho_m);
    elemento_matriz(matriz,tamanho_n,tamanho_m);
    printa_matriz(matriz,tamanho_n,tamanho_m);
    fim_matriz(matriz,tamanho_n);

    return 0;
}