int main(void){

    int vetor[20];
    int indice = 0;
    int maior;
    int menor;
    int mediap = 0;
    float media;
    int i;

    for(;indice < 20;){

        printf("informe o %d numero ",(indice + 1));
        scanf("%d%*c",&vetor[indice]);
        indice++;
    }
    maior = vetor[0];
    menor = vetor[0];

    for(; i < 20;i++){
       if(maior < vetor[i]){
        maior = vetor[i];
       }
       if(menor > vetor[i]){
        menor = vetor[i];
       }
       mediap = mediap + vetor[i];
    }

    media = (float)mediap/20;

    printf(" o maior valor é = %d\n",maior);
    printf(" o menor valor é = %d\n",menor);
    printf("a media é = %.2f6\n",media);

    return 0;
}
