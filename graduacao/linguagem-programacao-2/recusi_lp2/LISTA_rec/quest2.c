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
    int vet[3] = {1,2,3};
    imprimir_normal(vet,3);
    return 0;
}