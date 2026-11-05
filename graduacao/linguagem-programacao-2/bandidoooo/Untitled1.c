#define  red "\x001b[31;1m"
#define verde "\x001b[32;1m"
#define reset "\x01b[0m"
void main(){

    int quant_notas;
    float *p;
    float soma_notas = 0,media;
    printf("quantas notas vao ser inseridas? ");
    scanf("%d",&quant_notas);
    scanf("%*[^\n]");
    scanf("%*c");
    system("clear||cls");
    p=(float*)malloc(quant_notas * sizeof(float));

    for(int x=0;x<quant_notas;x++){
        do{
        printf("\nInsira a nota %d: ",x+1);
        scanf("%f",&p[x]);
        scanf("%*[^\n]");
        scanf("%*c");

        if(p[x] < 0 || p[x] > 10){
            printf("\n\tInsira uma nota valida\n");
        }
        }
        while(p[x] < 0 || p[x] > 10);
        soma_notas += p[x];

    }
    media = soma_notas/quant_notas;
    printf("\na media eh: ");
    printf( verde "%.2f" reset,media);
    printf("\nas notas abaixo das medias sao: ");
    for(int x=0;x<quant_notas;x++){
        if(p[x]<media){
            printf(red"%.2f "reset,p[x]);
        }
    }

    scanf("%*c");

    free(p);
}

