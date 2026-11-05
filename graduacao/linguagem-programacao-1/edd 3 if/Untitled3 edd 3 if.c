int main (void) {

    int numero;
    int resultado;

    printf("informe um numero\n");
    scanf("%d", &numero);

    resultado = (numero % 2);

    if (resultado == 0) {

        printf("\n%d eh um numero par\n",numero);
    }

    else {

        printf("\n%d eh um numero impar\n", numero);
    }

    return 0;

}

