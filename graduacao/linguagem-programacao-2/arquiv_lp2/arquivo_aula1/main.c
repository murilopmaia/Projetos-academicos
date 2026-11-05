#include <stdio.h>
#include <stdlib.h>

struct Ficha{
    float nota[3];
    char nome[30];
    char matricula[10];

};

typedef struct Ficha ficha;

void limpar_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
   
}

void obter_alunos(ficha *aluno,int tam){
    for(int i = 0;i<tam;i++){
        printf(" \nInforme o nome do %d aluno: ",i+1);
        scanf("%[^\n]s",aluno[i].nome);
        limpar_buffer();
        printf(" \nInforme a matricula do %d aluno: ",i+1);
        scanf("%[^\n]s",aluno[i].matricula);
        limpar_buffer();
        for(int j = 0; j<3 ;j++){
            printf("\nInforme a nota %d do aluno: ",j+1);
            scanf("%f",&aluno[i].nota[j]);
            limpar_buffer();
        }
    }
}

void armazena(char *nome_arquivo,ficha *alunos,int tam){
    FILE *fp;
    fp = fopen(nome_arquivo,"wb");

    fwrite(alunos,sizeof(ficha),tam,fp);
    fclose(fp);
}

void leitura(char *nome_arquivo,ficha *alunos,int tam){
    FILE *fp;
    fp = fopen(nome_arquivo,"rb");

    fread(alunos,sizeof(ficha),tam,fp);
    fclose(fp);
}

void mostrar_alunos_teste(ficha *alunos_teste,int tam){
     for(int i = 0;i<tam;i++){
        printf("\nNome do %d aluno: %s ",i+1,alunos_teste[i].nome);
        
        printf("\nMatricula do %d aluno: %s ",i+1,alunos_teste[i].matricula);
        
        for(int j = 0; j<3 ;j++){
            printf("\nNota%d %.2f ",j+1,alunos_teste[i].nota[j]);
        }
        printf("\n");
    }
}

int main(){
    
    ficha aluno[1];
    ficha aluno_teste[1];
    char nome_arquivo[30];
    printf("\nInforme o nome do arquivo: ");
    scanf(" %[^\n]s",nome_arquivo);
    limpar_buffer();
    obter_alunos(aluno,1);
    armazena(nome_arquivo,aluno,1);
    leitura(nome_arquivo,aluno_teste,1);
    printf("\n\n");
    mostrar_alunos_teste(aluno,1);
    printf("\n\n");
    mostrar_alunos_teste(aluno_teste,1);

    return 0;
}