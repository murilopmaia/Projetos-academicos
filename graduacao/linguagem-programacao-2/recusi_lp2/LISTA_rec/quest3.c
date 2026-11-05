void imprimir_inverso(int *vetor,int tam){
    if(tam == 1){
        printf (" %d ",vetor[tam-1]);
    }
    else{
        printf(" %d ",vetor[tam-1]);
        imprimir_inverso(vetor,tam-1);
    }
}

int main(){
    int vet[3] = {1,2,3};
    imprimir_inverso(vet,3);
    return 0;
}