#include <stdio.h>  
#include <stdlib.h>
#include <string.h>



#define CSVSIZE 17000
typedef struct{
    int ID;
    char *Name;
    char *Platform;
    int Year_Of_Release;
    char *Genre;
    char *Publisher;
    float NA_Sales;
    float EU_Sales;
    float JP_sales;
    float Other_Sales;
    float Global_Sales;   
}Games;

Games* carregaDados(char *fileName, int *tam);

Games* IniciaLista(int capacidade);

int main(void){
    Games *jogos;
    int tam=0;
    jogos = carregaDados("c:\\usersGrupo1DataSet.csv",&tam);
    printf("%d",jogos[1].ID);
}

Games* carregaDados(char *fileName, int *tam)
{
  Games *jogos;
  FILE *fp;
  int i = 0;
  char str[900];
    
  jogos = IniciaLista(CSVSIZE);

  fp = fopen(fileName, "r");
    
  if(fp == NULL) {
    printf("Arquivo não pode ser aberto\n");
    return NULL;
  }

  // pegando o cabeçalho
  char header[50]; 
  fscanf(fp,"%s",header);
  //printf("%s\n",header);

  //lendo o arquivo
  while(!feof(fp)){

    //id
    fscanf(fp,"\n%d",&jogos[i].ID);
    //nome    
    fscanf(fp,",%[^,]s",str);
    jogos[i].Name = (char*)malloc((strlen(str)+1)*sizeof(char));
    strcpy(jogos[i].Name,str);
    //plataforma    
    fscanf(fp,",%[^,]s",str);
    jogos[i].Platform = (char*)malloc((strlen(str)+1)*sizeof(char));
    strcpy(jogos[i].Platform,str);
    //ano de lançamento
    fscanf(fp,",%d",&jogos[i].Year_Of_Release);
    //genero
    fscanf(fp,",%[^,]s",str);
    jogos[i].Genre = (char*)malloc((strlen(str)+1)*sizeof(char));
    strcpy(jogos[i].Genre,str);
    //Empresa que publicou
    fscanf(fp,",%[^,]s",str);
    jogos[i].Publisher = (char*)malloc((strlen(str)+1)*sizeof(char));
    strcpy(jogos[i].Publisher,str);
    //vendas
fscanf(fp,",%f,%f,%f,%f,%f,",&jogos[i].NA_Sales,&jogos[i].EU_Sales,&jogos[i].JP_sales,&jogos[i].Other_Sales,&jogos[i].Global_Sales);
    fscanf(fp,"%[^\n]s",str);
    
    i++;
  }
    *tam = i;
    int err = fclose(fp);
    if (err) // err != 0
    {
        printf("Arquivo incorretamente fechado!!\n");
    }
    return jogos;
}

Games* IniciaLista(int capacidade){
  Games* jogos;
  jogos = (Games*) malloc((capacidade)*sizeof(Games));
  return jogos;
}