int main (void) {

     char minusculo;
     char maisculo;

     printf("digite uma letra minuscula \n");
     scanf("%c", &minusculo);

     if (minusculo >= 97 && minusculo <= 122) {

     maisculo = minusculo - 32;

     printf("\n%c", maisculo); }

    else {
        printf("digite corretamente");
    }
     return 0; }
