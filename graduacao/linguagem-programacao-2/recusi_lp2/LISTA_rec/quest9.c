int super_fatorial(int n){
    if(n == 1 || n == 0){
        printf("1! ");
        return 1;
    }
    else{
        printf("%d! * ",n);
        int resultado = 1;
        for(int i = 2;i<=n;i++){
            resultado = resultado*i;
        }
        return resultado*super_fatorial(n-1);
    }
}

int main(){
    printf(" = %d",super_fatorial(4));
    return 0;
}