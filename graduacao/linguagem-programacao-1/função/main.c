int soma(int a, int b){
    int z;
    z = a + b;
    return z;
}

void texto(){
    printf("oi eu\n\n");
}

int main(){
    int x = 5,y = 10;
    int resposta;

    resposta = soma(x,y);
    texto();
    printf("%d",resposta);
    return 0;
}