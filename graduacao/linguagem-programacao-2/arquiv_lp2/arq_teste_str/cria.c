#include <stdio.h>
#include <stdlib.h>

void limpa_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
}

int main(){
    FILE *fp;

    fp = fopen("lalala.dat","wb");
    char palavra[50];
    int num = 50;

    scanf("%[^\n]s",palavra);
    limpa_buffer();

    fwrite(palavra,sizeof(char),25,fp);
    fwrite(&num,sizeof(int),1,fp);

    fclose(fp);
    
    fp = fopen("lalala.dat","rb");
    char teste_palavra[50];
    int teste_num;

    fread(teste_palavra,sizeof(char),25,fp);
    fread(&teste_num,sizeof(int),1,fp);

    printf("\n%s-%d",teste_palavra,teste_num);

    fclose(fp);

    return 0;
}