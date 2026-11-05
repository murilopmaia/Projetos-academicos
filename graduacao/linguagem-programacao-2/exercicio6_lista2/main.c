int *criar_vetor(int tam){
    int *aux;
    aux = (int*)malloc(tam*sizeof(int));
    return aux;
}

void limpa_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
}

void calculadora(int *vet,int x,int y){
    vet[0] = x+y;
    vet[1] = x-y;

}

int main(){
    int *vetor;
    int tamanho = 2,x,y;
    vetor = criar_vetor(tamanho);
    printf("Informe o valor de X : ");
    scanf("%d",&x);
    limpa_buffer();
    printf("Informe o valor de y : ");
    scanf("%d",&y);
    limpa_buffer();
    calculadora(vetor,x,y);
    x = vetor[0];
    y = vetor[1];

    printf(" x  =  %d" ,x);
    printf("\n\n y = %d",y);
    free(vetor);
    return 0;

}