int main (void) {

    int numero;
    int resultado;

    printf("informe um numero\n");
    scanf("%d", &numero);

    resultado = (numero % 2);

    switch (resultado) {

        case 0: printf("%d eh um numero par",numero);break;
        default : printf("%d eh um numero impar",numero);

    }

    return 0;

}
