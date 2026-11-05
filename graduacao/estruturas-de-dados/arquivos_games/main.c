#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
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
    int id;
    
}Games;

int procura( int **Id_invalido,int ano,int *tam){
    int cont=0;

    for(int i = 0;i < (*tam);i++){
        if((*Id_invalido)[i] == ano){
            cont++;
        }
    }
    (*tam)++;
    (*Id_invalido) = (int*)realloc((*Id_invalido),(*tam)*sizeof(int));
    (*Id_invalido)[(*tam)-1] = ano;
    return cont;
}

int main(){
    FILE *fp;
    Games *jogos;
    char str[900];
    char header[100];
    
    int ind=0;

    jogos = (Games*)malloc(16719*sizeof(Games));

    fp = fopen("C:\\Users\\Murilo\\Desktop\\estrut dados\\arquivos_games\\Video_Games.csv","r");

    if(fp == NULL){
        printf("Arquivo nao encontrado");
        return 0;
    }

    fscanf(fp,"%[^\n]s",header);
    //printf("%s\n",header);
    
    while(!feof(fp)){
        
        fscanf(fp,"\n%[^,]s",str);
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
    
    /*for(int i = 0;i<(ind-1);i++ ){
        printf("%s,%s,%d,%s,%s,%.2f,%.2f,%.2f,%.f,%.2f\n",jogos[i].Name,jogos[i].Platform,jogos[i].Year_Of_Release,jogos[i].Genre,jogos[i].Publisher,jogos[i].NA_Sales,jogos[i].EU_Sales,jogos[i].JP_sales,jogos[i].Other_Sales,jogos[i].Global_Sales);
    }*/

    
    
    fclose(fp);
    //------------------------------------------------------------------------------------------------------
    int *id_invalido;
    int tam=1;
    int cont=0;
    fp = fopen("./Grupo1DataSet.csv","w");

    id_invalido = (int*)malloc(sizeof(int));

    fprintf(fp,"id,%s\n",header);

    for(int i = 0;i<16719;i++){
        jogos[i].id = jogos[i].Year_Of_Release;
        cont =  procura(&id_invalido,jogos[i].id,&tam);
        fprintf(fp,"%d00%d,%s,%s,%d,%s,%s,%.2f,%.2f,%.2f,%.f,%.2f\n",jogos[i].id,cont,jogos[i].Name,jogos[i].Platform,jogos[i].Year_Of_Release,jogos[i].Genre,jogos[i].Publisher,jogos[i].NA_Sales,jogos[i].EU_Sales,jogos[i].JP_sales,jogos[i].Other_Sales,jogos[i].Global_Sales);
    }







    fclose(fp);

    
     for(int i = 0;i<(ind-1);i++ ){
            free(jogos[i].Name);
            free(jogos[i].Platform);
            free(jogos[i].Genre);
            free(jogos[i].Publisher);
           
    }
    free(id_invalido);
    return 0;
}
