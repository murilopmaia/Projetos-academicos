#define num 10
#define origem 0
#include <stdio.h>
#include <stdlib.h>
int main (void){
    int vet1[num], vet2[num], i, soma[num];
    for (i=origem; i<num; i++){
        printf("Insira o %d elemento do 1 vetor: ", i+1);
        scanf("%d", &vet1[i]);
        scanf("%*[^\n]");
        scanf("%*c");
        printf("\n");
    }
    for (i=origem; i<num; i++){
        printf("\nInsira o %d elemento do 2 vetor: ", i+1);
        scanf("%d", &vet2[i]);
        scanf("%*[^\n]");
        scanf("%*c");
        printf("\n");
    }
    int *p1=vet1, *p2=vet2;
    for(i=origem; i<num;i++){
        soma[i]=p1[i]+p2[i];
    }
    printf("A matriz soma e dada por: ");
    for (i=origem; i<num; i++){
        printf(" %d ", soma[i]);
    }
    return 0;
}
