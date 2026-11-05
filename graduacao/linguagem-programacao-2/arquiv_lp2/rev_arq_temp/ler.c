#include <stdio.h>
#include <stdlib.h>

void limpar_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
}

int main(){
    FILE *fp;
    char mes[20];
    int dia;
    float max,min;

    fp = fopen("Temperatuda.dat","r");

    if(fp == NULL){
        printf("Arquivo nao existe");
        return 0;
    }

    while(!feof(fp)){
        
        fscanf(fp,"mes: %[^,]s",mes);
       
        fscanf(fp,",dia: %d,max: %f,min: %f\n",&dia,&max,&min);
         
        printf("mes: %s, dia %d, maximo: %.2f, minimo: %.2f\n",mes,dia,max,min);
    
    }
    fclose(fp);
    return 0;
}