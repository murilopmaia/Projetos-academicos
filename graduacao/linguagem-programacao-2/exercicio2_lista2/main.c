void criar_vetor(int **vet,int tam){
    (*vet) = (int*)malloc(tam*sizeof(int)); 
}

void limpa_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
}

void elementos_vetor(int *vetor,int tam){
    system("clear||cls");
    printf("\n\nInforme os elementos do vetor : ");
    for(int i = 0;i<tam;i++){
        printf("\nElemento %d ",i+1);
        scanf("%d",&vetor[i]);
        limpa_buffer();
    }
}

void mm(int *vetor,int tam,int *max,int *min){
    *max = vetor[0];
    *min = vetor[0];
    for(int i = 0;i<tam;i++){
        if(*max<vetor[i]){
            *max = vetor[i];
        }
        if(*min>vetor[i]){
            *min = vetor[i];
        }
    }
}

void printa_vetor(int *vetor,int tam){
    printf("\n\nVetor : ");
    for(int i = 0;i<tam;i++){
        printf(" %d ",vetor[i]);
    }
}

int main(){
    int *vetor,min,max,tam;

    printf("Infrome o tamanho do vetor : ");
    scanf("%d",&tam);
    limpa_buffer();
    criar_vetor(&vetor,tam);
    elementos_vetor(vetor,tam);
    mm(vetor,tam,&max,&min);
    printa_vetor(vetor,tam);
    printf("\n\nMaior elemento : %d",max);
    printf("\nMenor elemento : %d",min);
    free(vetor);
    return 0;
}