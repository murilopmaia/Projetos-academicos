
#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"



//Funções usadas para a demonstração:

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



FilaEnc* iniFilaEnc(){
  FilaEnc *fila;
  fila = (FilaEnc*)malloc(sizeof(FilaEnc));
  fila->fim = NULL;
  fila->ini = NULL;
  fila->tam=0;
  return fila;
}

void imprimeFila(FilaEnc *fila){
  printf("\n\n\t---------------------------");
  for(PNoGame p=fila->ini;p!=NULL;p=p->prox){
    printf("\n\tNome: %s",p->jogo.Name);
    printf("\n\tId: %d\n",p->jogo.ID);
     
  }
}

int insereNaFila(Games jogo,FilaEnc *fila){
    PNoGame p;
    p = alocaNoGame();
    cpyGame(jogo, &p->jogo);
    
  if(fila->tam == 0){
    fila->ini = p;
    fila->fim = p;
    fila->tam++;
  }
  else{
    fila->fim->prox = p;
    fila->fim = p;
    fila->tam++;
  }
  return 1;
}

void limpaJogo(Games *jogo){
   free(jogo->Name);
   free(jogo->Platform);
   free(jogo->Genre);
   free(jogo->Publisher);
}

//Funções, usadas e modificadas para o dataSet, da questão 5:

PNoGame alocaNoGame(){
  PNoGame p;
  p = (PNoGame)malloc(sizeof(TNoGame));
  p->prox = NULL;
  return p;
}

void cpyGame(Games jogo, Games* jogo_copia){
  
   (*jogo_copia).ID = jogo.ID;
      
    (*jogo_copia).Name = (char*)malloc((strlen(jogo.Name)+1)*sizeof(char));
    strcpy((*jogo_copia).Name,jogo.Name);
            
    (*jogo_copia).Platform = (char*)malloc((strlen(jogo.Platform)+1)*sizeof(char));
    strcpy((*jogo_copia).Platform,jogo.Platform);

    (*jogo_copia).Year_Of_Release =  jogo.Year_Of_Release;

    (*jogo_copia).Genre = (char*)malloc((strlen(jogo.Genre)+1)*sizeof(char));
    strcpy((*jogo_copia).Genre,jogo.Genre);

    (*jogo_copia).Publisher = (char*)malloc((strlen(jogo.Publisher)+1)*sizeof(char));
    strcpy((*jogo_copia).Publisher,jogo.Publisher);

   (*jogo_copia).NA_Sales = jogo.NA_Sales;

    (*jogo_copia).EU_Sales = jogo.EU_Sales;

    (*jogo_copia).JP_sales = jogo.JP_sales;

    (*jogo_copia).Other_Sales = jogo.Other_Sales;

    (*jogo_copia).Global_Sales = jogo.Global_Sales;

   
}

void destoiNoGame(PNoGame p){
  free(p->jogo.Name);
  free(p->jogo.Platform);
  free(p->jogo.Publisher);
  free(p->jogo.Genre);
  free(p);
}

//Funcões da Questão 5:

int insereMeio(Games jogo, FilaEnc*fila){
   if(fila->tam <= 2){
     return 0;
   }
  else{
    PNoGame p;
    p = alocaNoGame();
    cpyGame(jogo, &p->jogo);

    int meio = fila->tam/2;
    PNoGame aux;
    aux = fila->ini;
    int i =0;
    while(i != meio-1){
       aux = aux->prox;
       i++;
    }
    p->prox = aux->prox;
    aux->prox = p;
    fila->tam++;
    return 1;
  }
}

Games* removeMeio(FilaEnc*fila){
  if(fila->tam <= 2){
    return 0;
  }
  else{
    PNoGame p;
    p = fila->ini;

    int meio = fila->tam/2;

    int i =0;
    while(i != meio-1){
      p = p->prox;
      i++;
    }
     Games *jogo_removido;
    jogo_removido = (Games*)malloc(sizeof(Games));
    cpyGame(p->prox->jogo, jogo_removido);

    PNoGame aux;
    aux = p->prox;

    p->prox = aux->prox;
    destoiNoGame(aux);
    fila->tam--;
    return jogo_removido;
    
  }

}