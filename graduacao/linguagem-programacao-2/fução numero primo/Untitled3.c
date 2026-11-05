

void limpar_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");

}

int primo(int numero){
    int contador = 0;
    for(int x = 1;x<=numero;x++){
        if(numero%x == 0){
            contador++;
        }
        if(numero == 3){
            break;
        }
    }
    if(numero == 3){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){

    int numero;
    printf("informe o numero ");
    scanf("%d",&numero);
    limpar_buffer();

    printf("resultado: %d",primo(numero));



    return 0;
}

