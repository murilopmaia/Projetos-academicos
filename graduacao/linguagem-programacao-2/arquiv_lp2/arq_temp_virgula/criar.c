#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void limpar_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
}

void obter_informações(char *nome_arquivo){
    int mes,dia;
    float min,max;
    int fim=0;
    FILE* fp;
    fp = fopen(nome_arquivo,"r");
    
    if(fp == NULL){
        fclose(fp);
        fp = fopen(nome_arquivo,"w");
        for(;fim!=-1;){
            printf("----------------------------");
            printf("\nInforme o mes: ");
            scanf("%d",&mes);
            limpar_buffer();
            fprintf(fp,"%d,",mes);

            printf("\nInforme o dia: ");
            scanf("%d",&dia);
            limpar_buffer();
            fprintf(fp,"%d,",dia);

            printf("\nInforme a temperatura minima: ");
            scanf("%f",&min);
            limpar_buffer();
            fprintf(fp,"%.2f,",min);

            printf("\nInforme a temperatura maxima: ");
            scanf("%f",&max);
            limpar_buffer();
            fprintf(fp,"%.2f\n",max);

            printf("\n\nclique -1 para finalizar: ");
            scanf("%d",&fim);
            limpar_buffer();
            system("clear||cls");
        }
        fclose(fp);
    
    }
    else{
        fclose(fp);
        fp = fopen(nome_arquivo,"a");
        for(;fim!=-1;){
            printf("----------------------------");
            printf("\nInforme o mes: ");
            scanf("%d",&mes);
            limpar_buffer();
            fprintf(fp,"%d,",mes);

            printf("\nInforme o dia: ");
            scanf("%d",&dia);
            limpar_buffer();
            fprintf(fp,"%d,",dia);

            printf("\nInforme a temperatura minima: ");
            scanf("%f",&min);
            limpar_buffer();
            fprintf(fp,"%.2f,",min);

            printf("\nInforme a temperatura maxima: ");
            scanf("%f",&max);
            limpar_buffer();
            fprintf(fp,"%.2f\n",max);

            printf("\n\nclique -1 para finalizar: ");
            scanf("%d",&fim);
            limpar_buffer();
            system("clear||cls");
        }
        fclose(fp);
    }
}

int main(){
    obter_informações("temp_teste.dat");
    return 0;
}

