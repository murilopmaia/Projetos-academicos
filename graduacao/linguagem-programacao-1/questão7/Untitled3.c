
#define TAM 20
int main(void){
    float amostras[TAM];
    int i;

    for(i=0;i<TAM;i++){
        do{
            printf("informe a amostra %d ",i+1);
            scanf("%f",&amostras[i]);
            scanf("%*[^\n]");
            scanf("%*c");
            if(amostras[i]<0){
                printf("digite valor positivo\n");
            }
        }
        while(amostras[i]<0);
    }
    printf("\n---------amostras iniciais---------------\n");
    for(i=0;i<TAM;i++){
        printf("%.2f  ",amostras[i]);
    }
    printf("\n\n");
    printf("\n-----------amostras atualizadas-----------\n");
    for(i=0;i<TAM;i++){
        if(amostras[i]<20){
            continue;
        }
        printf("%.2f  ",amostras[i]);
    }

    return 0;
}

