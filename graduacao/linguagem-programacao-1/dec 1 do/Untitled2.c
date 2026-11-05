int main (void) {

    int numero = 0;

    do {
        printf("\n\t %d\n",numero);
        numero = numero + 1;
        if (numero == 2147483647) break;

    }

    while(numero >=0);

    do {

        printf("\n\t %d\n",numero);
        numero = numero - 1;

    }

    while(numero >=0);

    return 0;
}

