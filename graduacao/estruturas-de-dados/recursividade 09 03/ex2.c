#include <stdio.h>
#include <stdlib.h>

int sucessor(int n){
    return n+1;
}
int predecessor(int n){
    return n-1;
}

int soma(int a,int b){
    if(b==0){
        return a;
    }
    return soma(sucessor(a),predecessor(b));
}

int main(){
    printf("%d",soma(3,10));
    return 0;
}