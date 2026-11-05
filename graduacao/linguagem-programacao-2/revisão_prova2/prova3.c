#include <stdlib.h>
#include <stdio.h>

struct lista{
    int info;
    struct list *prox;
};

typedef struct lista lista;

lista *ensere_fim(lista* inicio,int valor){
    if(inicio == NULL){
        lista* novo;
        novo = (lista*)malloc(sizeof(lista));
        novo->info = valor;
        novo->prox = NULL;
        return novo;
    }
    else{
        lista*p;
        for(p=inicio;p->prox!=NULL;p=p->prox);
        lista* novo;
        novo = (lista*)malloc(sizeof(lista));
        novo->prox = NULL;
        novo->info = valor;
        p->prox = novo;
        return inicio;
    }
}

void printar(lista* inicio){
    for(lista* p=inicio;p!=NULL;p=p->prox){
        printf(" %d ",p->info);
    }
}

int procura(int *vet,int tam,int valor_teste){
    for(int i = 0;i<tam;i++){
        if(vet[i] == valor_teste){
            return 1;
        }
    }
    return 0;
}
void remove_repetidos(lista *ini){
    int tam_atual=1;
    lista* p;
    lista* aux = ini;
    int *vetor_base;
    vetor_base = (int*)malloc(sizeof(int));
    vetor_base[0] = ini->info;
    
    for(p=ini->prox;p!=NULL;p=p->prox){
        if(procura(vetor_base,tam_atual,p->info) == 1){
            aux->prox = p->prox;
            free(p);
            p = aux;
        }
        else{
            tam_atual++;
            vetor_base = (int*)realloc(vetor_base,tam_atual*sizeof(int));
            vetor_base[tam_atual-1] = p->info;
        }
        aux = p;
    }
    free(vetor_base);
}

lista *exclui_qtde(lista*ini,int n){
    lista *p;
    int tamanho = 0;
    int contador = 0;
    for(p=ini;p!=NULL;p=p->prox){
        tamanho++;
    }
    if(n>=tamanho){
        return NULL;
    }
    else{
        for(p=ini;contador<n;){
            ini = ini->prox;
            free(p);
            p = ini;
            contador++;
        }
    }
    return ini;
}

lista *construir_lista(int *Vet,int tam){
    lista *inicio;
    inicio = NULL;
    for(int i = 0;i<tam;i++){
        inicio = ensere_fim(inicio,Vet[i]);
    }
    return inicio;
}

int maiores(lista *ini,int n){
    int contador=0;
    for(lista*p=ini;p!=NULL;p=p->prox){
        if(p->info > n){
            contador++;
        }
    }
    return contador;
}

int main(){
    lista *inicio;
    inicio = NULL;
    inicio = ensere_fim(inicio,1);
    inicio = ensere_fim(inicio,1);
    inicio = ensere_fim(inicio,1);
    inicio = ensere_fim(inicio,2);
    inicio = ensere_fim(inicio,2);
    inicio = ensere_fim(inicio,2);
    inicio = ensere_fim(inicio,2);
    inicio = ensere_fim(inicio,3);
    inicio = ensere_fim(inicio,3);
    inicio = ensere_fim(inicio,3);
    inicio = ensere_fim(inicio,3);
    inicio = ensere_fim(inicio,1);
    inicio = ensere_fim(inicio,4);
    inicio = ensere_fim(inicio,2);
    inicio = ensere_fim(inicio,2);
    inicio = ensere_fim(inicio,2);
    printar(inicio);
    remove_repetidos(inicio);
    printf("\n\n");
    printar(inicio);
    printf("\n\n");
    int Vetor[5] = {11,22,33,44,55};
    lista *inicio_vetor;
    inicio_vetor = construir_lista(Vetor,5);
    printar(inicio_vetor);
    printf("\n\n");
    inicio = exclui_qtde(inicio,2);
    printar(inicio);
    printf("\n\n");
    printf(" %d ",maiores(inicio,2));
    return 0;
}