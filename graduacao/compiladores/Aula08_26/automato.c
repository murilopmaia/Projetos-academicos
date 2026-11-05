#include <stdio.h>

void estado2(char *cadeia, int index){
    char simbolo = cadeia[index];
    if(simbolo == '\0'){
        printf("A cadeia foi Aceita");
    }
    else{
        if((simbolo >= 97 && simbolo <= 122) || (simbolo >= 48 && simbolo <= 57)){
            estado2(cadeia, ++index);
        }
        else{
            printf("A cadeia foi recusada");
        }
    }
 
}

void estado1(char *cadeia, int index){
    char simbolo = cadeia[index];
    if(simbolo == '\0'){
        printf("A cadeia foi recusada!");
    }
    else{
        if(simbolo >= 97 && simbolo <= 122){
            estado2(cadeia, ++index);
        }
        else{
            printf("A cadeia foi recusada");
        }
    }
}

int main(){
    char cadeia[100];
    printf("Informe a cadeia\n");
    scanf("%s", cadeia);
    estado1(cadeia, 0);
    return 0;
}