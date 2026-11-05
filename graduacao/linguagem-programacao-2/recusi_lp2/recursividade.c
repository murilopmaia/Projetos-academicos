#include <stdio.h>

int fatorial(int num){
    if(num==1 || num==0){
        return 1;
    }
    else{
        int resultado;
        resultado=num*fatorial(num-1);
        return resultado;
    }
}

int soma_vet(int vet[], int tam){
    if(tam==1){
        return vet[0];
    }
    else{
        int soma;
        soma=vet[tam-1]+soma_vet(vet,tam-1);
        return soma;
    }
}

int fibonacci(int enesimo){
    if(enesimo==1 || enesimo==2){
        return 1;
    }
    else{
        int resultado;
        resultado=fibonacci(enesimo-1)+fibonacci(enesimo-2);
        return resultado;
    }
    
}

int fibonacci_todos(int enesimo){
    if(enesimo==1 || enesimo==2){
        printf(" 1  1 ");
        return 1;
    }
    else{
        int resultado;
        resultado=fibonacci_todos(enesimo-1)+fibonacci(enesimo-2);
        printf(" %d ",resultado);
        return resultado;
    }
    
}

void numero_pares(int numero){
         
        if(numero == 0){
            printf(" 0 ");
            
        }
        else{
            if(numero%2 == 0){
               numero_pares(numero-1);
                printf(" %d ",numero);
            
            }
        }    
}

void achar_n(int vet[],int tam,int n){
    if(tam==0){
        printf("\nNao esta no vetor");
        
    }
    else if(vet[tam-1] == n){
            printf("\nBixinho ta no vetor");
        }
        else{
            achar_n(vet,tam-1,n);
        }
}

void main(){
    int result;
    int vet[]={1,2,3,4,5};
    result=fatorial(6);
    printf("\n%d", result);
    result=soma_vet(vet, 5);
    printf("\n%d", result);
    result=fibonacci(3);
    printf("\n%d\n", result);
    fibonacci_todos(5);
    printf("\n");
    numero_pares(6);
    achar_n(vet,0,7);
}