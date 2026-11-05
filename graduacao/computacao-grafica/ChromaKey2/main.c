#include <stdio.h>
#include <stdlib.h>

void limpaBuffer()
{
    scanf("%*[^\n]");
    scanf("%*c");
}

typedef struct
{
    int red;
    int green;
    int blue;
} imagem;

imagem **backNoFront(FILE *fp1, FILE *fp2, int larguraBack, int alturaFront, int larguraFront, int minRed, int maxRed, int minBlue, int maxBlue, int minGreen, int maxGreen);
imagem **frontNoBack(FILE *fp1, FILE *fp2, int alturaBack, int larguraBack, int alturaFront, int larguraFront, int minRed, int maxRed, int minBlue, int maxBlue, int minGreen, int maxGreen);
void finalImprime(FILE *fp1, FILE *fp2, int altura, int largura, int maxBranco, char tipo[], imagem **output);
//void auxiliar(char front[], char back[]);

int main()
{
    FILE *fp1;
    FILE *fp2;
    imagem **output;
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
    int escolha;

    // Pedindo as imagens
    printf("Informe o caminho do back: ");
    scanf("%[^\n]s", caminhoBack);
    limpaBuffer();

    printf("\nInforme o caminho do front: ");
    scanf("%[^\n]s", caminhoFront);
    limpaBuffer();

    //Pedindo a banda
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

    // Abrindo e verificando a abertura
    fp1 = fopen(caminhoBack, "r");

    fp2 = fopen(caminhoFront, "r");

    if (fp1 == NULL || fp2 == NULL)
    {
        printf("Arquivo não pode ser aberto\n");
        return 0;
    }

    // Lendo o cabeçalho
    fscanf(fp1, "%s", tipoBack);
    fscanf(fp2, "%s", tipoFront);

    fscanf(fp1, "%d", &larguraBack);
    fscanf(fp1, "%d", &alturaBack);

    fscanf(fp2, "%d", &larguraFront);
    fscanf(fp2, "%d", &alturaFront);

    fscanf(fp1, "%d", &maxBrancoBack);
    fscanf(fp2, "%d", &maxBrancoFront);

    // Validando dimensões   
    if (alturaBack < alturaFront || larguraBack < larguraFront)
    {
        printf("\nTamanho de imagem invalida, back maior que front");
        return 0;
    }

    // As duas opções de saida
    printf("\nDeseja fazer:");
    printf("\n1-o back no front");
    printf("\n2-o Front no back, centralizado? ");
    scanf("%d", &escolha);
    limpaBuffer();

    if (escolha == 1)
    {
        output = backNoFront(fp1, fp2, larguraBack, alturaFront, larguraFront, minRed, maxRed, minBlue, maxBlue, minGreen, maxGreen);
        finalImprime(fp1, fp2, alturaFront, larguraFront, maxBrancoFront, tipoFront, output);
    }
    else if (escolha == 2)
    {
        output = frontNoBack(fp1, fp2, alturaBack, larguraBack, alturaFront, larguraFront, minRed, maxRed, minBlue, maxBlue, minGreen, maxGreen);
        finalImprime(fp1, fp2, alturaBack, larguraBack, maxBrancoBack, tipoBack, output);
    }
    else
    {
        printf("\nDigite corretamente");
    }

    //auxiliar(caminhoFront, caminhoBack);
    return 0;
}

imagem **backNoFront(FILE *fp1, FILE *fp2, int larguraBack, int alturaFront, int larguraFront, int minRed, int maxRed, int minBlue, int maxBlue, int minGreen, int maxGreen)
{
    imagem **front;
    imagem pixelBack;
    int lixo;

    front = (imagem **)malloc(alturaFront * sizeof(imagem *));

    for (int i = 0; i < alturaFront; i++)
    {
        front[i] = (imagem *)malloc(larguraBack * sizeof(imagem));
        for (int j = 0; j < larguraFront; j++)
        {
            fscanf(fp2, "%d", &front[i][j].red);
            fscanf(fp2, "%d", &front[i][j].green);
            fscanf(fp2, "%d", &front[i][j].blue);

            fscanf(fp1, "%d", &pixelBack.red);
            fscanf(fp1, "%d", &pixelBack.green);
            fscanf(fp1, "%d", &pixelBack.blue);

            if (front[i][j].blue >= minBlue && front[i][j].blue <= maxBlue && front[i][j].red >= minRed && front[i][j].red <= maxRed && front[i][j].green >= minGreen && front[i][j].green <= maxGreen)
            {
                front[i][j].red = pixelBack.red;
                front[i][j].blue = pixelBack.blue;
                front[i][j].green = pixelBack.green;
            }
        }
        for (int x = larguraFront; x < larguraBack; x++)
        {
            fscanf(fp1, "%d", &lixo);
            fscanf(fp1, "%d", &lixo);
            fscanf(fp1, "%d", &lixo);
        }
    }
    return front;
}

imagem **frontNoBack(FILE *fp1, FILE *fp2, int alturaBack, int larguraBack, int alturaFront, int larguraFront, int minRed, int maxRed, int minBlue, int maxBlue, int minGreen, int maxGreen)
{
    imagem **back;
    imagem pixelFront;
    int centroAltura, centroLargura;

    back = (imagem **)malloc(alturaBack * sizeof(imagem *));

    centroAltura = (alturaBack / 2) - (alturaFront / 2);
    centroLargura = (larguraBack / 2) - (larguraFront / 2);

    for (int i = 0; i < alturaBack; i++)
    {
        back[i] = (imagem *)malloc(larguraBack * sizeof(imagem));
        for (int j = 0; j < larguraBack; j++)
        {
            fscanf(fp1, "%d", &back[i][j].red);
            fscanf(fp1, "%d", &back[i][j].green);
            fscanf(fp1, "%d", &back[i][j].blue);
            if (i >= centroAltura && i < (alturaFront + centroAltura) && j >= centroLargura && j < (larguraFront + centroLargura))
            {
                fscanf(fp2, "%d", &pixelFront.red);
                fscanf(fp2, "%d", &pixelFront.green);
                fscanf(fp2, "%d", &pixelFront.blue);

                if (!(pixelFront.blue >= minBlue && pixelFront.blue <= maxBlue && pixelFront.red >= minRed && pixelFront.red <= maxRed && pixelFront.green >= minGreen && pixelFront.green <= maxGreen))
                {
                    back[i][j].red = pixelFront.red;
                    back[i][j].blue = pixelFront.blue;
                    back[i][j].green = pixelFront.green;
                }
            }
        }
    }
    return back;
}

void finalImprime(FILE *fp1, FILE *fp2, int altura, int largura, int maxBranco, char tipo[], imagem **output)
{

    FILE *fp3;
    char caminhoFinal[900];

    fclose(fp1);
    fclose(fp2);

    printf("\nInforme o caminho final do resultado ");
    scanf("%[^\n]s", caminhoFinal);
    limpaBuffer();

    fp3 = fopen(caminhoFinal, "w");

    fprintf(fp3, "%s\n", tipo);
    fprintf(fp3, "%d %d\n", largura, altura);
    fprintf(fp3, "%d\n", maxBranco);

    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            fprintf(fp3, "%d %d %d ", output[i][j].red, output[i][j].green, output[i][j].blue);
        }
        fprintf(fp3, "\n");
    }

    fclose(fp3);

    for (int i = 0; i < altura; i++)
    {
        free(output[i]);
    }
    free(output);
}

/*void auxiliar(char front[], char back[]){
    FILE *fp4;
    fp4 = fopen("C:\\Users\\Murilo\\Desktop\\CG\\ChromaKey2\\nomesImg.txt", "w");

    fprintf(fp4, "%s\n%s\n", front, back);
    fclose(fp4);
}*/