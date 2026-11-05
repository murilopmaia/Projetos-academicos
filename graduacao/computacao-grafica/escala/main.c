#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int R;
    int G;
    int B;
} RGB;

void limpaBuffer(void);
RGB **alocarMatriz(int x, int y);
RGB **lendoImagem(int *altura, int *largura, int *branco, char topo[]);
void vizinho1(RGB **imagem, RGB **output, int altura, int largura, float m, float n);
void vizinho4(RGB **imagem, RGB **output, int altura, int largura, float m, float n);
void escrevendoImagem(RGB **outputV1, RGB **outputV4, int altura, int largura, char topo[], int branco);
void limpandoMatriz(RGB **imagem, int altura);

int main(void)
{
    RGB **imagem;
    RGB **outputV1;
    RGB **outputV4;
    char topo[100];
    int largura, altura;
    int branco;
    float m, n;
    int newLagura, newAltura;

    // Lendo a imagem original
    imagem = lendoImagem(&altura, &largura, &branco, topo);

    // Lendo os valores de m e n
    do
    {
        printf("\nInforme m: ");
        scanf("%f", &m);
        limpaBuffer();
        if (m <= 0)
        {
            printf("\nDigite um valor maior que 0");
        }
    } while (m <= 0);

    do
    {
        printf("\nInforme n: ");
        scanf("%f", &n);
        limpaBuffer();
        if (n <= 0)
        {
            printf("\nDigite um valor maior que 0");
        }
    } while (n <= 0);

    // Definindo as novas alturas e larguras
    newAltura = (int)altura * m;
    newLagura = (int)largura * n;

    // alocando espaço para as duas matrizes
    outputV1 = alocarMatriz(newAltura, newLagura);
    outputV4 = alocarMatriz(newAltura, newLagura);

    // Executando o algoritmo
    vizinho1(imagem, outputV1, newAltura, newLagura, m, n);
    vizinho4(imagem, outputV4, newAltura, newLagura, m, n);

    // Escrevendo o resultado
    escrevendoImagem(outputV1, outputV4, newAltura, newLagura, topo, branco);

    // Limpando as matrizes
    limpandoMatriz(imagem, altura);
    limpandoMatriz(outputV1, newAltura);
    limpandoMatriz(outputV4, newAltura);

    return 0;
}

void limpaBuffer(void)
{
    scanf("%*[^\n]");
    scanf("%*c");
}

RGB **alocarMatriz(int x, int y)
{
    RGB **imagem;

    imagem = (RGB **)malloc(x * sizeof(RGB *));

    for (int i = 0; i < x; i++)
    {
        imagem[i] = (RGB *)malloc(y * sizeof(RGB));
    }

    return imagem;
}

RGB **lendoImagem(int *altura, int *largura, int *branco, char topo[])
{
    char caminho[999];
    FILE *fp;
    RGB **imagem;

    printf("Informe o caminho da imagem: ");
    scanf("%[^\n]s", caminho);
    limpaBuffer();

    fp = fopen(caminho, "r");

    if (fp == NULL)
    {
        printf("Arquivo nao aberto");
        exit(0);
    }

    fscanf(fp, "%s", topo);
    fscanf(fp, "%d %d", largura, altura);
    fscanf(fp, "%d", branco);

    imagem = (RGB **)malloc(*altura * sizeof(RGB *));

    for (int i = 0; i < *altura; i++)
    {
        imagem[i] = (RGB *)malloc(*largura * sizeof(RGB));
        for (int j = 0; j < *largura; j++)
        {
            fscanf(fp, "%d %d %d", &imagem[i][j].R, &imagem[i][j].G, &imagem[i][j].B);
        }
    }

    fclose(fp);
    return imagem;
}

void vizinho1(RGB **imagem, RGB **output, int altura, int largura, float m, float n)
{
    int i_div_m;
    int j_div_n;
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            i_div_m = (int)i / m;
            j_div_n = (int)j / n;
            output[i][j].R = imagem[i_div_m][j_div_n].R;
            output[i][j].G = imagem[i_div_m][j_div_n].G;
            output[i][j].B = imagem[i_div_m][j_div_n].B;
        }
    }
}

void vizinho4(RGB **imagem, RGB **output, int altura, int largura, float m, float n)
{
    int somaR;
    int somaG;
    int somaB;
    int qtd;
    float valX = m - 1;
    float valY = n - 1;
    int i_div_m;
    int j_div_n;
    int valx_div_m;
    int valy_div_n;
    int alt_div_m = (int)altura / m;
    int larg_div_n = (int)largura / n;

    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            qtd = 1;
            valx_div_m = (int)(i + valX) / m;
            valy_div_n = (int)(j + valY) / n;
            i_div_m = (int)i / m;
            j_div_n = (int)j / n;

            somaR = imagem[i_div_m][j_div_n].R;
            somaG = imagem[i_div_m][j_div_n].G;
            somaB = imagem[i_div_m][j_div_n].B;

            if (valx_div_m < alt_div_m)
            {
                somaR += imagem[valx_div_m][j_div_n].R;
                somaG += imagem[valx_div_m][j_div_n].G;
                somaB += imagem[valx_div_m][j_div_n].B;
                qtd++;
            }

            if (valy_div_n < larg_div_n)
            {
                somaR += imagem[i_div_m][valy_div_n].R;
                somaG += imagem[i_div_m][valy_div_n].G;
                somaB += imagem[i_div_m][valy_div_n].B;
                qtd++;
            }

            if (valx_div_m < alt_div_m && valy_div_n < larg_div_n)
            {
                somaR += imagem[valx_div_m][valy_div_n].R;
                somaG += imagem[valx_div_m][valy_div_n].G;
                somaB += imagem[valx_div_m][valy_div_n].B;
                qtd++;
            }

            output[i][j].R = (int)somaR / qtd;
            output[i][j].G = (int)somaG / qtd;
            output[i][j].B = (int)somaB / qtd;
        }
    }
}

void escrevendoImagem(RGB **outputV1, RGB **outputV4, int altura, int largura, char topo[], int branco)
{
    char caminho[999];
    FILE *fp1;
    FILE *fp2;

    printf("\nInforme o caminho da 1-vizinhaca: ");
    scanf("%[^\n]s", caminho);
    limpaBuffer();

    fp1 = fopen(caminho, "w");

    printf("\nInforme o caminho da 4-vizinhaca: ");
    scanf("%[^\n]s", caminho);
    limpaBuffer();

    fp2 = fopen(caminho, "w");

    if (fp1 == NULL || fp2 == NULL)
    {
        printf("Erro na escrita");
        exit(0);
    }

    fprintf(fp1, "%s\n", topo);
    fprintf(fp1, "%d %d\n", largura, altura);
    fprintf(fp1, "%d\n", branco);

    fprintf(fp2, "%s\n", topo);
    fprintf(fp2, "%d %d\n", largura, altura);
    fprintf(fp2, "%d\n", branco);

    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            fprintf(fp1, "%d %d %d ", outputV1[i][j].R, outputV1[i][j].G, outputV1[i][j].B);
            fprintf(fp2, "%d %d %d ", outputV4[i][j].R, outputV4[i][j].G, outputV4[i][j].B);
        }
        fprintf(fp1, "\n");
        fprintf(fp2, "\n");
    }

    fclose(fp1);
    fclose(fp2);
}

void limpandoMatriz(RGB **imagem, int altura)
{
    for (int i = 0; i < altura; i++)
    {
        free(imagem[i]);
    }
    free(imagem);
}