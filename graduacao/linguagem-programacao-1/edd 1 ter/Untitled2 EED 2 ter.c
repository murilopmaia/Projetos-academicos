int main (void) {

    int folhas;
    float custo;

    printf("informe o total de folhas\n");
    scanf("%d",&folhas);

    custo = (folhas <=100)? (folhas * 0.25) : (folhas * 0.20);

    printf ("o custo toal sera de %.2f",custo);

    return 0;

}
