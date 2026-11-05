#include <stdio.h>
#include <stdlib.h>

struct produto{
    int codigo;
    char nome[50];
    float preco;
};

typedef struct produto pro;

void limpar_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
}

int main(){
    FILE *fp;
    int parar = 0;
    pro produtos;
    int codigo_buscado;
    fp = fopen("Produtos.dat","rb");

    if(fp == NULL){
        printf("Arquivo nao existe");
        return 0;
    }

    for(;parar != -1;){
        printf("\nInforme o codigo do produto: ");
        scanf("%d",&codigo_buscado);
        limpar_buffer();
        rewind(fp);//aponta pro inicio;
        
        do{
            fread(&produtos,sizeof(pro),1,fp);
            if(produtos.codigo == codigo_buscado ){
                printf("\n\n----------------------------------------------------");
                printf("\nCodigo: %d",produtos.codigo);
                printf("\nNome : %s",produtos.nome);
                printf("\nPreco produto : %.2f",produtos.preco);
                printf("\n\n----------------------------------------------------");
            }
            if(feof(fp)){
                printf("\nProduto nao encontrado");
            }
        }
        while(!feof(fp) && produtos.codigo != codigo_buscado );

        printf("\n\n-Se deseja parar digite -1: ");
        scanf("%d",&parar);
        limpar_buffer();
    }

    fclose(fp);
    return 0;
}

