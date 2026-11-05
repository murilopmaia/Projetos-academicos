

int encontra_maior(int *vet,int tam){
    
    if(tam == 1){
        return vet[0];
    }
    else{ 
        int aux = encontra_maior(vet,tam-1);

        if(vet[tam-1]>aux){
            return vet[tam-1];
    }
     else{
        return aux;
    }}
    
}
void mostrar_pares( int numero){
    if(numero != 0){
        mostrar_pares(numero-1);
    }
     if(numero%2==0){
        printf(" %d ",numero);
    }
}

int calcula_formula(int numero){
    if(numero == 0){
        return 0;
    }
    else{
        int resultado;
        resultado = (numero*numero) + calcula_formula(numero-1);
        return resultado;
    }
}

int somatoria(int numero){
    if(numero == 1){
        return 1;
    }
    else{
        int resultado;
        resultado = numero + somatoria(numero-1);
        return resultado;
    }
}

int soma_multi(int numero,int multiplo){
    if(multiplo == 0 || numero == 0){
        return 0;
    }
    else{
        if(multiplo == 1){
            return numero;
        }
        else{
            int resultado;
            resultado = numero + soma_multi(numero,multiplo-1);
            return resultado;
        }
    }
}

void vetor_inverte(int *vetor,int tam){
    if(tam == 2){
        int aux;
        aux = vetor[0];
        vetor[0] = vetor[tam-1];
        vetor[tam-1] = aux;

    }
    else if(tam !=1){
        int aux;
        aux = vetor[0];
        vetor[0] = vetor[tam-1];
        vetor[tam-1] = aux;
        vetor_inverte(++vetor,tam-2);
    }   
}

int main(){
    system("clear||cls");
    int vetor[]={17,2,9,4,90,10};
    printf("%d\n",encontra_maior(vetor,6));
        
    mostrar_pares(8);

    printf("\n%d\n",calcula_formula(4));

    printf("\n%d\n",somatoria(4));

    printf("\n%d\n",soma_multi(0,5));
    

    vetor_inverte(vetor,6);

    for(int i = 0;i<6;i++){
        printf(" %d ",vetor[i]);
    }

    return 0;
}