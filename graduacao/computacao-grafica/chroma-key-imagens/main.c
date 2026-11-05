#include <stdio.h>
#include <stdlib.h>

void limpaBuffer(){
    scanf("%*[^\n]");
    scanf("%*c");
}


typedef struct{
    int red;
    int green;
    int blue;
}imagem;

int main(){
    FILE *fp1;
    FILE *fp2;
    FILE *fp3;
    imagem **back;
    imagem pixelFront;
    char caminhoBack[900];
    char caminhoFront[900];
    char tipoBack[3];
    char tipoFront[3];
    int alturaBack, larguraBack;
    int alturaFront, larguraFront;
    int maxBrancoBack, maxBrancoFront;
    int minRed, maxRed;
    int minBlue, maxBlue;
    int minGreen, maxGreen;
    int centroAltura, centroLargura;

    printf("Informe o caminho do back: ");
    scanf("%[^\n]s", caminhoBack);
    limpaBuffer();

    printf("\nInforme o caminho do front: ");
    scanf("%[^\n]s", caminhoFront);
    limpaBuffer();

    printf("\nInforme o Azul minimo: ");
    scanf("%d", &minBlue);
    limpaBuffer();

    printf("\nInfome o Azul maximo: ");
    scanf("%d", &maxBlue);
    limpaBuffer();

    printf("\nInforme o Verde minimo: ");
    scanf("%d", &minGreen);
    limpaBuffer();

    printf("\nInforme o Verde maximo: ");
    scanf("%d", &maxGreen);
    limpaBuffer();

    printf("\nInforme o Vermelho minimo: ");
    scanf("%d", &minRed);
    limpaBuffer();

    printf("\nInforme o Vermelho maximo: ");
    scanf("%d", &maxRed);
    limpaBuffer();


    fp1 = fopen(caminhoBack, "r");
    
    fp2 = fopen(caminhoFront, "r");
    
    if(fp1 == NULL || fp2 == NULL) {
        printf("Arquivo não pode ser aberto\n");
        return 0;
    }

    fscanf(fp1, "%s", tipoBack);
    fscanf(fp2, "%s", tipoFront);

    fscanf(fp1, "%d", &larguraBack);
    fscanf(fp1, "%d", &alturaBack);

    fscanf(fp2, "%d", &larguraFront);
    fscanf(fp2, "%d", &alturaFront);

    fscanf(fp1, "%d", &maxBrancoBack);
    fscanf(fp2, "%d", &maxBrancoFront);

    if(alturaBack < alturaFront || larguraBack < larguraFront){
        printf("\nTamanho de imagem invalida, back maior que front");
        return 0;
    }

    back = (imagem**)malloc(alturaBack * sizeof(imagem*));

    centroAltura =  (alturaBack/2) - (alturaFront/2);
    centroLargura = (larguraBack/2) - (larguraFront/2);

    for(int i = 0; i < alturaBack; i++){
        back[i] = (imagem*)malloc(larguraBack * sizeof(imagem));
        for(int j = 0; j < larguraBack; j++){
            fscanf(fp1, "%d", &back[i][j].red);
            fscanf(fp1, "%d", &back[i][j].green);
            fscanf(fp1, "%d", &back[i][j].blue);
            if(i >= centroAltura && i < (alturaFront + centroAltura) && j >= centroLargura && j < (larguraFront + centroLargura) ){
                fscanf(fp2, "%d", &pixelFront.red);
                fscanf(fp2, "%d", &pixelFront.green);
                fscanf(fp2, "%d", &pixelFront.blue);

                if(!(pixelFront.blue > minBlue && pixelFront.blue < maxBlue
                && pixelFront.red > minRed && pixelFront.red < maxRed
                && pixelFront.green > minGreen && pixelFront.green < maxGreen)){
                    back[i][j].red = pixelFront.red;
                    back[i][j].blue = pixelFront.blue;
                    back[i][j].green = pixelFront.green;
                }
            }
        }
    }

    fclose(fp1);
    fclose(fp2);

    fp3 = fopen("C:\\Users\\Murilo\\Desktop\\CG\\Nova pasta\\Output_img.pnm", "w");

    fprintf(fp3, "P3\n");
    fprintf(fp3, "%d %d\n",larguraBack,alturaBack);
    fprintf(fp3, "%d\n", maxBrancoBack);

    for(int i = 0; i < alturaBack; i++){
        for(int j = 0 ; j < larguraBack; j++){
            fprintf(fp3,"%d %d %d ", back[i][j].red, back[i][j].green, back[i][j].blue);
        }
        fprintf(fp3,"\n");
    }

    fclose(fp3);
    return 0;
}