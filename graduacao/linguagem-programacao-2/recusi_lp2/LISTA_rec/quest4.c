void inverter_vetor(int *vetor,int tam,int atual){
    if(tam>atual){
        int aux;
        aux = vetor[atual];
        vetor[atual] = vetor[tam];
        vetor[tam] = aux;
        inverter_vetor(vetor,tam-1,atual+1);
    }
}

void inverter(int *vetor,int tam){
    inverter_vetor(vetor,tam-1,0);
}

void imprimir_normal(int *vet,int tam){
    if(tam == 1){
        printf(" %d ",vet[tam-1]);

    }
    else{
        imprimir_normal(vet,tam-1);
        printf(" %d ",vet[tam-1]);
    }
}

int main(){
    int vetor[] = {1,2,3,4};
    imprimir_normal(vetor,4);
    inverter(vetor,4);
    printf("\n\n");
    imprimir_normal(vetor,4);
    return 0;
}