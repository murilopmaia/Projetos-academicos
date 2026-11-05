#include <stdio.h>
#include <string.h>
#define TAM 1000
#define TAM_LETRAS 50

void limpa_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
}

void menu(){
    
    printf("\n1. Incluir novo produto");
    printf("\n2. Mostrar relatorio de estoque");
    printf("\n3. Incluir itens em estoque");
    printf("\n4. Excluir item em estoque");
    printf("\n5. Sair ");
    
    
}

int verificar_string(char nome[TAM_LETRAS],char produto[TAM][TAM_LETRAS],int qtd){
    int existe;
    for(int i =0;i<qtd;i++){
        if(strcmp(produto[i],nome) == 0){
            existe = 0;
            return existe;
        }
    }
    existe = 1;
    return existe;
}

int new_produto(char produto[TAM][TAM_LETRAS],int *estoque,int qtd){
    system("clear||cls");

    int sair = 0;
    char nome[TAM_LETRAS];
    int existe;
    int escolha;

    for(int i = qtd;sair != 1; i++){
        if(qtd == TAM){
            printf("\nLimite de estoque alcancado");
            scanf("%*c");
            system("clear||cls");
            return qtd;
        }
        printf("\nInforme o nome do novo produto:  ");
        scanf("%[^\n]s",&nome);
        limpa_buffer();
        existe = verificar_string(nome,produto,qtd);
        if(existe == 0){
            system("clear||cls");
            do{
            printf("\n\n\tProduto ja cadastrado");
            printf("\nDigite 1. Para sair");
            printf("\nDigite 2. Para cadastrar outro produto  ");
            scanf("%d",&escolha);
            limpa_buffer();
            if(escolha!= 1 && escolha != 2){
                system("clear||cls");
                printf("\n\n\tInforme um valor valido ");
            }
            }
            while(escolha!= 1 && escolha!=2);
            if(escolha == 1){
                system("clear||cls");
                return qtd;
            }
            else
                if(escolha == 2){
                    system("clear||cls");
                    i--;
                    continue;
                }
        }
        else{
            strcpy(produto[i],nome);
            estoque[i] = 0;
            system("clear||cls");
            printf("\nProduto cadastrado!!");
            printf("\n\nPara sair Digite: 1 ");
            printf("\nPara continuar confirme qualquer tecla difeente de [1] ");
            scanf("%d",&sair);
            limpa_buffer();
            system("clear||cls");
            qtd++;
            
        }
    }
    return qtd;
}

void consulta_estoque(char produtos[TAM][TAM_LETRAS], int *estoque , int qtd){
    system("clear||cls");
    if(qtd == 0){
        printf("\nNenhum produto cadastrado ");
        scanf("%*c");
        system("clear||cls");
        return 0;
        
    }
    for(int i = 0; i < qtd;i++){
        if(!estoque[i]){
            estoque[i] = 0;
        }
        printf("\n\n Produto: %s // Quantidade: %d",produtos[i],estoque[i]);
    }
    scanf("%*c");
    system("clear||cls");
}

void inclui_estoque(char produtos[TAM][TAM_LETRAS], int *estoque, int qtd){
    system("clear||cls");
    int i;
    int escolha;
    int somar;

    if(qtd == 0){
        printf("\nNenhum produto cadastrado ");
        scanf("%*c");
        system("clear||cls");
        return 0;
        
    }
    do{
    printf("\ninforme qual desse itens queres adicionar estoque: \n");
    for( i = 0 ; i < qtd;i++){
        printf("\n%d. %s  ",i+1,produtos[i]);
    }
    scanf("%d",&escolha);
    limpa_buffer();
    if(escolha<0 || escolha > qtd){
        system("clear||cls");
        printf("\tUse valores validos\n\n");
    }
    }
    while(escolha<0 || escolha > qtd);

    system("clear||cls");
    do{
    printf("\n\n\nProduto : %s // Quantidade Atual: %d",produtos[escolha-1],estoque[escolha-1]);
    printf("\n\nInforme a quantidade que sejas incluir no estoque: +");
    scanf("%d",&somar);
    limpa_buffer();
    if(somar<0){
        system("clear||cls");
        printf("\n\tDigite um numero inteiro positivo\n");
    }
    }
    while(somar<0);
    estoque[escolha-1] = estoque[escolha-1] + somar;
    printf("\n\nNovo estoque: %d",estoque[escolha-1]);
    scanf("%*c");
    system("clear||cls");
}

void excluir_estoque(char produtos[TAM][TAM_LETRAS], int *estoque, int *qtd){
    system("clear||cls");
    int i;
    int escolha;
    int diminuir;
    int escolha2;

    if(*qtd == 0){
        printf("\nNenhum produto cadastrado ");
        scanf("%*c");
        system("clear||cls");
        return 0;
        
    }
    do{
    printf("\ninforme qual desse itens queres excluir estoque: \n");
    for( i = 0 ; i < *qtd;i++){
        printf("\n%d. %s  ",i+1,produtos[i]);
    }
    scanf("%d",&escolha);
    limpa_buffer();
    if(escolha<0 || escolha > *qtd){
        system("clear||cls");
        printf("\tUse valores validos\n\n");
    }
    }
    while(escolha<0 || escolha > *qtd);

    system("clear||cls");
    do{
    printf("\n\n\nProduto : %s // Quantidade Atual: %d",produtos[escolha-1],estoque[escolha-1]);
    printf("\n\nInforme a quantidade que sejas excluir no estoque: -");
    scanf("%d",&diminuir);
    limpa_buffer();
    if(diminuir<0){
        system("clear||cls");
        printf("\n\tDigite um numero inteiro positivo\n");
    }
    }
    while(diminuir<0);
    if((estoque[escolha-1] - diminuir) <= 0){
        do{
        
        printf("\n\n\tA quanidade ficara negativa, o produto sera excluido, tem certeza disso? ");
        printf("\n1. Sim");
        printf("\n2. Nao ");
        scanf("%d",&escolha2);
        limpa_buffer();
        if(escolha2!=1 && escolha2!= 2){
            printf("\n\nPreencha com valores validos\n");
        }
        
        }
        while(escolha2!=1 && escolha2!= 2);
        if(escolha2 == 1){
            for(int x = (escolha-1);x<*qtd;x++){
                strcpy(produtos[x],produtos[x+1]);
                estoque[x] = estoque[x+1];
            }
            *qtd = *qtd - 1;
            system("clear||cls");
        }
        else
            if(escolha2 == 2){
               system("clear||cls");
               
            }
    }
    else{
        estoque[escolha-1] = estoque[escolha-1] - diminuir;
        printf("\n\nNovo estoque: %d",estoque[escolha-1]);
        scanf("%*c");
        system("clear||cls");
    }
}




int main(){
    int escolha;
    char produtos[TAM][TAM_LETRAS];
    int estoque[TAM];
    int quantidade = 0;
    do{
    do{
    menu();
    scanf("%d",&escolha);
    limpa_buffer();
    if(escolha<0 || escolha > 5){
        system("clear||cls");
        printf("\n\tInforme um valor valido\n");
    }
    }
    while(escolha<0 || escolha > 5);

    switch(escolha){
        case 1: quantidade = new_produto( produtos,estoque,quantidade);break;
        case 2 : consulta_estoque(produtos,estoque , quantidade);break;
        case 3: inclui_estoque(produtos, estoque, quantidade );break;
        case 4: excluir_estoque(produtos,estoque,&quantidade);break;

    }
    }
    while(escolha != 5);
    return 0;
}