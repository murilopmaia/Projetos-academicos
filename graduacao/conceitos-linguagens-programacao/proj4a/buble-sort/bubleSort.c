#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void gerarVetor(int* vetor, long int tam){
    for (int i = 0; i < tam; i++){
        vetor[i] = rand() % 1024;
    }
}

void bubbleSort(int array[], long int size) {
    int temp;
    for (int step = 0; step < size - 1; ++step) {
        for (int i = 0; i < size - step - 1; ++i) {
      
            if (array[i] > array[i + 1]) {
        
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
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
        bubbleSort(vetor, tam);
        fim = clock();
        tempo = ((double)(fim - ini)) / CLOCKS_PER_SEC;
        printf("%d -> tempo: %lf -> tamanho: %ld\n", i, tempo, tam);
        if(tempo < 60){
            tam *= 10;
        }
        free(vetor);
    }
    return 0;
}