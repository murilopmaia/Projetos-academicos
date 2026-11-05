int soma_digitos(int n){
    if(n/10 == 0){
        printf("%d",n%10);
        return n%10;
    }
    else{
        int calc;
        calc = soma_digitos(n/10);
        printf(" + %d",n%10);
        return n%10 + calc;
    }
}

int main(){
    printf(" = %d",soma_digitos(1235));
    return 0;
}