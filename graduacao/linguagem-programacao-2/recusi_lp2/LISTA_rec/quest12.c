int menor_valor(int *vetor,int tam){
    if(tam == 1){
        return vetor[tam-1];
    }
    else{
        int busca = menor_valor(vetor,tam-1);
        if(vetor[tam-1]< busca){
            return vetor[tam-1];
        }
        else{
            return menor_valor(vetor,tam-1);
        }
    }
}

int main(){
    int vetor[] = {1,-2,3,4,-5};
    printf("%d",menor_valor(vetor,5));
    return 0;

}