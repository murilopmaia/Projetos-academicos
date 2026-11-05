#include <stdio.h>

void estado6(char *cadeia, int index){
    char simbolo = cadeia[index];
    if(simbolo == '\0'){
        printf("Identificador atribuicao numero\n");
    }
    else{
        if(simbolo >= 48 && simbolo <= 57){
            estado6(cadeia, ++index);
        }
        else{
            printf("ERRO\n");
        }
    } 
}

void estado5(char *cadeia, int index){
    char simbolo = cadeia[index];
    if(simbolo == '\0'){
        printf("ERRO\n");
    }
    else{
        if(simbolo >= 48 && simbolo <= 57){
            estado6(cadeia, ++index);
        }
        else{
            printf("ERRO\n");
        }
    } 
}

void estado4(char *cadeia, int index){
    char simbolo = cadeia[index];
    if(simbolo == '\0'){
        printf("ERRO\n");
    }
    else{
        if((simbolo == 32)){
            estado5(cadeia, ++index);
        }
        else{
            printf("ERRO\n");
        }
    } 
}

void estado3(char *cadeia, int index){
    char simbolo = cadeia[index];
    if(simbolo == '\0'){
        printf("ERRO\n");
    }
    else{
        if((simbolo == 61)){
            estado4(cadeia, ++index);
        }
        else{
            printf("ERRO\n");
        }
    }
}

void estado2(char *cadeia, int index){
    char simbolo = cadeia[index];
    if(simbolo == '\0'){
        printf("ERRO\n");
    }
    else{
        if((simbolo >= 97 && simbolo <= 122)){
            estado2(cadeia, ++index);
        }
        else if(simbolo == 32){
            estado3(cadeia, ++index);
        }
        else{
            printf("ERRO\n");
        }
    }
 
}

void estado1(char *cadeia){
    char simbolo = cadeia[0];
    if(simbolo == '\0'){
        printf("ERRO\n");
    }
    else{
        if(simbolo >= 97 && simbolo <= 122){
            estado2(cadeia, 1);
        }
        else{
            printf("ERRO\n");
        }
    }
}

int main(){
    FILE *fp;
    char cadeia[100];
    fp = fopen(".\\inputEx2.txt", "r");
    if(fp == NULL){
        printf("Problema na leitura\n");
        return 0;
    }
    while(fscanf(fp, "%[^\n]s", cadeia) != EOF){
        fscanf(fp, "\n");
        printf("cadeia: %s - ", cadeia);
        estado1(cadeia);
    }
    return 0;
}