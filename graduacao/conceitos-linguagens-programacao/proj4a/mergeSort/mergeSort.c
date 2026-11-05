#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void gerarVetor(int* vetor, long int tam){
    for (int i = 0; i < tam; i++){
        vetor[i] = rand() % 1024;
    }
}

void merge(int arr[], int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
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
    
        mergeSort(vetor, 0, tam-1);

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