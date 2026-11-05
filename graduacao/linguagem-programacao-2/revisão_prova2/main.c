#include <stdio.h>
#include <stdlib.h>

struct lista{
    int numero;
    struct lista *prox;
};
typedef struct lista NO;

NO* insere_inicio(NO* inicio,int valor){
    NO* new_no;
    new_no = (NO*)malloc(sizeof(NO));
    new_no->numero = valor;
    new_no->prox=inicio;
    return new_no;
}

NO* insere_fim(NO* inicio,int valor){
    if(inicio == NULL){
        NO* novo;
        novo = (NO*)malloc(sizeof(NO));
        novo->numero = valor;
        novo->prox = inicio;
        return novo;
    }
    else{
        NO*p;
        for(p=inicio;p->prox!=NULL;p=p->prox);
        NO* novo;
        novo = (NO*)malloc(sizeof(NO));
        p->prox = novo;
        novo->numero = valor;
        novo->prox = NULL;
        return inicio;
        
    }
}

void printar_lista(NO *inicio){
    for(NO*p=inicio;p!=NULL;p=p->prox){
        printf(" %d ",p->numero);
    }
}

int buscar_enesimo(NO*inicio,int enesimo){
    int cont=0;
    for(NO*p=inicio;p!=NULL;p=p->prox){
        if(cont == enesimo){
            return p->numero;
        }
        cont++;
    }
    return 0;
}

NO* excluir_enesimo(NO*inicio,int enesimo){
    int cont = 1;
    if(enesimo == 0){
        NO*p = inicio;
        inicio = inicio->prox;
        free(p);
        return inicio;
    }
    else{
        for(NO*p=inicio;p!=NULL;p=p->prox){
            if(cont == enesimo){
                NO*aux;
                aux = p->prox;
                p->prox=p->prox->prox;
                free(aux);
                return inicio;
            }
            cont++;
        }
    }
}

NO* excluir_valor(NO* inicio,int valor){
    if(inicio->numero == valor){
        NO*p = inicio;
        inicio = inicio->prox;
        free(p);
        return inicio;
    }
    else{
        NO*aux = inicio;
        for(NO*p = inicio;p!=NULL;p=p->prox){
            if(p->numero == valor){
                aux->prox = p->prox;
                free(p);
                return inicio;
            }
            aux = p;
        }
    }
}

NO* excluir_valor_todos(NO* inicio,int valor){
    NO*p,*aux2;
    for(p=inicio;p!=NULL;){
        if(inicio->numero == valor){
            
            inicio = inicio->prox;
            free(p);
            p = inicio;
        }
        else{
            if(p->numero == valor){
                aux2->prox = p->prox;
                free(p);
                p = aux2;
            }
            aux2 = p;
        
             p = p->prox;
            
        } 
        
    }
    return inicio;
    

}

int main(){

    NO *inicio;
    inicio = NULL;
    


    inicio = insere_inicio(inicio,25);
    inicio = insere_inicio(inicio,40);
    inicio = insere_inicio(inicio,40);
    inicio = insere_inicio(inicio,40);
    inicio = insere_inicio(inicio,40);
    inicio = insere_fim(inicio,40);
    
    inicio = insere_fim(inicio,47);
    inicio = insere_fim(inicio,99);
    inicio = insere_fim(inicio,30);
    inicio = insere_fim(inicio,24);
    inicio = insere_fim(inicio,59);
    inicio = insere_fim(inicio,40);
    inicio = insere_fim(inicio,40);
    inicio = insere_fim(inicio,40);
    inicio = insere_fim(inicio,40);
    inicio = insere_fim(inicio,40);

    

    printar_lista(inicio);
    printf("\n\n");
    printf(" %d ",(buscar_enesimo(inicio,2)+buscar_enesimo(inicio,3)));

    printf("\n\n");
    inicio = excluir_enesimo(inicio,2);
    printar_lista(inicio);

    printf("\n\n");
    inicio = excluir_valor(inicio,40);
    printar_lista(inicio);

    printf("\n\n");
    inicio = excluir_valor_todos(inicio,40);
    printar_lista(inicio);
    return 0;
}