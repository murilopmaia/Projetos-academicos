#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* int2Bin2(int n,char *str2){
    if(n/2 == 0){
        if(n%2 == 0){
           str2[0] = '0'; 
          
        }
        else{
            str2[0] = '1';     
        }
        str2[1] = '\0';
          return str2;
    }
    int2Bin2(n/2,str2);
    int posicao;
    posicao = strlen(str2);
   
    if(n%2 == 0){
           str2[posicao] = '0'; 
        }
        else{
            str2[posicao] = '1';
        }
        
    str2[posicao+1] = '\0';
    return str2;
}

char *int2Bin(int n){
    char *str;
    str = (char*)malloc(50*sizeof(char));
    
    return int2Bin2(n,str);
}


int main(){
    char *resposta;
    resposta = int2Bin(16);
    printf("%s",resposta);
    free(resposta);
    return 0;
}