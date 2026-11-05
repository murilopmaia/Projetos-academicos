int main(void){

    int num[10];
    int contador = 0;
    int indice = 0;

    for(;indice < 10;){
        contador++;
        printf("informe o %d numero ",contador);
        scanf("%d%*c",&num[indice]);
        indice++;
    }
    printf("\n");

    for(;indice > 0;indice-- ){
        printf("%d ",num[indice-1]);
    }
    return 0;

}
