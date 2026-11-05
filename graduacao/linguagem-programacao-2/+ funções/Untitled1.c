
#define TAM 2

void limpar_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");

}

void ler_dados(int **matri){
    for(int x = 0;x<TAM;x++){
        for(int y = 0;y<TAM;y++){
            printf("\ninforme o elemento A[%d,%d] ",x+1,y+1);
            scanf("%d",&matri[x][y]);
            limpar_buffer();
        }
    }

}

void criar_coluna(int **mat){

    for(int x = 0; x<TAM ;x++){
        mat[x]= (int*)malloc(TAM * sizeof(int));
    }


}

int main (){
 int **matriz;

    matriz = (int**)malloc(TAM * sizeof(int*));

    criar_coluna(matriz);
    ler_dados(matriz);

     for(int x = 0;x<TAM;x++){
        for(int y = 0;y<TAM;y++){
            printf("%d ",matriz[x][y]);

        }
    }
    return 0;
}
