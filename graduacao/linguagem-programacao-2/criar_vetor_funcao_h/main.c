
#include "murilo.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vetor;
    int tamanho;
    printf("Infome o tamanho do vetor ");
    scanf("%d",&tamanho);
    limpar_buffer();
    vetor = criar_vetor(tamanho);
    elementos_vetor(vetor,tamanho);
    printa_vetor(vetor,tamanho);
    free(vetor);
    return 0;
}