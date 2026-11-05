#include <stdio.h>

int A(int m, int n, int p){
    if(p == 0)
        return m + n;
    else if(n == 0 && p == 1)
        return 0;
    else if(n == 0 && p == 2)
        return 1;
    else if(n == 0 && p > 2)
        return m;
    else if(n > 0 && p > 0)
        return A(m, A(m, n-1, p), p-1);
    
    return 0;
}

int main(){
    printf("%d", A(7, 6, 2));
    return 0;
}