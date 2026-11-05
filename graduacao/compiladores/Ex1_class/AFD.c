#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAM_MAX_LINHA 1024 // Tamanho maximo de caracteres na linha do arquivo
#define TAM_MAX_PALAVRA 20 // Tamanho maximo de uma palavra, um estado, por exemplo
#define TAM_MAX_ESTADOS 50 // Tamanho maximo da quantidade de estados do automato
#define TAM_MAX_ALFABETO 50 // tamanho maximo do alfabeto
#define TAM_MAX_TRANSICAO 50 // tamanho maximo de transições
#define TAM_MAX_CADEIA 100 // tam maximo da cadeia

typedef struct {
    char Q[TAM_MAX_ESTADOS][TAM_MAX_PALAVRA];
    char sigma[TAM_MAX_ALFABETO][TAM_MAX_PALAVRA];
    char delta[TAM_MAX_TRANSICAO][3][TAM_MAX_PALAVRA];
    char q0[TAM_MAX_PALAVRA];
    char F[TAM_MAX_ESTADOS][TAM_MAX_PALAVRA];

    int Q_tam;
    int sigma_tam;
    int delta_tam;
    int F_tam;
}quintupla;


void parse_linha(char *line, char tokens[TAM_MAX_ESTADOS][TAM_MAX_PALAVRA], int *num_tokens);
int AFD(quintupla quint, char *cadeia);
int existe(quintupla quint, char *estadoAtual, char elemento);
int pertence(char *estadoAtual, quintupla quint);

int main(){
    FILE *fp;
    quintupla quint;
    char buffer[TAM_MAX_LINHA];
    char cadeia[TAM_MAX_CADEIA];
    
    fp = fopen(".\\input.txt", "r");
    // Verificando o caminho
    if(fp == NULL){
        printf("Falha na leitura do arquivo");
        return 0;
    }
    
    // Pegando os estados do automato
    if(fgets(buffer, sizeof(buffer), fp)){
        buffer[strcspn(buffer, "\n")] = '\0';
        parse_linha(buffer, quint.Q, &quint.Q_tam);
        

    };

    // Pegando os elementos do alfabeto
    if(fgets(buffer, sizeof(buffer), fp)){
        buffer[strcspn(buffer, "\n")] = '\0';
        parse_linha(buffer, quint.sigma, &quint.sigma_tam);
        

    };
    int aux_tam = 0;
    char aux[TAM_MAX_ESTADOS][TAM_MAX_PALAVRA];
    quint.delta_tam = 0;

    // Pegando as funções de transição e o estado inicial
    do{
        aux_tam = 0;
        if(fgets(buffer, sizeof(buffer), fp)){
            buffer[strcspn(buffer, "\n")] = '\0';
            parse_linha(buffer, aux, &aux_tam);
        };
        if(aux_tam == 1){
            strcpy(quint.q0, aux[0]);
        }
        else if(aux_tam == 3){
            strcpy(quint.delta[quint.delta_tam][0], aux[0]);
            strcpy(quint.delta[quint.delta_tam][1], aux[1]);
            strcpy(quint.delta[quint.delta_tam++][2], aux[2]);
        }
    }while(aux_tam == 3);
    
    // Pegando os estados finais
    if(fgets(buffer, sizeof(buffer), fp)){
        buffer[strcspn(buffer, "\n")] = '\0';
        parse_linha(buffer, quint.F, &quint.F_tam);
    };

    // Pegando a cadeia
    fscanf(fp, "%s", cadeia);
    
    AFD(quint, cadeia);
    fclose(fp);
    return 0;
}


// Função que recebe uma linha e devolve seus tokens (cada elemento da linha separado por espaço)
void parse_linha(char *line, char tokens[TAM_MAX_ESTADOS][TAM_MAX_PALAVRA], int *num_tokens) {
    char buffer[TAM_MAX_LINHA];
    strncpy(buffer, line, sizeof(buffer));
    buffer[sizeof(buffer) - 1] = '\0'; // Garantir terminação nula

    char *token = strtok(buffer, " ");
    *num_tokens = 0;
    
    while (token != NULL && *num_tokens < TAM_MAX_ESTADOS) {
        strncpy(tokens[*num_tokens], token, TAM_MAX_PALAVRA - 1);
        tokens[*num_tokens][TAM_MAX_PALAVRA - 1] = '\0'; // Garantir terminação nula
        (*num_tokens)++;
        token = strtok(NULL, " ");
    }
}

// Função para verificar a existencia de uma transição do automato
int existe(quintupla quint, char *estadoAtual, char elemento){
    for(int i = 0; i < quint.delta_tam; i++){
        if(!strcmp(quint.delta[i][0], estadoAtual) && (quint.delta[i][1][0] == elemento)){
            return i;
        }
    }
    return -1;
} 

// Função para verificar se o ultimo estado é o estado final
int pertence(char *estadoAtual, quintupla quint){
    for(int i = 0; i < quint.F_tam; i++){
        if(!strcmp(estadoAtual, quint.F[i])){
            return 1;
        }
    }
    return 0;
}

// Nosso AFD
int AFD(quintupla quint, char *cadeia){
    char estadoAtual[TAM_MAX_PALAVRA];
    int aux;
    strcpy(estadoAtual, quint.q0);

    for(int i = 0; cadeia[i] != '\0'; i++){
        aux = existe(quint, estadoAtual, cadeia[i]);
        if(aux != -1){
            strcpy(estadoAtual, quint.delta[aux][2]);
        }
        else{
            printf("Rejeita");
            return 0;
        }
        
    }
    if(pertence(estadoAtual, quint)){
        printf("Aceita");
        return 1;
    }
    else{
        printf("Rejeita");
        return 0;
    }

}