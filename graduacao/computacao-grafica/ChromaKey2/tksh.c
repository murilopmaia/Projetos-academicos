#include <stdio.h>
#include <stdlib.h>

#define BAND_MIN 0
#define BAND_MAX 255

typedef struct
{
    int red;
    int green;
    int blue;
} Pixel;

typedef struct
{
    char type[2];
    int width;
    int height;
    int maxValue;
} ImageProperties;

Pixel **get_image(char *, char *, int *, int *, int *);
void compare_resolutions(ImageProperties, ImageProperties);
void apply_chromaKey(Pixel **, Pixel **, ImageProperties, Pixel, Pixel);
void write_image(Pixel **, ImageProperties);

int main()
{
    Pixel **background, **foreground, minValues, maxValues;
    ImageProperties bg, fg;
    char bgFilename[20], fgFilename[20];

    // Ler nome do arquivo background
    printf("Digite o nome do arquivo do background: ");
    scanf("%[^\n]s", bgFilename);
    scanf("%*c");
    background = get_image(bgFilename, bg.type, &bg.width, &bg.height, &bg.maxValue);

    // Ler nome do arquivo foreground
    printf("Digite o nome do arquivo do foreground: ");
    scanf("%[^\n]s", fgFilename);
    scanf("%*c");
    foreground = get_image(fgFilename, fg.type, &fg.width, &fg.height, &fg.maxValue);

    // Comparar resoluções
    compare_resolutions(bg, fg);

    // Ler valores mínimos e máximos da banda
    printf("Digite o valor minimo para RED: ");
    scanf("%d%*c", &minValues.red);
    printf("Digite o valor maximo para RED: ");
    scanf("%d%*c", &maxValues.red);

    printf("Digite o valor minimo para GREEN: ");
    scanf("%d%*c", &minValues.green);
    printf("Digite o valor maximo para GREEN: ");
    scanf("%d%*c", &maxValues.green);

    printf("Digite o valor minimo para BLUE: ");
    scanf("%d%*c", &minValues.blue);
    printf("Digite o valor maximo para BLUE: ");
    scanf("%d%*c", &maxValues.blue);
    // minValues.red = 0;
    // maxValues.red = 100;
    // minValues.green = 100;
    // maxValues.green = 190;
    // minValues.blue = 40;
    // maxValues.blue = 90;

    // Aplicar algoritmo
    apply_chromaKey(background, foreground, fg, minValues, maxValues);

    // Imprimir imagem
    write_image(foreground, fg);
    printf("Imagem gerada: final.ppm.\n");

    // free
    for (int i = 0; i < bg.height; i++)
        free(background[i]);
    free(background);
    // free
    for (int i = 0; i < fg.height; i++)
        free(foreground[i]);
    free(foreground);
}

/* Ler imagens foreground e background */
Pixel **get_image(char *filename, char *type, int *width, int *height, int *maxValue)
{
    // Abrir arquivo
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Erro: Falha ao abrir arquivo.\n");
        exit(1);
    }

    // Ler cabeçalho
    fscanf(file, "%s\n", type);
    fscanf(file, "%d %d\n", width, height);
    fscanf(file, "%d\n", maxValue);

    // Validação do tipo de arquivo
    if (!(type[0] == 'P' && type[1] == '3'))
    {
        printf("Erro: Formato PPM nao suportado. Utilize um arquivo de formato P3.\n");
        exit(1);
    }

    // Alocar memória para matriz
    Pixel **image = (Pixel **)malloc(*height * sizeof(Pixel *));
    if (image == NULL)
    {
        printf("Erro: Falha ao alocar memoria (row).\n");
        exit(1);
    }

    for (int i = 0; i < *height; i++)
    {
        image[i] = (Pixel *)malloc(*width * sizeof(Pixel));
        if (image[i] == NULL)
        {
            printf("Erro: Falha ao alocar memoria (column).\n");
            exit(1);
        }
    }

    // Ler imagem
    for (int i = 0; i < *height; i++)
    {
        for (int j = 0; j < *width; j++)
        {
            fscanf(file, "%d ", &image[i][j].red);
            fscanf(file, "%d ", &image[i][j].green);
            fscanf(file, "%d ", &image[i][j].blue);
        }
    }

    fclose(file);

    return image;
}

/* Comparar resoluções */
void compare_resolutions(ImageProperties bg, ImageProperties fg)
{
    if (fg.height > bg.height || fg.width > bg.width)
    {
        printf("Erro: Dimensoes da imagem do background deve ser maior ou igual a imagem do foreground.\n");
        exit(1);
    }
}

/* Substituir pixels dentro da faixa da imagem de foreground pela imagem de background */
void apply_chromaKey(Pixel **background, Pixel **foreground, ImageProperties fg, Pixel minValues, Pixel maxValues)
{
    // Algoritmo da faixa
    for (int i = 0; i < fg.height; i++)
    {
        for (int j = 0; j < fg.width; j++)
        {
            if (foreground[i][j].red >= minValues.red && foreground[i][j].red <= maxValues.red &&
                foreground[i][j].green >= minValues.green && foreground[i][j].green <= maxValues.green &&
                foreground[i][j].blue >= minValues.blue && foreground[i][j].blue <= maxValues.blue)
            {
                foreground[i][j].red = background[i][j].red;
                foreground[i][j].green = background[i][j].green;
                foreground[i][j].blue = background[i][j].blue;
            }
        }
    }
}

/* Escrever imagem */
void write_image(Pixel **image, ImageProperties img)
{
    FILE *file = fopen("final.ppm", "w");
    if (file == NULL)
    {
        printf("Erro: falha ao escrever arquivo.");
        exit(1);
    }

    fprintf(file, "%s\n", img.type);
    fprintf(file, "%d %d\n", img.width, img.height);
    fprintf(file, "%d\n", img.maxValue);
    for (int i = 0; i < img.height; i++)
    {
        for (int j = 0; j < img.width; j++)
        {
            fprintf(file, "%d ", image[i][j].red);
            fprintf(file, "%d ", image[i][j].green);
            fprintf(file, "%d ", image[i][j].blue);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}