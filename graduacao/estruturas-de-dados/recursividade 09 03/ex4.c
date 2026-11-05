#include <stdio.h>
#include <stdlib.h>

int somaN(int n){
    if(n == 0){
        return 0;
    }
    return n + somaN(n-1);
}

int main(){
    printf("%d",somaN(6));
    return 0;
}