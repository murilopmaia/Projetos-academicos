#define TAM 6
int maior_elemento(int *vetor,int tam){
    if(tam == 0){
        return vetor[tam];
    }
    else{
        if(vetor[tam]>maior_elemento(vetor,tam-1)){
            return vetor[tam];
        }
        return maior_elemento(vetor,tam-1);
    }
}

int main(){
    system("clear||cls");
    int vetor[TAM]={8,2,3,10,5,6};
    printf(" %d ",maior_elemento(vetor, TAM-1));
    return 0;
}