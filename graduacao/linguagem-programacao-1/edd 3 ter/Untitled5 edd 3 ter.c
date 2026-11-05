int main (void) {

    int numero;
    int resultado;
    int config;

    printf("informe um numero\n");
    scanf("%d", &numero);

    resultado = (numero % 2);

    config = (resultado == 0)? printf("%d eh um numero par",numero): printf("%d eh um impar par",numero);

    return 0;

}


