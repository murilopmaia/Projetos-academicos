#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int r, g, b;
} RGB;

FILE *abrir_arquivo(const char *filename, const char *mode) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        printf("Erro ao abrir o arquivo: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    return file;
}

void ler_cabecalho(FILE *file, int *width, int *height) {
    char magic_number[3];
    fscanf(file, "%2s", magic_number);

    if (strcmp(magic_number, "P3") != 0) {
        printf("Formato de arquivo PPM não suportado.\n");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d %d", width, height);

    int max_intensity;
    fscanf(file, "%d", &max_intensity);
}

RGB **ler_imagem(FILE *file, int width, int height) {
    RGB **imagem = (RGB **)malloc(height * sizeof(RGB *));
    if (imagem == NULL) {
        printf("Falha na alocacao de memoria para imagem\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < height; i++) {
        imagem[i] = (RGB *)malloc(width * sizeof(RGB));
        if (imagem[i] == NULL) {
            printf("Falha na alocacao de memoria para linha %d\n", i);
            exit(EXIT_FAILURE);
        }
        for (int j = 0; j < width; j++) {
            fscanf(file, "%d", &imagem[i][j].r);
            fscanf(file, "%d", &imagem[i][j].g);
            fscanf(file, "%d", &imagem[i][j].b);
        }
    }

    return imagem;
}

RGB **chromakey(RGB **mat_f, RGB **mat_b, int width_f, int height_f, int width_b, int height_b, int min_r, int max_r, int min_g, int max_g, int min_b, int max_b) {
    RGB **resultado = malloc(height_f * sizeof(RGB *));
    if (resultado == NULL) {
        printf("Falha na alocacao de memoria para o resultado\n");
        exit(EXIT_FAILURE);
    }
      for (int i = 0; i < height_f; i++) {
        resultado[i] = (RGB*)malloc(width_f * sizeof(RGB));
        if (resultado[i] == NULL) {
            printf("Falha na alocacao de memoria para linha %d do resultado\n", i);
            exit(EXIT_FAILURE);
        }
        for (int j = 0; j < width_f; j++) {
            if (mat_f[i][j].r >= min_r && mat_f[i][j].r <= max_r &&
                mat_f[i][j].g >= min_g && mat_f[i][j].g <= max_g &&
                mat_f[i][j].b >= min_b && mat_f[i][j].b <= max_b) {
                resultado[i][j].r = mat_b[i][j].r;
                resultado[i][j].g = mat_b[i][j].g;
                resultado[i][j].b = mat_b[i][j].b;
            } else {
                resultado[i][j].r = mat_f[i][j].r;
                resultado[i][j].g = mat_f[i][j].g;
                resultado[i][j].b = mat_f[i][j].b;
            }
        }
    }
    return resultado;
}

void salvar_imagem(const char *filename, RGB **imagem, int width, int height) {
    FILE *file = abrir_arquivo(filename, "w");
    fprintf(file, "P3\n%d %d\n255\n", width, height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(file, "%d %d %d ", imagem[i][j].r, imagem[i][j].g, imagem[i][j].b);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}
void escreverImagemPNM(const char* filename, RGB** imagem, int largura, int altura) {
    FILE* arquivo = fopen(filename, "w");
    if (!arquivo) {
        printf("Não foi possível criar o arquivo.\n");
        return;
    }
}

int main() {
    int width_front, height_front, width_back, height_back;
    int min_r, max_r, min_g, max_g, min_b, max_b;
    char fundo[100], frente[100];

    printf("Digite o nome do fundo: ");
    scanf("%[^\n]s", fundo);
    scanf("%*[^\n]");
    scanf("%*c");
    printf("Digite o nome da frente: ");
    scanf("%[^\n]s", frente);
    scanf("%*[^\n]");
    scanf("%*c");

    printf("Digite o valor mínimo de vermelho: ");
    scanf("%d", &min_r);
    printf("Digite o valor máximo de vermelho: ");
    scanf("%d", &max_r);
    printf("Digite o valor mínimo de verde: ");
    scanf("%d", &min_g);
    printf("Digite o valor máximo de verde: ");
    scanf("%d", &max_g);
    printf("Digite o valor mínimo de azul: ");
    scanf("%d", &min_b);
    printf("Digite o valor máximo de azul: ");
    scanf("%d", &max_b);

    FILE *arquivo_front = abrir_arquivo(frente, "r");
    FILE *arquivo_fundo = abrir_arquivo(fundo, "r");

    ler_cabecalho(arquivo_front, &width_front, &height_front);
    ler_cabecalho(arquivo_fundo, &width_back, &height_back);

    RGB **mat_f = ler_imagem(arquivo_front, width_front, height_front);
    RGB **mat_b = ler_imagem(arquivo_fundo, width_back, height_back);

  
    RGB **resultado = chromakey(mat_f, mat_b, width_front, height_front, width_back, height_back, min_r, max_r, min_g, max_g, min_b, max_b);

    salvar_imagem("C:\\Users\\Murilo\\Desktop\\CG\\ChromaKey2\\outputJulia.pnm", resultado, width_front, height_front);

  //escreverImagemPNM("C:\\Users\\Murilo\\Desktop\\CG\\ChromaKey2\\outputJulia.pnm", resultado, width_front, height_front);
  
    // Liberando a memória alocada
    for (int i = 0; i < height_front; i++) {
        free(mat_f[i]);
        free(mat_b[i]);
        free(resultado[i]);
    }
    free(mat_f);
    free(mat_b);
    free(resultado);

    fclose(arquivo_front);
    fclose(arquivo_fundo);

    return 0;
}