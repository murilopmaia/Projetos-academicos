//Declaração de bibliotecas
#include <stdio.h>
#include <stdlib.h>
//criação de struct
struct tno{
    int info;
    struct tno *prox;
};
typedef struct tno No; // No = struct tno

//criação função para inserir no inicio
No* insere_ini(No*ini,int valor){
    No *novo;//criação de ponteiro
    novo = (No*)malloc(sizeof(No));//alocando espaço para o ponteiro
    novo->info = valor;//o conteuro de info = valor 
    novo->prox = ini; //prox passa a apontar pro inicio da lista
    return novo;//retorna nó criado e esse nó entra no inicio da lista
}

//criação de função para printar
void printa_de_cria(No *ini){
for(No *p=ini;p!=NULL;p=p->prox){//for para percorrer a lista
        printf(" %d ",p->info);//printando elementos da lista
    }
}

//criando função para inserir no fim da lista
No* insere_fim(No*ini,int valor){
    if(ini == NULL){//caso a lista esteja vazia:
        No *new;//criando ponteiro
        new = (No*)malloc(sizeof(No)); //alocando espaço pro ponteiro
        new->prox = NULL;//prox passa a apontar pra null
        new->info = valor;//conteudo de info = valor
        return new;
    }
    else{//caso a lista não seja vazia
        No* p;//criação de ponteiro
        for(p = ini;p->prox!=NULL;p = p->prox){//percorrendo lista e fazendo ponteiro P apontar pro ultimo 

        }
        No *new;//criando ponteiro do tipo nó
        new = (No*)malloc(sizeof(No));//alocando espaço pro nó
        p->prox = new;//prox passa a apontar para o novo nó
        new->prox = NULL; //prox aponta pra null
        new->info = valor; //o conteudo do novo nó é o valor
        return ini;
    }


}
//criando função de multiplicação
void multiplica(No*ini,int multi){
    No* p;//criando ponteiro
    for(p = ini;p!=NULL;p = p->prox){//percorrendo lista
        p->info = p->info * multi;//multiplicando as info dos nós pelo multi
    }
}

//criando função para inserir no meio da lista
No* insere_meio(No* ini,int valor){
    if(ini == NULL){//se a lista estiver vazia
        No *new;//criação de ponteiro nó
        new = (No*)malloc(sizeof(No));//alocando espaço pro nó
        new->prox = NULL;//prox aponta pra null
        new->info = valor;//conteudo do nó é valor
        return new;
    }
    else{
        No* p;//criação de ponteiro
        int cont;//criação de contador
        for(p=ini;p!=NULL;p=p->prox){//percorrendo lista
            cont++;//atualizando contador
        }
        cont = cont/2;//definindo posição do meio da lista
        int indice=1;//criando indice
        No* n;//criando ponteiro
        for(n = ini;indice<cont;n=n->prox){//percorrendo a lista até o meio
            indice++;//atualizando indice
        }
        No* novo;//criação de nó
        novo = (No*)malloc(sizeof(No));//alocando espaço pra o nó
        novo->prox = n->prox;//proximo do novo nó aponta pro proximo elemento da lista (cont/2 +1)
        novo->info = valor;//conteudo do nó = valor
        n->prox = novo;//antigo nó do meio aponta pro novo nó
        return ini;
    }
}

//criando função para concatenar as listas
void concatena(No* ini_1,No* ini_2){
    No *p;//criando ponteiro
    for(p = ini_1;p->prox!=NULL;p=p->prox){//percorrendo a lista

    }
    p->prox = ini_2;//fazendo o prox da lista 1 apontar pro inicio da lista 2
    ini_2 = NULL;//lista dois aponta pro null
}

//programa principal
int main(void){
    system("clear||cls");//limpa tela
    No *ini1;//criando lista 1
    No *ini2;//criando lista 2
    ini1 = NULL;//lista 1 aponta pra null
    ini2 = NULL;//lista 2 aponta pra null
   
   //inserindo conteudos em nó(s)
    ini1 = insere_ini(ini1,5);
    ini1 = insere_ini(ini1,7);
    ini1 = insere_ini(ini1,8);
    ini2 = insere_ini(ini2,10);
    //printando listas
    printa_de_cria(ini1);
    printf("\n\n");
    printa_de_cria(ini2);
    //inserindo no final da lista
    ini1 = insere_fim(ini1,24);
    printf("\n\n");
    //printando lista 1
    printa_de_cria(ini1);
    //multiplicando elementos da lista
    multiplica(ini1,2);
    printf("\n\n");
    //pritnando lista
    printa_de_cria(ini1);
    printf("\n\n");
    //inserindo no final da lista 
    ini2 = insere_fim(ini2,255);
    //inserindo no meio da lista
    ini1 = insere_meio(ini1,99);
    //printa lista
    printa_de_cria(ini1);
    //concatenando listas
    concatena(ini1,ini2);
    printf("\n\n");
    //printando lista 1 após concatenação
    printa_de_cria(ini1);

    return 0;
}
