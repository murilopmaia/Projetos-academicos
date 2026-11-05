
void limpa_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
}

void novo_vetor(int **vetor,int *tam){
    
    for(int i = 0;i<*tam;i++){
        if(vetor[i] == vetor[i+1]){
            for(int x = i+1;x<*tam;x++){
                vetor[x] = vetor[x+1];
            }
            //*tam--; NÃO FUNCIONA , MELHORE C
            *tam = *tam -1;
            *vetor = (int*)realloc(*vetor,(*tam)*sizeof(int));
            i--;
        }
    }
}

int main(){
    int *vetor;
    int tamanho;
    printf("\nInforme o tamanho do vetor ");
    scanf("%d",&tamanho);
    limpa_buffer();
    vetor = (int*)malloc(tamanho * sizeof(int));
    printf("\n\ninforme os elementos do vetor ");
    for(int i = 0;i<tamanho;i++){
        printf("\nelemento %d : ",i+1);
        scanf("%d",&vetor[i]);
        limpa_buffer();
    }
    system("clear||cls");
    printf("\n\nVetor Antigo : ");
    for(int i = 0;i<tamanho;i++){
        printf(" %d ",vetor[i]);
    }
    novo_vetor(&vetor,&tamanho);
   

    printf("\n\nNovo Vetor : ");;
     for(int i = 0;i<tamanho;i++){
        printf(" %d ",vetor[i]);
    }
    free(vetor);
    return 0;

}
