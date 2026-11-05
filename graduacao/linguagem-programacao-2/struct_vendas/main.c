#include <stdio.h>
#include <stdlib.h>

 struct CadProduto{
    int codigo;
    char descricao[50];
    float preco;
};

typedef struct CadProduto CadProduto;

struct cliente{
    int codigo;
    char nome[50];    
};
typedef struct cliente cliente;

void limpa_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
}

void menu(){
    printf("1. Cadastrar Produto\n");
    printf("2. Alterar Produto\n");
    printf("3. Excluir Produto\n");
    printf("4. Cadastrar Cliente\n");
    printf("5. Alterar Cliente\n");
    printf("6. Excluir Cliente\n");
    printf("7. Efetuar compra\n");
    printf("Digite qualquer outra opcao para encerrar o programa\n\n");
}

int verificar_codigo(CadProduto *pro,int tam,int codigo){
    for(int i = 0;i<tam;i++){
        if(pro[i].codigo == codigo){
            return 1;
        }
    }
    return 0;
}

void cadastrar_produto(CadProduto *pro,int *Tam){
    
   //int teste;
   // teste = *Tam + 1;
   //pro = (struct CadProduto*)realloc(pro,sizeof(struct CadProduto)*teste);
   int aux;
    printf("\nInforme o Codigo do novo Produto: ");
    do{
    scanf("%d",&aux);
    limpa_buffer();
    if(verificar_codigo(pro,*Tam,aux)==1){
        printf("\n\nCodigo ja cadastrado,Digite outro\n");
    }
    }
    while(verificar_codigo(pro,*Tam,aux)==1);
    pro[*Tam].codigo = aux;

    printf("\nINforme a descricao do novo Produto: ");
    scanf("%[^\n]s",&pro[*Tam].descricao);
    limpa_buffer();
   
    
    printf("\nInforme o preco do produto: ");
    scanf("%f",&pro[*Tam].preco);
    limpa_buffer();
    *Tam = *Tam + 1;

}

void printar_produtos(CadProduto *pro, int Tam){
    
    for(int i = 0;i<Tam;i++){
        
        printf("\nCodigo: %d",pro[i].codigo);
        printf("\n\nDescricao: %s",pro[i].descricao);
        printf("\n\nPreco : %.2f",pro[i].preco);
        printf("\n---------------------------------------------------------------------------\n");
    }
}

void alterar_produto(CadProduto *pro,int Tam,int codigo){
    int i;
    for(i = 0;i<Tam;i++){
        if(pro[i].codigo == codigo){
            break;
        }
    }

    printf("\nInforme o Codigo  novo do Produto: ");
    scanf("%d",&pro[i].codigo);
    limpa_buffer();

    printf("\nINforme a descricao  nova do Produto: ");
    scanf("%[^\n]s",&pro[i].descricao);
    limpa_buffer();
   
    
    printf("\nInforme o preco novo do produto: ");
    scanf("%f",&pro[i].preco);
    limpa_buffer();
}

int verificar_existencia_codigo(CadProduto *pro,int tam,int codigo){
    int verificar;
    for(int i = 0;i<tam;i++){
        if(pro[i].codigo == codigo){
            return 1;
        }
    }
    return 0;
}

void excluir_produto(CadProduto *pro,int *tam,int codigo){
    int i;
    for(i = 0;i<*tam;i++){
        if(pro[i].codigo == codigo){
            break;
        }
    }

    for(int j = i;j<*tam;j++){
        pro[j] = pro[j+1];
    }
   // pro = (CadProduto*)realloc(pro,(*tam)*sizeof(CadProduto));
    *tam = *tam - 1;
}

int verificar_codigo_cliente(cliente *cli,int tam,int codigo){
    for(int i = 0;i<tam;i++){
        if(cli[i].codigo == codigo){
            return 1;
        }
    }
    return 0;
}

void cadastrar_cliente(cliente *cli,int *Tam){
    int aux;

    do{
        printf("Informe o codigo do cliente: ");
        scanf("%d",&aux);
        limpa_buffer();
        if(verificar_codigo_cliente(cli,*Tam,aux) == 1){
            printf("\n\nCliente ja cadastrado,digite outro codigo ");

        }
    }
    while(verificar_codigo_cliente(cli,*Tam,aux) == 1);
    cli[*Tam].codigo = aux;

    printf("\nInforme o nome do cliente: ");
    scanf("%[^\n]s",&cli[*Tam].nome);
    limpa_buffer();
    *Tam = *Tam +1;
}

void printar_cliente(cliente *cli, int Tam){
   
    for(int i = 0;i<Tam;i++){
        
        printf("\nCodigo: %d",cli[i].codigo);
        printf("\n\nNome: %s",cli[i].nome);
        printf("\n---------------------------------------------------------------------------\n");
    }
}

int verificar_existencia_codigo_cliente(cliente *cli,int tam,int codigo){
    int verificar;
    for(int i = 0;i<tam;i++){
        if(cli[i].codigo == codigo){
            return 1;
        }
    }
    return 0;
}

void alterar_cliente(cliente *cli,int Tam,int codigo){
    int i;
    for(i = 0;i<Tam;i++){
        if(cli[i].codigo == codigo){
            break;
        }
    }

    printf("\nInforme o Codigo  novo do Cliente: ");
    scanf("%d",&cli[i].codigo);
    limpa_buffer();

    printf("\nINforme o Nome novo do Cliente: ");
    scanf("%[^\n]s",&cli[i].nome);
    limpa_buffer();
   
}

void excluir_cliente(cliente *cli,int *Tam,int codigo){
    int i;
    for(i = 0;i<*Tam;i++){
        if(cli[i].codigo == codigo){
            break;
        }
    }

    for(int j = i;j<*Tam;j++){
        cli[j] = cli[j+1];
    }
   
    *Tam = *Tam - 1;
}

int procurar_cliente(cliente *cli,int tam,int codigo){
    for(int i = 0;i<tam;i++){
        if(cli[i].codigo == codigo){
            return i;
        }
    }
}

int somador(CadProduto *pro,int tam,int codigo){
    for(int i = 0;i<tam;i++){
        if(pro[i].codigo == codigo){
            return pro[i].preco;
        }
    }
}

CadProduto compras(CadProduto *pro,int tam,int codigo){
    for(int i = 0;i<tam;i++){
        if(pro[i].codigo == codigo){
            return pro[i];
        }
    }
}

void mostrar_estrato(cliente *cli,int indice,int soma,CadProduto *pro_cli,int tam){
    system("clearr||cls");
    printf("O cliente: %s , de codigo: %d, tem no total de comprar o preco de: %d\n\n",cli[indice].nome,cli[indice].codigo,soma);
    printf("\n\nProdutos comprados: \n");
    printf("\n--------------------------------------------------------------------------------------\n");
     printar_produtos(pro_cli,tam);
    
}

int main(){
    CadProduto *produtos;
    cliente *clientela;
    int escolha;
    int Tam_Produtos=0;
    int Tam_clientes=0;
    int escolha_codigo;

    int escolha_codigo_cliente;
    int escolha_codigo_produto;
    int estrato = 0;
    int soma=0;
    CadProduto *compras_str;
    int i = 0;

    compras_str = (CadProduto*)malloc(100*sizeof(CadProduto));


    produtos = (CadProduto*)malloc(100*sizeof(CadProduto));
    clientela = (cliente*)malloc(100*sizeof(cliente));
    

    for(;;){
        system("clear||cls");
        menu();
        scanf("%d",&escolha);
        limpa_buffer();
        system("clear||cls");
        switch (escolha){
        case 1: cadastrar_produto(produtos,&Tam_Produtos);
            break;
        
        case 2: 
                printf("Informe o codigo do produto: \n\n");
                printar_produtos(produtos,Tam_Produtos);
                scanf("%d",&escolha_codigo);
                limpa_buffer();
                if(verificar_existencia_codigo(produtos,Tam_Produtos,escolha_codigo) == 1){
                    alterar_produto(produtos,Tam_Produtos,escolha_codigo);
                    printf("\n\nProduto alterado");
                    scanf("%*c");
                }
                else{
                    system("clear||cls");
                    printf("Produto nao cadastrado");
                    scanf("%*c");
                }
            
            break;
        case 3:
                printf("Informe o codigo do produto: \n\n");
                printar_produtos(produtos,Tam_Produtos);
                scanf("%d",&escolha_codigo);
                limpa_buffer();
                if(verificar_existencia_codigo(produtos,Tam_Produtos,escolha_codigo) == 1){
                    excluir_produto(produtos,&Tam_Produtos,escolha_codigo);
                    printf("\n\nProduto excluido ");
                    scanf("%*c");
                }
                else{
                    system("clear||cls");
                    printf("Produto nao cadastrado");
                    scanf("%*c");
                }
            break;

        case 4:
                cadastrar_cliente(clientela,&Tam_clientes);
            break;

        case 5:
                printf("Informe o codigo do Cliente: \n\n");
                printar_cliente(clientela,Tam_clientes);
                scanf("%d",&escolha_codigo);
                limpa_buffer();
                if(verificar_existencia_codigo_cliente(clientela,Tam_clientes,escolha_codigo) == 1){
                    alterar_cliente(clientela,Tam_clientes,escolha_codigo);
                    printf("\n\nCliente alterado");
                    scanf("%*c");
                }
                else{
                    system("clear||cls");
                    printf("Cliente nao cadastrado");
                    scanf("%*c");
                }
            break;
        case 6:
                printf("Informe o codigo do Cliente: \n\n");
                printar_cliente(clientela,Tam_clientes);
                scanf("%d",&escolha_codigo);
                limpa_buffer();
                if(verificar_existencia_codigo_cliente(clientela,Tam_clientes,escolha_codigo) == 1){
                    excluir_cliente(clientela,&Tam_clientes,escolha_codigo);
                    printf("\n\nCliente excluido ");
                    scanf("%*c");
                }
                else{
                    system("clear||cls");
                    printf("Cliente nao cadastrado");
                    scanf("%*c");
                }
            break;
        case 7:
                

                printf("Informe o codigo do Cliente que queres efetuar a compra: \n\n");
                printar_cliente(clientela,Tam_clientes);
                scanf("%d",&escolha_codigo_cliente);
                limpa_buffer();
                if(verificar_codigo_cliente(clientela,Tam_Produtos,escolha_codigo_cliente) == 1){
                    system("clear||cls");
                    
                    for(i=0;estrato!=-1;i++){
                        do{
                            printf("Escolha os produtos que desejas comprar,digite -1 para obter o saldo da comprar: \n\n");
                            printar_produtos(produtos,Tam_Produtos);
                            scanf("%d",&escolha_codigo_produto);
                            limpa_buffer();
                            if(verificar_codigo(produtos,Tam_Produtos,escolha_codigo_produto)!=1){
                                system("clear||cls");
                                printf("Codigo errado, digite novamente \n\n");
                                
                            }
                        }
                        while(verificar_codigo(produtos,Tam_Produtos,escolha_codigo_produto)!=1);
                        soma = soma + somador(produtos,Tam_Produtos,escolha_codigo_produto);
                        compras_str[i] = compras(produtos,Tam_Produtos,escolha_codigo_produto);
                        printf("\n\nDeseja finalizar?(-1 para finalizar): ");
                        scanf("%d",&estrato);
                        limpa_buffer();
                        system("clear||cls");
                    }
                    estrato = 0;
                   
                    int ind = procurar_cliente(clientela,Tam_clientes,escolha_codigo_cliente);
                    mostrar_estrato(clientela,ind,soma,compras_str,i);
                    scanf("%*c");
                    
                    
                }
                else{
                    system("clear||cls");
                    printf("\n\nCliente nao cadastrado");
                    scanf("%*c");
                }

            break;
        
        default:
            free(compras_str);
            free(produtos);
            free(clientela);
            return 0;
            break;
        }
    }
}