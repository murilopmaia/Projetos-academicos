#include <stdio.h>
#include <stdlib.h>


int main(){
    FILE *fp;
    int num=10;
    float x=2.5;
    char palavra[7]= {"murilo"};

    fp = fopen("teste.txt","wb");
    fwrite(&num,sizeof(int),1,fp);
    fwrite(&x,sizeof(float),1,fp);
    fwrite(palavra,sizeof(char),7,fp);
    fclose(fp);

    fp = fopen("teste.txt","rb");
    int teste_num;
    float teste_x;
    char teste_palavra[60];
    fread(&teste_num,sizeof(int),1,fp);
    fread(&teste_x,sizeof(float),1,fp);
    fread(teste_palavra,sizeof(char),7,fp);
    printf("%d %.2f",teste_num,teste_x);
    printf("\n%s",teste_palavra);

    fclose(fp);

    
    return 0;
}