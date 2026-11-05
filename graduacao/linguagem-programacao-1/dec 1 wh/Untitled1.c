int main (void) {

    int numero = 0;

    while(numero >= 0){

        printf("\n\t %d\n",numero);
        numero = numero + 1;
        if (numero == 2147483647) break;
    }

    while(numero>=0) {

        printf("\n\t %d\n",numero);
        numero = numero - 1;

    }



    return 0;
}
