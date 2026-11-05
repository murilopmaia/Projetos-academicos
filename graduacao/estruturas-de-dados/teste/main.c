#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    long int ID;
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

void incLis(Games lista[], Games* jogos, int tam);

void buscaId(int id, Games *jogos, int tam);

int verificaId(int id, Games lista[], int tam);

int main(){
  FILE *fp;
  Games *jogos;
  Games lista[101];
  char str[900];
  char header[50];
  int ind=0;
  long int id=0;
  int stop=1;
  int tam = 16717;

  jogos = (Games*)malloc(16717*sizeof(Games));

  fp = fopen("./Grupo1DataSet.csv","r");

  if(fp == NULL){
    printf("Arquivo nao encontrado");
    return 0;
  }

  fscanf(fp,"%s",header);
  
    
  while(!feof(fp)){

    fscanf(fp,"\n%ld",&jogos[ind].ID);
        
    fscanf(fp,",%[^,]s",str);
    jogos[ind].Name = (char*)malloc((strlen(str)+1)*sizeof(char));
    strcpy(jogos[ind].Name,str);
        
    fscanf(fp,",%[^,]s",str);
    jogos[ind].Platform = (char*)malloc((strlen(str)+1)*sizeof(char));
    strcpy(jogos[ind].Platform,str);

    fscanf(fp,",%d",&jogos[ind].Year_Of_Release);

    fscanf(fp,",%[^,]s",str);
    jogos[ind].Genre = (char*)malloc((strlen(str)+1)*sizeof(char));
    strcpy(jogos[ind].Genre,str);

    fscanf(fp,",%[^,]s",str);
    jogos[ind].Publisher = (char*)malloc((strlen(str)+1)*sizeof(char));
    strcpy(jogos[ind].Publisher,str);

        fscanf(fp,",%f,%f,%f,%f,%f,",&jogos[ind].NA_Sales,&jogos[ind].EU_Sales,&jogos[ind].JP_sales,&jogos[ind].Other_Sales,&jogos[ind].Global_Sales);

    fscanf(fp,"%[^\n]s",str);
    ind++;

  }

  while(stop!=0){
    
    printf("\n\nDigite o id do jogo: ");
    scanf("%ld",&id);
    scanf("%*[^\n]");
    scanf("%*c");
      
    buscaId(id,jogos, tam);

    printf("\nDeseja continuar? (1-sim/0-não): ");
    scanf("%d", &stop);
    scanf("%*c");
    system("clear||cls");
  }
  
  incLis(lista, jogos, tam);

  for(int i = 0;i<(ind-1);i++ ){
    free(jogos[i].Name);
    free(jogos[i].Platform);
    free(jogos[i].Genre);
    free(jogos[i].Publisher);    
  }

  

  for(int i = 0; i < 100; i++){
    printf("\n");
    printf(" Nome: %s\n Plataforma: %s\n Ano de laçamento: %d\n Genero: %s\n Empresa: %s\n Vendas America do Norte: %.2f\n Vendas Estados Unidos: %.2f\n Vendas Japão: %.2f\n Outras vendas: %.f\n Vendas globais: %.2f\n ",lista[i].Name,lista[i].Platform,lista[i].Year_Of_Release,lista[i].Genre,lista[i].Publisher,lista[i].NA_Sales,lista[i].EU_Sales,lista[i].JP_sales,lista[i].Other_Sales,lista[i].Global_Sales);
    printf("\n");
  }
  scanf("%*c");
   
  return 0;
}

void buscaId(int id, Games *jogos,int tam){
    for(int i=0; i<=tam; i++){
      if(jogos[i].ID == id){
         printf(" Nome: %s\n Plataforma: %s\n Ano de laçamento: %d\n Genero: %s\n Empresa: %s\n Vendas America do Norte: %.2f\n Vendas Estados Unidos: %.2f\n Vendas Japão: %.2f\n Outras vendas: %.f\n Vendas globais: %.2f\n ",jogos[i].Name,jogos[i].Platform,jogos[i].Year_Of_Release,jogos[i].Genre,jogos[i].Publisher,jogos[i].NA_Sales,jogos[i].EU_Sales,jogos[i].JP_sales,jogos[i].Other_Sales,jogos[i].Global_Sales);
        break;
      }
      if(i == tam && jogos[i].ID != id){
        printf("ID inexistente!!");
      }
    }
}

int verificaId(int id, Games lista[],int tam){
    for(int i = 0; i <= tam; i++){
      if(lista[i].ID == id){
        return 0;
      }
      return 1;
    }
}

void incLis(Games lista[], Games* jogos, int tam){
    int n = 0;
    int i,ok;

    while(n != 100){
        
        do{
            i = rand() % tam;
            ok = verificaId(jogos[i].ID,lista,n);
        } while (ok == 0);

        lista[n].ID = jogos[i].ID;
        
        lista[n].Name = (char*)malloc((strlen(jogos[i].Name)+1)*sizeof(char));
        strcpy(lista[n].Name,jogos[i].Name);
            
        lista[n].Platform = (char*)malloc((strlen(jogos[i].Platform)+1)*sizeof(char));
        strcpy(lista[n].Platform,jogos[i].Platform);

        lista[n].Year_Of_Release =  jogos[i].Year_Of_Release;

        lista[n].Genre = (char*)malloc((strlen(jogos[i].Genre)+1)*sizeof(char));
        strcpy(lista[n].Genre,jogos[i].Genre);

        lista[n].Publisher = (char*)malloc((strlen(jogos[i].Publisher)+1)*sizeof(char));
        strcpy(lista[n].Publisher,jogos[i].Publisher);

        lista[n].NA_Sales = jogos[i].NA_Sales;

        lista[n].EU_Sales = jogos[i].EU_Sales;

        lista[n].JP_sales = jogos[i].JP_sales;

        lista[n].Other_Sales = jogos[i].Other_Sales;

        lista[n].Global_Sales = jogos[i].Global_Sales;

        n++;
    }
}