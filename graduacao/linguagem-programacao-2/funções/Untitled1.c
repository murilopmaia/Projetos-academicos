int maior(int A, int B, int C);//prototipo

void limpar(){
    scanf("%*[^\n]");
    scanf("%*c");
}

void mensagem(char *msg){
    printf("\nseu nome eh: %s",msg);
}

void pausa(){
    scanf("%*c");
}

void troca(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int main(){
    int valor[3], W;
    char nome[100];
    for(int x = 0; x<3;x++){
        printf("\ninforme o %d valor ",x+1);
        scanf("%d",&valor[x]);
        limpar();
    }
    W = maior(valor[0],valor[1],valor[2]);
    printf("\n\no maior termo : %d\n",W);
    pausa();

    //string ponteiro
    system("clear||cls");
    printf("\nEscreva seu nome: ");
    scanf("%[^\n]s",nome);
    limpar();
    mensagem(nome);
    pausa();

    //troca
    system("clear||cls");
    int troca1=5, troca2=10 , troca3=20;
    troca(&troca1,&troca2);
    troca(&troca1,&troca3);
    printf("\ntermos trocados : %d %d %d\n",troca1,troca2,troca3);
    pausa();

    return 0;
}

int maior(int A, int B, int C){

    if(A >= B && A >= C ){
        return A;
    }
    else
    if(B >= C){
        return B;
    }
    else{
        return C;
    }

};
