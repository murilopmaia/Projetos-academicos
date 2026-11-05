#include <stdio.h>
#include <stdlib.h>

int *randArray(int n,int a,int b){
    int *vet = (int*) malloc(n*sizeof(int));
    for(int i = 0;i<n;i++){
        vet[i] = a + rand()%(b-a+1);
    }
    return vet;
}

void print_Array(int *vet,int tam){
    for(int i = 0;i<tam;i++){
        printf("%d ",vet[i]);
    }
}

int VetMax(int *vet,int n){
    if((n-1) == 0){
        return vet[0];
    }

    int valor = VetMax(vet,n-1);
    
    if(vet[(n-1)] <= valor){
        return valor;
    }

    return vet[(n-1)];
}

int VetSoma(int *vet,int n){
    if((n-1) == 0){
        return vet[0];
    }
    return vet[(n-1)] + VetSoma(vet,n-1);
}

int ValInVet(int valor,int *vet,int n){
    if(vet[(n-1)] == valor){
        return 1;
    }else if((n-1) == 0){
        return 0;
    }
    return ValInVet(valor,vet,n-1);

}

int posValInVet(int valor,int *vet,int n){
    if(vet[(n-1)] == valor){
        return n;
    }else if((n-1)==0){
        return n;
    }
    return posValInVet(valor,vet,n-1);

}

int main(){
    int *Array;
    Array = randArray(10,0,90);

    print_Array(Array,10);
    printf("\n\nmaior: %d",VetMax(Array,10));
    printf("\n\nsoma: %d",VetSoma(Array,10));

    if(ValInVet(55,Array,10) == 0){
        printf("\n\nValor nao encontrado");
    }else{
        printf("\n\nValor encontrado");
    }

    printf("\n\nResultado da procura: %d",posValInVet(55,Array,10));
    free(Array);
    return 0;
}