int main (void){

    int numero;

    for(numero = 0;numero >= 0;numero = numero + 1){

        if (numero == 30) break;
        printf("\n\t %d\n",numero);


    }

    for(;numero >= 0; numero = numero - 1){

        printf("\n\t %d\n",numero);

    }

    return 0;

}
