#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int numero;
} str;

void teste(int *n){
    *n = 5;
}

int main(){
    str *no;
    no = (str*)malloc(sizeof(str));
    
    (*(no + 0)).numero = 10;
    printf("%d", no->numero);
    return 0;
}