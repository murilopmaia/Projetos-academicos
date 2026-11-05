void limpar(){
    scanf("%*[^\n]");
    scanf("%*c");
};

int quantidade_pares(int *vet , int quant){
    int quant_pares=0;
    for(int x = 0; x < quant ; x++){
        if(vet[x]%2 ==0){
            quant_pares++;
        }
    }
    return quant_pares;
}

int main(){
    int quant_de_pares;
    int quantidade;
    printf("\nquantos elementos tem no vetor? ");
    scanf("%d",&quantidade);
    limpar();
    int vetor[quantidade];

    for(int x =0 ; x<quantidade; x++){
        printf("\n\ninforme o %d  elemento : ",x+1);
        scanf("%d",&vetor[x]);
        limpar();
    }
    quant_de_pares = quantidade_pares(vetor,quantidade);
    printf("\n\n\ta quantidade de pares eh : %d\n",quant_de_pares);

    return 0;
}
