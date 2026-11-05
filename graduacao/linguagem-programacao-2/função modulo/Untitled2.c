
void limpar_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");

}

int abs(int modulo){
    if(modulo < 0){
        return modulo*(-1);
    }
    return modulo;
}

int main(){
    int numero;
    printf("informe o valor para recebelo em modulo ");
    scanf("%d",&numero);
    printf("\n\no modulo de %d eh %d ",numero,abs(numero));
   return 0;
}
