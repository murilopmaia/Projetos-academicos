#include <stdio.h>

void estado2(char *cadeia, int index){
    char simbolo = cadeia[index];
    if(simbolo == '\0'){
        printf("A cadeia foi Aceita\n");
    }
    else{
        if((simbolo >= 48 && simbolo <= 57)){
            estado2(cadeia, ++index);
        }
        else{
            printf("A cadeia foi recusada\n");
        }
    }
 
}

void estado1(char *cadeia){
    char simbolo = cadeia[0];
    if(simbolo == '\0'){
        printf("A cadeia foi recusada\n");
    }
    else{
        if(simbolo >= 48 && simbolo <= 57){
            estado2(cadeia, 1);
        }
        else{
            printf("A cadeia foi recusada\n");
        }
    }
}

int main(){
    FILE *fp;
    char cadeia[100];
    fp = fopen(".\\inputE1.txt", "r");
    if(fp == NULL){
        printf("Problema na leitura\n");
        return 0;
    }
    while(fscanf(fp, "%s\n", cadeia) != EOF){
        printf("cadeia: %s - ", cadeia);
        estado1(cadeia);
    }
    return 0;
}