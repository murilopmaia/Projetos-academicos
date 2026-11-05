#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void gerarVetor(int* vetor, long int tam){
    for (int i = 0; i < tam; i++){
        vetor[i] = rand() % 1024;
    }
}

void insertionSort(int* vetor, long int tam){
    int chave;
    int j, i;
    for (i = 1; i < tam; i++){
        chave = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > chave){
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

void imprimeVetor(int *vetor, long int tam){
    printf("\n{%d", vetor[0]);
    for(int i = 1; i < tam; i++){
        printf(" ,%d", vetor[i]);
    }
    printf("}");
}

int main(void){
    clock_t ini, fim;
    double tempo;
    long int tam = 10;
    int *vetor;
    for(int i = 0; i < 10; i++){
        vetor = (int*)malloc(sizeof(int) * tam);
        gerarVetor(vetor, tam);
        ini = clock();
        insertionSort(vetor, tam);
        fim = clock();
        tempo = ((double)(fim - ini)) / CLOCKS_PER_SEC;
        printf("%d -> tempo: %lf -> tamanho: %ld\n", i, tempo, tam);
        if(tam != 100000){
            tam *= 10;
        }
        free(vetor);
    }
    return 0;
}