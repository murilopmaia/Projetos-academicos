#include <stdlib.h>
#include <stdio.h>
float somatorio(int n){
    if(n == 1){
        printf(" 1 ");
        return 1.0;
    }
    else{
        float calc = somatorio(n-1);
        printf(" + 1/%d",n);
        return ((1.0/n) + calc);
    }
}

int main(){
    printf(" = %.2f",somatorio(3));
    return 0;
}