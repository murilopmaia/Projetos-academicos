#define  red "\x001b[31;1m"
#define verde "\x001b[32;1m"
#define roxo "\x01b[35;1m"
#define reset "\x01b[0m"

void main(){

    int quant,*p,*par,*impar;
    int contp=0,conti=0;
    int y=0,z=0;
    printf("qual sera a quantidade de numeros? ");
    scanf("%d",&quant);
    scanf("%*[^\n]");
    scanf("%*c");

    p = (int*)malloc(quant * sizeof(int));

    system("clear||cls");
    for(int x=0;x<quant;x++){

        printf("\nInsira o inteiro ");
        scanf("%d",&p[x]);
        scanf("%*[^\n]");
        scanf("%*c");
    }

    for(int x=0;x<quant;x++){
        if(p[x]%2 == 0){
            contp++;
        }
        else{
            conti++;
        }
    }

      par = (int*)malloc(contp * sizeof(int));
    impar = (int*)malloc(conti * sizeof(int));

     for(int x=0;x<quant;x++){
        if(p[x]%2 == 0){
           par[y] = p[x];
           y++;
        }
        else{
            impar[z] = p[x];
            z++;
        }
    }
    system("clear||cls");
    printf("\n\nO vetor eh: ");
    for(int x=0;x<quant;x++){
       printf( roxo "%d " reset,p[x]);
    }
    printf("\n\nOs pares sao: ");
    for(int x=0;x<contp;x++){
        printf( verde "%d " reset,par[x]);
    }
    printf("\n\nOs impares sao: ");
    for(int x=0;x<conti;x++){
        printf( red "%d " reset,impar[x]);
    }

    printf("\n");
    free(p);
    free(par);
    free(impar);
}
