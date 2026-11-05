#include <stdio.h>
#include <stdlib.h>

void limpa_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
}

int main(){
    FILE *fp;
    int parar = 0;
    char mes[20];
    int dia;
    float max,min;
    fp = fopen("Temperatuda.dat","w");
    for(;parar==0;){
        printf("\nInforme o nome do mes: ");
        scanf("%[^\n]s",mes);
        limpa_buffer();

        printf("\n\nInforme o dia: ");
        scanf("%d",&dia);
        limpa_buffer();

        printf("\n\nInforme a temperatura maxima: ");
        scanf("%f",&max);
        limpa_buffer();

        printf("\n\nInforme a temperatuda minima: ");
        scanf("%f",&min);
        limpa_buffer();

        printf("\n\nDigite 0 para continuar: ");
        scanf("%d",&parar);
        limpa_buffer();

        fprintf(fp,"mes: %s,dia: %d,max: %.2f,min: %.2f\n",mes,dia,max,min);
        system("clear||cls");
    }
    fclose(fp);
    return 0;
}