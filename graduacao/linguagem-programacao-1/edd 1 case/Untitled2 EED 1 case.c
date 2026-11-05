int main (void) {

    unsigned int folhas;
    float custo;

    printf("informe o total de folhas\n");
    scanf("%d",&folhas);

    switch(folhas){

        case 0 ... 100 : (custo = folhas * 0.25); break;
        case 101 ... 4294967295  : (custo = folhas * 0.20); break;

    }

    printf("o custo total sera de = %.2f",custo);

    return 0;
}
