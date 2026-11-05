#include <stdio.h>
#include  <stdlib.h>

struct No{
    int numero;
   struct No*prox;
};

typedef struct No No;

No *insere_inicio(No *inicio,int valor){
    No *novo;
    novo = (No*)malloc(sizeof(No));
    novo->numero = valor;
    novo->prox = inicio;
    return novo;

}

int maior(No *inicio){
    int maior_elemento;
    maior_elemento = inicio->numero;
    
    for(No*p=inicio;p!=NULL;p=p->prox){
        if(p->numero > maior_elemento){
            maior_elemento = p->numero;
        }
    }
    return maior_elemento;
}

int quantidade(No *inicio){
    int contador=0;
    for(No*p=inicio;p!=NULL;p=p->prox){
        contador++;
    }
    return contador;
}

void excluir_enesimo(No **inicio,int n){
    int j=1;
    No* aux;
    
    
    if(n==1){
        No*p = *inicio;
        *inicio=p->prox;
        free(p);
    }
    else{
    for(No*p=*inicio;p!=NULL;p=p->prox){

        if(j == n-1){
            
            aux = p->prox;
            p->prox = p->prox->prox;
            free(aux);
        }
        j++;
       
    }
    }
    
}



void printar(No* inicio){
    printf("\n");
    for(No*p=inicio;p!=NULL;p=p->prox){
        printf(" %d ",p->numero);
    }
}

void excluir_valor(No **inicio,int n){
    No*aux;
    No*p=*inicio;
    if(p->numero == n){
        
        *inicio = p->prox;
        free(p);
    }
    else{
        for(No *p= *inicio;p!=NULL;p=p->prox){
            if(p->numero == n){
                aux->prox = p->prox;
                free(p);
                break;
            }
            aux = p;
        }
    }
    
}

No* excluir_valor_todos(No *inicio,int n){
    No*aux;
    
        for(No *p= inicio;p!=NULL;){
            if(inicio->numero == n){
                
                inicio = inicio->prox;
                free(p);
                p = inicio;
                aux = p;
            }
            else{
                if(p->numero == n){
                    aux->prox = p->prox;
                    free(p);
                    p=aux;
                
                }
            
                aux = p;
                if(p->numero != n){
                    p=p->prox;
                }
            }
            
        
    }
    return inicio;
    
}

No* inverte(No* inicio){
    No* anterior;
    No* atual;
    No* proximo;


    anterior = NULL;
    atual = inicio;
    proximo = inicio->prox;
    
    for(;proximo!=NULL;){
        atual->prox = anterior;

        anterior = atual;
        atual = proximo;
        proximo = atual->prox;
        
    }
    atual->prox = anterior;

    return atual;

}

No* lista_par(No* inicio_lista){
    No* inicio_par;
    for(No *p = inicio_lista;p != NULL;p=p->prox){
        if(p->numero % 2 == 0){
            inicio_par = insere_inicio(inicio_par,p->numero);
        }
    }
    return inicio_par;
}


int main(){
    system("clear||cls");
    No *ini;
    int maiore;
    int qtd;
    No *ini_pares;

    ini = NULL;
    ini =  insere_inicio(ini,17);
    ini =  insere_inicio(ini,16);
    ini =  insere_inicio(ini,14);
    ini =  insere_inicio(ini,9);
    ini =  insere_inicio(ini,7);
    ini =  insere_inicio(ini,4);
    ini =  insere_inicio(ini,13);
    ini =  insere_inicio(ini,13);
    ini = insere_inicio(ini,13);
    ini =  insere_inicio(ini,5);
    ini =  insere_inicio(ini,-2);
    ini =  insere_inicio(ini,5);
    ini =  insere_inicio(ini,5);
    ini = insere_inicio(ini,13);
    
    
    maiore = maior(ini);

    printf("O maior valor eh : %d ",maiore);
    
    qtd = quantidade(ini);

    printf("\n\nA quantidade de elementos da lista eh : %d ",qtd);
    printar(ini);
    excluir_enesimo(&ini,3);
    printar(ini);

    excluir_valor(&ini,5);
    printar(ini);

    ini = excluir_valor_todos(ini,13);
    printar(ini);

    ini = inverte(ini);
    printar(ini);

    ini_pares = lista_par(ini);
    printar(ini_pares);
    return 0;

}