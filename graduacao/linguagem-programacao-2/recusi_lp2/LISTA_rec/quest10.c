int tetranacci(int n){
    if(n == 1 || n == 2 || n == 3){
        return 0;
    }
    else if(n == 4){
        
        return 1;
    }
    else{
        int resultado;
        resultado = tetranacci(n-1) + tetranacci(n-2) + tetranacci(n-3) + tetranacci(n-4);
        
        return resultado;
    }
}

int main(){
    printf("%d",tetranacci(10));
    return 0;
}