/*
    -> Seja as cadeias aceitas:
        . identificadores: Sequencia de letras minusculas
        . Numeros naturais
        . comando de atribuição
    -> Fazer um programa que leia de um arquivo texto uma sequencia de caracteres e 
    grave em um arquivo texto de saida as cadeias e suas categorias:
    identificador, numero, atribuição
    -> A entrada pode conter espaços em branco para separar as caideas ou não
    -> Cada linha contém uma sequencia de ideficiador, atribuição e numero.
    -> utilizar automato do exercicio do class
    
    Exemplo: 

    entrada.txt
    num=10
    num = 10
    resultado=257
    231
    rei =
    Erro

    saida.txt
    num identificador
    = atribuição
    10 numero
    num identificador
    ...
    Erro erro
*/

#include <stdio.h>

void estado6(char *cadeia, int index){
    char simbolo = cadeia[index];
    if(simbolo == '\0'){
        FILE *fp
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
        else if(simbolo >= 48 && simbolo <= 57){
            estado6(cadeia, 1);
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