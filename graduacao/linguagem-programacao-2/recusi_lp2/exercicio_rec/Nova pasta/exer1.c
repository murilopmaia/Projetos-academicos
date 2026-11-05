 int cont_3_4(int numero){
    if(numero/10== 0){
        if(numero%10 == 3 || numero%10 == 4){
            return 1;
        }
        return 0;
    }
    else{
        if(numero%10 == 3 || numero%10 == 4){
            return (1 + cont_3_4(numero/10));
        }    
        return  cont_3_4(numero/10);        
    }
}

int main(){
    system("clear||cls");
    printf(" %d ",cont_3_4(1234341));
    return 0;
}