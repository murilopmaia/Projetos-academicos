


#define pi 3.14
void limpar_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");

}

float area(int raio){
    return pi*raio*raio;

}

int main(){

    int raio;
    float resultado;

    printf("informe o raio ");
    scanf("%d",&raio);
    limpar_buffer();
    resultado = area(raio);
    printf("A area eh : %.2f",resultado);
    return 0;
}
