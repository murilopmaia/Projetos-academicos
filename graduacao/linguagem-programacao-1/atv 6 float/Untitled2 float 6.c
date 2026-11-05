/* Murilo Patricio Maia
   Questão 6 */

int main (void) {

    char a;
    char b;
    char c;


    printf("escreva 2 caracteres\n");
    scanf("%c %c",&a,&b);

    c = b;
    b = a;
    a = c;

    printf("\nvoce colocou %c e %c ? nessa ordem ? rs\n",a ,b);

    return 0;

}

