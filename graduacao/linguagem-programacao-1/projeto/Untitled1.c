#include <stdio.h>
#define linha 20
#define coluna 96
#define red "\x01b[41;1m"
#define reset "\x1b[0m"
#define blue "\x01b[44;1m"
#define fundo "\x01b[47;1m"
int main (void){
    char labirito[linha][coluna] ={
                             "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
                             "@  @  @  @   @   @  @  @  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @",
                             "@                                                                                          @  @",
                             "@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @@@@@@@@@@@@@@@@@@@@@@@@@@  @@  @@@@@@@@@@@@@@@@@@@@@@@  @@  @  @",
                             "@                             @                     @     @@  @                     @  @@  @  @",
                             "@ @@@@@@@@@@@@@@@@@@@@@@@@@@  @  xxxxxxxxxxxxxxx    @     xx  @  @  xxxxxxxxxxxxxxx @  @@  @  @",
                             "@ @                           @  xxxxxxxxxxxxxxx    @     xx  @  @  xxxxxxxxxxxxxxx @  @@  @  @",
                             "@ @ @@@@ @@@@@  @  @  @       @  xx                  @    xx  @  @  xx              @      @  @",
                             "@ @ @        @  @  @  @       @  xx@@@@@@@@@@@@@@@@@ @    xx  @  @  xx@@@@@@@@@@@@  @@@@@  @@@@",
                             "@ @ @        @  @  @  @       @  xx                  @    xx  @  @  xS                        @",
                             "@ @ @@@@@@@  @  @  @  @       @  xx @@@@@@@@@@@@@@@@ @@@@@xx  @  @  xx@@@@@@@@@@@@@@@@@@@@@@  @",
                             "@         @  @  @  @  @@@@@@@@@  xx                @      xx  @@@@  xx                     @  @",
                             "@ @@@@@@@ @  @  @  @             xxxxxxxxxxxxxxx   @      xx        xxxxxxxxxxxxxxx        @  @",
                             "@ @     @ @  @  @  @@@@@@@@@@@@@@xxxxxxxxxxxxxxx   @ @@@@@xx@@@@@@@@xxxxxxxxxxxxxxx        @  @",
                             "@       @ @  @  @                                                                          @  @",
                             "@@@@@@@@@ @  @  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @",
                             "@                                                                                             @",
                             "@ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
                             "@V@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
                             "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"};
    int i,j,x,y;
    char seta, star;
    char nick[50];

    printf("informe o seu nick: ");
    scanf("%[^\n]s",nick);
    scanf("%*[^\n]");
    scanf("%*c");


   do{
    printf("\n\tpara sair clique = f\n\n");
    for(i=0;i<linha;i++){
        printf("\n\t\t");
        for(j=0;j<coluna;j++){
            if(labirito[i][j] == 'x'){
                printf(blue"\x01b[34;1mx"reset);
                continue;
            }
            else
                if(labirito[i][j] == 'V'){
                    x = i;
                    y = j;
                    printf(red"\x01b[31;1m+"reset);
                }
                else
                    if(labirito[i][j] == 'S'){
                        printf(red"S"reset);
                    }
                    else
                        if(labirito[i][j] == '@'){
                            printf(fundo"."reset);
                        }
                        else{
                            printf("%c",labirito[i][j]);
                        }

        }
    }
    scanf("%c",&seta);
    scanf("%*[^\n]");
    scanf("%*c");
    if(seta == 'd' || seta == 'D'){
        if(labirito[x][y+1] == '@' || labirito[x][y+1] == 'x'){
                printf("\n\timpossivel passar parede");
                scanf("%c",&star);
                scanf("%*[^\n]");
                scanf("%*c");
                system("clear||cls");
        }
        else{
            labirito[x][y] = ' ';
            labirito[x][y+1]= 'V';
        }
    }
    else
        if(seta == 'w'|| seta == 'W'){
            if(labirito[x-1][y] == '@' || labirito[x-1][y] == 'x'){
                printf("\n\timpossivel passar parede");
                scanf("%c",&star);
                scanf("%*[^\n]");
                scanf("%*c");
                system("clear||cls");
            }
            else{
                labirito[x][y] = ' ';
                labirito[x-1][y]= 'V';
            }
        }
        else
            if(seta == 'a'|| seta == 'A'){
                if(labirito[x][y-1] == '@' || labirito[x][y-1] == 'x'){
                    printf("\n\timpossivel passar parede");
                    scanf("%c",&star);
                    scanf("%*[^\n]");
                    scanf("%*c");
                    system("clear||cls");
                }
                else{
                    labirito[x][y] = ' ';
                    labirito[x][y-1]= 'V';
                }
            }
            else
                if(seta == 's' || seta == 'S'){
                    if(labirito[x +1][y] == '@' || labirito[x + 1][y] == 'x'){
                        printf("\n\timpossivel passar parede");
                        scanf("%c",&star);
                        scanf("%*[^\n]");
                        scanf("%*c");
                        system("clear||cls");

                    }
                    else{
                        labirito[x][y] = ' ';
                        labirito[x+1][y]= 'V';
                    }
                }

    system("clear||cls");

   }
   while(seta!='f');



    return 0;
}
