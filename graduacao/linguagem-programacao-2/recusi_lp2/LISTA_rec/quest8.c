float somatorio(int n){
    if(n==1){
        printf(" 2/4");
        return (2.0/4.0);
    }   
    else{
        float calc = somatorio(n-1);
        printf(" + %d/%d ",((n*n)+1),(n+3)); 
        return (n*n + 1.0)/(n + 3.0) + calc;
    }
}

int main(){
    printf(" = %.2f",somatorio(4));
    return 0;
}