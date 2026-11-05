
#include <stdio.h>
#include <stdlib.h>

void limpar_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
}

int *criar_vetor(int tam){
    int *vetor;
    vetor = (int*)malloc(tam*sizeof(int));
    return vetor;
}

void elementos_vetor(int *vetor,int tam){
    printf("\n\nInforme os elementos:");
    for(int i = 0;i<tam;i++){
        printf("\nA[%d]: ",i+1);
        scanf("%d",&vetor[i]);
        limpar_buffer();
    }
}

void printa_vetor(int *vetor,int tam){
    printf("\n\n Vetor: ");
    for(int i = 0;i<tam;i++){
        printf(" %d ",vetor[i]);
    }
}