#include <stdlib.h>
#include <stdio.h>

struct Lista{
    int valor;
    struct Lista *prox;
};

typedef struct Lista no;

int Fibonacci(int Tam){
    
    if(Tam == 1 || Tam == 2){
        
        return 1;
    }
    else{
        int resultado;
        
        resultado = Fibonacci(Tam-1) +  Fibonacci(Tam-2);
        
        return resultado;
    }
}

int Fibonacci_printar(int Tam){
    
    if(Tam == 1 || Tam == 2){
        printf(" 1  1 ");
        return 1;
    }
    else{
        int resultado;
        
        resultado = Fibonacci_printar(Tam-1) +  Fibonacci(Tam-2);
        printf(" %d ",resultado);
        return resultado;
    }
}

void achar_n(no* ini,int n){
    if(ini ==  NULL){
        printf("não encontrado");
    }
    else{
        if(ini->valor == n){
            printf("encontrado");
        }
        else{
            achar_n(ini->prox,n);
        }
    }
}

no* insere_fim(no* ini,int numero){
    no* novo;
    novo = (no*)malloc(sizeof(no));
    novo->prox = NULL;
    novo->valor = numero;
    if(ini == NULL){
        
        return novo;
    }
    else{
        no*p;
        for(p=ini;p->prox != NULL ; p=p->prox){};
        p->prox = novo;
        return ini;
    }
}

void printar_lista(no* ini){
    for(no*p=ini;p!=NULL;p=p->prox){
        printf(" %d ",p->valor);
    }
}


void inverter(int *vetor,int tam,int atual){
    if(tam>atual){
        int aux;
        aux = vetor[atual];
        vetor[atual] = vetor[tam];
        vetor[tam] = aux;
        inverter(vetor,tam-1,atual+1);
    }
}

void inverter_principal(int *vetor,int tam){
    inverter(vetor,tam-1,0);
}

void printar_vetor(int *vetor,int tam){
    for(int i = 0;i<tam;i++){
        printf(" %d ",vetor[i]);
    }
}

void printar_pares(int *vetor,int tam){
    
    if(tam>= 0){
        if(vetor[tam]%2 == 0){
            printf(" %d ",vetor[tam]);
        }
        printar_pares(vetor,tam-1);
    }
}

void printar_pares_ate_n(int n){
    if(n == 0){
        printf(" %d ",n);
    }
    else{
        printar_pares_ate_n(n-1);
        if(n%2 == 0){
            printf(" %d ",n);
        }
    }
}

void multiplicar_vetor_porx(int *vetor,int tam,int x){
    if(tam >= 0){
        vetor[tam] = vetor[tam] * x;
        
        multiplicar_vetor_porx(vetor,tam-1,x);
        printf(" %d ",vetor[tam]);
    }
}

int printar_somatoria(int i,int n){
    if(n == i){
        printf(" %d ",(i*i));
        return i*i;


    }
    else{
        
        printf(" %d +",(i*i));
        int valor = (i*i) + printar_somatoria(i+1,n);
        return valor;
    }
}

int outro_tipo_printar_somatoria(int i,int n){
    if(n == i){
        printf(" %d ",(n*n));
        return (n*n);
    }
    else{
        int valor = (n*n) + outro_tipo_printar_somatoria(i,n-1);
        printf(" %d +",(n*n));
        return valor;
    }
}

int main(){
    Fibonacci_printar(6);
    printf("\n\n");
    no* ini=NULL;
    ini = insere_fim(ini,1);
    ini = insere_fim(ini,2);
    ini = insere_fim(ini,3);
    ini = insere_fim(ini,4);
    printar_lista(ini);
    printf("\n\n");
    achar_n(ini,1);
    printf("\n\n");
    printar_lista(ini);
    int vetor[] = {1,2,3,4,5,6};
    printf("\n\n");
    printar_vetor(vetor,6);
    inverter_principal(vetor,6);
    printf("\n\n");
    printar_vetor(vetor,6);
    printf("\n\n");
    printar_pares(vetor,5);
    printf("\n\n");
    printar_pares_ate_n(10);
    printf("\n\n");
    
    multiplicar_vetor_porx(vetor,5,2);
    printf("\n\n");
    printf(" = %d",printar_somatoria(1,4) );
    printf("\n\n");
    printf("= %d",outro_tipo_printar_somatoria(1,4));
    
    return 0;
}