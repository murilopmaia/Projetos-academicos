int palindromo(char *nome,int tamini,int tamfim){
    if(nome[tamini] != nome[tamfim]){
        return 0;
    }
    else if(tamfim == tamini || tamini > tamfim){
        return 1;
    }
    palindromo(nome,tamini + 1,tamfim-1);
}

int main(){
    char str[39]={"socorram me subi no on ibus em marrocos"};
    if( palindromo(str,0,38) == 1){
        printf("e um palimedro");
    }
    else{
        printf("nao e palimedro");
    }
    return 0;
}