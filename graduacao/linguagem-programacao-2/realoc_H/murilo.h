#include <stdio.h>
#include <stdlib.h>

void criar_vetor(int **vetor,int tam){
    
    *vetor = (int*)realloc(*vetor,(tam)*sizeof(int));
    
}

int *vetor_start(){
    int *vetor;
    vetor = (int*)malloc(1*sizeof(int));
    return vetor;
}

void limpa_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
}

void printar_vetor(int *vetor,int tam){
    printf("\n\nVetor : ");
    for(int i = 0;i<tam;i++){
        printf(" %d ",vetor[i]);
    }
}