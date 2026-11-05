#define CSVSIZE 17000
typedef struct{
    int ID;
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
}Games;


Games* carregaDados(char *fileName, int *tam);

Games* IniciaLista(int capacidade);

void limpaJogos(Games *jogos, int tam);

void limpaJogos02(Games *jogos, int Pos);

int buscaPorId(int ID, Games* lista, int *tam);

int incJogo(Games jogos, Games* jogos02, int* tam);

int remJogo(Games jogo, Games* jogos02, int* tam);

int buscaBinPorId(int ID, Games *lista, int tamanho);

int remJogoOrdenado(Games jogo, Games* jogos03, int* tam);

int incJogoOrdenado(Games jogo, Games* jogos03, int* tam);

int buscaBinRecPorId(int ID, Games *lista, int ini, int fim);