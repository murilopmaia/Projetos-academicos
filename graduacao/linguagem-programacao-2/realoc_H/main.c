#include "murilo.h"

int main(){
    int *vetor;
    int opcao=0;
    int tamanho=1;
    vetor = vetor_start();
    printf("informe os elementos do vetor,aperte 24 para parar :");
    for(int i = 0 ;opcao!=24;i++){
        printf("\nElemento A[%d]: ",i+1);
        scanf("%d",&opcao);
        limpa_buffer();
        if(opcao == 24){
            tamanho--;
            criar_vetor(&vetor,tamanho);
        }
        if(opcao != 24){
            vetor[i] = opcao;
            tamanho++;
            criar_vetor(&vetor,tamanho);
            
        }
        
    }

    printar_vetor(vetor,tamanho);
    free(vetor);
    return 0;
}