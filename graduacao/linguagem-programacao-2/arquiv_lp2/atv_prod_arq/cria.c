
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
    pro produtos;
    int parar=0;

    fp = fopen("Produtos.dat","wb");
    for(;parar==0;){
        printf("\nInforme o codigo do produto: ");
        scanf("%d",&produtos.codigo);
        limpar_buffer();

        printf("\nInforme o nome do produto: ");
        scanf("%[^\n]s",&produtos.nome);
        limpar_buffer();

        printf("\nInforme o preco do produto: ");
        scanf("%f",&produtos.preco);
        limpar_buffer();

        fwrite(&produtos,sizeof(pro),1,fp);

        printf("\nSe deseja continuar digite 0: ");
        scanf("%d",&parar);
        limpar_buffer();

        system("clear||cls");
    }
    fclose(fp);
    return 0;
}