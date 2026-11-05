#include <stdio.h>
#include <stdlib.h>

struct lista{
    int valor;
    struct lista *prox;
};

typedef struct lista no;

no* insere_inicio(no* inicio,int numero){
    no* novo;
    novo = (no*)malloc(sizeof(no));
    novo->valor = numero;
    novo->prox = inicio;
    return novo;
}

no* insere_fim(no* inicio,int numero){
    if(inicio == NULL){
        no* novo;
        novo = (no*)malloc(sizeof(no));
        novo->prox = NULL;
        novo->valor = numero;
        return novo;
    }
    else{
        no *p;
        for(p=inicio;p->prox!=NULL;p=p->prox);
        no* novo;
        novo = (no*)malloc(sizeof(no));
        novo->valor = numero;
        novo->prox = NULL;
        p->prox = novo;
        return inicio;
    }
}

void printar(no *inicio){
    for(no *p=inicio;p!=NULL;p=p->prox){
        printf(" %d ",p->valor);
    }
}

void multiplicar(no* inicio,int multi){
    no* p;
    for(p=inicio;p!=NULL;p=p->prox){
        p->valor = p->valor*multi;
    }
}

no* insere_meio(no* inicio,int valor){
    int cont=0;
    no* p;
    int indice=1;
    for(p=inicio;p!=NULL;p=p->prox){
        cont++;
    }
    cont = cont/2;
    for(p=inicio;indice<cont;p=p->prox){
        indice++;
    }
    no* novo;
    novo = (no*)malloc(sizeof(no));
    novo->valor = valor;
    novo->prox = p->prox;
    p->prox = novo;
    return inicio;
}

no* cocatenar(no*incio1,no*incio2){
    if(incio1 == NULL){
        return incio2;
    }
    if(incio2 == NULL){
        return incio1;
    }
    no*p;
    for(p=incio1;p->prox!=NULL;p=p->prox);
    p->prox = incio2;
    return incio1;
}

int main(){
    no* inicio;
    no* inicio2;
    inicio = NULL;
    inicio2 = NULL;
    inicio = insere_fim(inicio,20);
    inicio = insere_fim(inicio,22);
    inicio = insere_fim(inicio,24);
    inicio = insere_fim(inicio,26);
    inicio = insere_inicio(inicio,99);
    printar(inicio);
    multiplicar(inicio,3);
    printf("\n\n");
    printar(inicio);
    inicio = insere_meio(inicio,666);
    printf("\n\n");
    printar(inicio);
    inicio2 = insere_fim(inicio2,220);
    inicio2= insere_fim(inicio2,222);
    inicio2 = insere_fim(inicio2,224);
    inicio2 = insere_fim(inicio2,226);
    inicio2 = insere_inicio(inicio2,299);
    printf("\n\n");
    printar(inicio2);

    inicio=cocatenar(inicio,inicio2);
    printf("\n\n");
    printar(inicio);
    return 0;
}