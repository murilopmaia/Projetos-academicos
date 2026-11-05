int *criar_vetor(int tam){
    int *vetor;
    vetor = (int*)malloc(tam*sizeof(int));
    return vetor;
}

void limpa_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
}

void elementos_vetor(int *vetor,int tam){
    printf("\n\nInforme os elementos do vetor ");
    for(int i  = 0;i<tam;i++){
        printf("\nElemento %d ",i+1);
        scanf("%d",&vetor[i]);
        limpa_buffer();
    }
}

void hexadecimal(int *vetor,int tam){
    printf("\n\nPosicao de cada elemento: ");
    for(int i =0;i<tam;i++){
        printf("\n%d == %p",vetor[i],&vetor[i]);
    }
}

int main(){
    int *vetor;
    int tamanho;
    printf("informe o tamanho do vetor : ");
    scanf("%d",&tamanho);
    limpa_buffer();
    vetor = criar_vetor(tamanho);
    elementos_vetor(vetor,tamanho);
    hexadecimal(vetor,tamanho);
    return 0;


}