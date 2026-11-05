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

struct NoGame{
  Games jogo;
  struct NoGame *prox;
};

typedef struct NoGame TNoGame;
typedef TNoGame* PNoGame;

typedef struct{
  PNoGame ini;
  PNoGame fim;
  int tam;
}FilaEnc;



//Funções usadas para a demonstração:

Games* carregaDados(char *fileName, int *tam);
Games* IniciaLista(int capacidade);
FilaEnc* iniFilaEnc();
int insereNaFila(Games jogo,FilaEnc *fila);
void imprimeFila(FilaEnc *fila);
void limpaJogo(Games *jogo); 

//Funções, usadas e modificadas para o dataSet, da questão 5:

PNoGame alocaNoGame();
void cpyGame(Games jogo, Games* jogo_copia);
void destoiNoGame(PNoGame p);

//Funcões da Questão 5:

int insereMeio(Games jogo, FilaEnc*fila);
Games* removeMeio(FilaEnc*fila);