#include <stdio.h>

void limpa_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
}

void cria_vetor(int **vetorzin,int tam){
    (*vetorzin)=(int*)malloc(tam*sizeof(int));
}

void preenche_vetor(int *vetorzin,int tam){
    printf("\n\ninforme os elementos do vetor :");
    for(int x = 0;x<tam;x++){
        printf("\nElemento %d ",x+1);
        scanf("%d",&vetorzin[x]);
        limpa_buffer();
    }
}

void mostrar_vetor_tela(int **vetorzin,int tam){
    printf("\n\nVetor: ");
    for(int i = 0;i<tam;i++){
        printf(" %d ",(*vetorzin)[i]);
    }
}

int main(){
    int *vetor;
    int tamanho;

    printf("\nInforme o tamanho do vetor : ");
    scanf("%d",&tamanho);
    limpa_buffer();
     cria_vetor(&vetor,tamanho);
     preenche_vetor(vetor,tamanho);
     mostrar_vetor_tela(&vetor,tamanho);
     free(vetor);
}
