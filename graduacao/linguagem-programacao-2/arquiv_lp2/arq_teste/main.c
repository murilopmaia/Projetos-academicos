#include <stdio.h>
#include <stdlib.h>


int main(){
    FILE *fp;
    char palavra[50];

    fp = fopen("teste.txt","w");
    fprintf(fp,"\nola mundinho");
    fprintf(fp,"\noi oi oi oi");
    fclose(fp);

    fp = fopen("teste.txt","r");

    while(!feof(fp)){
        fscanf(fp,"\n%[^\n]s",palavra);

    
        

        printf("%s",palavra);
        scanf("%*c");
    }
    
    fclose(fp);
    return 0;
}