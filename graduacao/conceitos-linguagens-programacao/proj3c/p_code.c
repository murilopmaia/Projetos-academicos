#include <stdio.h>
#include <limits.h>
#include <string.h>

int main(int argc, char *argv[]){

    if(argc != 3){
        printf("Falta de Argumentos");
        return 0;
    }

    FILE *fp, *fp2;
    char valor2[100];
    int valor;
    fp = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "w");

    if(fp == NULL){
        printf("Caminho de arquivo de entrada invalido");
        return 0;
    }
    
    while(!feof(fp)){
        valor = INT_MAX;
        fscanf(fp, "PUSH(%d)\n", &valor);
        if(valor != INT_MAX){
            fprintf(fp2, "LIT 0 %d\n", valor);
        }
        
        strcpy(valor2, "inf");
        fscanf(fp, "y=POP(); x=POP(); PUSH(x %s y)\n", valor2);
        if(!strcmp(valor2, "ADD")){
            fprintf(fp2, "OPR 0 2\n");
        }
        else if(!strcmp(valor2, "SUB")){
            fprintf(fp2, "OPR 0 3\n");
        }
        else if(!strcmp(valor2, "MUL")){
            fprintf(fp2, "OPR 0 4\n");
        }
        else if(!strcmp(valor2, "DIV")){
            fprintf(fp2, "OPR 0 5\n");
        }

    }
    
    fclose(fp);
    fclose(fp2);
    return 0;
}