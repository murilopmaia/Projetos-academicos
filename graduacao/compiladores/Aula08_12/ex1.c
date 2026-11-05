/*
    Escreva um programa em C que recebe um número
    natural n e calcule o somatório de 1 ate n
    e imprima na tela
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int result = 0;

    printf("informe n: ");
    scanf("%d", &n);

    for(int i=1; i <= n; i++){
        result += i;
    }
    printf("\nResultado: %d", result);
    return 0;
}