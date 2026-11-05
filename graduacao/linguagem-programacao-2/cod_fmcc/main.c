int contador(int numero,int busca){

    if(numero == 0){
        return 0;
    }
    else{
        int cont;

''        if(numero%10 == busca){
            cont ++;
        }

        return cont;
    }
}

int main(){
    printf("%d",contador(2020,2));
    return 0;
}
