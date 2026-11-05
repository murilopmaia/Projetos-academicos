#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *ISBN;
    char *BookTitle;
    char *BookAuthor;
    int YearOfPublication;
    char *Publisher;
    char *ImageURLS;
    char *ImageURLM;
    char *ImageURLL;
}Book;

int main(){
    Book *livro;
    char str[900];
    char cabeca[90];
    FILE *fp;
    int ind = 0;

    livro = (Book*)malloc(271360*sizeof(Book));
    fp = fopen("C:\\Users\\Murilo\\Desktop\\estrut dados\\arquivos 10 03\\Books.csv","r");

    if(fp == NULL){
        printf("Arquivo nao pode ser aberto\n");
        exit(1);
    }
   
    fscanf(fp,"%[^\n]s",cabeca);
    while(!feof(fp)){
    
        fscanf(fp,"\n%[^,]s",str);
        livro[ind].ISBN = (char*)malloc(strlen(str)*sizeof(char));
        strcpy(livro[ind].ISBN,str);
        
        fscanf(fp,",%[^,]s",str);
        livro[ind].BookTitle = (char*)malloc(strlen(str)*sizeof(char));
        strcpy(livro[ind].BookTitle,str);

        fscanf(fp,",%[^,]s",str);
        livro[ind].BookAuthor = (char*)malloc(strlen(str)*sizeof(char));
        strcpy(livro[ind].BookAuthor,str);

        fscanf(fp,",%d,%[^,]s",&livro[ind].YearOfPublication,str);
        livro[ind].Publisher = (char*)malloc(strlen(str)*sizeof(char));
        strcpy(livro[ind].Publisher,str);

        fscanf(fp,",%[^,]s",str);
        livro[ind].ImageURLS = (char*)malloc(strlen(str)*sizeof(char));
        strcpy(livro[ind].ImageURLS,str);

        fscanf(fp,",%[^,]s",str);
        livro[ind].ImageURLM = (char*)malloc(strlen(str)*sizeof(char));
        strcpy(livro[ind].ImageURLM,str);

        fscanf(fp,",%[^\n]s",str);
        livro[ind].ImageURLL = (char*)malloc(strlen(str)*sizeof(char));
        strcpy(livro[ind].ImageURLL,str);

        ind++;
    }
    
    printf("%s\n",cabeca);
    
    for(int i = 0; i <= ind;i++){
        printf("%s,%s,%s,%d,%s,%s,%s,%s\n",livro[i].ISBN,livro[i].BookTitle,livro[i].BookAuthor,livro[i].YearOfPublication,livro[i].Publisher,livro[i].ImageURLS,livro[i].ImageURLM,livro[i].ImageURLL);
    }
    return 0;
}