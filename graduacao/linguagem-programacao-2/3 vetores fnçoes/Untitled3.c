
void limpar(){
    scanf("%*[^\n]");
    scanf("%*c");
};

void tela(){
    system("clear||cls");
};

void soma_vet(int *vet1, int tam1 , int *vet2 , int tam2 , int *vet3){
    int tam3 = tam1 + tam2;
    int x;
    for(x = 0;x<tam1;x++){
        vet3[x] = vet1[x];
    }
    for(int y = 0; y<tam2;y++){

        vet3[x] = vet2[y];
        x++;
    }
    printf("\n\n\tvetor3 : ");
    for(int z = 0; z < tam3;z++){
        printf(" %d,",vet3[z]);
    }
    printf("\n");
}

int main (){

    int tam1,tam2,tam3;

    printf("\ninforme o Tamanho do 1 vetor: ");
    scanf("%d",&tam1);
    limpar();
    int vetor1[tam1];

    printf("\ninforme o Tamanho do 2 vetor: ");
    scanf("%d",&tam2);
    limpar();
    int vetor2[tam2];

    tam3 = tam1 + tam2;
    int vetor3[tam3];
    tela();
    for(int x = 0; x<tam1;x++){
        printf("\n\ninforme o elemento %d do 1 vetor " ,x+1);
        scanf("%d",&vetor1[x]);
        limpar();
    }

    tela();

     for(int x = 0; x<tam2;x++){
        printf("\n\ninforme o elemento %d do 2 vetor ",x+1);
        scanf("%d",&vetor2[x]);
        limpar();
    }

    tela();

    soma_vet(vetor1,tam1,vetor2,tam2,vetor3);

return 0;

}

