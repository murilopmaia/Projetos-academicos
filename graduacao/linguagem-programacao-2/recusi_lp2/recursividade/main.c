int soma_vetor (int *vetor,int tam){
    if(tam == 1){
        return vetor[0];
    }
    else{
        int soma;
        soma = vetor[tam-1] + soma_vetor(vetor,tam-1);
        return soma;
    }
}

int Fibonacci(int enesimo){
    if(enesimo == 1|| enesimo == 2){
        return 1;
    }
    else{
        int resultado;
        resultado = Fibonacci(enesimo-1) + Fibonacci(enesimo-2);
        return resultado;
    }
}

int Fibonacci_tudo(int enesimo){
    if(enesimo == 1|| enesimo == 2){
        printf(" 1  1 ");
        return 1;
    }
    else{
        int resultado;
        resultado = Fibonacci_tudo(enesimo-1) + Fibonacci(enesimo-2);
        printf(" %d ",resultado);
        return resultado;
    }
    
}



void pares(int numero){
    if(numero != 0){
        pares(numero-1);
    }
    if(numero%2==0){
        printf(" %d ",numero);
    } 
}

int formula_somatorio(int n){
    
    if(n==0){
        return 0;
    }
    else{
        int i = n;
        int somatorio;
        somatorio = (i*i) + formula_somatorio(n-1);
        return somatorio;
    }
}

int main(){
    int vet[] = {1,2,3,4,5};
    printf("soma : %d",soma_vetor(vet,5));

    printf("\nO termo da posicao escolhida no Fibonacci eh: %d \n",Fibonacci(6));

    Fibonacci_tudo(6);
    printf("\n");

    
    pares(6);

    printf("\n %d ",formula_somatorio(3));
    return 0;

}