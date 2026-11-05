#include<time.h>
#include<stdio.h>
#define ANSI_COLOR_RED  "\x1b[31m" //cores em ANSI utilizadas
#define ANSI_COLOR_RESET   "\x1b[0m"
#include <locale.h>

int main(void)
{   setlocale (LC_ALL,"pt_BR.UTF-8"); // importa as variáveis de ambiente
  // setlocale (LC_CTYPE, "en_BR.UTF-8"); // por via das dúvidas ,ou

// setlocale (LC_CTYPE, "en_BR.UTF-8"); // não lembro se é no UTF do Brasil ou americano...
    int x,y; //Onde x é a linha da matriz e y é a coluna.
    char  comando, posx, posy;
    char mapa[15][14]={
      {3,1,1,11,3,1,1,1,1,5,0,3,1,5},
      {2,0,0,0,2,0,0,0,0,2,0,2,0,2},
      {2,0,2,0,4,1,1,0,1,10,0,4,0,2},
      {2,0,2,0,0,0,0,0,0,2,0,0,0,2},
      {2,0,4,1,1,1,1,5,0,9,1,5,0,2},
      {2,0,0,0,0,0,0,2,0,2,0,2,0,2},
      {9,1,7,1,1,1,1,6,0,2,0,0,0,2},
      {2,0,2,0,0,0,0,0,0,2,0,2,0,2},
      {2,0,2,0,3,1,1,1,0,2,0,2,0,2},
      {2,0,2,0,2,0,0,0,0,2,0,2,0,2},
      {2,0,2,0,4,1,1,1,1,8,1,6,0,2},
      {2,0,0,0,0,0,0,0,0,0,0,0,0,2},
      {2,0,3,1,1,1,1,1,1,1,0,1,1,10},
      {2,0,2,0,0,0,0,0,0,0,0,0,0,2},
      {4,1,8,1,1,1,1,1,1,1,1,1,1,6}};

    printf("\tBEM VINDO\n");

     do
    {



    for(x=0;x<15;x++){
        printf("   ");
        for(y=0;y<14;y++){
                if(mapa[x][y] == 11){
                    printf(ANSI_COLOR_RED"\u2689"ANSI_COLOR_RESET);
                    posx=x;
                    posx=x;
                    posy=y;
                }
                else switch(mapa[x][y]){
                        case 0: printf(" "); break;         // Espaço em branco
                        case 1: printf("\u2551"); break;   // Barra horizontal
                        case 2: printf("\u2503"); break;    // Barra vertical
                        case 3: printf("\u250f"); break;    // curva esqueda cima
                        case 4: printf("\u02517"); break;   // curva esquerda baixo
                        case 5: printf("\u2513"); break;   // curva direita cima
                        case 6: printf("\u251b"); break;   // curva direita baixo
                        case 7: printf("\u2533"); break;   // T pra baixo
                        case 8: printf("\u253b"); break;   // T pra cima
                        case 9: printf("\u2523"); break;   // T pra direita
                        case 10: printf("\u252b"); break;  // T pra esquerda

                }
        }
        printf("\n");
    }

     scanf("%c",&comando);
     scanf("%*[^\n]");
     scanf("%*c");

    if (comando=='d'){
        mapa[posx][posy]=0;

        if(mapa[posx][posy+1]==0)
            mapa[posx][posy+1]=11;

        else {
            mapa[posx][posy]=11;
            printf("\t\tOUTCH!!!\n\tVoce bateu em uma parede!\n Aperte ENTER novamente para continuar...");
            scanf("%*[^\n]");
            scanf("%*c");
        }
    }

    if (comando=='w'){
            mapa[posx][posy]=0;

        if(mapa[posx-1][posy]==0)
            mapa[posx-1][posy]=11;

        else {
            mapa[posx][posy]=11;
            printf("\t\tOUTCH!!!\n\tVoce bateu em uma parede!\n Aperte ENTER novamente para continuar...");
            scanf("%*[^\n]");
            scanf("%*c");
        }
    }

    if (comando=='s'){
            mapa[posx][posy]=0;

        if(mapa[posx+1][posy]==0)
            mapa[posx+1][posy]=11;

        else {
            mapa[posx][posy]=11;
            printf("\t\tOUTCH!!!\n\tVoce bateu em uma parede!\n Aperte ENTER novamente para continuar...");
            scanf("%*[^\n]");
            scanf("%*c");
        }
    }

    if (comando=='a'){
            mapa[posx][posy]=0;

        if(mapa[posx][posy-1]==0)
            mapa[posx][posy-1]=11;

        else {
            mapa[posx][posy]=11;
            printf("\t\tOUTCH!!!\n\tVoce bateu em uma parede!\n Aperte ENTER novamente para continuar...");
            scanf("%*[^\n]");
            scanf("%*c");
        }
    }

    system("clear||cls");

    } while (mapa[0][10]!=11);

    return 0;
}
