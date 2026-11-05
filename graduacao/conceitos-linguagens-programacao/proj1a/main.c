#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAMANHO_VETOR 10000
#define NUM_VETORES 1024

void gerarVetor(int* vetor){
    for (int i = 0; i < TAMANHO_VETOR; i++){
        vetor[i] = rand() % 1024;
    }
}

void imprimirVetorTempo(double* vetor){

    printf("\n[%lf", vetor[0]);
    for (int i = 1; i < NUM_VETORES; i++)
    {
        printf(", %lf", vetor[i]);
    }
    printf("]\n");
}

void escreverVetorTempo(double* vetor){
    FILE *fp;
    fp = fopen(".\\ResultadosC.txt", "w");

    if(fp == NULL){
        printf("\nErro na escrita");
    }
    for(int i = 0; i < NUM_VETORES; i++){
        fprintf(fp, "%lf\n", vetor[i]);
    }

    fclose(fp);
}

void insertionSort(int* vetor){
    int chave;
    int j, i;
    for (i = 1; i < TAMANHO_VETOR; i++)
    {
        chave = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > chave)
        {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

int main(void){
    clock_t ini, fim;
    double tempo;
    double * vetorTempo;
    vetorTempo = (double*) malloc(sizeof(double) * NUM_VETORES);
    int* vetor;
    vetor = (int*) malloc(sizeof(int) * TAMANHO_VETOR);
    srand(5);

    for (int i = 0; i < NUM_VETORES; i++){

        gerarVetor(vetor); 
        ini = clock();
        insertionSort(vetor);
        fim = clock();
        tempo = ((double)(fim - ini)) / CLOCKS_PER_SEC;
        vetorTempo[i] = tempo;
    }
        imprimirVetorTempo(vetorTempo);
        escreverVetorTempo(vetorTempo);

    return 0;
}