#include <stdio.h>
#include <stdlib.h>

int fibonacciRec(int n){
    if(n == 1){
        return 0;
    }
    else if(n == 2){
        return 1;
    }

    return fibonacciRec(n-1)+fibonacciRec(n-2);
}

int fibonacci(int n){
    int result1=0;
    int result2=1;
    int result3;

    for(int x = 3;x <= n;x++ ){
        result3 = result1 + result2;
        result1 = result2;
        result2 = result3;
        
    }

   if(n == 1){
        return 0;
    }
    else if(n == 2){
        return 1;
    }else{
        return result3;
    }
}

int main(){
    printf("%d",fibonacciRec(7));
    printf("\n%d",fibonacci(7));
    return 0;
}