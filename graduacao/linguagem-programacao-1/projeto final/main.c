
// Murilo Patricio Maia

#include <stdio.h>
#define linha 20
#define coluna 96
#define TAM 50
#define vida_max 100
#define vida_ext 25
#define dano_combo 15
#define fundo_red "\x01b[41;1m"
#define fundo_verde "\x001b[42m"
#define fundo_amarelo "\x001b[43m"
#define reset "\x1b[0m"
#define fundo_blue "\x01b[44;1m"
#define fundo_branco "\x01b[47;1m"
#define fundo_magenta "\x001b[45m"
#define red "\x01b[31;1m"
#define blue "\x01b[34;1m"
#define amarelo "\x01b[33;1m"
#define verde "\x01b[32;1m"
#define roxo "\x01b[35;1m"
#define tempo_max 999999999 //Tempo para aparecer os chefes na tela

int main (void){
    char labirito[linha][coluna] ={
                             "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
                             "@@h@@t@@h@@h@@@@h@@g@@h@h@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @",
                             "@                          k                                                               @  @",
                             "@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @@@@@@@@@@@@@@@@@@@@@@@@@@  @@  @@@@@@@@@@@@@@@@@@@@@@@  @@  @  @",
                             "@                             @                           @@  @                     @  @@  @  @",
                             "@ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@  xxxxxxxxxxxxxxx    @     xx  @  @  xxxxxxxxxxxxxxx @  @@  @  @",
                             "@ @          @                @  xxxxxxxxxxxxxxx    @@    xx  @  @  xxxxxxxxxxxxxxx @  @@  @  @",
                             "@ @ @@@@ @@@@@  @  @  @       @  xx                  @    xx  @  @  xxu             @      @ n@",
                             "@ @ @        @  @  @  @       @  xx@@@@@@@@@@@@@@@@@ @    xx  @  @  xx@@@@@@@@@@@@  @@@@@  @@@@",
                             "@ @ @u       @  @  @  @       @  xx                  @u   xx  @  @  xS                        @",
                             "@ @ @@@@@@@  @  @  @  @   c   @  xx @@@@@@@@@@@@@@@@ @@@@@xx  @ m@  xx@@@@@@@@@@@@@@@@@@@@@@  @",
                             "@         @  @  @  @  @@@@@@@@@  xxz               @      xx  @@@@  xxb                    @  @",
                             "@ @@@@@@@ @  @  @  @             xxxxxxxxxxxxxxx   @     uxx        xxxxxxxxxxxxxxx        @  @",
                             "@ @     @ @  @  @  @@@@@@@@@@@@@@xxxxxxxxxxxxxxx   @ @@@@@xx@@@@@@@@xxxxxxxxxxxxxxx        @  @",
                             "@      q@ @  @  @                                                                          @  @",
                             "@@@@@@@@@ @  @  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@u@@  @",
                             "@                                                                                         @@ l@",
                             "@E@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
                             "@V@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
                             "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"};
    char i,j,x,y,vida = 100,habilidades,nota = 0,cont,fim;
    int classe,dano_perto_basico=25,dano_longe_basico=25,dano_chefe,escudo_basico,dano_perto_assasino=35,dano_longe_atirador=35,escudo_tank,dano_tank = 20,combo1,combo2,combo3,vida_chefe,tempo;
    char seta;
    char nick[TAM];
    system("clear||cls");
    printf("\t\t   hello - hola - ola - annyeonghaseyo - salut\n\n"); // Menu incial com instruções basicas
    printf("\t\t-----------Como jogar o joguinho"red " <3" reset "--------------\n");
    printf("\t\t"red "W"reset "- para mover o personagem para cima\n\t\t"amarelo "S"reset "- para mover o personagem para baixo\n\t\t"verde "D"reset "- para mover o personagem para a direita\n\t\t" blue"A"reset "- para mover o personagem para a esquerda\n\n");
    printf(roxo"\t\t\t\tBoa sorte!!!  "reset);
    scanf("%*[^\n]");
    scanf("%*c");
    printf("\n\n\t\t por favor,informe o seu nick para iniciar" red" S2: "reset);
    scanf("%[^\n]s",nick);
    scanf("%*[^\n]");
    scanf("%*c");
    system("clear||cls");
    printf("\n\n\n\t\t\t----------------------------------------------"blue"Introducao"reset"--------------------------------------------------------------"// sobre o jogo
           "\n\n\t\t\tBem vindo ao RPG - "red "terror na faculdade"reset " o objetivo do joguinho eh simples:"
            "\n\t\t\tconclua a sua faculdade com a " roxo"sanidade mental intacta"reset" , e eh claro deves ter pelo menos uma " amarelo "media 7" reset " Rs"
            "\n\t\t\tas notas voce vai conseguir aniquilando os "verde"Chefes"reset" (materias)"
            "\n\t\t\tmas relaxe, voce vai "amarelo"encontrar momentos de pausa(ou nao)"reset" durante o caminho,mas cuidado sua sanidade nao passa de 100"
            "\n\t\t\tFique espertx, os chefes"verde" irao aparecer rapidamente"reset", grave-os e cace-os !!!" );
    printf("\n\n\n\t\t\t----------------------------------------------"blue"Classes"reset"--------------------------------------------------------------"
           "\n\n\t\t\tO jogo tem um sistema de classes,escolha com sabedoria:"
           "\n\n\t\t\t"red"Mago"reset" - Drena a vida do chefe ao abate-lo"
           "\n\t\t\t"amarelo"Assasino"reset" - Ataques corpo a corpo causam mais dano"
           "\n\t\t\t"blue"Atirador"reset" - Ataques a distacia causam mais dano"
           "\n\t\t\t"roxo"Tank"reset" - Bloqueios tambem devolvem dano ao chefe");
    scanf("%*[^\n]");
    scanf("%*c");
    system("clear||cls");

    printf("\n\tpara sair clique = f"); // printf do labirinto temporario, onde estara visiveis os chefes
    printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
    printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

        
    for(i=0;i<linha;i++){
        printf("\n\t\t");
        for(j=0;j<coluna;j++){
              if(labirito[i][j] == 'x'){
                 printf(fundo_blue blue" "reset);
                   continue;
              }
              else
                if(labirito[i][j] == 'V'){
                     x = i;
                     y = j;
                    printf(fundo_red red" "reset);
                }
                else
                    if(labirito[i][j] == 'S'){
                        printf(fundo_red red"S"reset);
                    }
                     else
                        if(labirito[i][j] == '@'){
                            printf(fundo_branco" "reset);
                        }
                        else
                            if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                    printf(fundo_magenta" "reset);
                                                    
                                                    
                            }
                            else{
                                printf(" ");
                            }
        }
    }
    for(tempo=0;tempo<tempo_max;tempo++){}
    system("clear||cls");

   do{ 

        printf("\n\tpara sair clique = f"); // printf do labirinto quando o personagem andar
        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

        for(i=0;i<linha;i++){
            printf("\n\t\t");
            for(j=0;j<coluna;j++){
                if(labirito[i][j] == 'x'){
                    printf(fundo_blue blue" "reset);
                    continue;
                }
                else
                    if(labirito[i][j] == 'V'){
                        x = i;
                        y = j;
                        printf(fundo_red red" "reset);
                    }
                    else
                        if(labirito[i][j] == 'S'){
                            printf(fundo_red red"S"reset);
                        }
                        else
                            if(labirito[i][j] == '@'){
                                printf(fundo_branco" "reset);
                            }
                            else{
                                printf(" ");
                            }
            }
        }
        
        if(labirito[x][y+1] == 'E' || labirito[x-1][y] == 'E' || labirito[x][y-1] == 'E' ||labirito[x +1][y] == 'E' ){ // onde sera possivel escolher a classe do personagem
            do{
                    printf("\n\n\t Bem vindo invocador , por favor escolha sua classe:");
                    printf("\n\n\t "red"1"reset"-Mago \t "amarelo"2"reset"-Assasino\n\n\t "blue"3"reset"-Atirador \t "roxo"4"reset"-Tank\n");
                    scanf("%d",&classe);
                    scanf("%*[^\n]");
                    scanf("%*c");
                    if(classe != 1 && classe != 2 && classe != 3 && classe != 4){ // para aparecer a mensagem de erro de digitação
                        printf("\n\tDigite corretamente "red"player"reset", pressione qualquer tecla para continuar");
                        scanf("%*c");
                        system("clear||cls");
                        printf("\n\tpara sair clique = f");
                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                        for(i=0;i<linha;i++){
                            printf("\n\t\t");
                            for(j=0;j<coluna;j++){
                                if(labirito[i][j] == 'x'){
                                    printf(fundo_blue blue" "reset);
                                    continue;
                                }
                                else
                                    if(labirito[i][j] == 'V'){
                                        x = i;
                                        y = j;
                                        printf(fundo_red red" "reset);
                                    }
                                    else
                                        if(labirito[i][j] == 'S'){
                                            printf(fundo_red red"S"reset);
                                        }
                                        else
                                            if(labirito[i][j] == '@'){
                                                printf(fundo_branco" "reset);
                                            }
                                                else{
                                                    printf(" ");
                                                }
            
                                            
                            }
                        }
                        continue;
                    }
                    printf("\n\tclasse escolhida ,"verde"prossiga"reset); // mensagem de confirmação
            }
            while(classe != 1 && classe != 2 && classe != 3 && classe != 4);

        }
        else
            if(labirito[x][y+1] == 'q' || labirito[x-1][y] == 'q' || labirito[x][y-1] == 'q' ||labirito[x +1][y] == 'q' ){//caso chegue perto deste chefe acontecerá isso
                vida_chefe = 100;
                system("clear||cls");
                printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Logica"reset);
                printf("\n\n\t\t\tLogica eh um Boss que gosta de fugir muito(as vezes nem vem) , ataques a distancia talvez seja a melhor escolha");

                switch(classe){
                    case 1: //chefe contra a classe mago
                        combo1 = 0;
                        combo2 = 0;
                            do{
                                system("clear||cls");
                                printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Logica"reset); //introdução sobre o chefe e sobre a classe escolhida, jutamente com suas habilidades
                                printf("\n\n\t\t\tLogica eh um Boss que gosta de fugir muito(as vezes nem vem) , ataques a distancia talvez seja a melhor escolha");
                                printf("\n\n\t\t\tHabilidades da classe "amarelo"Mago"reset" : "amarelo"i"reset" - Soco da mae Fenix|| "amarelo"o"reset" - Raio destruidor de sinapses neurais||  "amarelo"p"reset" - escudo de gelo verdadeiro ");
                                printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                printf("\n\n\t\t\tLogica meteu um argumento melhor que o seu");
                                dano_chefe = 5;
                                vida = vida - dano_chefe;//o personagem recebe dano
                                escudo_basico=(dano_chefe*0.4); //o escudo varia com o dano que o chefe causa
                                printf("\n\n\t\t\tLance sua habilidade!!! ");
                                scanf("%c",&habilidades);
                                scanf("%*[^\n]");
                                scanf("%*c");
                                switch(habilidades){
                                        case 'i': printf("\n\n\t\t\tvoce usou o Soco da mae fenix, " red"pouco eficaz"reset);
                                                  combo1++;
                                                  if(combo1%2 == 0){
                                                    printf("\n\t\t\t\t"red"COMBO!!"reset); //caso o jogador preesione  2 vezes a mesma habildade em sequencia causa um dano extra
                                                    vida_chefe = vida_chefe - dano_perto_basico + 20 - dano_combo;
                                                  }
                                                  else{
                                                    vida_chefe = vida_chefe - dano_perto_basico + 20;
                                                  }
                                                  combo2 =0;
                                                  scanf("%*[^\n]");
                                                  scanf("%*c");
                                                  break;
                                        case 'o' : printf("\n\n\t\t\tvoce usou o Raio destruidor de sinapses neurais, "red"extremamente eficaz!!!"reset); //este chefe recebe mais dano a distancia, por isso o -35
                                                   combo2++;
                                                   if(combo2%2 == 0){
                                                     printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                     vida_chefe = vida_chefe - dano_longe_basico - 35 - dano_combo;
                                                   }
                                                   else{
                                                     vida_chefe = vida_chefe - dano_longe_basico - 35;
                                                   }
                                                   combo1 = 0;
                                                   scanf("%*[^\n]");
                                                   scanf("%*c");
                                                   break;
                                        case 'p' : printf("\n\n\t\t\tvoce usou o escudo de gelo verdadeiro, "red"bloqueou parte do proximo ataque do chefe"reset);
                                                   vida = vida + escudo_basico;
                                                   combo1 = 0;
                                                   combo2 = 0;
                                                   scanf("%*[^\n]");
                                                   scanf("%*c");
                                                   break;
                                        default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , sem segunda chance ;-;");// se o jogador preesionar algum botão errado ele nao terá outra chance
                                                 scanf("%*[^\n]");
                                                 scanf("%*c");

                                        }
                                labirito[14][7] = ' ';// retira o chefe da matriz
                                if(vida<=0){ // printa a tela de derrota
                                    system("clear||cls");
                                    for(i=0;i<linha;i++){
                                        printf("\n\t\t");
                                        for(j=0;j<coluna;j++){
                                            if(labirito[i][j] == 'x'){
                                                printf(fundo_branco" "reset);
                                                continue;
                                            }
                                            else
                                                if(labirito[i][j] == 'V'){
                                                    x = i;
                                                    y = j;
                                                    printf(fundo_red red" "reset);
                                                }
                                                else
                                                    if(labirito[i][j] == 'S'){
                                                        printf(fundo_red red"S"reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == '@'){
                                                            printf(fundo_red red" "reset);
                                                        }
                                                        else{
                                                            printf(" ");
                                                        }
                                        }
                                    }
                                    printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                    fim = 1;//condição para finalizar o jogo
                                    break;
                                }
                                if(vida_chefe<=0){ // retorna ao labirinto, printando primeiro o labirinto temporario e depois o labirinto em si
                                    for(cont=1;vida <vida_max;cont++){ // a classe mago recupera sanidade ao matar o chefe, esta parte nao permite a sanidade passar de 100
                                        vida++;
                                        if(cont == vida_ext){
                                            break;
                                        }
                                    }
                                    nota = nota + 1; // aumenta a nota do jogador
                                    printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                    scanf("%*[^\n]");
                                    scanf("%*c");
                                    system("clear||cls");
                                    
                                    printf("\n\tpara sair clique = f"); // print do labirinto temporario
                                    printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                    printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                    
                                    for(i=0;i<linha;i++){
                                        printf("\n\t\t");
                                        for(j=0;j<coluna;j++){
                                            if(labirito[i][j] == 'x'){
                                                printf(fundo_blue blue" "reset);
                                                continue;
                                            }
                                            else
                                                if(labirito[i][j] == 'V'){
                                                    x = i;
                                                    y = j;
                                                    printf(fundo_red red" "reset);
                                                }
                                                else
                                                    if(labirito[i][j] == 'S'){
                                                        printf(fundo_red red"S"reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == '@'){
                                                            printf(fundo_branco" "reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                    printf(fundo_magenta" "reset);
                                                                                    
                                                                                    
                                                            }
                                                            else{
                                                                printf(" ");
                                                            }
                                        }
                                    }
                                    for(tempo=0;tempo<tempo_max;tempo++){}
                                    system("clear||cls");

                                    printf("\n\tpara sair clique = f"); // printa novamente o labirinto para nao dar tela preta antes de andar
                                    printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                    printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                    for(i=0;i<linha;i++){
                                        printf("\n\t\t");
                                        for(j=0;j<coluna;j++){
                                            if(labirito[i][j] == 'x'){
                                                printf(fundo_blue blue" "reset);
                                                continue;
                                            }
                                            else
                                                if(labirito[i][j] == 'V'){
                                                    x = i;
                                                    y = j;
                                                    printf(fundo_red red" "reset);
                                                }
                                                else
                                                    if(labirito[i][j] == 'S'){
                                                        printf(fundo_red red"S"reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == '@'){
                                                            printf(fundo_branco" "reset);
                                                        }
                                                        else{
                                                            printf(" ");
                                                        }
                                        }
                                    }


                                    break;
                                }

                            }
                            while(vida > 0 || vida_chefe>0);
                            break;
                    case 2://chefe contra a classe assasino
                        combo1 = 0;
                        combo2 = 0;
                            do{
                                system("clear||cls");
                                printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Logica"reset);// introdução sobre o chefe e as habilidades da classe escolhida
                                printf("\n\n\t\t\tLogica eh um Boss que gosta de fugir muito(as vezes nem vem) , ataques a distancia talvez seja a melhor escolha");
                                printf("\n\n\t\t\tHabilidades da classe "amarelo"Assasino"reset" : "amarelo"i"reset" - Ataque armageddon|| "amarelo"o"reset" - shurikens flamejantes||  "amarelo"p"reset" - Fuga canibal ");
                                printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                printf("\n\n\t\t\tLogica meteu um argumento melhor que o seu");
                                dano_chefe = 5;
                                vida = vida - dano_chefe;
                                escudo_basico=(dano_chefe*0.4);//o escudo varia com a quantidade de dano do chefe
                                printf("\n\n\t\t\tLance sua habilidade!!! ");
                                scanf("%c",&habilidades);
                                scanf("%*[^\n]");
                                scanf("%*c");
                                switch(habilidades){
                                        case 'i': printf("\n\n\t\t\tvoce usou o Ataque armageddon, " red"pouco eficaz"reset);
                                                  combo1++;
                                                  if(combo1%2 ==0){
                                                    printf("\n\t\t\t\t"red"COMBO!!"reset);//se a pessoa usar a mesma habilidade 2 vezes seguidas ela causara mais dano
                                                    vida_chefe = vida_chefe - dano_perto_assasino + 20 - dano_combo;
                                                  }
                                                  else{
                                                    vida_chefe = vida_chefe - dano_perto_assasino + 20;
                                                  }
                                                  combo2 =0;
                                                  scanf("%*[^\n]");
                                                  scanf("%*c");
                                                  break;
                                        case 'o' : printf("\n\n\t\t\tvoce usou shurikens flamejantes, "red"extremamente eficaz!!!"reset);//este chefe recebe mais dano de ataques a distancia, por isso o -35
                                                   combo2++;
                                                   if(combo2%2 == 0){
                                                    printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                    vida_chefe = vida_chefe - dano_longe_basico - 35 - dano_combo;
                                                   }
                                                   else{
                                                    vida_chefe = vida_chefe - dano_longe_basico - 35;
                                                   }
                                                   combo1 = 0;
                                                   scanf("%*[^\n]");
                                                   scanf("%*c");
                                                   break;
                                        case 'p' : printf("\n\n\t\t\tvoce usou Fuga canibal, "red"bloqueou parte do proximo ataque do chefe"reset);
                                                   vida = vida + escudo_basico;
                                                   combo1 = 0;
                                                   combo2 =0;
                                                   scanf("%*[^\n]");
                                                   scanf("%*c");
                                                   break;
                                        default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , sem segunda chance ;-;");
                                                 scanf("%*[^\n]");
                                                 scanf("%*c");

                                        }
                                labirito[14][7] = ' ';//retira o chefe daquela localização
                                if(vida<=0){
                                    system("clear||cls");
                                    for(i=0;i<linha;i++){ //printa a tela de derrota
                                        printf("\n\t\t");
                                        for(j=0;j<coluna;j++){
                                            if(labirito[i][j] == 'x'){
                                                printf(fundo_branco" "reset);
                                                continue;
                                            }
                                            else
                                                if(labirito[i][j] == 'V'){
                                                    x = i;
                                                    y = j;
                                                    printf(fundo_red red" "reset);
                                                }
                                                else
                                                    if(labirito[i][j] == 'S'){
                                                        printf(fundo_red red"S"reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == '@'){
                                                            printf(fundo_red red" "reset);
                                                        }
                                                        else{
                                                            printf(" ");
                                                        }
                                        }
                                    }
                                    printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                    fim = 1;//condição para finalizar o jogo 
                                    break;
                                }
                                if(vida_chefe<=0){//printa o labirinto temporario e o labirinto original
                                    nota = nota + 1;
                                    printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                    scanf("%*[^\n]");
                                    scanf("%*c");
                                    system("clear||cls");
                                    printf("\n\tpara sair clique = f");
                                    printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                    printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                    
                                    for(i=0;i<linha;i++){
                                        printf("\n\t\t");
                                        for(j=0;j<coluna;j++){
                                            if(labirito[i][j] == 'x'){
                                                printf(fundo_blue blue" "reset);
                                                continue;
                                            }
                                            else
                                                if(labirito[i][j] == 'V'){
                                                    x = i;
                                                    y = j;
                                                    printf(fundo_red red" "reset);
                                                }
                                                else
                                                    if(labirito[i][j] == 'S'){
                                                        printf(fundo_red red"S"reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == '@'){
                                                            printf(fundo_branco" "reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                    printf(fundo_magenta" "reset);
                                                                                    
                                                                                    
                                                            }
                                                            else{
                                                                printf(" ");
                                                            }
                                        }
                                    }
                                    for(tempo=0;tempo<tempo_max;tempo++){}
                                    system("clear||cls");

                                    printf("\n\tpara sair clique = f");
                                    printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                    printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                    for(i=0;i<linha;i++){
                                        printf("\n\t\t");
                                        for(j=0;j<coluna;j++){
                                            if(labirito[i][j] == 'x'){
                                                printf(fundo_blue blue" "reset);
                                                continue;
                                            }
                                            else
                                                if(labirito[i][j] == 'V'){
                                                    x = i;
                                                    y = j;
                                                    printf(fundo_red red" "reset);
                                                }
                                                else
                                                    if(labirito[i][j] == 'S'){
                                                        printf(fundo_red red"S"reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == '@'){
                                                            printf(fundo_branco" "reset);
                                                        }
                                                        else{
                                                            printf(" ");
                                                        }
                                        }
                                    }


                                    break;
                                }

                            }
                            while(vida > 0 || vida_chefe>0);
                            break;
                    case 3://chefe contra a classe atirador
                        combo1 = 0;
                        combo2 = 0;
                            do{
                                system("clear||cls");
                                printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Logica"reset);//introdução sobre o chefe e as habilidades da classe escolhida
                                printf("\n\n\t\t\tLogica eh um Boss que gosta de fugir muito(as vezes nem vem) , ataques a distancia talvez seja a melhor escolha");
                                printf("\n\n\t\t\tHabilidades da classe "amarelo"Atirador"reset" : "amarelo"i"reset" - Perfuracao eletrizante|| "amarelo"o"reset" - Mata-Craquens||  "amarelo"p"reset" - Arco-escudo ");
                                printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                printf("\n\n\t\t\tLogica meteu um argumento melhor que o seu");
                                dano_chefe = 5;
                                vida = vida - dano_chefe;
                                escudo_basico=(dano_chefe*0.4);// a quantidade de escudo varia com o dano do chefe
                                printf("\n\n\t\t\tLance sua habilidade!!! ");
                                scanf("%c",&habilidades);
                                scanf("%*[^\n]");
                                scanf("%*c");
                                switch(habilidades){
                                        case 'i': printf("\n\n\t\t\tvoce usou Perfuracao eletrizante, " red"pouco eficaz"reset);
                                                  combo1++;
                                                  if(combo1%2 == 0){
                                                    printf("\n\t\t\t\t"red"COMBO!!"reset);//se a pessoa usar a mesma habilidade 2 vezes seguidas ela causa mais dano
                                                    vida_chefe = vida_chefe - dano_perto_basico + 20 - dano_combo;
                                                  }
                                                  else{
                                                    vida_chefe = vida_chefe - dano_perto_basico + 20;
                                                  }
                                                  combo2 = 0;
                                                  scanf("%*[^\n]");
                                                  scanf("%*c");
                                                  break;
                                        case 'o' : printf("\n\n\t\t\tvoce usou Mata-Craquens, "red"extremamente eficaz!!!"reset);//o chefe recebe menos dano de ataques a distancia, por isso o - 35
                                                   combo2++;
                                                   if(combo2%2 == 0){
                                                    printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                    vida_chefe = vida_chefe - dano_longe_atirador - 35 - dano_combo;
                                                   }
                                                   else{
                                                    vida_chefe = vida_chefe - dano_longe_atirador - 35;
                                                   }
                                                   combo1 = 0;
                                                   scanf("%*[^\n]");
                                                   scanf("%*c");
                                                   break;
                                        case 'p' : printf("\n\n\t\t\tvoce usou Arco-escudo, "red"bloqueou parte do proximo ataque do chefe"reset);
                                                   vida = vida + escudo_basico;
                                                   combo1 = 0;
                                                   combo2 =0;
                                                   scanf("%*[^\n]");
                                                   scanf("%*c");
                                                   break;
                                        default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , sem segunda chance ;-;");
                                                 scanf("%*[^\n]");
                                                 scanf("%*c");

                                        }
                                labirito[14][7] = ' ';//retira o chefe da matriz
                                if(vida<=0){
                                    system("clear||cls");
                                    for(i=0;i<linha;i++){//printa a tela de derrota
                                        printf("\n\t\t");
                                        for(j=0;j<coluna;j++){
                                            if(labirito[i][j] == 'x'){
                                                printf(fundo_branco" "reset);
                                                continue;
                                            }
                                            else
                                                if(labirito[i][j] == 'V'){
                                                    x = i;
                                                    y = j;
                                                    printf(fundo_red red" "reset);
                                                }
                                                else
                                                    if(labirito[i][j] == 'S'){
                                                        printf(fundo_red red"S"reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == '@'){
                                                            printf(fundo_red red" "reset);
                                                        }
                                                        else{
                                                            printf(" ");
                                                        }
                                        }
                                    }
                                    printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                    fim = 1;//condição para finalizar o jogo ao ser derrotado
                                    break;
                                }
                                if(vida_chefe<=0){ // printa o labirinto temporario e o labirinto original
                                    nota = nota + 1;
                                    printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                    scanf("%*[^\n]");
                                    scanf("%*c");
                                    system("clear||cls");
                                    printf("\n\tpara sair clique = f");
                                    printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                    printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                    
                                    for(i=0;i<linha;i++){
                                        printf("\n\t\t");
                                        for(j=0;j<coluna;j++){
                                            if(labirito[i][j] == 'x'){
                                                printf(fundo_blue blue" "reset);
                                                continue;
                                            }
                                            else
                                                if(labirito[i][j] == 'V'){
                                                    x = i;
                                                    y = j;
                                                    printf(fundo_red red" "reset);
                                                }
                                                else
                                                    if(labirito[i][j] == 'S'){
                                                        printf(fundo_red red"S"reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == '@'){
                                                            printf(fundo_branco" "reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                    printf(fundo_magenta" "reset);
                                                                                    
                                                                                    
                                                            }
                                                            else{
                                                                printf(" ");
                                                            }
                                        }
                                    }
                                    for(tempo=0;tempo<tempo_max;tempo++){}
                                    system("clear||cls");

                                    printf("\n\tpara sair clique = f");
                                    printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                    printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                    for(i=0;i<linha;i++){
                                        printf("\n\t\t");
                                        for(j=0;j<coluna;j++){
                                            if(labirito[i][j] == 'x'){
                                                printf(fundo_blue blue" "reset);
                                                continue;
                                            }
                                            else
                                                if(labirito[i][j] == 'V'){
                                                    x = i;
                                                    y = j;
                                                    printf(fundo_red red" "reset);
                                                }
                                                else
                                                    if(labirito[i][j] == 'S'){
                                                        printf(fundo_red red"S"reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == '@'){
                                                            printf(fundo_branco" "reset);
                                                        }
                                                        else{
                                                            printf(" ");
                                                        }
                                        }
                                    }


                                    break;
                                }

                            }
                            while(vida > 0 || vida_chefe>0);
                            break;
                    case 4://chefe contra aa classe tank
                        combo1 = 0;
                        combo2 = 0;
                        combo3 = 0;
                            do{
                                system("clear||cls");
                                printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Logica"reset);//introdução sobre o chefe e as habilidades da classe escolhida
                                printf("\n\n\t\t\tLogica eh um Boss que gosta de fugir muito(as vezes nem vem) , ataques a distancia talvez seja a melhor escolha");
                                printf("\n\n\t\t\tHabilidades da classe "amarelo"Tank"reset" : "amarelo"i"reset" - Golpe de escudo fermentado|| "amarelo"o"reset" - Chuva de rochedos||  "amarelo"p"reset" - colete milenar de espinhos cerimoniais ");
                                printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                printf("\n\n\t\t\tLogica meteu um argumento melhor que o seu");
                                dano_chefe = 5;
                                vida = vida - dano_chefe;
                                escudo_basico=(dano_chefe*0.4);//a quantidade de escudo depende do dano causado pelo chefe
                                escudo_tank=(dano_chefe*0.8);// o tank tem a porcentagem de escudo maior
                                printf("\n\n\t\t\tLance sua habilidade!!! ");
                                scanf("%c",&habilidades);
                                scanf("%*[^\n]");
                                scanf("%*c");
                                switch(habilidades){
                                        case 'i': printf("\n\n\t\t\tvoce usou Golpe de escudo fermentado, " red"pouco eficaz"reset);//o chefe recebe menos dano de ataques de perto, por isso o +20
                                                   combo1++;
                                                  if(combo1%2 == 0){
                                                    printf("\n\t\t\t\t"red"COMBO!!"reset);//se o jogador usar a mesma habilidade 2 vezes seguidas ela causa mais dano
                                                    vida_chefe = vida_chefe - dano_perto_basico + 20 - dano_combo;
                                                  }
                                                  else{
                                                    vida_chefe = vida_chefe - dano_perto_basico + 20;
                                                  }
                                                  combo2 = 0;
                                                  combo3 = 0;
                                                  scanf("%*[^\n]");
                                                  scanf("%*c");
                                                  break;
                                        case 'o' : printf("\n\n\t\t\tvoce usou Chuva de rochedos, "red"extremamente eficaz!!!"reset);//este chefe recebe mais dano de ataques a distancia por isso o -35
                                                   combo2++;
                                                   if(combo2%2 == 0){
                                                    printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                    vida_chefe = vida_chefe - dano_longe_basico - 35 - dano_combo;
                                                    }
                                                    else{
                                                        vida_chefe = vida_chefe - dano_longe_basico - 35;
                                                    }
                                                   combo1 = 0;
                                                   combo3 = 0;
                                                   scanf("%*[^\n]");
                                                   scanf("%*c");
                                                   break;
                                        case 'p' : printf("\n\n\t\t\tvoce usou colete milenar de espinhos cerimoniais, "red"bloqueou grande parte do proximo ataque do chefe e aplicou dano refletor"reset);
                                                   combo3++;
                                                   if(combo3 > 2){//o tank nao pode usar o escudo toda hora, se ele usar 2 vezes seguidas o proximo escudo sera contato como um escudo normal
                                                    printf("\n\t\t\t\t"red"Escudo quebrado!!"reset);
                                                    vida = vida + escudo_basico;
                                                   }
                                                   else{
                                                    vida = vida + escudo_tank;
                                                    vida_chefe = vida_chefe - dano_tank;
                                                   }
                                                   combo2 = 0;
                                                   combo1 = 0;

                                                   scanf("%*[^\n]");
                                                   scanf("%*c");
                                                   break;
                                        default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , sem segunda chance ;-;");
                                                 scanf("%*[^\n]");
                                                 scanf("%*c");

                                        }
                                labirito[14][7] = ' ';//retira este chefe da matriz
                                if(vida<=0){
                                    system("clear||cls");
                                    for(i=0;i<linha;i++){//printa a tela de derrota para o jogador
                                        printf("\n\t\t");
                                        for(j=0;j<coluna;j++){
                                            if(labirito[i][j] == 'x'){
                                                printf(fundo_branco" "reset);
                                                continue;
                                            }
                                            else
                                                if(labirito[i][j] == 'V'){
                                                    x = i;
                                                    y = j;
                                                    printf(fundo_red red" "reset);
                                                }
                                                else
                                                    if(labirito[i][j] == 'S'){
                                                        printf(fundo_red red"S"reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == '@'){
                                                            printf(fundo_red red" "reset);
                                                        }
                                                        else{
                                                            printf(" ");
                                                        }
                                        }
                                    }
                                    printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                    fim = 1;
                                    break;
                                }
                                if(vida_chefe<=0){//printa o labirinto temporario e o labirinto original
                                    nota = nota + 1;
                                    printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                    scanf("%*[^\n]");
                                    scanf("%*c");
                                    system("clear||cls");
                                    printf("\n\tpara sair clique = f");
                                    printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                    printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                    
                                    for(i=0;i<linha;i++){
                                        printf("\n\t\t");
                                        for(j=0;j<coluna;j++){
                                            if(labirito[i][j] == 'x'){
                                                printf(fundo_blue blue" "reset);
                                                continue;
                                            }
                                            else
                                                if(labirito[i][j] == 'V'){
                                                    x = i;
                                                    y = j;
                                                    printf(fundo_red red" "reset);
                                                }
                                                else
                                                    if(labirito[i][j] == 'S'){
                                                        printf(fundo_red red"S"reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == '@'){
                                                            printf(fundo_branco" "reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                    printf(fundo_magenta" "reset);
                                                                                    
                                                                                    
                                                            }
                                                            else{
                                                                printf(" ");
                                                            }
                                        }
                                    }
                                    for(tempo=0;tempo<tempo_max;tempo++){}
                                    system("clear||cls");

                                    printf("\n\tpara sair clique = f");
                                    printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                    printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                    for(i=0;i<linha;i++){
                                        printf("\n\t\t");
                                        for(j=0;j<coluna;j++){
                                            if(labirito[i][j] == 'x'){
                                                printf(fundo_blue blue" "reset);
                                                continue;
                                            }
                                            else
                                                if(labirito[i][j] == 'V'){
                                                    x = i;
                                                    y = j;
                                                    printf(fundo_red red" "reset);
                                                }
                                                else
                                                    if(labirito[i][j] == 'S'){
                                                        printf(fundo_red red"S"reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == '@'){
                                                            printf(fundo_branco" "reset);
                                                        }
                                                        else{
                                                            printf(" ");
                                                        }
                                        }
                                    }


                                    break;
                                }

                            }
                            while(vida > 0 || vida_chefe>0);
                            break;
                    }

            }
            else
                 if(labirito[x][y+1] == 'c' || labirito[x-1][y] == 'c' || labirito[x][y-1] == 'c' ||labirito[x +1][y] == 'c' ){//se o jogador estiver perto desse chefe ativara o mini-game
                    vida_chefe = 100;
                    system("clear||cls");
                    printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Ingles"reset);
                    printf("\n\n\t\t\tIngles eh um Chefe tranquilo, na dele,mas eh bom em desviar de ataques");

                    switch(classe){
                        case 1:
                            combo1 = 0;
                            combo2 = 0;
                                do{
                                    system("clear||cls");
                                    printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Ingles"reset);//introdução sobre o chefe junto com as habilidades da classe escolhida
                                    printf("\n\n\t\t\tIngles eh um Chefe tranquilo, na dele,mas eh bom em desviar de ataques");
                                    printf("\n\n\t\t\tHabilidades da classe "amarelo"Mago"reset" : "amarelo"i"reset" - Soco da mae Fenix|| "amarelo"o"reset" - Raio destruidor de sinapses neurais||  "amarelo"p"reset" - escudo de gelo verdadeiro ");
                                    printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                    printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                    printf("\n\n\t\t\tThe book is on the table");
                                    dano_chefe = 10;
                                    vida = vida - dano_chefe;
                                    escudo_basico=(dano_chefe*0.4);//a quntidade de escudo depende do dano do chefe
                                    printf("\n\n\t\t\tLance sua habilidade!!! ");
                                    scanf("%c",&habilidades);
                                    scanf("%*[^\n]");
                                    scanf("%*c");
                                    switch(habilidades){
                                            case 'i': printf("\n\n\t\t\tvoce usou o Soco da mae fenix, " red"Dano Normal"reset);
                                                      combo1++;
                                                      if(combo1%2 == 0){
                                                        printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                        vida_chefe = vida_chefe - dano_perto_basico - dano_combo;
                                                      }
                                                      else{
                                                        vida_chefe = vida_chefe - dano_perto_basico;
                                                      }
                                                      combo2 =0;
                                                      scanf("%*[^\n]");
                                                      scanf("%*c");
                                                      break;
                                            case 'o' : printf("\n\n\t\t\tvoce usou o Raio destruidor de sinapses neurais, "red"pouco eficaz!!!"reset);//este chefe recebe menos dano de ataque a distancia, por isso o +25
                                                       combo2++;
                                                       if(combo2%2 == 0){
                                                         printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                         vida_chefe = vida_chefe - dano_longe_basico + 25 - dano_combo;
                                                       }
                                                       else{
                                                         vida_chefe = vida_chefe - dano_longe_basico + 25;
                                                       }
                                                       combo1 = 0;
                                                       scanf("%*[^\n]");
                                                       scanf("%*c");
                                                       break;
                                            case 'p' : printf("\n\n\t\t\tvoce usou o escudo de gelo verdadeiro, "red"bloqueou parte do proximo ataque do chefe"reset);
                                                       vida = vida + escudo_basico;
                                                       combo1 = 0;
                                                       combo2 = 0;
                                                       scanf("%*[^\n]");
                                                       scanf("%*c");
                                                       break;
                                            default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , sem segunda chance ;-;");
                                                     scanf("%*[^\n]");
                                                     scanf("%*c");

                                            }
                                    labirito[10][26] = ' ';//retira o chefe da matriz
                                    if(vida<=0){
                                        system("clear||cls");
                                        for(i=0;i<linha;i++){
                                            printf("\n\t\t");
                                            for(j=0;j<coluna;j++){
                                                if(labirito[i][j] == 'x'){
                                                    printf(fundo_branco" "reset);
                                                    continue;
                                                }
                                                else
                                                    if(labirito[i][j] == 'V'){
                                                        x = i;
                                                        y = j;
                                                        printf(fundo_red red" "reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'S'){
                                                            printf(fundo_red red"S"reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == '@'){
                                                                printf(fundo_red red" "reset);
                                                            }
                                                            else{
                                                                printf(" ");
                                                            }
                                            }
                                        }
                                        printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                        fim = 1;//condição para finalizar o jogo
                                        break;
                                    }
                                    if(vida_chefe<=0){//prita o labirinto temporario e o labirinto original
                                        for(cont=1;vida<vida_max;cont++){//como a classe é mago, ele se cura depois de derrotar o chefe
                                            vida++;
                                            if(cont == vida_ext){
                                                break;
                                            }
                                        }
                                        nota = nota + 1;
                                        printf(amarelo"\n\n\t\t\tvoce derrotou o chefe ,%s, parabens "reset,nick);
                                        scanf("%*[^\n]");
                                        scanf("%*c");
                                        system("clear||cls");

                                        printf("\n\tpara sair clique = f");
                                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                        
                                        for(i=0;i<linha;i++){
                                            printf("\n\t\t");
                                            for(j=0;j<coluna;j++){
                                                if(labirito[i][j] == 'x'){
                                                    printf(fundo_blue blue" "reset);
                                                    continue;
                                                }
                                                else
                                                    if(labirito[i][j] == 'V'){
                                                        x = i;
                                                        y = j;
                                                        printf(fundo_red red" "reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'S'){
                                                            printf(fundo_red red"S"reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == '@'){
                                                                printf(fundo_branco" "reset);
                                                            }
                                                            else
                                                                if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                        printf(fundo_magenta" "reset);
                                                                                        
                                                                                        
                                                                }
                                                                else{
                                                                    printf(" ");
                                                                }
                                            }
                                        }
                                        for(tempo=0;tempo<tempo_max;tempo++){}
                                        system("clear||cls");

                                        printf("\n\tpara sair clique = f");
                                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                        for(i=0;i<linha;i++){
                                            printf("\n\t\t");
                                            for(j=0;j<coluna;j++){
                                                if(labirito[i][j] == 'x'){
                                                    printf(fundo_blue blue" "reset);
                                                    continue;
                                                }
                                                else
                                                    if(labirito[i][j] == 'V'){
                                                        x = i;
                                                        y = j;
                                                        printf(fundo_red red" "reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'S'){
                                                            printf(fundo_red red"S"reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == '@'){
                                                                printf(fundo_branco" "reset);
                                                            }
                                                            else{
                                                                printf(" ");
                                                            }
                                            }
                                        }


                                        break;
                                    }

                                }
                                while(vida > 0 || vida_chefe>0);
                                break;
                        case 2://chefe contra a classe assasino
                            combo1 = 0;
                            combo2 = 0;
                                do{
                                    system("clear||cls");
                                    printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Ingles"reset);// introdução sobre o chefe juntamente com as habilidades da classe escolhida
                                    printf("\n\n\t\t\tIngles eh um Chefe tranquilo, na dele,mas eh bom em desviar de ataques");
                                    printf("\n\n\t\t\tHabilidades da classe "amarelo"Assasino"reset" : "amarelo"i"reset" - Ataque armageddon|| "amarelo"o"reset" - shurikens flamejantes||  "amarelo"p"reset" - Fuga canibal ");
                                    printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                    printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                    printf("\n\n\t\t\tThe book is on the table");
                                    dano_chefe = 10;
                                    vida = vida - dano_chefe;
                                    escudo_basico=(dano_chefe*0.4);//a quantidade de escudo depende do dano do chefe
                                    printf("\n\n\t\t\tLance sua habilidade!!! ");
                                    scanf("%c",&habilidades);
                                    scanf("%*[^\n]");
                                    scanf("%*c");
                                    switch(habilidades){
                                            case 'i': printf("\n\n\t\t\tvoce usou o Ataque armageddon, " red"Dano Normal"reset);
                                                      combo1++;
                                                      if(combo1%2 ==0){
                                                        printf("\n\t\t\t\t"red"COMBO!!"reset);//quando o jogador usa a mesma habilidade 2 vezes seguidas ela causa mais dano
                                                        vida_chefe = vida_chefe - dano_perto_assasino - dano_combo;
                                                      }
                                                      else{
                                                        vida_chefe = vida_chefe - dano_perto_assasino;
                                                      }
                                                      combo2 =0;
                                                      scanf("%*[^\n]");
                                                      scanf("%*c");
                                                      break;
                                            case 'o' : printf("\n\n\t\t\tvoce usou shurikens flamejantes, "red"pouco eficaz!!!"reset);//esta classe recebe menos dano de ataques a distancia, por isso o +25
                                                       combo2++;
                                                       if(combo2%2 == 0){
                                                        printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                        vida_chefe = vida_chefe - dano_longe_basico + 25 - dano_combo;
                                                       }
                                                       else{
                                                        vida_chefe = vida_chefe - dano_longe_basico + 25;
                                                       }
                                                       combo1 = 0;
                                                       scanf("%*[^\n]");
                                                       scanf("%*c");
                                                       break;
                                            case 'p' : printf("\n\n\t\t\tvoce usou Fuga canibal, "red"bloqueou parte do proximo ataque do chefe"reset);
                                                       vida = vida + escudo_basico;
                                                       combo1 = 0;
                                                       combo2 =0;
                                                       scanf("%*[^\n]");
                                                       scanf("%*c");
                                                       break;
                                            default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , sem segunda chance ;-;");
                                                     scanf("%*[^\n]");
                                                     scanf("%*c");

                                            }
                                    labirito[10][26] = ' ';//retira o chefe da matriz
                                    if(vida<=0){
                                        system("clear||cls");
                                        for(i=0;i<linha;i++){
                                            printf("\n\t\t");
                                            for(j=0;j<coluna;j++){
                                                if(labirito[i][j] == 'x'){
                                                    printf(fundo_branco" "reset);
                                                    continue;
                                                }
                                                else
                                                    if(labirito[i][j] == 'V'){
                                                        x = i;
                                                        y = j;
                                                        printf(fundo_red red" "reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'S'){
                                                            printf(fundo_red red"S"reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == '@'){
                                                                printf(fundo_red red" "reset);
                                                            }
                                                            else{
                                                                printf(" ");
                                                            }
                                            }
                                        }
                                        printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                        fim = 1;//condição para finalizar o jogo
                                        break;
                                    }
                                    if(vida_chefe<=0){//prita o labirinto temporario, depois o labirinto original
                                        nota = nota + 1;
                                        printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                        scanf("%*[^\n]");
                                        scanf("%*c");
                                        system("clear||cls");

                                        printf("\n\tpara sair clique = f");
                                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                        
                                        for(i=0;i<linha;i++){
                                            printf("\n\t\t");
                                            for(j=0;j<coluna;j++){
                                                if(labirito[i][j] == 'x'){
                                                    printf(fundo_blue blue" "reset);
                                                    continue;
                                                }
                                                else
                                                    if(labirito[i][j] == 'V'){
                                                        x = i;
                                                        y = j;
                                                        printf(fundo_red red" "reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'S'){
                                                            printf(fundo_red red"S"reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == '@'){
                                                                printf(fundo_branco" "reset);
                                                            }
                                                            else
                                                                if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                        printf(fundo_magenta" "reset);
                                                                                        
                                                                                        
                                                                }
                                                                else{
                                                                    printf(" ");
                                                                }
                                            }
                                        }
                                        for(tempo=0;tempo<tempo_max;tempo++){}
                                        system("clear||cls");

                                        printf("\n\tpara sair clique = f");
                                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                        for(i=0;i<linha;i++){
                                            printf("\n\t\t");
                                            for(j=0;j<coluna;j++){
                                                if(labirito[i][j] == 'x'){
                                                    printf(fundo_blue blue" "reset);
                                                    continue;
                                                }
                                                else
                                                    if(labirito[i][j] == 'V'){
                                                        x = i;
                                                        y = j;
                                                        printf(fundo_red red" "reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'S'){
                                                            printf(fundo_red red"S"reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == '@'){
                                                                printf(fundo_branco" "reset);
                                                            }
                                                            else{
                                                                printf(" ");
                                                            }
                                            }
                                        }


                                        break;
                                    }

                                }
                                while(vida > 0 || vida_chefe>0);
                                break;
                        case 3: //chefe contra a classe atirador
                            combo1 = 0;
                            combo2 = 0;
                                do{
                                    system("clear||cls");
                                    printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Ingles"reset);//introdução sobre o chefe jutamente com as habilidades da classe escolhida
                                    printf("\n\n\t\t\tIngles eh um Chefe tranquilo, na dele,mas eh bom em desviar de ataques");
                                    printf("\n\n\t\t\tHabilidades da classe "amarelo"Atirador"reset" : "amarelo"i"reset" - Perfuracao eletrizante|| "amarelo"o"reset" - Mata-Craquens||  "amarelo"p"reset" - Arco-escudo ");
                                    printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                    printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                    printf("\n\n\t\t\tThe book is on the table");
                                    dano_chefe = 10;
                                    vida = vida - dano_chefe;
                                    escudo_basico=(dano_chefe*0.4); // a quantidade de escudo depende do dano do chefe
                                    printf("\n\n\t\t\tLance sua habilidade!!! ");
                                    scanf("%c",&habilidades);
                                    scanf("%*[^\n]");
                                    scanf("%*c");
                                    switch(habilidades){
                                            case 'i': printf("\n\n\t\t\tvoce usou Perfuracao eletrizante, " red"Dano Normal"reset);
                                                      combo1++;
                                                      if(combo1%2 == 0){
                                                        printf("\n\t\t\t\t"red"COMBO!!"reset);//se a pessoa usar a mesma habilidade 2 vezes seguidas ela causa dano extra
                                                        vida_chefe = vida_chefe - dano_perto_basico - dano_combo;
                                                      }
                                                      else{
                                                        vida_chefe = vida_chefe - dano_perto_basico ;
                                                      }
                                                      combo2 = 0;
                                                      scanf("%*[^\n]");
                                                      scanf("%*c");
                                                      break;
                                            case 'o' : printf("\n\n\t\t\tvoce usou Mata-Craquens, "red"pouco eficaz!!!"reset);//este chefe recebe menos dano de atqaues a distancia, por isso o +25
                                                       combo2++;
                                                       if(combo2%2 == 0){
                                                        printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                        vida_chefe = vida_chefe - dano_longe_atirador + 25 - dano_combo;
                                                       }
                                                       else{
                                                        vida_chefe = vida_chefe - dano_longe_atirador + 25;
                                                       }
                                                       combo1 = 0;
                                                       scanf("%*[^\n]");
                                                       scanf("%*c");
                                                       break;
                                            case 'p' : printf("\n\n\t\t\tvoce usou Arco-escudo, "red"bloqueou parte do proximo ataque do chefe"reset);
                                                       vida = vida + escudo_basico;
                                                       combo1 = 0;
                                                       combo2 =0;
                                                       scanf("%*[^\n]");
                                                       scanf("%*c");
                                                       break;
                                            default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , sem segunda chance ;-;");
                                                     scanf("%*[^\n]");
                                                     scanf("%*c");

                                            }
                                    labirito[10][26] = ' ';// retira o chefe da matriz
                                    if(vida<=0){//printa a tela de derrota
                                        system("clear||cls");
                                        for(i=0;i<linha;i++){
                                            printf("\n\t\t");
                                            for(j=0;j<coluna;j++){
                                                if(labirito[i][j] == 'x'){
                                                    printf(fundo_branco" "reset);
                                                    continue;
                                                }
                                                else
                                                    if(labirito[i][j] == 'V'){
                                                        x = i;
                                                        y = j;
                                                        printf(fundo_red red" "reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'S'){
                                                            printf(fundo_red red"S"reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == '@'){
                                                                printf(fundo_red red" "reset);
                                                            }
                                                            else{
                                                                printf(" ");
                                                            }
                                            }
                                        }
                                        printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                        fim = 1;//condiçao para finalizar o jogo
                                        break;
                                    }
                                    if(vida_chefe<=0){//printa o labirinto temporario e o orginal
                                        nota = nota + 1;
                                        printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                        scanf("%*[^\n]");
                                        scanf("%*c");
                                        system("clear||cls");

                                        printf("\n\tpara sair clique = f");
                                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                        
                                        for(i=0;i<linha;i++){
                                            printf("\n\t\t");
                                            for(j=0;j<coluna;j++){
                                                if(labirito[i][j] == 'x'){
                                                    printf(fundo_blue blue" "reset);
                                                    continue;
                                                }
                                                else
                                                    if(labirito[i][j] == 'V'){
                                                        x = i;
                                                        y = j;
                                                        printf(fundo_red red" "reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'S'){
                                                            printf(fundo_red red"S"reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == '@'){
                                                                printf(fundo_branco" "reset);
                                                            }
                                                            else
                                                                if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                        printf(fundo_magenta" "reset);
                                                                                        
                                                                                        
                                                                }
                                                                else{
                                                                    printf(" ");
                                                                }
                                            }
                                        }
                                        for(tempo=0;tempo<tempo_max;tempo++){}
                                        system("clear||cls");

                                        printf("\n\tpara sair clique = f");
                                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                        for(i=0;i<linha;i++){
                                            printf("\n\t\t");
                                            for(j=0;j<coluna;j++){
                                                if(labirito[i][j] == 'x'){
                                                    printf(fundo_blue blue" "reset);
                                                    continue;
                                                }
                                                else
                                                    if(labirito[i][j] == 'V'){
                                                        x = i;
                                                        y = j;
                                                        printf(fundo_red red" "reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'S'){
                                                            printf(fundo_red red"S"reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == '@'){
                                                                printf(fundo_branco" "reset);
                                                            }
                                                            else{
                                                                printf(" ");
                                                            }
                                            }
                                        }


                                        break;
                                    }

                                }
                                while(vida > 0 || vida_chefe>0);
                                break;
                        case 4:// chefe contra a classe tank
                            combo1 = 0;
                            combo2 = 0;
                            combo3 = 0;
                                do{
                                    system("clear||cls");
                                    printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Ingles"reset);//intodução sobre o chefe juntamente com as habilidades da classe escolhida
                                    printf("\n\n\t\t\tIngles eh um Chefe tranquilo, na dele,mas eh bom em desviar de ataques");
                                    printf("\n\n\t\t\tHabilidades da classe "amarelo"Tank"reset" : "amarelo"i"reset" - Golpe de escudo fermentado|| "amarelo"o"reset" - Chuva de rochedos||  "amarelo"p"reset" - colete milenar de espinhos cerimoniais ");
                                    printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                    printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                    printf("\n\n\t\t\tThe book is on the table");
                                    dano_chefe = 10;
                                    vida = vida - dano_chefe;
                                    escudo_basico=(dano_chefe*0.4);//a quantidade de escudo depende do dano do chefe
                                    escudo_tank=(dano_chefe*0.8);//o tank tem um escudo maior 
                                    printf("\n\n\t\t\tLance sua habilidade!!! ");
                                    scanf("%c",&habilidades);
                                    scanf("%*[^\n]");
                                    scanf("%*c");
                                    switch(habilidades){
                                            case 'i': printf("\n\n\t\t\tvoce usou Golpe de escudo fermentado, " red"Dano Normal"reset);
                                                      combo1++;
                                                      if(combo1%2 == 0){
                                                        printf("\n\t\t\t\t"red"COMBO!!"reset);//se o jogador usar a mesma habilidade 2 vezes seguidas ela causa dano extra
                                                        vida_chefe = vida_chefe - dano_perto_basico - dano_combo;
                                                      }
                                                      else{
                                                        vida_chefe = vida_chefe - dano_perto_basico;
                                                      }
                                                      combo2 = 0;
                                                      combo3 = 0;
                                                      scanf("%*[^\n]");
                                                      scanf("%*c");
                                                      break;
                                            case 'o' : printf("\n\n\t\t\tvoce usou Chuva de rochedos, "red"pouco eficaz!!!"reset);//este chefe recebe menos de ataques a distancia, por isso o +25
                                                       combo2++;
                                                       if(combo2%2 == 0){
                                                        printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                        vida_chefe = vida_chefe - dano_longe_basico + 25 - dano_combo;
                                                        }
                                                        else{
                                                            vida_chefe = vida_chefe - dano_longe_basico + 25;
                                                        }
                                                       combo1 = 0;
                                                       combo3 = 0;
                                                       scanf("%*[^\n]");
                                                       scanf("%*c");
                                                       break;
                                            case 'p' : printf("\n\n\t\t\tvoce usou colete milenar de espinhos cerimoniais, "red"bloqueou grande parte do proximo ataque do chefe e aplicou dano refletor"reset);
                                                       combo3++;
                                                        if(combo3 > 2){//o tank nao pode usar o mesmo escudo varias vezes, se ele usar 2 vezes seguidas ele sera tratado como um escudo normal
                                                            printf("\n\t\t\t\t"red"Escudo quebrado!!"reset);
                                                            vida = vida + escudo_basico;
                                                        }
                                                       else{
                                                            vida = vida + escudo_tank;
                                                            vida_chefe = vida_chefe - dano_tank;
                                                       }
                                                       combo2 = 0;
                                                       combo1 = 0;

                                                       scanf("%*[^\n]");
                                                       scanf("%*c");
                                                       break;
                                            default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , sem segunda chance ;-;");
                                                     scanf("%*[^\n]");
                                                     scanf("%*c");

                                            }
                                    labirito[10][26] = ' ';//retira o chefe da matriz
                                    if(vida<=0){//printa a tela de fim de jogo
                                        system("clear||cls");
                                        for(i=0;i<linha;i++){
                                            printf("\n\t\t");
                                            for(j=0;j<coluna;j++){
                                                if(labirito[i][j] == 'x'){
                                                    printf(fundo_branco" "reset);
                                                    continue;
                                                }
                                                else
                                                    if(labirito[i][j] == 'V'){
                                                        x = i;
                                                        y = j;
                                                        printf(fundo_red red" "reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'S'){
                                                            printf(fundo_red red"S"reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == '@'){
                                                                printf(fundo_red red" "reset);
                                                            }
                                                            else{
                                                                printf(" ");
                                                            }
                                            }
                                        }
                                        printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                        fim = 1;//condição para finalizar o jogo
                                        break;
                                    }
                                    if(vida_chefe<=0){//printa o labirinto temporario e o labirinto original
                                        nota = nota + 1;
                                        printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                        scanf("%*[^\n]");
                                        scanf("%*c");
                                        system("clear||cls");

                                        printf("\n\tpara sair clique = f");
                                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                        
                                        for(i=0;i<linha;i++){
                                            printf("\n\t\t");
                                            for(j=0;j<coluna;j++){
                                                if(labirito[i][j] == 'x'){
                                                    printf(fundo_blue blue" "reset);
                                                    continue;
                                                }
                                                else
                                                    if(labirito[i][j] == 'V'){
                                                        x = i;
                                                        y = j;
                                                        printf(fundo_red red" "reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'S'){
                                                            printf(fundo_red red"S"reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == '@'){
                                                                printf(fundo_branco" "reset);
                                                            }
                                                            else
                                                                if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                        printf(fundo_magenta" "reset);
                                                                                        
                                                                                        
                                                                }
                                                                else{
                                                                    printf(" ");
                                                                }
                                            }
                                        }
                                        for(tempo=0;tempo<tempo_max;tempo++){}
                                        system("clear||cls");

                                        printf("\n\tpara sair clique = f");
                                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                        for(i=0;i<linha;i++){
                                            printf("\n\t\t");
                                            for(j=0;j<coluna;j++){
                                                if(labirito[i][j] == 'x'){
                                                    printf(fundo_blue blue" "reset);
                                                    continue;
                                                }
                                                else
                                                    if(labirito[i][j] == 'V'){
                                                        x = i;
                                                        y = j;
                                                        printf(fundo_red red" "reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'S'){
                                                            printf(fundo_red red"S"reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == '@'){
                                                                printf(fundo_branco" "reset);
                                                            }
                                                            else{
                                                                printf(" ");
                                                            }
                                            }
                                        }


                                        break;
                                    }

                                }
                                while(vida > 0 || vida_chefe>0);
                                break;
                        }

                }
                else
                    if(labirito[x][y+1] == 'z' || labirito[x-1][y] == 'z' || labirito[x][y-1] == 'z' ||labirito[x +1][y] == 'z' ){ //se o perosonagem estiver perto do chefe o mini-game sera ativado

                    vida_chefe = 100;
                    system("clear||cls");
                    printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Fisica"reset);
                    printf("\n\n\t\t\tFisica é um grande sabio das artes obscuras(nao é atoa que so passa nesse curso 2/3 pessoas), ela se alimenta da defesa inimiga e se volta contra eles");

                    switch(classe){
                        case 1:
                            combo1 = 0;
                            combo2 = 0;
                                do{
                                    system("clear||cls");
                                    printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Fisica"reset);//introdução sobre o chefe, jutamente com as habilidades da classe escolhida
                                    printf("\n\n\t\t\tFisica eh um grande sabio das artes obscuras(nao eh atoa que so passa nesse curso 2/3 pessoas), ela se alimenta da defesa inimiga e se volta contra eles");
                                    printf("\n\n\t\t\tHabilidades da classe "amarelo"Mago"reset" : "amarelo"i"reset" - Soco da mae Fenix|| "amarelo"o"reset" - Raio destruidor de sinapses neurais||  "amarelo"p"reset" - escudo de gelo verdadeiro ");
                                    printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                    printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                    printf("\n\n\t\t\tFisica usou a 3 lei de Newton (toma la de ca)");
                                    dano_chefe = 10;
                                    vida = vida - dano_chefe;
                                    escudo_basico=(dano_chefe*0.4);//a quantidade de escudo depende do dano do chefe
                                    printf("\n\n\t\t\tLance sua habilidade!!! ");
                                    scanf("%c",&habilidades);
                                    scanf("%*[^\n]");
                                    scanf("%*c");
                                    switch(habilidades){
                                            case 'i': printf("\n\n\t\t\tvoce usou o Soco da mae fenix, " red"Dano Normal"reset);
                                                      combo1++;
                                                      if(combo1%2 == 0){
                                                        printf("\n\t\t\t\t"red"COMBO!!"reset);//se o jogador usar a mesma habilidade 2 vezes seguidas ela causa mais dano
                                                        vida_chefe = vida_chefe - dano_perto_basico - dano_combo;
                                                      }
                                                      else{
                                                        vida_chefe = vida_chefe - dano_perto_basico;
                                                      }
                                                      combo2 =0;
                                                      scanf("%*[^\n]");
                                                      scanf("%*c");
                                                      break;
                                            case 'o' : printf("\n\n\t\t\tvoce usou o Raio destruidor de sinapses neurais, "red"Dano normal"reset);
                                                       combo2++;
                                                       if(combo2%2 == 0){
                                                         printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                         vida_chefe = vida_chefe - dano_longe_basico - dano_combo;
                                                       }
                                                       else{
                                                         vida_chefe = vida_chefe - dano_longe_basico;
                                                       }
                                                       combo1 = 0;
                                                       scanf("%*[^\n]");
                                                       scanf("%*c");
                                                       break;
                                            case 'p' : printf("\n\n\t\t\tvoce usou o escudo de gelo verdadeiro, "red"O chefe destruiu seu escudo e se alimentou dele"reset);//este chefe se alimenta do escudo, se o jogador usar o escudo curará o chefe e receberá dano proporcional ao tanto de escudo que iria refletir
                                                       vida_chefe = vida_chefe + 20;
                                                       vida = vida - escudo_basico;
                                                       combo1 = 0;
                                                       combo2 = 0;
                                                       scanf("%*[^\n]");
                                                       scanf("%*c");
                                                       break;
                                            default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , sem segunda chance ;-;");
                                                     scanf("%*[^\n]");
                                                     scanf("%*c");

                                            }
                                    labirito[11][35] = ' ';//retira o chefe da matriz
                                    if(vida<=0){//printa a tela de derrota
                                        system("clear||cls");
                                        for(i=0;i<linha;i++){
                                            printf("\n\t\t");
                                            for(j=0;j<coluna;j++){
                                                if(labirito[i][j] == 'x'){
                                                    printf(fundo_branco" "reset);
                                                    continue;
                                                }
                                                else
                                                    if(labirito[i][j] == 'V'){
                                                        x = i;
                                                        y = j;
                                                        printf(fundo_red red" "reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'S'){
                                                            printf(fundo_red red"S"reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == '@'){
                                                                printf(fundo_red red" "reset);
                                                            }
                                                            else{
                                                                printf(" ");
                                                            }
                                            }
                                        }
                                        printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                        fim = 1;//condição para finalizar o jogo
                                        break;
                                    }
                                    if(vida_chefe<=0){//printa o labirinto temporario e o orginal
                                        for(cont=1;vida<vida_max;cont++){//o mago se cura quando derrota o chefe, tal cura nao pode passar de 100
                                            vida++;
                                            if(cont == vida_ext){
                                                break;
                                            }
                                        }
                                        nota = nota + 1;
                                        printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                        scanf("%*[^\n]");
                                        scanf("%*c");
                                        system("clear||cls");

                                        printf("\n\tpara sair clique = f");
                                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                        
                                        for(i=0;i<linha;i++){
                                            printf("\n\t\t");
                                            for(j=0;j<coluna;j++){
                                                if(labirito[i][j] == 'x'){
                                                    printf(fundo_blue blue" "reset);
                                                    continue;
                                                }
                                                else
                                                    if(labirito[i][j] == 'V'){
                                                        x = i;
                                                        y = j;
                                                        printf(fundo_red red" "reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'S'){
                                                            printf(fundo_red red"S"reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == '@'){
                                                                printf(fundo_branco" "reset);
                                                            }
                                                            else
                                                                if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                        printf(fundo_magenta" "reset);
                                                                                        
                                                                                        
                                                                }
                                                                else{
                                                                    printf(" ");
                                                                }
                                            }
                                        }
                                        for(tempo=0;tempo<tempo_max;tempo++){}
                                        system("clear||cls");

                                        printf("\n\tpara sair clique = f");
                                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                        for(i=0;i<linha;i++){
                                            printf("\n\t\t");
                                            for(j=0;j<coluna;j++){
                                                if(labirito[i][j] == 'x'){
                                                    printf(fundo_blue blue" "reset);
                                                    continue;
                                                }
                                                else
                                                    if(labirito[i][j] == 'V'){
                                                        x = i;
                                                        y = j;
                                                        printf(fundo_red red" "reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'S'){
                                                            printf(fundo_red red"S"reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == '@'){
                                                                printf(fundo_branco" "reset);
                                                            }
                                                            else{
                                                                printf(" ");
                                                            }
                                            }
                                        }


                                        break;
                                    }

                                }
                                while(vida > 0 || vida_chefe>0);
                                break;
                        case 2://chefe contra a classe assasino
                            combo1 = 0;
                            combo2 = 0;
                                do{
                                    system("clear||cls");
                                    printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Fisica"reset);//introdução sobre o chefe jutamente com as habilidades da classe escolhida
                                    printf("\n\n\t\t\tFisica eh um grande sabio das artes obscuras(nao eh atoa que so passa nesse curso 2/3 pessoas), ela se alimenta da defesa inimiga e se volta contra eles");
                                    printf("\n\n\t\t\tHabilidades da classe "amarelo"Assasino"reset" : "amarelo"i"reset" - Ataque armageddon|| "amarelo"o"reset" - shurikens flamejantes||  "amarelo"p"reset" - Fuga canibal ");
                                    printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                    printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                    printf("\n\n\t\t\tFisica usou a 3 lei de Newton (toma la de ca)");
                                    dano_chefe = 10;
                                    vida = vida - dano_chefe;
                                    escudo_basico=(dano_chefe*0.4);//a quantidade de escudo depende do dano do chefe
                                    printf("\n\n\t\t\tLance sua habilidade!!! ");
                                    scanf("%c",&habilidades);
                                    scanf("%*[^\n]");
                                    scanf("%*c");
                                    switch(habilidades){
                                            case 'i': printf("\n\n\t\t\tvoce usou o Ataque armageddon, " red"Dano Normal"reset);
                                                      combo1++;
                                                      if(combo1%2 ==0){
                                                        printf("\n\t\t\t\t"red"COMBO!!"reset);//se o jogador usar a mesma habilidade 2 vezes seguidas ele causará dano extra
                                                        vida_chefe = vida_chefe - dano_perto_assasino - dano_combo;
                                                      }
                                                      else{
                                                        vida_chefe = vida_chefe - dano_perto_assasino;
                                                      }
                                                      combo2 =0;
                                                      scanf("%*[^\n]");
                                                      scanf("%*c");
                                                      break;
                                            case 'o' : printf("\n\n\t\t\tvoce usou shurikens flamejantes, "red"Dano Normal"reset);
                                                       combo2++;
                                                       if(combo2%2 == 0){
                                                        printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                        vida_chefe = vida_chefe - dano_longe_basico - dano_combo;
                                                       }
                                                       else{
                                                        vida_chefe = vida_chefe - dano_longe_basico;
                                                       }
                                                       combo1 = 0;
                                                       scanf("%*[^\n]");
                                                       scanf("%*c");
                                                       break;
                                            case 'p' : printf("\n\n\t\t\tvoce usou Fuga canibal, "red"O chefe destruiu seu escudo e se alimentou dele"reset);//este chefe se alimenta do escudo, se o jogador usar o escudo curará o chefe e receberá dano proporcional ao tanto de escudo que iria refletir
                                                       vida_chefe = vida_chefe + 20;
                                                       vida = vida - escudo_basico;
                                                       combo1 = 0;
                                                       combo2 =0;
                                                       scanf("%*[^\n]");
                                                       scanf("%*c");
                                                       break;
                                            default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , sem segunda chance ;-;");
                                                     scanf("%*[^\n]");
                                                     scanf("%*c");

                                            }
                                    labirito[11][35] = ' ';//retira o chefe da matriz
                                    if(vida<=0){//printa a tela de derrota
                                        system("clear||cls");
                                        for(i=0;i<linha;i++){
                                            printf("\n\t\t");
                                            for(j=0;j<coluna;j++){
                                                if(labirito[i][j] == 'x'){
                                                    printf(fundo_branco" "reset);
                                                    continue;
                                                }
                                                else
                                                    if(labirito[i][j] == 'V'){
                                                        x = i;
                                                        y = j;
                                                        printf(fundo_red red" "reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'S'){
                                                            printf(fundo_red red"S"reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == '@'){
                                                                printf(fundo_red red" "reset);
                                                            }
                                                            else{
                                                                printf(" ");
                                                            }
                                            }
                                        }
                                        printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                        fim = 1;//condição para finalizar o jogo
                                        break;
                                    }
                                    if(vida_chefe<=0){//printa o labirinto temporario e o orginal
                                        nota = nota + 1;
                                        printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                        scanf("%*[^\n]");
                                        scanf("%*c");
                                        system("clear||cls");

                                        printf("\n\tpara sair clique = f");
                                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                        
                                        for(i=0;i<linha;i++){
                                            printf("\n\t\t");
                                            for(j=0;j<coluna;j++){
                                                if(labirito[i][j] == 'x'){
                                                    printf(fundo_blue blue" "reset);
                                                    continue;
                                                }
                                                else
                                                    if(labirito[i][j] == 'V'){
                                                        x = i;
                                                        y = j;
                                                        printf(fundo_red red" "reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'S'){
                                                            printf(fundo_red red"S"reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == '@'){
                                                                printf(fundo_branco" "reset);
                                                            }
                                                            else
                                                                if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                        printf(fundo_magenta" "reset);
                                                                                        
                                                                                        
                                                                }
                                                                else{
                                                                    printf(" ");
                                                                }
                                            }
                                        }
                                        for(tempo=0;tempo<tempo_max;tempo++){}
                                        system("clear||cls");

                                        printf("\n\tpara sair clique = f");
                                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                        for(i=0;i<linha;i++){
                                            printf("\n\t\t");
                                            for(j=0;j<coluna;j++){
                                                if(labirito[i][j] == 'x'){
                                                    printf(fundo_blue blue" "reset);
                                                    continue;
                                                }
                                                else
                                                    if(labirito[i][j] == 'V'){
                                                        x = i;
                                                        y = j;
                                                        printf(fundo_red red" "reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'S'){
                                                            printf(fundo_red red"S"reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == '@'){
                                                                printf(fundo_branco" "reset);
                                                            }
                                                            else{
                                                                printf(" ");
                                                            }
                                            }
                                        }


                                        break;
                                    }

                                }
                                while(vida > 0 || vida_chefe>0);
                                break;
                        case 3://chfe contra a classe atirador
                            combo1 = 0;
                            combo2 = 0;
                                do{
                                    system("clear||cls");
                                    printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Fisica"reset);//informações sobre o chefe,jutamente com as habilidadas da classe escohida
                                    printf("\n\n\t\t\tFisica eh um grande sabio das artes obscuras(nao eh atoa que so passa nesse curso 2/3 pessoas), ela se alimenta da defesa inimiga e se volta contra eles");
                                    printf("\n\n\t\t\tHabilidades da classe "amarelo"Atirador"reset" : "amarelo"i"reset" - Perfuracao eletrizante|| "amarelo"o"reset" - Mata-Craquens||  "amarelo"p"reset" - Arco-escudo ");
                                    printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                    printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                    printf("\n\n\t\t\tFisica usou a 3 lei de Newton (toma la de ca)");
                                    dano_chefe = 10;
                                    vida = vida - dano_chefe;
                                    escudo_basico=(dano_chefe*0.4);//a quantidade de escudo depende do dano do chefe
                                    printf("\n\n\t\t\tLance sua habilidade!!! ");
                                    scanf("%c",&habilidades);
                                    scanf("%*[^\n]");
                                    scanf("%*c");
                                    switch(habilidades){
                                            case 'i': printf("\n\n\t\t\tvoce usou Perfuracao eletrizante, " red"Dano Normal"reset);
                                                      combo1++;
                                                      if(combo1%2 == 0){
                                                        printf("\n\t\t\t\t"red"COMBO!!"reset);//se a pessoa usar a mesma habilidade 2 vezes seguidas ela causa dano extra
                                                        vida_chefe = vida_chefe - dano_perto_basico - dano_combo;
                                                      }
                                                      else{
                                                        vida_chefe = vida_chefe - dano_perto_basico ;
                                                      }
                                                      combo2 = 0;
                                                      scanf("%*[^\n]");
                                                      scanf("%*c");
                                                      break;
                                            case 'o' : printf("\n\n\t\t\tvoce usou Mata-Craquens, "red"Dano Normal"reset);
                                                       combo2++;
                                                       if(combo2%2 == 0){
                                                        printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                        vida_chefe = vida_chefe - dano_longe_atirador - dano_combo;
                                                       }
                                                       else{
                                                        vida_chefe = vida_chefe - dano_longe_atirador;
                                                       }
                                                       combo1 = 0;
                                                       scanf("%*[^\n]");
                                                       scanf("%*c");
                                                       break;
                                            case 'p' : printf("\n\n\t\t\tvoce usou Arco-escudo, "red"O chefe destruiu seu escudo e se alimentou dele"reset);//este chefe se alimenta do escudo, se o jogador usar o escudo curará o chefe e receberá dano proporcional ao tanto de escudo que iria refletir
                                                       vida_chefe = vida_chefe + 20;
                                                       vida = vida - escudo_basico;
                                                       combo1 = 0;
                                                       combo2 =0;
                                                       scanf("%*[^\n]");
                                                       scanf("%*c");
                                                       break;
                                            default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , sem segunda chance ;-;");
                                                     scanf("%*[^\n]");
                                                     scanf("%*c");

                                            }
                                    labirito[11][35] = ' ';//retira o chefe da matriz
                                    if(vida<=0){//printa a tela de derrota
                                       system("clear||cls");
                                        for(i=0;i<linha;i++){
                                            printf("\n\t\t");
                                            for(j=0;j<coluna;j++){
                                                if(labirito[i][j] == 'x'){
                                                    printf(fundo_branco" "reset);
                                                    continue;
                                                }
                                                else
                                                    if(labirito[i][j] == 'V'){
                                                        x = i;
                                                        y = j;
                                                        printf(fundo_red red" "reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'S'){
                                                            printf(fundo_red red"S"reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == '@'){
                                                                printf(fundo_red red" "reset);
                                                            }
                                                            else{
                                                                printf(" ");
                                                            }
                                            }
                                        }
                                        printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                        fim = 1;//condição para finalizar o jogo
                                        break;
                                    }
                                    if(vida_chefe<=0){//printa o labirinto temporario e o original
                                        nota = nota + 1;
                                        printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                        scanf("%*[^\n]");
                                        scanf("%*c");
                                        system("clear||cls");

                                        printf("\n\tpara sair clique = f");
                                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                        
                                        for(i=0;i<linha;i++){
                                            printf("\n\t\t");
                                            for(j=0;j<coluna;j++){
                                                if(labirito[i][j] == 'x'){
                                                    printf(fundo_blue blue" "reset);
                                                    continue;
                                                }
                                                else
                                                    if(labirito[i][j] == 'V'){
                                                        x = i;
                                                        y = j;
                                                        printf(fundo_red red" "reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'S'){
                                                            printf(fundo_red red"S"reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == '@'){
                                                                printf(fundo_branco" "reset);
                                                            }
                                                            else
                                                                if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                        printf(fundo_magenta" "reset);
                                                                                        
                                                                                        
                                                                }
                                                                else{
                                                                    printf(" ");
                                                                }
                                            }
                                        }
                                        for(tempo=0;tempo<tempo_max;tempo++){}
                                        system("clear||cls");

                                        printf("\n\tpara sair clique = f");
                                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                        for(i=0;i<linha;i++){
                                            printf("\n\t\t");
                                            for(j=0;j<coluna;j++){
                                                if(labirito[i][j] == 'x'){
                                                    printf(fundo_blue blue" "reset);
                                                    continue;
                                                }
                                                else
                                                    if(labirito[i][j] == 'V'){
                                                        x = i;
                                                        y = j;
                                                        printf(fundo_red red" "reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'S'){
                                                            printf(fundo_red red"S"reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == '@'){
                                                                printf(fundo_branco" "reset);
                                                            }
                                                            else{
                                                                printf(" ");
                                                            }
                                            }
                                        }


                                        break;
                                    }

                                }
                                while(vida > 0 || vida_chefe>0);
                                break;
                        case 4://chefe contra a classe tank
                            combo1 = 0;
                            combo2 = 0;

                                do{
                                    system("clear||cls");
                                    printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Fisica"reset);//introdução sobre o chefe jutamente com as habilidades da classe escolhida
                                    printf("\n\n\t\t\tFisica eh um grande sabio das artes obscuras(nao eh atoa que so passa nesse curso 2/3 pessoas), ela se alimenta da defesa inimiga e se volta contra eles");
                                    printf("\n\n\t\t\tHabilidades da classe "amarelo"Tank"reset" : "amarelo"i"reset" - Golpe de escudo fermentado|| "amarelo"o"reset" - Chuva de rochedos||  "amarelo"p"reset" - colete milenar de espinhos cerimoniais ");
                                    printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                    printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                    printf("\n\n\t\t\tFisica usou a 3 lei de Newton (toma la de ca)");
                                    dano_chefe = 10;
                                    vida = vida - dano_chefe;
                                    escudo_basico=(dano_chefe*0.4);//a quantidade de escudo depende do dano do chefe
                                    escudo_tank=(dano_chefe*0.8);//o tank tem uma quantidade de escudo maior
                                    printf("\n\n\t\t\tLance sua habilidade!!! ");
                                    scanf("%c",&habilidades);
                                    scanf("%*[^\n]");
                                    scanf("%*c");
                                    switch(habilidades){
                                            case 'i': printf("\n\n\t\t\tvoce usou Golpe de escudo fermentado, " red"Dano Normal"reset);
                                                      combo1++;
                                                      if(combo1%2 == 0){
                                                        printf("\n\t\t\t\t"red"COMBO!!"reset);//se a pessoa usar a mesma habilidade 2 vezes seguidas causa dano extra
                                                        vida_chefe = vida_chefe - dano_perto_basico - dano_combo;
                                                      }
                                                      else{
                                                        vida_chefe = vida_chefe - dano_perto_basico;
                                                      }
                                                      combo2 = 0;
                                                      scanf("%*[^\n]");
                                                      scanf("%*c");
                                                      break;
                                            case 'o' : printf("\n\n\t\t\tvoce usou Chuva de rochedos, "red"Dano Normal"reset);
                                                       combo2++;
                                                       if(combo2%2 == 0){
                                                        printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                        vida_chefe = vida_chefe - dano_longe_basico- dano_combo;
                                                        }
                                                        else{
                                                            vida_chefe = vida_chefe - dano_longe_basico;
                                                        }
                                                       combo1 = 0;
                                                       scanf("%*[^\n]");
                                                       scanf("%*c");
                                                       break;
                                            case 'p' : printf("\n\n\t\t\tvoce usou colete milenar de espinhos cerimoniais, "red"O chefe destruiu seu escudo e se alimentou dele"reset); //este chefe se alimenta do escudo, se o jogador usar o escudo curará o chefe e receberá dano proporcional ao tanto de escudo que iria refletir
                                                       vida = vida - escudo_tank;
                                                       vida_chefe = vida_chefe + 20;
                                                       combo2 = 0;
                                                       combo1 = 0;
                                                       scanf("%*[^\n]");
                                                       scanf("%*c");
                                                       break;
                                            default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , sem segunda chance ;-;");
                                                     scanf("%*[^\n]");
                                                     scanf("%*c");

                                            }
                                    labirito[11][35] = ' '; //retira o chefe da matriz
                                    if(vida<=0){//printa a tela de derrota
                                        system("clear||cls");
                                        for(i=0;i<linha;i++){
                                            printf("\n\t\t");
                                            for(j=0;j<coluna;j++){
                                                if(labirito[i][j] == 'x'){
                                                    printf(fundo_branco" "reset);
                                                    continue;
                                                }
                                                else
                                                    if(labirito[i][j] == 'V'){
                                                        x = i;
                                                        y = j;
                                                        printf(fundo_red red" "reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'S'){
                                                            printf(fundo_red red"S"reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == '@'){
                                                                printf(fundo_red red" "reset);
                                                            }
                                                            else{
                                                                printf(" ");
                                                            }
                                            }
                                        }
                                        printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                        fim = 1;//condição para finalizar o jogo
                                        break;
                                    }
                                    if(vida_chefe<=0){//printa o labirinto temporario juntamente com o orginal
                                        nota = nota + 1;
                                        printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                        scanf("%*[^\n]");
                                        scanf("%*c");
                                        system("clear||cls");

                                        printf("\n\tpara sair clique = f");
                                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                        
                                        for(i=0;i<linha;i++){
                                            printf("\n\t\t");
                                            for(j=0;j<coluna;j++){
                                                if(labirito[i][j] == 'x'){
                                                    printf(fundo_blue blue" "reset);
                                                    continue;
                                                }
                                                else
                                                    if(labirito[i][j] == 'V'){
                                                        x = i;
                                                        y = j;
                                                        printf(fundo_red red" "reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'S'){
                                                            printf(fundo_red red"S"reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == '@'){
                                                                printf(fundo_branco" "reset);
                                                            }
                                                            else
                                                                if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                        printf(fundo_magenta" "reset);
                                                                                        
                                                                                        
                                                                }
                                                                else{
                                                                    printf(" ");
                                                                }
                                            }
                                        }
                                        for(tempo=0;tempo<tempo_max;tempo++){}
                                        system("clear||cls");

                                        printf("\n\tpara sair clique = f");
                                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                        for(i=0;i<linha;i++){
                                            printf("\n\t\t");
                                            for(j=0;j<coluna;j++){
                                                if(labirito[i][j] == 'x'){
                                                    printf(fundo_blue blue" "reset);
                                                    continue;
                                                }
                                                else
                                                    if(labirito[i][j] == 'V'){
                                                        x = i;
                                                        y = j;
                                                        printf(fundo_red red" "reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'S'){
                                                            printf(fundo_red red"S"reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == '@'){
                                                                printf(fundo_branco" "reset);
                                                            }
                                                            else{
                                                                printf(" ");
                                                            }
                                            }
                                        }


                                        break;
                                    }

                                }
                                while(vida > 0 || vida_chefe>0);
                                break;
                        }

                }
                else
                    if(labirito[x][y+1] == 'm' || labirito[x-1][y] == 'm' || labirito[x][y-1] == 'm' ||labirito[x +1][y] == 'm' ){//se o jogador estiver perto do chefe ativará o mini-game
                        vida_chefe = 110;
                        system("clear||cls");
                        printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Metodologia"reset);
                        printf("\n\n\t\t\tMetodologia viu um erro ortografico no seu codigo,erro = nota 0 = sanidade 0 :3");

                        switch(classe){
                            case 1://chefe contra a classe mago
                                combo1 = 0;
                                combo2 = 0;
                                    do{
                                        system("clear||cls");
                                        printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Metodologia"reset); //introdução sobre o chefe jutamente com as habilidades da classe escolhida
                                        printf("\n\n\t\t\tMetodologia viu um erro ortografico no seu codigo,erro = nota 0 = sanidade 0 :3");
                                        printf("\n\n\t\t\tHabilidades da classe "amarelo"Mago"reset" : "amarelo"i"reset" - Soco da mae Fenix|| "amarelo"o"reset" - Raio destruidor de sinapses neurais||  "amarelo"p"reset" - escudo de gelo verdadeiro ");
                                        printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                        printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                        printf("\n\n\t\t\tAtaque coordenado das oracoes coordenadas");
                                        dano_chefe = 5;
                                        vida = vida - dano_chefe;
                                        escudo_basico=(dano_chefe*0.4); //a quantidade de escudo depende do dano do chefe
                                        printf("\n\n\t\t\tLance sua habilidade!!! ");
                                        scanf("%c",&habilidades);
                                        scanf("%*[^\n]");
                                        scanf("%*c");
                                        switch(habilidades){
                                                case 'i': printf("\n\n\t\t\tvoce usou o Soco da mae fenix, " red"Dano Normal"reset);
                                                          combo1++;
                                                          if(combo1%2 == 0){
                                                            printf("\n\t\t\t\t"red"COMBO!!"reset);//se a pessoa usar a mesma habilidade 2 vezes seguidas causa  dano extra
                                                            vida_chefe = vida_chefe - dano_perto_basico - dano_combo;
                                                          }
                                                          else{
                                                            vida_chefe = vida_chefe - dano_perto_basico;
                                                          }
                                                          combo2 =0;
                                                          scanf("%*[^\n]");
                                                          scanf("%*c");
                                                          break;
                                                case 'o' : printf("\n\n\t\t\tvoce usou o Raio destruidor de sinapses neurais, "red"Dano Normal"reset);
                                                           combo2++;
                                                           if(combo2%2 == 0){
                                                             printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                             vida_chefe = vida_chefe - dano_longe_basico - dano_combo;
                                                           }
                                                           else{
                                                             vida_chefe = vida_chefe - dano_longe_basico ;
                                                           }
                                                           combo1 = 0;
                                                           scanf("%*[^\n]");
                                                           scanf("%*c");
                                                           break;
                                                case 'p' : printf("\n\n\t\t\tvoce usou o escudo de gelo verdadeiro, "red"bloqueou parte do proximo ataque do chefe"reset);
                                                           vida = vida + escudo_basico;
                                                           combo1 = 0;
                                                           combo2 = 0;
                                                           scanf("%*[^\n]");
                                                           scanf("%*c");
                                                           break;
                                                default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , metodologia nao perdoa"); // metodologia zera a vida do jogador caso ele erre 
                                                         vida = 0;
                                                         scanf("%*[^\n]");
                                                         scanf("%*c");

                                                }
                                        labirito[10][64] = ' '; //retira o chefe da matriz
                                        if(vida<=0){ //printa a tela de derrota
                                            system("clear||cls");
                                            for(i=0;i<linha;i++){
                                                printf("\n\t\t");
                                                for(j=0;j<coluna;j++){
                                                    if(labirito[i][j] == 'x'){
                                                        printf(fundo_branco" "reset);
                                                        continue;
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'V'){
                                                            x = i;
                                                            y = j;
                                                            printf(fundo_red red" "reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == 'S'){
                                                                printf(fundo_red red"S"reset);
                                                            }
                                                            else
                                                                if(labirito[i][j] == '@'){
                                                                    printf(fundo_red red" "reset);
                                                                }
                                                                else{
                                                                    printf(" ");
                                                                }
                                                }
                                            }
                                            printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                            fim = 1;//condição para finalizar o jogo
                                            break;
                                        }
                                        if(vida_chefe<=0){ //printa o labirinto temporario juntamente com o orginal
                                            for(cont=1;vida<vida_max;cont++){ //o mago recupera sanidade ao matar o chefe
                                                vida++;
                                                if(cont == vida_ext){
                                                    break;
                                                }
                                            }
                                            nota = nota + 1;
                                            printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                            scanf("%*[^\n]");
                                            scanf("%*c");
                                            system("clear||cls");

                                            printf("\n\tpara sair clique = f");
                                            printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                            printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                            
                                            for(i=0;i<linha;i++){
                                                printf("\n\t\t");
                                                for(j=0;j<coluna;j++){
                                                    if(labirito[i][j] == 'x'){
                                                        printf(fundo_blue blue" "reset);
                                                        continue;
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'V'){
                                                            x = i;
                                                            y = j;
                                                            printf(fundo_red red" "reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == 'S'){
                                                                printf(fundo_red red"S"reset);
                                                            }
                                                            else
                                                                if(labirito[i][j] == '@'){
                                                                    printf(fundo_branco" "reset);
                                                                }
                                                                else
                                                                    if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                            printf(fundo_magenta" "reset);
                                                                                            
                                                                                            
                                                                    }
                                                                    else{
                                                                        printf(" ");
                                                                    }
                                                }
                                            }
                                            for(tempo=0;tempo<tempo_max;tempo++){}
                                            system("clear||cls");

                                            printf("\n\tpara sair clique = f");
                                            printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                            printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                            for(i=0;i<linha;i++){
                                                printf("\n\t\t");
                                                for(j=0;j<coluna;j++){
                                                    if(labirito[i][j] == 'x'){
                                                        printf(fundo_blue blue" "reset);
                                                        continue;
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'V'){
                                                            x = i;
                                                            y = j;
                                                            printf(fundo_red red" "reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == 'S'){
                                                                printf(fundo_red red"S"reset);
                                                            }
                                                            else
                                                                if(labirito[i][j] == '@'){
                                                                    printf(fundo_branco" "reset);
                                                                }
                                                                else{
                                                                    printf(" ");
                                                                }
                                                }
                                            }


                                            break;
                                        }

                                    }
                                    while(vida > 0 || vida_chefe>0);
                                    break;
                            case 2://chefe contra o assasino
                                combo1 = 0;
                                combo2 = 0;
                                    do{
                                        system("clear||cls");
                                        printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Metodologia"reset);//introdução sobre o chefe jutamente com as habilidades da classe escolhida
                                        printf("\n\n\t\t\tMetodologia viu um erro ortografico no seu codigo,erro = nota 0 = sanidade 0 :3");
                                        printf("\n\n\t\t\tHabilidades da classe "amarelo"Assasino"reset" : "amarelo"i"reset" - Ataque armageddon|| "amarelo"o"reset" - shurikens flamejantes||  "amarelo"p"reset" - Fuga canibal ");
                                        printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                        printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                        printf("\n\n\t\t\tAtaque coordenado das oracoes coordenadas");
                                        dano_chefe = 5;
                                        vida = vida - dano_chefe;
                                        escudo_basico=(dano_chefe*0.4);//a quantidade de escudo depende do dano do chefe
                                        printf("\n\n\t\t\tLance sua habilidade!!! ");
                                        scanf("%c",&habilidades);
                                        scanf("%*[^\n]");
                                        scanf("%*c");
                                        switch(habilidades){
                                                case 'i': printf("\n\n\t\t\tvoce usou o Ataque armageddon, " red"Dano Normal"reset);
                                                          combo1++;
                                                          if(combo1%2 ==0){
                                                            printf("\n\t\t\t\t"red"COMBO!!"reset);//se a pessoa usar a mesma habilidade 2 vezes seguidas causa  dano extra
                                                            vida_chefe = vida_chefe - dano_perto_assasino - dano_combo;
                                                          }
                                                          else{
                                                            vida_chefe = vida_chefe - dano_perto_assasino;
                                                          }
                                                          combo2 =0;
                                                          scanf("%*[^\n]");
                                                          scanf("%*c");
                                                          break;
                                                case 'o' : printf("\n\n\t\t\tvoce usou shurikens flamejantes, "red"Dano Normal"reset);
                                                           combo2++;
                                                           if(combo2%2 == 0){
                                                            printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                            vida_chefe = vida_chefe - dano_longe_basico - dano_combo;
                                                           }
                                                           else{
                                                            vida_chefe = vida_chefe - dano_longe_basico;
                                                           }
                                                           combo1 = 0;
                                                           scanf("%*[^\n]");
                                                           scanf("%*c");
                                                           break;
                                                case 'p' : printf("\n\n\t\t\tvoce usou Fuga canibal, "red"bloqueou parte do proximo ataque do chefe"reset);
                                                           vida = vida + escudo_basico;
                                                           combo1 = 0;
                                                           combo2 =0;
                                                           scanf("%*[^\n]");
                                                           scanf("%*c");
                                                           break;
                                                default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , metodologia nao perdoa"); // metodologia zera a vida do jogador caso ele erre 
                                                         vida =0;
                                                         scanf("%*[^\n]");
                                                         scanf("%*c");

                                                }
                                        labirito[10][64] = ' '; //retira o chefe da matriz
                                        if(vida<=0){ //printa a tela de derrota
                                            system("clear||cls");
                                            for(i=0;i<linha;i++){
                                                printf("\n\t\t");
                                                for(j=0;j<coluna;j++){
                                                    if(labirito[i][j] == 'x'){
                                                        printf(fundo_branco" "reset);
                                                        continue;
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'V'){
                                                            x = i;
                                                            y = j;
                                                            printf(fundo_red red" "reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == 'S'){
                                                                printf(fundo_red red"S"reset);
                                                            }
                                                            else
                                                                if(labirito[i][j] == '@'){
                                                                    printf(fundo_red red" "reset);
                                                                }
                                                                else{
                                                                    printf(" ");
                                                                }
                                                }
                                            }
                                            printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                            fim = 1; //condição para finalizar o jogo
                                            break;
                                        }
                                        if(vida_chefe<=0){ //printa o labirinto temporario juntamente com o orginal
                                            nota = nota + 1;
                                            printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                            scanf("%*[^\n]");
                                            scanf("%*c");
                                            system("clear||cls");

                                            printf("\n\tpara sair clique = f");
                                            printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                            printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                            
                                            for(i=0;i<linha;i++){
                                                printf("\n\t\t");
                                                for(j=0;j<coluna;j++){
                                                    if(labirito[i][j] == 'x'){
                                                        printf(fundo_blue blue" "reset);
                                                        continue;
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'V'){
                                                            x = i;
                                                            y = j;
                                                            printf(fundo_red red" "reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == 'S'){
                                                                printf(fundo_red red"S"reset);
                                                            }
                                                            else
                                                                if(labirito[i][j] == '@'){
                                                                    printf(fundo_branco" "reset);
                                                                }
                                                                else
                                                                    if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                            printf(fundo_magenta" "reset);
                                                                                            
                                                                                            
                                                                    }
                                                                    else{
                                                                        printf(" ");
                                                                    }
                                                }
                                            }
                                            for(tempo=0;tempo<tempo_max;tempo++){}
                                            system("clear||cls");

                                            printf("\n\tpara sair clique = f");
                                            printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                            printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                            for(i=0;i<linha;i++){
                                                printf("\n\t\t");
                                                for(j=0;j<coluna;j++){
                                                    if(labirito[i][j] == 'x'){
                                                        printf(fundo_blue blue" "reset);
                                                        continue;
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'V'){
                                                            x = i;
                                                            y = j;
                                                            printf(fundo_red red" "reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == 'S'){
                                                                printf(fundo_red red"S"reset);
                                                            }
                                                            else
                                                                if(labirito[i][j] == '@'){
                                                                    printf(fundo_branco" "reset);
                                                                }
                                                                else{
                                                                    printf(" ");
                                                                }
                                                }
                                            }


                                            break;
                                        }

                                    }
                                    while(vida > 0 || vida_chefe>0);
                                    break;
                            case 3: //chefe contra o atirador
                                combo1 = 0;
                                combo2 = 0;
                                    do{
                                        system("clear||cls");
                                        printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Metodologia"reset); //introdução sobre o chefe jutamente com as habilidades da classe escolhida
                                        printf("\n\n\t\t\tMetodologia viu um erro ortografico no seu codigo,erro = nota 0 = sanidade 0 :3");
                                        printf("\n\n\t\t\tHabilidades da classe "amarelo"Atirador"reset" : "amarelo"i"reset" - Perfuracao eletrizante|| "amarelo"o"reset" - Mata-Craquens||  "amarelo"p"reset" - Arco-escudo ");
                                        printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                        printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                        printf("\n\n\t\t\tAtaque coordenado das oracoes coordenadas");
                                        dano_chefe = 5;
                                        vida = vida - dano_chefe;
                                        escudo_basico=(dano_chefe*0.4); //a quantidade de escudo depende do dano do chefe
                                        printf("\n\n\t\t\tLance sua habilidade!!! ");
                                        scanf("%c",&habilidades);
                                        scanf("%*[^\n]");
                                        scanf("%*c");
                                        switch(habilidades){
                                                case 'i': printf("\n\n\t\t\tvoce usou Perfuracao eletrizante, " red"Dano Normal"reset);
                                                          combo1++;
                                                          if(combo1%2 == 0){
                                                            printf("\n\t\t\t\t"red"COMBO!!"reset); //se a pessoa usar a mesma habilidade 2 vezes seguidas causa  dano extra
                                                            vida_chefe = vida_chefe - dano_perto_basico  - dano_combo;
                                                          }
                                                          else{
                                                            vida_chefe = vida_chefe - dano_perto_basico ;
                                                          }
                                                          combo2 = 0;
                                                          scanf("%*[^\n]");
                                                          scanf("%*c");
                                                          break;
                                                case 'o' : printf("\n\n\t\t\tvoce usou Mata-Craquens, "red"Dano Normal"reset);
                                                           combo2++;
                                                           if(combo2%2 == 0){
                                                            printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                            vida_chefe = vida_chefe - dano_longe_atirador  - dano_combo;
                                                           }
                                                           else{
                                                            vida_chefe = vida_chefe - dano_longe_atirador ;
                                                           }
                                                           combo1 = 0;
                                                           scanf("%*[^\n]");
                                                           scanf("%*c");
                                                           break;
                                                case 'p' : printf("\n\n\t\t\tvoce usou Arco-escudo, "red"bloqueou parte do proximo ataque do chefe"reset);
                                                           vida = vida + escudo_basico;
                                                           combo1 = 0;
                                                           combo2 =0;
                                                           scanf("%*[^\n]");
                                                           scanf("%*c");
                                                           break;
                                                default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , metodologia nao perdoa"); // metodologia zera a vida do jogador caso ele erre 
                                                         vida = 0;
                                                         scanf("%*[^\n]");
                                                         scanf("%*c");

                                                }
                                        labirito[10][64] = ' '; //retira o chefe da matriz
                                        if(vida<=0){ //printa a tela de derrota
                                                system("clear||cls");
                                                for(i=0;i<linha;i++){
                                                    printf("\n\t\t");
                                                    for(j=0;j<coluna;j++){
                                                        if(labirito[i][j] == 'x'){
                                                            printf(fundo_branco" "reset);
                                                            continue;
                                                        }
                                                        else
                                                            if(labirito[i][j] == 'V'){
                                                                x = i;
                                                                y = j;
                                                                printf(fundo_red red" "reset);
                                                            }
                                                            else
                                                                if(labirito[i][j] == 'S'){
                                                                    printf(fundo_red red"S"reset);
                                                                }
                                                                else
                                                                    if(labirito[i][j] == '@'){
                                                                        printf(fundo_red red" "reset);
                                                                    }
                                                                    else{
                                                                        printf(" ");
                                                                    }
                                                    }
                                                }
                                                printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                                fim = 1; //condição para finalizar o jogo
                                                break;
                                        }
                                        if(vida_chefe<=0){
                                            nota = nota + 1;
                                            printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                            scanf("%*[^\n]");
                                            scanf("%*c");
                                            system("clear||cls");

                                            printf("\n\tpara sair clique = f");
                                            printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                            printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                            
                                            for(i=0;i<linha;i++){
                                                printf("\n\t\t");
                                                for(j=0;j<coluna;j++){
                                                    if(labirito[i][j] == 'x'){
                                                        printf(fundo_blue blue" "reset);
                                                        continue;
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'V'){
                                                            x = i;
                                                            y = j;
                                                            printf(fundo_red red" "reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == 'S'){
                                                                printf(fundo_red red"S"reset);
                                                            }
                                                            else
                                                                if(labirito[i][j] == '@'){
                                                                    printf(fundo_branco" "reset);
                                                                }
                                                                else
                                                                    if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                            printf(fundo_magenta" "reset);
                                                                                            
                                                                                            
                                                                    }
                                                                    else{
                                                                        printf(" ");
                                                                    }
                                                }
                                            }
                                            for(tempo=0;tempo<tempo_max;tempo++){}
                                            system("clear||cls");

                                            printf("\n\tpara sair clique = f");
                                            printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                            printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                            for(i=0;i<linha;i++){
                                                printf("\n\t\t");
                                                for(j=0;j<coluna;j++){
                                                    if(labirito[i][j] == 'x'){
                                                        printf(fundo_blue blue" "reset);
                                                        continue;
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'V'){
                                                            x = i;
                                                            y = j;
                                                            printf(fundo_red red" "reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == 'S'){
                                                                printf(fundo_red red"S"reset);
                                                            }
                                                            else
                                                                if(labirito[i][j] == '@'){
                                                                    printf(fundo_branco" "reset);
                                                                }
                                                                else{
                                                                    printf(" ");
                                                                }
                                                }
                                            }


                                            break;
                                        }

                                    }
                                    while(vida > 0 || vida_chefe>0);
                                    break;
                            case 4: //chefe contra a classe tank
                                combo1 = 0;
                                combo2 = 0;
                                combo3 = 0;
                                    do{
                                        system("clear||cls");
                                        printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Metodologia"reset); //introdução sobre o chefe jutamente com as habilidades da classe escolhida
                                        printf("\n\n\t\t\tMetodologia viu um erro ortografico no seu codigo,erro = nota 0 = sanidade 0 :3");
                                        printf("\n\n\t\t\tHabilidades da classe "amarelo"Tank"reset" : "amarelo"i"reset" - Golpe de escudo fermentado|| "amarelo"o"reset" - Chuva de rochedos||  "amarelo"p"reset" - colete milenar de espinhos cerimoniais ");
                                        printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                        printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                        printf("\n\n\t\t\tAtaque coordenado das oracoes coordenadas");
                                        dano_chefe = 5;
                                        vida = vida - dano_chefe;
                                        escudo_basico=(dano_chefe*0.4); //a quantidade de escudo depende do dano do chefe
                                        escudo_tank=(dano_chefe*0.8); //o tank tem uma quantidade de escudo maior
                                        printf("\n\n\t\t\tLance sua habilidade!!! ");
                                        scanf("%c",&habilidades);
                                        scanf("%*[^\n]");
                                        scanf("%*c");
                                        switch(habilidades){
                                                case 'i': printf("\n\n\t\t\tvoce usou Golpe de escudo fermentado, " red"Dano Normal"reset);
                                                           combo1++;
                                                          if(combo1%2 == 0){
                                                            printf("\n\t\t\t\t"red"COMBO!!"reset); //se a pessoa usar a mesma habilidade 2 vezes seguidas causa  dano extra
                                                            vida_chefe = vida_chefe - dano_perto_basico - dano_combo;
                                                          }
                                                          else{
                                                            vida_chefe = vida_chefe - dano_perto_basico;
                                                          }
                                                          combo2 = 0;
                                                          combo3 = 0;
                                                          scanf("%*[^\n]");
                                                          scanf("%*c");
                                                          break;
                                                case 'o' : printf("\n\n\t\t\tvoce usou Chuva de rochedos, "red"Dano Normal"reset);
                                                           combo2++;
                                                           if(combo2%2 == 0){
                                                            printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                            vida_chefe = vida_chefe - dano_longe_basico  - dano_combo;
                                                            }
                                                            else{
                                                                vida_chefe = vida_chefe - dano_longe_basico;
                                                            }
                                                           combo1 = 0;
                                                           combo3 = 0;
                                                           scanf("%*[^\n]");
                                                           scanf("%*c");
                                                           break;
                                                case 'p' : printf("\n\n\t\t\tvoce usou colete milenar de espinhos cerimoniais, "red"bloqueou grande parte do proximo ataque do chefe e aplicou dano refletor"reset);
                                                           combo3++;
                                                           if(combo3 > 2){ // o tank nao pode usar a habilidade varias vezes seguidas, caso use sera tratado como um escudo basico
                                                            printf("\n\t\t\t\t"red"Escudo quebrado!!"reset);
                                                            vida = vida + escudo_basico;
                                                           }
                                                           else{
                                                            vida = vida + escudo_tank;
                                                            vida_chefe = vida_chefe - dano_tank;
                                                           }
                                                           combo2 = 0;
                                                           combo1 = 0;

                                                           scanf("%*[^\n]");
                                                           scanf("%*c");
                                                           break;
                                                default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , metodologia nao perdoa"); // metodologia zera a vida do jogador caso ele erre 
                                                         scanf("%*[^\n]");
                                                         scanf("%*c");

                                                }
                                        labirito[10][64] = ' '; //retira o chefe da matriz
                                        if(vida<=0){ //printa a tela de derrota
                                            system("clear||cls");
                                            for(i=0;i<linha;i++){
                                                printf("\n\t\t");
                                                for(j=0;j<coluna;j++){
                                                    if(labirito[i][j] == 'x'){
                                                        printf(fundo_branco" "reset);
                                                        continue;
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'V'){
                                                            x = i;
                                                            y = j;
                                                            printf(fundo_red red" "reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == 'S'){
                                                                printf(fundo_red red"S"reset);
                                                            }
                                                            else
                                                                if(labirito[i][j] == '@'){
                                                                    printf(fundo_red red" "reset);
                                                                }
                                                                else{
                                                                    printf(" ");
                                                                }
                                                }
                                            }
                                            printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                            fim = 1; //condição para finalizar o jogo
                                            break;
                                        }
                                        if(vida_chefe<=0){ //printa o labirinto temporario juntamente com o orginal
                                            nota = nota + 1;
                                            printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                            scanf("%*[^\n]");
                                            scanf("%*c");
                                            system("clear||cls");

                                            printf("\n\tpara sair clique = f");
                                            printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                            printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                            
                                            for(i=0;i<linha;i++){
                                                printf("\n\t\t");
                                                for(j=0;j<coluna;j++){
                                                    if(labirito[i][j] == 'x'){
                                                        printf(fundo_blue blue" "reset);
                                                        continue;
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'V'){
                                                            x = i;
                                                            y = j;
                                                            printf(fundo_red red" "reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == 'S'){
                                                                printf(fundo_red red"S"reset);
                                                            }
                                                            else
                                                                if(labirito[i][j] == '@'){
                                                                    printf(fundo_branco" "reset);
                                                                }
                                                                else
                                                                    if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                            printf(fundo_magenta" "reset);
                                                                                            
                                                                                            
                                                                    }
                                                                    else{
                                                                        printf(" ");
                                                                    }
                                                }
                                            }
                                            for(tempo=0;tempo<tempo_max;tempo++){}
                                            system("clear||cls");

                                            printf("\n\tpara sair clique = f");
                                            printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                            printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                            for(i=0;i<linha;i++){
                                                printf("\n\t\t");
                                                for(j=0;j<coluna;j++){
                                                    if(labirito[i][j] == 'x'){
                                                        printf(fundo_blue blue" "reset);
                                                        continue;
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'V'){
                                                            x = i;
                                                            y = j;
                                                            printf(fundo_red red" "reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == 'S'){
                                                                printf(fundo_red red"S"reset);
                                                            }
                                                            else
                                                                if(labirito[i][j] == '@'){
                                                                    printf(fundo_branco" "reset);
                                                                }
                                                                else{
                                                                    printf(" ");
                                                                }
                                                }
                                            }


                                            break;
                                        }

                                    }
                                    while(vida > 0 || vida_chefe>0);
                                    break;
                            }

                    }
                    else
                        if(labirito[x][y+1] == 'b' || labirito[x-1][y] == 'b' || labirito[x][y-1] == 'b' ||labirito[x +1][y] == 'b' ){ //se o jogador estiver perto do chefe ativará o mini-game
                                vida_chefe = 100;
                                system("clear||cls");
                                printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" ICC"reset);
                                printf("\n\n\t\t\tICC trabalha com binarios, quando vem o terceiro... eh brutal,cuidado");

                                switch(classe){
                                    case 1: //chefe contra a classe mago
                                        combo1 = 0;
                                        combo2 = 0;
                                        cont = 0;
                                            do{
                                                system("clear||cls");
                                                printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" ICC"reset); //introdução sobre o chefe jutamente com as habilidades da classe escolhida
                                                printf("\n\n\t\t\tICC trabalha com binarios, quando vem o terceiro... eh brutal,cuidado");
                                                printf("\n\n\t\t\tHabilidades da classe "amarelo"Mago"reset" : "amarelo"i"reset" - Soco da mae Fenix|| "amarelo"o"reset" - Raio destruidor de sinapses neurais||  "amarelo"p"reset" - escudo de gelo verdadeiro ");
                                                printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                                printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                                printf("\n\n\t\t\tICC te jogou uma maquina de turing com arquiterura de von neumann");
                                                dano_chefe = 10;
                                                vida = vida - dano_chefe;
                                                escudo_basico=(dano_chefe*0.4); //a quantidade de escudo depende do dano do chefe
                                                printf("\n\n\t\t\tLance sua habilidade!!! ");
                                                scanf("%c",&habilidades);
                                                scanf("%*[^\n]");
                                                scanf("%*c");
                                                cont++;
                                                switch(habilidades){
                                                        case 'i': printf("\n\n\t\t\tvoce usou o Soco da mae fenix, " red"Dano Normal"reset);
                                                                  combo1++;
                                                                  if(combo1%2 == 0){
                                                                    printf("\n\t\t\t\t"red"COMBO!!"reset); //se a pessoa usar a mesma habilidade 2 vezes seguidas causa  dano extra
                                                                    vida_chefe = vida_chefe - dano_perto_basico - dano_combo;
                                                                  }
                                                                  else{
                                                                    vida_chefe = vida_chefe - dano_perto_basico;
                                                                  }
                                                                  combo2 =0;
                                                                  scanf("%*[^\n]");
                                                                  scanf("%*c");
                                                                  break;
                                                        case 'o' : printf("\n\n\t\t\tvoce usou o Raio destruidor de sinapses neurais, "red"Dano Normal"reset);
                                                                   combo2++;
                                                                   if(combo2%2 == 0){
                                                                     printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                                     vida_chefe = vida_chefe - dano_longe_basico - dano_combo;
                                                                   }
                                                                   else{
                                                                     vida_chefe = vida_chefe - dano_longe_basico;
                                                                   }
                                                                   combo1 = 0;
                                                                   scanf("%*[^\n]");
                                                                   scanf("%*c");
                                                                   break;
                                                        case 'p' : printf("\n\n\t\t\tvoce usou o escudo de gelo verdadeiro, "red"bloqueou parte do proximo ataque do chefe"reset);
                                                                   vida = vida + escudo_basico;
                                                                   if(cont == 3){ //se a pessoa usar o escudo no 3 ataque de icc nao tomará o dano extra
                                                                    cont = 0;
                                                                   }
                                                                   combo1 = 0;
                                                                   combo2 = 0;
                                                                   scanf("%*[^\n]");
                                                                   scanf("%*c");
                                                                   break;
                                                        default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , sem segunda chance ;-;");
                                                                 scanf("%*[^\n]");
                                                                 scanf("%*c");

                                                        }
                                                if (cont == 3){ //se a pessoa nao usar escudo no 3 ataque de icc tomará dano extra
                                                    vida = vida - 75;
                                                }
                                                labirito[11][70] = ' '; //retira o chefe da matriz
                                                if(vida<=0){ //printa a tela de derrota
                                                    system("clear||cls");
                                                    for(i=0;i<linha;i++){
                                                        printf("\n\t\t");
                                                        for(j=0;j<coluna;j++){
                                                            if(labirito[i][j] == 'x'){
                                                                printf(fundo_branco" "reset);
                                                                continue;
                                                            }
                                                            else
                                                                if(labirito[i][j] == 'V'){
                                                                    x = i;
                                                                    y = j;
                                                                    printf(fundo_red red" "reset);
                                                                }
                                                                else
                                                                    if(labirito[i][j] == 'S'){
                                                                        printf(fundo_red red"S"reset);
                                                                    }
                                                                    else
                                                                        if(labirito[i][j] == '@'){
                                                                            printf(fundo_red red" "reset);
                                                                        }
                                                                        else{
                                                                            printf(" ");
                                                                        }
                                                        }
                                                    }
                                                    printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                                    fim = 1; //condição para finalizar o jogo
                                                    break;
                                                }
                                                if(vida_chefe<=0){ //printa o labirinto temporario juntamente com o orginal
                                                    for(cont=1;vida<vida_max;cont++){ //o mago recupera sanidade ao matar o chefe
                                                        vida++;
                                                        if(cont == vida_ext){
                                                            break;
                                                        }
                                                    }
                                                    nota = nota + 2;
                                                    printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                                    scanf("%*[^\n]");
                                                    scanf("%*c");
                                                    system("clear||cls");

                                                    printf("\n\tpara sair clique = f");
                                                    printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                                    printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                                    
                                                    for(i=0;i<linha;i++){
                                                        printf("\n\t\t");
                                                        for(j=0;j<coluna;j++){
                                                            if(labirito[i][j] == 'x'){
                                                                printf(fundo_blue blue" "reset);
                                                                continue;
                                                            }
                                                            else
                                                                if(labirito[i][j] == 'V'){
                                                                    x = i;
                                                                    y = j;
                                                                    printf(fundo_red red" "reset);
                                                                }
                                                                else
                                                                    if(labirito[i][j] == 'S'){
                                                                        printf(fundo_red red"S"reset);
                                                                    }
                                                                    else
                                                                        if(labirito[i][j] == '@'){
                                                                            printf(fundo_branco" "reset);
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                                    printf(fundo_magenta" "reset);
                                                                                                    
                                                                                                    
                                                                            }
                                                                            else{
                                                                                printf(" ");
                                                                            }
                                                        }
                                                    }
                                                    for(tempo=0;tempo<tempo_max;tempo++){}
                                                    system("clear||cls");

                                                    printf("\n\tpara sair clique = f");
                                                    printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                                    printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                                    for(i=0;i<linha;i++){
                                                        printf("\n\t\t");
                                                        for(j=0;j<coluna;j++){
                                                            if(labirito[i][j] == 'x'){
                                                                printf(fundo_blue blue" "reset);
                                                                continue;
                                                            }
                                                            else
                                                                if(labirito[i][j] == 'V'){
                                                                    x = i;
                                                                    y = j;
                                                                    printf(fundo_red red" "reset);
                                                                }
                                                                else
                                                                    if(labirito[i][j] == 'S'){
                                                                        printf(fundo_red red"S"reset);
                                                                    }
                                                                    else
                                                                        if(labirito[i][j] == '@'){
                                                                            printf(fundo_branco" "reset);
                                                                        }
                                                                        else{
                                                                            printf(" ");
                                                                        }
                                                        }
                                                    }


                                                    break;
                                                }

                                            }
                                            while(vida > 0 || vida_chefe>0);
                                            break;
                                    case 2: //chefe contra o assasino
                                        combo1 = 0;
                                        combo2 = 0;
                                        cont = 0;
                                            do{
                                                system("clear||cls");
                                                printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" ICC"reset); //introdução sobre o chefe jutamente com as habilidades da classe escolhida
                                                printf("\n\n\t\t\tICC trabalha com binarios, quando vem o terceiro... eh brutal,cuidado");;
                                                printf("\n\n\t\t\tHabilidades da classe "amarelo"Assasino"reset" : "amarelo"i"reset" - Ataque armageddon|| "amarelo"o"reset" - shurikens flamejantes||  "amarelo"p"reset" - Fuga canibal ");
                                                printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                                printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                                printf("\n\n\t\t\tICC te jogou uma maquina de turing com arquiterura de von neumann");
                                                dano_chefe = 10;
                                                vida = vida - dano_chefe;
                                                escudo_basico=(dano_chefe*0.4); //a quantidade de escudo depende do dano do chefe
                                                printf("\n\n\t\t\tLance sua habilidade!!! ");
                                                scanf("%c",&habilidades);
                                                scanf("%*[^\n]");
                                                scanf("%*c");
                                                cont++;
                                                switch(habilidades){
                                                        case 'i': printf("\n\n\t\t\tvoce usou o Ataque armageddon, " red"Dano Normal"reset);
                                                                  combo1++;
                                                                  if(combo1%2 ==0){
                                                                    printf("\n\t\t\t\t"red"COMBO!!"reset); //se a pessoa usar a mesma habilidade 2 vezes seguidas causa  dano extra
                                                                    vida_chefe = vida_chefe - dano_perto_assasino - dano_combo;
                                                                  }
                                                                  else{
                                                                    vida_chefe = vida_chefe - dano_perto_assasino ;
                                                                  }
                                                                  combo2 =0;
                                                                  scanf("%*[^\n]");
                                                                  scanf("%*c");
                                                                  break;
                                                        case 'o' : printf("\n\n\t\t\tvoce usou shurikens flamejantes, "red"Dano Normal"reset);
                                                                   combo2++;
                                                                   if(combo2%2 == 0){
                                                                    printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                                    vida_chefe = vida_chefe - dano_longe_basico - dano_combo;
                                                                   }
                                                                   else{
                                                                    vida_chefe = vida_chefe - dano_longe_basico;
                                                                   }
                                                                   combo1 = 0;
                                                                   scanf("%*[^\n]");
                                                                   scanf("%*c");
                                                                   break;
                                                        case 'p' : printf("\n\n\t\t\tvoce usou Fuga canibal, "red"bloqueou parte do proximo ataque do chefe"reset);
                                                                   vida = vida + escudo_basico;
                                                                   if(cont == 3){ //se a pessoa usar o escudo no 3 ataque de icc nao tomará o dano extra
                                                                    cont = 0;
                                                                   }
                                                                   combo1 = 0;
                                                                   combo2 =0;
                                                                   scanf("%*[^\n]");
                                                                   scanf("%*c");
                                                                   break;
                                                        default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , sem segunda chance ;-;");
                                                                 scanf("%*[^\n]");
                                                                 scanf("%*c");

                                                        }
                                                if(cont == 3){ //se a pessoa nao usar escudo no 3 ataque de icc tomará dano extra
                                                    vida = vida - 75;
                                                }
                                                labirito[11][70] = ' '; //retira o chefe da matriz
                                                if(vida<=0){ //printa a tela de derrota
                                                        system("clear||cls");
                                                        for(i=0;i<linha;i++){
                                                            printf("\n\t\t");
                                                            for(j=0;j<coluna;j++){
                                                                if(labirito[i][j] == 'x'){
                                                                    printf(fundo_branco" "reset);
                                                                    continue;
                                                                }
                                                                else
                                                                    if(labirito[i][j] == 'V'){
                                                                        x = i;
                                                                        y = j;
                                                                        printf(fundo_red red" "reset);
                                                                    }
                                                                    else
                                                                        if(labirito[i][j] == 'S'){
                                                                            printf(fundo_red red"S"reset);
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == '@'){
                                                                                printf(fundo_red red" "reset);
                                                                            }
                                                                            else{
                                                                                printf(" ");
                                                                            }
                                                            }
                                                        }
                                                        printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                                        fim = 1; //condição para finalizar o jogo
                                                        break;
                                                }
                                                if(vida_chefe<=0){ //printa o labirinto temporario juntamente com o orginal
                                                    nota = nota + 2;
                                                    printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                                    scanf("%*[^\n]");
                                                    scanf("%*c");
                                                    system("clear||cls");

                                                    printf("\n\tpara sair clique = f");
                                                    printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                                    printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                                    
                                                    for(i=0;i<linha;i++){
                                                        printf("\n\t\t");
                                                        for(j=0;j<coluna;j++){
                                                            if(labirito[i][j] == 'x'){
                                                                printf(fundo_blue blue" "reset);
                                                                continue;
                                                            }
                                                            else
                                                                if(labirito[i][j] == 'V'){
                                                                    x = i;
                                                                    y = j;
                                                                    printf(fundo_red red" "reset);
                                                                }
                                                                else
                                                                    if(labirito[i][j] == 'S'){
                                                                        printf(fundo_red red"S"reset);
                                                                    }
                                                                    else
                                                                        if(labirito[i][j] == '@'){
                                                                            printf(fundo_branco" "reset);
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                                    printf(fundo_magenta" "reset);
                                                                                                    
                                                                                                    
                                                                            }
                                                                            else{
                                                                                printf(" ");
                                                                            }
                                                        }
                                                    }
                                                    for(tempo=0;tempo<tempo_max;tempo++){}
                                                    system("clear||cls");

                                                    printf("\n\tpara sair clique = f");
                                                    printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                                    printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                                    for(i=0;i<linha;i++){
                                                        printf("\n\t\t");
                                                        for(j=0;j<coluna;j++){
                                                            if(labirito[i][j] == 'x'){
                                                                printf(fundo_blue blue" "reset);
                                                                continue;
                                                            }
                                                            else
                                                                if(labirito[i][j] == 'V'){
                                                                    x = i;
                                                                    y = j;
                                                                    printf(fundo_red red" "reset);
                                                                }
                                                                else
                                                                    if(labirito[i][j] == 'S'){
                                                                        printf(fundo_red red"S"reset);
                                                                    }
                                                                    else
                                                                        if(labirito[i][j] == '@'){
                                                                            printf(fundo_branco" "reset);
                                                                        }
                                                                        else{
                                                                            printf(" ");
                                                                        }
                                                        }
                                                    }


                                                    break;
                                                }

                                            }
                                            while(vida > 0 || vida_chefe>0);
                                            break;
                                    case 3: //chefe contra o atirador
                                        combo1 = 0;
                                        combo2 = 0;
                                        cont = 0;
                                            do{
                                                system("clear||cls");
                                                printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" ICC"reset); //introdução sobre o chefe jutamente com as habilidades da classe escolhida
                                                printf("\n\n\t\t\tICC trabalha com binarios, quando vem o terceiro... eh brutal,cuidado");;
                                                printf("\n\n\t\t\tHabilidades da classe "amarelo"Atirador"reset" : "amarelo"i"reset" - Perfuracao eletrizante|| "amarelo"o"reset" - Mata-Craquens||  "amarelo"p"reset" - Arco-escudo ");
                                                printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                                printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                                printf("\n\n\t\t\tICC te jogou uma maquina de turing com arquiterura de von neumann");
                                                dano_chefe = 10;
                                                vida = vida - dano_chefe; 
                                                escudo_basico=(dano_chefe*0.4); //a quantidade de escudo depende do dano do chefe
                                                printf("\n\n\t\t\tLance sua habilidade!!! ");
                                                scanf("%c",&habilidades);
                                                scanf("%*[^\n]");
                                                scanf("%*c");
                                                cont++;
                                                switch(habilidades){
                                                        case 'i': printf("\n\n\t\t\tvoce usou Perfuracao eletrizante, " red"Dano Normal"reset); 
                                                                  combo1++;
                                                                  if(combo1%2 == 0){
                                                                    printf("\n\t\t\t\t"red"COMBO!!"reset);//se a pessoa usar a mesma habilidade 2 vezes seguidas causa  dano extra
                                                                    vida_chefe = vida_chefe - dano_perto_basico - dano_combo;
                                                                  }
                                                                  else{
                                                                    vida_chefe = vida_chefe - dano_perto_basico;
                                                                  }
                                                                  combo2 = 0;
                                                                  scanf("%*[^\n]");
                                                                  scanf("%*c");
                                                                  break;
                                                        case 'o' : printf("\n\n\t\t\tvoce usou Mata-Craquens, "red"Dano Normal"reset);
                                                                   combo2++;
                                                                   if(combo2%2 == 0){
                                                                    printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                                    vida_chefe = vida_chefe - dano_longe_atirador - dano_combo;
                                                                   }
                                                                   else{
                                                                    vida_chefe = vida_chefe - dano_longe_atirador;
                                                                   }
                                                                   combo1 = 0;
                                                                   scanf("%*[^\n]");
                                                                   scanf("%*c");
                                                                   break;
                                                        case 'p' : printf("\n\n\t\t\tvoce usou Arco-escudo, "red"bloqueou parte do proximo ataque do chefe"reset);
                                                                   vida = vida + escudo_basico;
                                                                   if(cont == 3){ //se a pessoa usar o escudo no 3 ataque de icc nao tomará o dano extra
                                                                    cont = 0;
                                                                   }
                                                                   combo1 = 0;
                                                                   combo2 =0;
                                                                   scanf("%*[^\n]");
                                                                   scanf("%*c");
                                                                   break;
                                                        default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , sem segunda chance ;-;");
                                                                 scanf("%*[^\n]");
                                                                 scanf("%*c");

                                                        }
                                                if(cont == 3){ //se a pessoa nao usar escudo no 3 ataque de icc tomará dano extra
                                                    vida = vida - 75;
                                                }
                                                labirito[11][70] = ' '; //retira o chefe da matriz
                                                if(vida<=0){ //printa a tela de derrota
                                                    system("clear||cls");
                                                    for(i=0;i<linha;i++){
                                                        printf("\n\t\t");
                                                        for(j=0;j<coluna;j++){
                                                            if(labirito[i][j] == 'x'){
                                                                printf(fundo_branco" "reset);
                                                                continue;
                                                            }
                                                            else
                                                                if(labirito[i][j] == 'V'){
                                                                    x = i;
                                                                    y = j;
                                                                    printf(fundo_red red" "reset);
                                                                }
                                                                else
                                                                    if(labirito[i][j] == 'S'){
                                                                        printf(fundo_red red"S"reset);
                                                                    }
                                                                    else
                                                                        if(labirito[i][j] == '@'){
                                                                            printf(fundo_red red" "reset);
                                                                        }
                                                                        else{
                                                                            printf(" ");
                                                                        }
                                                        }
                                                    }
                                                    printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                                    fim = 1; //condição para finalizar o jogo
                                                    break;
                                                }
                                                if(vida_chefe<=0){ //printa o labirinto temporario juntamente com o orginal
                                                    nota = nota + 2;
                                                    printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                                    scanf("%*[^\n]");
                                                    scanf("%*c");
                                                    system("clear||cls");

                                                    printf("\n\tpara sair clique = f");
                                                    printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                                    printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                                    
                                                    for(i=0;i<linha;i++){
                                                        printf("\n\t\t");
                                                        for(j=0;j<coluna;j++){
                                                            if(labirito[i][j] == 'x'){
                                                                printf(fundo_blue blue" "reset);
                                                                continue;
                                                            }
                                                            else
                                                                if(labirito[i][j] == 'V'){
                                                                    x = i;
                                                                    y = j;
                                                                    printf(fundo_red red" "reset);
                                                                }
                                                                else
                                                                    if(labirito[i][j] == 'S'){
                                                                        printf(fundo_red red"S"reset);
                                                                    }
                                                                    else
                                                                        if(labirito[i][j] == '@'){
                                                                            printf(fundo_branco" "reset);
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                                    printf(fundo_magenta" "reset);
                                                                                                    
                                                                                                    
                                                                            }
                                                                            else{
                                                                                printf(" ");
                                                                            }
                                                        }
                                                    }
                                                    for(tempo=0;tempo<tempo_max;tempo++){}
                                                    system("clear||cls");

                                                    printf("\n\tpara sair clique = f");
                                                    printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                                    printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                                    for(i=0;i<linha;i++){
                                                        printf("\n\t\t");
                                                        for(j=0;j<coluna;j++){
                                                            if(labirito[i][j] == 'x'){
                                                                printf(fundo_blue blue" "reset);
                                                                continue;
                                                            }
                                                            else
                                                                if(labirito[i][j] == 'V'){
                                                                    x = i;
                                                                    y = j;
                                                                    printf(fundo_red red" "reset);
                                                                }
                                                                else
                                                                    if(labirito[i][j] == 'S'){
                                                                        printf(fundo_red red"S"reset);
                                                                    }
                                                                    else
                                                                        if(labirito[i][j] == '@'){
                                                                            printf(fundo_branco" "reset);
                                                                        }
                                                                        else{
                                                                            printf(" ");
                                                                        }
                                                        }
                                                    }


                                                    break;
                                                }

                                            }
                                            while(vida > 0 || vida_chefe>0);
                                            break;
                                    case 4: //chefe contra a classe tank
                                        combo1 = 0;
                                        combo2 = 0;
                                        combo3 = 0;
                                        cont = 0;
                                            do{
                                                system("clear||cls");
                                                printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" ICC"reset); //introdução sobre o chefe jutamente com as habilidades da classe escolhida
                                                printf("\n\n\t\t\tICC trabalha com binarios, quando vem o terceiro... eh brutal,cuidado");
                                                printf("\n\n\t\t\tHabilidades da classe "amarelo"Tank"reset" : "amarelo"i"reset" - Golpe de escudo fermentado|| "amarelo"o"reset" - Chuva de rochedos||  "amarelo"p"reset" - colete milenar de espinhos cerimoniais ");
                                                printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                                printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                                printf("\n\n\t\t\tICC te jogou uma maquina de turing com arquiterura de von neumann");
                                                dano_chefe = 10;
                                                vida = vida - dano_chefe;
                                                escudo_basico=(dano_chefe*0.4); //a quantidade de escudo depende do dano do chefe
                                                escudo_tank=(dano_chefe*0.8); //o tank tem uma quantidade de escudo maior
                                                printf("\n\n\t\t\tLance sua habilidade!!! ");
                                                scanf("%c",&habilidades);
                                                scanf("%*[^\n]");
                                                scanf("%*c");
                                                cont++;
                                                switch(habilidades){
                                                        case 'i': printf("\n\n\t\t\tvoce usou Golpe de escudo fermentado, " red"Dano normal"reset);
                                                                   combo1++;
                                                                  if(combo1%2 == 0){
                                                                    printf("\n\t\t\t\t"red"COMBO!!"reset); //se a pessoa usar a mesma habilidade 2 vezes seguidas causa  dano extra
                                                                    vida_chefe = vida_chefe - dano_perto_basico - dano_combo;
                                                                  }
                                                                  else{
                                                                    vida_chefe = vida_chefe - dano_perto_basico;
                                                                  }
                                                                  combo2 = 0;
                                                                  combo3 = 0;
                                                                  scanf("%*[^\n]");
                                                                  scanf("%*c");
                                                                  break;
                                                        case 'o' : printf("\n\n\t\t\tvoce usou Chuva de rochedos, "red"Dano normal"reset);
                                                                   combo2++;
                                                                   if(combo2%2 == 0){
                                                                    printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                                    vida_chefe = vida_chefe - dano_longe_basico - dano_combo;
                                                                    }
                                                                    else{
                                                                        vida_chefe = vida_chefe - dano_longe_basico;
                                                                    }
                                                                   combo1 = 0;
                                                                   combo3 = 0;
                                                                   scanf("%*[^\n]");
                                                                   scanf("%*c");
                                                                   break;
                                                        case 'p' : printf("\n\n\t\t\tvoce usou colete milenar de espinhos cerimoniais, "red"bloqueou grande parte do proximo ataque do chefe e aplicou dano refletor"reset);
                                                                   combo3++;
                                                                   if(combo3 > 2){ // o tank nao pode usar a habilidade varias vezes seguidas, caso use sera tratado como um escudo basico
                                                                    printf("\n\t\t\t\t"red"Escudo quebrado!!"reset);
                                                                    vida = vida + escudo_basico;
                                                                   }
                                                                   else{ 
                                                                    vida = vida + escudo_tank;
                                                                    vida_chefe = vida_chefe - dano_tank;
                                                                   }
                                                                   if(cont == 3){ //se a pessoa usar o escudo no 3 ataque de icc nao tomará o dano extra
                                                                    cont = 0;
                                                                   }
                                                                   combo2 = 0;
                                                                   combo1 = 0;

                                                                   scanf("%*[^\n]");
                                                                   scanf("%*c");
                                                                   break;
                                                        default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , sem segunda chance ;-;");
                                                                 scanf("%*[^\n]");
                                                                 scanf("%*c");

                                                        }
                                                if(cont == 3){ //se a pessoa nao usar escudo no 3 ataque de icc tomará dano extra
                                                    vida = vida - 75;
                                                }
                                                labirito[11][70] = ' '; //retira o chefe da matriz
                                                if(vida<=0){ //printa a tela de derrota
                                                    system("clear||cls");
                                                    for(i=0;i<linha;i++){
                                                        printf("\n\t\t");
                                                        for(j=0;j<coluna;j++){
                                                            if(labirito[i][j] == 'x'){
                                                                printf(fundo_branco" "reset);
                                                                continue;
                                                            }
                                                            else
                                                                if(labirito[i][j] == 'V'){
                                                                    x = i;
                                                                    y = j;
                                                                    printf(fundo_red red" "reset);
                                                                }
                                                                else
                                                                    if(labirito[i][j] == 'S'){
                                                                        printf(fundo_red red"S"reset);
                                                                    }
                                                                    else
                                                                        if(labirito[i][j] == '@'){
                                                                            printf(fundo_red red" "reset);
                                                                        }
                                                                        else{
                                                                            printf(" ");
                                                                        }
                                                        }
                                                    }
                                                    printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                                    fim = 1; //condição para finalizar o jogo
                                                    break;
                                                }
                                                if(vida_chefe<=0){ //printa o labirinto temporario juntamente com o orginal
                                                    nota = nota + 2;
                                                    printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                                    scanf("%*[^\n]");
                                                    scanf("%*c");
                                                    system("clear||cls");

                                                    printf("\n\tpara sair clique = f");
                                                    printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                                    printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                                    
                                                    for(i=0;i<linha;i++){
                                                        printf("\n\t\t");
                                                        for(j=0;j<coluna;j++){
                                                            if(labirito[i][j] == 'x'){
                                                                printf(fundo_blue blue" "reset);
                                                                continue;
                                                            }
                                                            else
                                                                if(labirito[i][j] == 'V'){
                                                                    x = i;
                                                                    y = j;
                                                                    printf(fundo_red red" "reset);
                                                                }
                                                                else
                                                                    if(labirito[i][j] == 'S'){
                                                                        printf(fundo_red red"S"reset);
                                                                    }
                                                                    else
                                                                        if(labirito[i][j] == '@'){
                                                                            printf(fundo_branco" "reset);
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                                    printf(fundo_magenta" "reset);
                                                                                                    
                                                                                                    
                                                                            }
                                                                            else{
                                                                                printf(" ");
                                                                            }
                                                        }
                                                    }
                                                    for(tempo=0;tempo<tempo_max;tempo++){}
                                                    system("clear||cls");

                                                    printf("\n\tpara sair clique = f");
                                                    printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                                    printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                                    for(i=0;i<linha;i++){
                                                        printf("\n\t\t");
                                                        for(j=0;j<coluna;j++){
                                                            if(labirito[i][j] == 'x'){
                                                                printf(fundo_blue blue" "reset);
                                                                continue;
                                                            }
                                                            else
                                                                if(labirito[i][j] == 'V'){
                                                                    x = i;
                                                                    y = j;
                                                                    printf(fundo_red red" "reset);
                                                                }
                                                                else
                                                                    if(labirito[i][j] == 'S'){
                                                                        printf(fundo_red red"S"reset);
                                                                    }
                                                                    else
                                                                        if(labirito[i][j] == '@'){
                                                                            printf(fundo_branco" "reset);
                                                                        }
                                                                        else{
                                                                            printf(" ");
                                                                        }
                                                        }
                                                    }


                                                    break;
                                                }

                                            }
                                            while(vida > 0 || vida_chefe>0);
                                            break;
                                    }

                            }
                            else
                                if(labirito[x][y+1] == 'l' || labirito[x-1][y] == 'l' || labirito[x][y-1] == 'l' ||labirito[x +1][y] == 'l' ){ //se o jogador estiver perto do chefe ativará o mini-game
                                    vida_chefe = 100;
                                    system("clear||cls");
                                    printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Calculo"reset);
                                    printf("\n\n\t\t\tCalculo eh um chefe enjoado, ele nao gosta muito de coisas repetidas, varie pequena variavel");

                                    switch(classe){ 
                                        case 1: //chefe contra a classe mago
                                            combo1 = 0;
                                            combo2 = 0;
                                                do{
                                                    system("clear||cls");
                                                    printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Calculo"reset); //introdução sobre o chefe jutamente com as habilidades da classe escolhida
                                                    printf("\n\n\t\t\tCalculo eh um chefe enjoado, ele nao gosta muito de coisas repetidas, varie pequena variavel");
                                                    printf("\n\n\t\t\tHabilidades da classe "amarelo"Mago"reset" : "amarelo"i"reset" - Soco da mae Fenix|| "amarelo"o"reset" - Raio destruidor de sinapses neurais||  "amarelo"p"reset" - escudo de gelo verdadeiro ");
                                                    printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                                    printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                                    printf("\n\n\t\t\tCalculo multiplicou pi * Euler,travou tudo ne Bb");
                                                    dano_chefe = 10;
                                                    vida = vida - dano_chefe;
                                                    escudo_basico=(dano_chefe*0.4); //a quantidade de escudo depende do dano do chefe
                                                    printf("\n\n\t\t\tLance sua habilidade!!! ");
                                                    scanf("%c",&habilidades);
                                                    scanf("%*[^\n]");
                                                    scanf("%*c");
                                                    switch(habilidades){
                                                            case 'i': printf("\n\n\t\t\tvoce usou o Soco da mae fenix, " red"Dano Normal"reset);
                                                                      combo1++;
                                                                      if(combo1%2 == 0){ //se a pessoa usar a mesma habilidade 2 vezes seguidas recebera dano extra
                                                                        printf("\n\t\t\t\t"red"Vish!!"reset);
                                                                        vida = vida - 60;
                                                                      }
                                                                      else{
                                                                        vida_chefe = vida_chefe - dano_perto_basico;
                                                                      }
                                                                      combo2 =0;
                                                                      scanf("%*[^\n]");
                                                                      scanf("%*c");
                                                                      break;
                                                            case 'o' : printf("\n\n\t\t\tvoce usou o Raio destruidor de sinapses neurais, "red"Dano Normal"reset);
                                                                       combo2++;
                                                                       if(combo2%2 == 0){
                                                                         printf("\n\t\t\t\t"red"Vish!!"reset);
                                                                         vida = vida - 60;
                                                                       }
                                                                       else{
                                                                         vida_chefe = vida_chefe - dano_longe_basico;
                                                                       }
                                                                       combo1 = 0;
                                                                       scanf("%*[^\n]");
                                                                       scanf("%*c");
                                                                       break;
                                                            case 'p' : printf("\n\n\t\t\tvoce usou o escudo de gelo verdadeiro, "red"bloqueou parte do proximo ataque do chefe"reset);
                                                                       vida = vida + escudo_basico;
                                                                       combo1 = 0;
                                                                       combo2 = 0;
                                                                       scanf("%*[^\n]");
                                                                       scanf("%*c");
                                                                       break;
                                                            default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , sem segunda chance ;-;");
                                                                     scanf("%*[^\n]");
                                                                     scanf("%*c");

                                                            }
                                                    labirito[16][93] = ' '; //retira o chefe da matriz
                                                    if(vida<=0){ //printa a tela de derrota
                                                            system("clear||cls");
                                                            for(i=0;i<linha;i++){
                                                                printf("\n\t\t");
                                                                for(j=0;j<coluna;j++){
                                                                    if(labirito[i][j] == 'x'){
                                                                        printf(fundo_branco" "reset);
                                                                        continue;
                                                                    }
                                                                    else
                                                                        if(labirito[i][j] == 'V'){
                                                                            x = i;
                                                                            y = j;
                                                                            printf(fundo_red red" "reset);
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == 'S'){
                                                                                printf(fundo_red red"S"reset);
                                                                            }
                                                                            else
                                                                                if(labirito[i][j] == '@'){
                                                                                    printf(fundo_red red" "reset);
                                                                                }
                                                                                else{
                                                                                    printf(" ");
                                                                                }
                                                                }
                                                            }
                                                            printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                                            fim = 1; //condição para finalizar o jogo
                                                            break;
                                                    }
                                                    if(vida_chefe<=0){ //printa o labirinto temporario juntamente com o orginal
                                                        for(cont=1;vida<vida_max;cont++){ //o mago recupera sanidade ao matar o chefe
                                                            vida++;
                                                            if(cont == vida_ext){
                                                                break;
                                                            }
                                                        }
                                                        nota = nota + 2;
                                                        printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                                        scanf("%*[^\n]");
                                                        scanf("%*c");
                                                        system("clear||cls");

                                                        printf("\n\tpara sair clique = f");
                                                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                                        
                                                        for(i=0;i<linha;i++){
                                                            printf("\n\t\t");
                                                            for(j=0;j<coluna;j++){
                                                                if(labirito[i][j] == 'x'){
                                                                    printf(fundo_blue blue" "reset);
                                                                    continue;
                                                                }
                                                                else
                                                                    if(labirito[i][j] == 'V'){
                                                                        x = i;
                                                                        y = j;
                                                                        printf(fundo_red red" "reset);
                                                                    }
                                                                    else
                                                                        if(labirito[i][j] == 'S'){
                                                                            printf(fundo_red red"S"reset);
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == '@'){
                                                                                printf(fundo_branco" "reset);
                                                                            }
                                                                            else
                                                                                if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                                        printf(fundo_magenta" "reset);
                                                                                                        
                                                                                                        
                                                                                }
                                                                                else{
                                                                                    printf(" ");
                                                                                }
                                                            }
                                                        }
                                                        for(tempo=0;tempo<tempo_max;tempo++){}
                                                        system("clear||cls");

                                                        printf("\n\tpara sair clique = f");
                                                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                                        for(i=0;i<linha;i++){
                                                            printf("\n\t\t");
                                                            for(j=0;j<coluna;j++){
                                                                if(labirito[i][j] == 'x'){
                                                                    printf(fundo_blue blue" "reset);
                                                                    continue;
                                                                }
                                                                else
                                                                    if(labirito[i][j] == 'V'){
                                                                        x = i;
                                                                        y = j;
                                                                        printf(fundo_red red" "reset);
                                                                    }
                                                                    else
                                                                        if(labirito[i][j] == 'S'){
                                                                            printf(fundo_red red"S"reset);
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == '@'){
                                                                                printf(fundo_branco" "reset);
                                                                            }
                                                                            else{
                                                                                printf(" ");
                                                                            }
                                                            }
                                                        }


                                                        break;
                                                    }

                                                }
                                                while(vida > 0 || vida_chefe>0);
                                                break;
                                        case 2: //chefe contra o assasino
                                            combo1 = 0;
                                            combo2 = 0;
                                                do{
                                                    system("clear||cls");
                                                    printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Calculo"reset); //introdução sobre o chefe jutamente com as habilidades da classe escolhida
                                                    printf("\n\n\t\t\tCalculo eh um chefe enjoado, ele nao gosta muito de coisas repetidas, varie pequena variavel");
                                                    printf("\n\n\t\t\tHabilidades da classe "amarelo"Assasino"reset" : "amarelo"i"reset" - Ataque armageddon|| "amarelo"o"reset" - shurikens flamejantes||  "amarelo"p"reset" - Fuga canibal ");
                                                    printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                                    printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                                    printf("\n\n\t\t\tCalculo multiplicou pi * Euler,travou tudo ne Bb");
                                                    dano_chefe = 10;
                                                    vida = vida - dano_chefe;
                                                    escudo_basico=(dano_chefe*0.4); //a quantidade de escudo depende do dano do chefe
                                                    printf("\n\n\t\t\tLance sua habilidade!!! ");
                                                    scanf("%c",&habilidades);
                                                    scanf("%*[^\n]");
                                                    scanf("%*c");
                                                    switch(habilidades){
                                                            case 'i': printf("\n\n\t\t\tvoce usou o Ataque armageddon, " red"Dano Normal"reset);
                                                                      combo1++;
                                                                      if(combo1%2 ==0){ //se a pessoa usar a mesma habilidade 2 vezes seguidas recebera dano extra
                                                                        printf("\n\t\t\t\t"red"Vish!!"reset);
                                                                        vida = vida - 60;
                                                                      }
                                                                      else{
                                                                        vida_chefe = vida_chefe - dano_perto_assasino;
                                                                      }
                                                                      combo2 =0;
                                                                      scanf("%*[^\n]");
                                                                      scanf("%*c");
                                                                      break;
                                                            case 'o' : printf("\n\n\t\t\tvoce usou shurikens flamejantes, "red"Dano Normal"reset);
                                                                       combo2++;
                                                                       if(combo2%2 == 0){
                                                                        printf("\n\t\t\t\t"red"Vish!!"reset);
                                                                        vida = vida - 60;
                                                                       }
                                                                       else{
                                                                        vida_chefe = vida_chefe - dano_longe_basico;
                                                                       }
                                                                       combo1 = 0;
                                                                       scanf("%*[^\n]");
                                                                       scanf("%*c");
                                                                       break;
                                                            case 'p' : printf("\n\n\t\t\tvoce usou Fuga canibal, "red"bloqueou parte do proximo ataque do chefe"reset);
                                                                       vida = vida + escudo_basico;
                                                                       combo1 = 0;
                                                                       combo2 =0;
                                                                       scanf("%*[^\n]");
                                                                       scanf("%*c");
                                                                       break;
                                                            default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , sem segunda chance ;-;");
                                                                     scanf("%*[^\n]");
                                                                     scanf("%*c");

                                                            }
                                                    labirito[16][93] = ' '; //retira o chefe da matriz
                                                    if(vida<=0){ //printa a tela de derrota
                                                            system("clear||cls");
                                                            for(i=0;i<linha;i++){
                                                                printf("\n\t\t");
                                                                for(j=0;j<coluna;j++){
                                                                    if(labirito[i][j] == 'x'){
                                                                        printf(fundo_branco" "reset);
                                                                        continue;
                                                                    }
                                                                    else
                                                                        if(labirito[i][j] == 'V'){
                                                                            x = i;
                                                                            y = j;
                                                                            printf(fundo_red red" "reset);
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == 'S'){
                                                                                printf(fundo_red red"S"reset);
                                                                            }
                                                                            else
                                                                                if(labirito[i][j] == '@'){
                                                                                    printf(fundo_red red" "reset);
                                                                                }
                                                                                else{
                                                                                    printf(" ");
                                                                                }
                                                                }
                                                            }
                                                            printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                                            fim = 1; //condição para finalizar o jogo
                                                            break;
                                                    }
                                                    if(vida_chefe<=0){ //printa o labirinto temporario juntamente com o orginal
                                                        nota = nota + 2;
                                                        printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                                        scanf("%*[^\n]");
                                                        scanf("%*c");
                                                        system("clear||cls");

                                                        printf("\n\tpara sair clique = f");
                                                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                                        
                                                        for(i=0;i<linha;i++){
                                                            printf("\n\t\t");
                                                            for(j=0;j<coluna;j++){
                                                                if(labirito[i][j] == 'x'){
                                                                    printf(fundo_blue blue" "reset);
                                                                    continue;
                                                                }
                                                                else
                                                                    if(labirito[i][j] == 'V'){
                                                                        x = i;
                                                                        y = j;
                                                                        printf(fundo_red red" "reset);
                                                                    }
                                                                    else
                                                                        if(labirito[i][j] == 'S'){
                                                                            printf(fundo_red red"S"reset);
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == '@'){
                                                                                printf(fundo_branco" "reset);
                                                                            }
                                                                            else
                                                                                if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                                        printf(fundo_magenta" "reset);
                                                                                                        
                                                                                                        
                                                                                }
                                                                                else{
                                                                                    printf(" ");
                                                                                }
                                                            }
                                                        }
                                                        for(tempo=0;tempo<tempo_max;tempo++){}
                                                        system("clear||cls");

                                                        printf("\n\tpara sair clique = f");
                                                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                                        for(i=0;i<linha;i++){
                                                            printf("\n\t\t");
                                                            for(j=0;j<coluna;j++){
                                                                if(labirito[i][j] == 'x'){
                                                                    printf(fundo_blue blue" "reset);
                                                                    continue;
                                                                }
                                                                else
                                                                    if(labirito[i][j] == 'V'){
                                                                        x = i;
                                                                        y = j;
                                                                        printf(fundo_red red" "reset);
                                                                    }
                                                                    else
                                                                        if(labirito[i][j] == 'S'){
                                                                            printf(fundo_red red"S"reset);
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == '@'){
                                                                                printf(fundo_branco" "reset);
                                                                            }
                                                                            else{
                                                                                printf(" ");
                                                                            }
                                                            }
                                                        }


                                                        break;
                                                    }

                                                }
                                                while(vida > 0 || vida_chefe>0);
                                                break;
                                        case 3: //chefe contra o atirador
                                            combo1 = 0;
                                            combo2 = 0;
                                                do{
                                                    system("clear||cls");
                                                    printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Calculo"reset); //introdução sobre o chefe jutamente com as habilidades da classe escolhida
                                                    printf("\n\n\t\t\tCalculo eh um chefe enjoado, ele nao gosta muito de coisas repetidas, varie pequena variavel");
                                                    printf("\n\n\t\t\tHabilidades da classe "amarelo"Atirador"reset" : "amarelo"i"reset" - Perfuracao eletrizante|| "amarelo"o"reset" - Mata-Craquens||  "amarelo"p"reset" - Arco-escudo ");
                                                    printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                                    printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                                    printf("\n\n\t\t\tCalculo multiplicou Pi * Euler,travou tudo Bb");
                                                    dano_chefe = 10;
                                                    vida = vida - dano_chefe;
                                                    escudo_basico=(dano_chefe*0.4); //a quantidade de escudo depende do dano do chefe
                                                    printf("\n\n\t\t\tLance sua habilidade!!! ");
                                                    scanf("%c",&habilidades);
                                                    scanf("%*[^\n]");
                                                    scanf("%*c");
                                                    switch(habilidades){
                                                            case 'i': printf("\n\n\t\t\tvoce usou Perfuracao eletrizante, " red"Dano Normal"reset);
                                                                      combo1++;
                                                                      if(combo1%2 == 0){ //se a pessoa usar a mesma habilidade 2 vezes seguidas recebera dano extra
                                                                        printf("\n\t\t\t\t"red"Vish!!"reset);
                                                                        vida = vida - 60;
                                                                      }
                                                                      else{
                                                                        vida_chefe = vida_chefe - dano_perto_basico;
                                                                      }
                                                                      combo2 = 0;
                                                                      scanf("%*[^\n]");
                                                                      scanf("%*c");
                                                                      break;
                                                            case 'o' : printf("\n\n\t\t\tvoce usou Mata-Craquens, "red"Dano Normal"reset);
                                                                       combo2++;
                                                                       if(combo2%2 == 0){
                                                                        printf("\n\t\t\t\t"red"Vish!!"reset);
                                                                        vida = vida - 60;
                                                                       }
                                                                       else{
                                                                        vida_chefe = vida_chefe - dano_longe_atirador;
                                                                       }
                                                                       combo1 = 0;
                                                                       scanf("%*[^\n]");
                                                                       scanf("%*c");
                                                                       break;
                                                            case 'p' : printf("\n\n\t\t\tvoce usou Arco-escudo, "red"bloqueou parte do proximo ataque do chefe"reset);
                                                                       vida = vida + escudo_basico;
                                                                       combo1 = 0;
                                                                       combo2 =0;
                                                                       scanf("%*[^\n]");
                                                                       scanf("%*c");
                                                                       break;
                                                            default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , sem segunda chance ;-;");
                                                                     scanf("%*[^\n]");
                                                                     scanf("%*c");

                                                            }
                                                    labirito[16][93] = ' '; //retira o chefe da matriz
                                                    if(vida<=0){ //printa a tela de derrota
                                                            system("clear||cls");
                                                            for(i=0;i<linha;i++){
                                                                printf("\n\t\t");
                                                                for(j=0;j<coluna;j++){
                                                                    if(labirito[i][j] == 'x'){
                                                                        printf(fundo_branco" "reset);
                                                                        continue;
                                                                    }
                                                                    else
                                                                        if(labirito[i][j] == 'V'){
                                                                            x = i;
                                                                            y = j;
                                                                            printf(fundo_red red" "reset);
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == 'S'){
                                                                                printf(fundo_red red"S"reset);
                                                                            }
                                                                            else
                                                                                if(labirito[i][j] == '@'){
                                                                                    printf(fundo_red red" "reset);
                                                                                }
                                                                                else{
                                                                                    printf(" ");
                                                                                }
                                                                }
                                                            }
                                                            printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                                            fim = 1; //condição para finalizar o jogo
                                                            break;
                                                    }
                                                    if(vida_chefe<=0){ //printa o labirinto temporario juntamente com o orginal
                                                        nota = nota + 2;
                                                        printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                                        scanf("%*[^\n]");
                                                        scanf("%*c");
                                                        system("clear||cls");

                                                        printf("\n\tpara sair clique = f");
                                                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                                        
                                                        for(i=0;i<linha;i++){
                                                            printf("\n\t\t");
                                                            for(j=0;j<coluna;j++){
                                                                if(labirito[i][j] == 'x'){
                                                                    printf(fundo_blue blue" "reset);
                                                                    continue;
                                                                }
                                                                else
                                                                    if(labirito[i][j] == 'V'){
                                                                        x = i;
                                                                        y = j;
                                                                        printf(fundo_red red" "reset);
                                                                    }
                                                                    else
                                                                        if(labirito[i][j] == 'S'){
                                                                            printf(fundo_red red"S"reset);
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == '@'){
                                                                                printf(fundo_branco" "reset);
                                                                            }
                                                                            else
                                                                                if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                                        printf(fundo_magenta" "reset);
                                                                                                        
                                                                                                        
                                                                                }
                                                                                else{
                                                                                    printf(" ");
                                                                                }
                                                            }
                                                        }
                                                        for(tempo=0;tempo<tempo_max;tempo++){}
                                                        system("clear||cls");

                                                        printf("\n\tpara sair clique = f");
                                                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                                        for(i=0;i<linha;i++){
                                                            printf("\n\t\t");
                                                            for(j=0;j<coluna;j++){
                                                                if(labirito[i][j] == 'x'){
                                                                    printf(fundo_blue blue" "reset);
                                                                    continue;
                                                                }
                                                                else
                                                                    if(labirito[i][j] == 'V'){
                                                                        x = i;
                                                                        y = j;
                                                                        printf(fundo_red red" "reset);
                                                                    }
                                                                    else
                                                                        if(labirito[i][j] == 'S'){
                                                                            printf(fundo_red red"S"reset);
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == '@'){
                                                                                printf(fundo_branco" "reset);
                                                                            }
                                                                            else{
                                                                                printf(" ");
                                                                            }
                                                            }
                                                        }


                                                        break;
                                                    }

                                                }
                                                while(vida > 0 || vida_chefe>0);
                                                break;
                                        case 4: //chefe contra a classe tank
                                            combo1 = 0;
                                            combo2 = 0;
                                            combo3 = 0;
                                                do{
                                                    system("clear||cls");
                                                    printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Calculo"reset); //introdução sobre o chefe jutamente com as habilidades da classe escolhida
                                                    printf("\n\n\t\t\tCalculo eh um chefe enjoado, ele nao gosta muito de coisas repetidas, varie pequena variavel");
                                                    printf("\n\n\t\t\tHabilidades da classe "amarelo"Tank"reset" : "amarelo"i"reset" - Golpe de escudo fermentado|| "amarelo"o"reset" - Chuva de rochedos||  "amarelo"p"reset" - colete milenar de espinhos cerimoniais ");
                                                    printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                                    printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                                    printf("\n\n\t\t\tCalculo multiplicou Pi * Euler,travou tudo ne Bb");
                                                    dano_chefe = 10;
                                                    vida = vida - dano_chefe;
                                                    escudo_basico=(dano_chefe*0.4); //a quantidade de escudo depende do dano do chefe
                                                    escudo_tank=(dano_chefe*0.8); //o tank tem uma quantidade de escudo maior
                                                    printf("\n\n\t\t\tLance sua habilidade!!! ");
                                                    scanf("%c",&habilidades);
                                                    scanf("%*[^\n]");
                                                    scanf("%*c");
                                                    switch(habilidades){
                                                            case 'i': printf("\n\n\t\t\tvoce usou Golpe de escudo fermentado, " red"Dano Normal"reset);
                                                                       combo1++;
                                                                      if(combo1%2 == 0){
                                                                        printf("\n\t\t\t\t"red"Vish!!"reset); //se a pessoa usar a mesma habilidade 2 vezes seguidas recebera dano extra
                                                                        vida = vida - 60;
                                                                      }
                                                                      else{
                                                                        vida_chefe = vida_chefe - dano_perto_basico;
                                                                      }
                                                                      combo2 = 0;
                                                                      combo3 = 0;
                                                                      scanf("%*[^\n]");
                                                                      scanf("%*c");
                                                                      break;
                                                            case 'o' : printf("\n\n\t\t\tvoce usou Chuva de rochedos, "red"Dano Normal"reset);
                                                                       combo2++;
                                                                       if(combo2%2 == 0){
                                                                        printf("\n\t\t\t\t"red"Vish!!"reset);
                                                                        vida = vida - 60;
                                                                        }
                                                                        else{
                                                                            vida_chefe = vida_chefe - dano_longe_basico;
                                                                        }
                                                                       combo1 = 0;
                                                                       combo3 = 0;
                                                                       scanf("%*[^\n]");
                                                                       scanf("%*c");
                                                                       break;
                                                            case 'p' : printf("\n\n\t\t\tvoce usou colete milenar de espinhos cerimoniais, "red"bloqueou grande parte do proximo ataque do chefe e aplicou dano refletor"reset);
                                                                       combo3++;
                                                                       if(combo3%2 == 0){ //nesse caso usar o escudo 2 vezes contará como combo
                                                                        printf("\n\t\t\t\t"red"Vish!!"reset);
                                                                        vida = vida - 60;
                                                                       }
                                                                       else{
                                                                        vida = vida + escudo_tank;
                                                                        vida_chefe = vida_chefe - dano_tank;
                                                                       }
                                                                       combo2 = 0;
                                                                       combo1 = 0;

                                                                       scanf("%*[^\n]");
                                                                       scanf("%*c");
                                                                       break;
                                                            default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , sem segunda chance ;-;");
                                                                     scanf("%*[^\n]");
                                                                     scanf("%*c");

                                                            }
                                                    labirito[16][93] = ' '; //retira o chefe da matriz
                                                    if(vida<=0){ //printa a tela de derrota
                                                            system("clear||cls");
                                                            for(i=0;i<linha;i++){
                                                                printf("\n\t\t");
                                                                for(j=0;j<coluna;j++){
                                                                    if(labirito[i][j] == 'x'){
                                                                        printf(fundo_branco" "reset);
                                                                        continue;
                                                                    }
                                                                    else
                                                                        if(labirito[i][j] == 'V'){
                                                                            x = i;
                                                                            y = j;
                                                                            printf(fundo_red red" "reset);
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == 'S'){
                                                                                printf(fundo_red red"S"reset);
                                                                            }
                                                                            else
                                                                                if(labirito[i][j] == '@'){
                                                                                    printf(fundo_red red" "reset);
                                                                                }
                                                                                else{
                                                                                    printf(" ");
                                                                                }
                                                                }
                                                            }
                                                            printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                                            fim = 1; //condição para finalizar o jogo
                                                            break;
                                                    }
                                                    if(vida_chefe<=0){ //printa o labirinto temporario juntamente com o orginal
                                                        nota = nota + 2;
                                                        printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                                        scanf("%*[^\n]");
                                                        scanf("%*c");
                                                        system("clear||cls");

                                                        printf("\n\tpara sair clique = f");
                                                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                                        
                                                        for(i=0;i<linha;i++){
                                                            printf("\n\t\t");
                                                            for(j=0;j<coluna;j++){
                                                                if(labirito[i][j] == 'x'){
                                                                    printf(fundo_blue blue" "reset);
                                                                    continue;
                                                                }
                                                                else
                                                                    if(labirito[i][j] == 'V'){
                                                                        x = i;
                                                                        y = j;
                                                                        printf(fundo_red red" "reset);
                                                                    }
                                                                    else
                                                                        if(labirito[i][j] == 'S'){
                                                                            printf(fundo_red red"S"reset);
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == '@'){
                                                                                printf(fundo_branco" "reset);
                                                                            }
                                                                            else
                                                                                if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                                        printf(fundo_magenta" "reset);
                                                                                                        
                                                                                                        
                                                                                }
                                                                                else{
                                                                                    printf(" ");
                                                                                }
                                                            }
                                                        }
                                                        for(tempo=0;tempo<tempo_max;tempo++){}
                                                        system("clear||cls");

                                                        printf("\n\tpara sair clique = f");
                                                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                                        for(i=0;i<linha;i++){
                                                            printf("\n\t\t");
                                                            for(j=0;j<coluna;j++){
                                                                if(labirito[i][j] == 'x'){
                                                                    printf(fundo_blue blue" "reset);
                                                                    continue;
                                                                }
                                                                else
                                                                    if(labirito[i][j] == 'V'){
                                                                        x = i;
                                                                        y = j;
                                                                        printf(fundo_red red" "reset);
                                                                    }
                                                                    else
                                                                        if(labirito[i][j] == 'S'){
                                                                            printf(fundo_red red"S"reset);
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == '@'){
                                                                                printf(fundo_branco" "reset);
                                                                            }
                                                                            else{
                                                                                printf(" ");
                                                                            }
                                                            }
                                                        }


                                                        break;
                                                    }

                                                }
                                                while(vida > 0 || vida_chefe>0);
                                                break;
                                        }

                                }
                                else
                                    if(labirito[x][y+1] == 'n' || labirito[x-1][y] == 'n' || labirito[x][y-1] == 'n' ||labirito[x +1][y] == 'n' ){ //se o jogador estiver perto do chefe ativará o mini-game
                                            vida_chefe = 100;
                                            system("clear||cls");
                                            printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Final Boss !! : LP"reset);
                                            printf("\n\n\t\t\tLP eh um chefe ardiloso,quando voce menos espera ele ...");

                                            switch(classe){
                                                case 1: //chefe contra a classe mago
                                                    combo1 = 0;
                                                    combo2 = 0;
                                                    cont = 0;
                                                        do{
                                                            system("clear||cls");
                                                            printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Final Boss !! : LP"reset);//introdução sobre o chefe jutamente com as habilidades da classe escolhida
                                                            printf("\n\n\t\t\tLP eh um chefe ardiloso,quando voce menos espera ele ...");
                                                            printf("\n\n\t\t\tHabilidades da classe "amarelo"Mago"reset" : "amarelo"i"reset" - Soco da mae Fenix|| "amarelo"o"reset" - Raio destruidor de sinapses neurais||  "amarelo"p"reset" - escudo de gelo verdadeiro ");
                                                            printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                                            printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                                            printf("\n\n\t\t\tLP tirou um ';' do seu programa");
                                                            if(cont == 0){ // o dano desse chefe muda
                                                                dano_chefe = 5;
                                                            }
                                                            vida = vida - dano_chefe;
                                                            escudo_basico=(dano_chefe*0.4); //a quantidade de escudo depende do dano do chefe
                                                            printf("\n\n\t\t\tLance sua habilidade!!! ");
                                                            scanf("%c",&habilidades);
                                                            scanf("%*[^\n]");
                                                            scanf("%*c");
                                                            switch(habilidades){
                                                                    case 'i': printf("\n\n\t\t\tvoce usou o Soco da mae fenix, " red"Dano Normal"reset);
                                                                              combo1++;
                                                                              if(combo1%2 == 0){
                                                                                printf("\n\t\t\t\t"red"COMBO!!"reset); //se a pessoa usar a mesma habilidade 2 vezes seguidas causa  dano extra
                                                                                vida_chefe = vida_chefe - dano_perto_basico - dano_combo;
                                                                              }
                                                                              else{
                                                                                vida_chefe = vida_chefe - dano_perto_basico;
                                                                              }
                                                                              combo2 =0;
                                                                              scanf("%*[^\n]");
                                                                              scanf("%*c");
                                                                              break;
                                                                    case 'o' : printf("\n\n\t\t\tvoce usou o Raio destruidor de sinapses neurais, "red"Dano Normal"reset);
                                                                               combo2++;
                                                                               if(combo2%2 == 0){
                                                                                 printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                                                 vida_chefe = vida_chefe - dano_longe_basico- dano_combo;
                                                                               }
                                                                               else{
                                                                                 vida_chefe = vida_chefe - dano_longe_basico;
                                                                               }
                                                                               combo1 = 0;
                                                                               scanf("%*[^\n]");
                                                                               scanf("%*c");
                                                                               break;
                                                                    case 'p' : printf("\n\n\t\t\tvoce usou o escudo de gelo verdadeiro, "red"bloqueou parte do proximo ataque do chefe"reset);
                                                                               vida = vida + escudo_basico;
                                                                               combo1 = 0;
                                                                               combo2 = 0;
                                                                               scanf("%*[^\n]");
                                                                               scanf("%*c");
                                                                               break;
                                                                    default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , sem segunda chance ;-;");
                                                                             scanf("%*[^\n]");
                                                                             scanf("%*c");

                                                                    }
                                                            if(vida_chefe <= 30 && cont == 0){ // quando a vida do chefe estiver <= 30 ele voltara mais forte
                                                                cont = 1; // para acontecer so uma vez
                                                                vida_chefe = 125;
                                                                dano_chefe = 15;

                                                            }
                                                            labirito[7][93] = ' '; //retira o chefe da matriz
                                                            if(vida<=0){ //printa a tela de derrota
                                                                system("clear||cls");
                                                                for(i=0;i<linha;i++){
                                                                    printf("\n\t\t");
                                                                    for(j=0;j<coluna;j++){
                                                                        if(labirito[i][j] == 'x'){
                                                                            printf(fundo_branco" "reset);
                                                                            continue;
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == 'V'){
                                                                                x = i;
                                                                                y = j;
                                                                                printf(fundo_red red" "reset);
                                                                            }
                                                                            else
                                                                                if(labirito[i][j] == 'S'){
                                                                                    printf(fundo_red red"S"reset);
                                                                                }
                                                                                else
                                                                                    if(labirito[i][j] == '@'){
                                                                                        printf(fundo_red red" "reset);
                                                                                    }
                                                                                    else{
                                                                                        printf(" ");
                                                                                    }
                                                                    }
                                                                }
                                                                printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                                                fim = 1; //condição para finalizar o jogo
                                                                break;
                                                            }
                                                            if(vida_chefe<=0){ //printa o labirinto temporario juntamente com o orginal
                                                                for(cont=1;vida<vida_max;cont++){ //o mago recupera sanidade ao matar o chefe
                                                                    vida++;
                                                                    if(cont == vida_ext){
                                                                        break;
                                                                    }
                                                                }
                                                                labirito[7][91] = ' '; //abre uma parede
                                                                nota = nota + 2;
                                                                printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                                                scanf("%*[^\n]");
                                                                scanf("%*c");
                                                                system("clear||cls");

                                                                printf("\n\tpara sair clique = f");
                                                                printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                                                printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                                                
                                                                for(i=0;i<linha;i++){
                                                                    printf("\n\t\t");
                                                                    for(j=0;j<coluna;j++){
                                                                        if(labirito[i][j] == 'x'){
                                                                            printf(fundo_blue blue" "reset);
                                                                            continue;
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == 'V'){
                                                                                x = i;
                                                                                y = j;
                                                                                printf(fundo_red red" "reset);
                                                                            }
                                                                            else
                                                                                if(labirito[i][j] == 'S'){
                                                                                    printf(fundo_red red"S"reset);
                                                                                }
                                                                                else
                                                                                    if(labirito[i][j] == '@'){
                                                                                        printf(fundo_branco" "reset);
                                                                                    }
                                                                                    else
                                                                                        if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                                                printf(fundo_magenta" "reset);
                                                                                                                
                                                                                                                
                                                                                        }
                                                                                        else{
                                                                                            printf(" ");
                                                                                        }
                                                                    }
                                                                }
                                                                for(tempo=0;tempo<tempo_max;tempo++){}
                                                                system("clear||cls");

                                                                printf("\n\tpara sair clique = f");
                                                                printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                                                printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                                                for(i=0;i<linha;i++){
                                                                    printf("\n\t\t");
                                                                    for(j=0;j<coluna;j++){
                                                                        if(labirito[i][j] == 'x'){
                                                                            printf(fundo_blue blue" "reset);
                                                                            continue;
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == 'V'){
                                                                                x = i;
                                                                                y = j;
                                                                                printf(fundo_red red" "reset);
                                                                            }
                                                                            else
                                                                                if(labirito[i][j] == 'S'){
                                                                                    printf(fundo_red red"S"reset);
                                                                                }
                                                                                else
                                                                                    if(labirito[i][j] == '@'){
                                                                                        printf(fundo_branco" "reset);
                                                                                    }
                                                                                    else{
                                                                                        printf(" ");
                                                                                    }
                                                                    }
                                                                }


                                                                break;
                                                            }

                                                        }
                                                        while(vida > 0 || vida_chefe>0);
                                                        break;
                                                case 2: //chefe contra o assasino
                                                    combo1 = 0;
                                                    combo2 = 0;
                                                    cont = 0;
                                                        do{
                                                            system("clear||cls");
                                                            printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Final Boss !! : LP"reset);
                                                            printf("\n\n\t\t\tLP eh um chefe ardiloso,quando voce menos espera ele ...");
                                                            printf("\n\n\t\t\tHabilidades da classe "amarelo"Assasino"reset" : "amarelo"i"reset" - Ataque armageddon|| "amarelo"o"reset" - shurikens flamejantes||  "amarelo"p"reset" - Fuga canibal ");
                                                            printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                                            printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                                            printf("\n\n\t\t\tLP tirou um ';' no seu programa");
                                                            if(cont == 0){ // o dano desse chefe muda
                                                                dano_chefe = 5;
                                                            }
                                                            vida = vida - dano_chefe;
                                                            escudo_basico=(dano_chefe*0.4); //a quantidade de escudo depende do dano do chefe
                                                            printf("\n\n\t\t\tLance sua habilidade!!! ");
                                                            scanf("%c",&habilidades);
                                                            scanf("%*[^\n]");
                                                            scanf("%*c");
                                                            switch(habilidades){
                                                                    case 'i': printf("\n\n\t\t\tvoce usou o Ataque armageddon, " red"Dano Normal"reset);
                                                                              combo1++;
                                                                              if(combo1%2 ==0){
                                                                                printf("\n\t\t\t\t"red"COMBO!!"reset); //se a pessoa usar a mesma habilidade 2 vezes seguidas causa  dano extra
                                                                                vida_chefe = vida_chefe - dano_perto_assasino - dano_combo;
                                                                              }
                                                                              else{
                                                                                vida_chefe = vida_chefe - dano_perto_assasino;
                                                                              }
                                                                              combo2 =0;
                                                                              scanf("%*[^\n]");
                                                                              scanf("%*c");
                                                                              break;
                                                                    case 'o' : printf("\n\n\t\t\tvoce usou shurikens flamejantes, "red"Dano Normal"reset);
                                                                               combo2++;
                                                                               if(combo2%2 == 0){
                                                                                printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                                                vida_chefe = vida_chefe - dano_longe_basico - dano_combo;
                                                                               }
                                                                               else{
                                                                                vida_chefe = vida_chefe - dano_longe_basico ;
                                                                               }
                                                                               combo1 = 0;
                                                                               scanf("%*[^\n]");
                                                                               scanf("%*c");
                                                                               break;
                                                                    case 'p' : printf("\n\n\t\t\tvoce usou Fuga canibal, "red"bloqueou parte do proximo ataque do chefe"reset);
                                                                               vida = vida + escudo_basico;
                                                                               combo1 = 0;
                                                                               combo2 =0;
                                                                               scanf("%*[^\n]");
                                                                               scanf("%*c");
                                                                               break;
                                                                    default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , sem segunda chance ;-;");
                                                                             scanf("%*[^\n]");
                                                                             scanf("%*c");

                                                                    }
                                                            if(vida_chefe <= 30 && cont == 0){ // quando a vida do chefe estiver <= 30 ele voltara mais forte
                                                                cont = 1; // para acontecer so uma vez
                                                                vida_chefe = 125;
                                                                dano_chefe = 15;

                                                            }
                                                            labirito[7][93] = ' '; //retira o chefe da matriz
                                                            if(vida<=0){ //printa a tela de derrota
                                                                system("clear||cls");
                                                                for(i=0;i<linha;i++){
                                                                    printf("\n\t\t");
                                                                    for(j=0;j<coluna;j++){
                                                                        if(labirito[i][j] == 'x'){
                                                                            printf(fundo_branco" "reset);
                                                                            continue;
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == 'V'){
                                                                                x = i;
                                                                                y = j;
                                                                                printf(fundo_red red" "reset);
                                                                            }
                                                                            else
                                                                                if(labirito[i][j] == 'S'){
                                                                                    printf(fundo_red red"S"reset);
                                                                                }
                                                                                else
                                                                                    if(labirito[i][j] == '@'){
                                                                                        printf(fundo_red red" "reset);
                                                                                    }
                                                                                    else{
                                                                                        printf(" ");
                                                                                    }
                                                                    }
                                                                }
                                                                printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                                                fim = 1; //condição para finalizar o jogo
                                                                break;
                                                            }
                                                            if(vida_chefe<=0){ //printa o labirinto temporario juntamente com o orginal
                                                                labirito[7][91] = ' '; //abre uma parede
                                                                nota = nota + 2;
                                                                printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                                                scanf("%*[^\n]");
                                                                scanf("%*c");
                                                                system("clear||cls");

                                                                printf("\n\tpara sair clique = f");
                                                                printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                                                printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                                                
                                                                for(i=0;i<linha;i++){
                                                                    printf("\n\t\t");
                                                                    for(j=0;j<coluna;j++){
                                                                        if(labirito[i][j] == 'x'){
                                                                            printf(fundo_blue blue" "reset);
                                                                            continue;
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == 'V'){
                                                                                x = i;
                                                                                y = j;
                                                                                printf(fundo_red red" "reset);
                                                                            }
                                                                            else
                                                                                if(labirito[i][j] == 'S'){
                                                                                    printf(fundo_red red"S"reset);
                                                                                }
                                                                                else
                                                                                    if(labirito[i][j] == '@'){
                                                                                        printf(fundo_branco" "reset);
                                                                                    }
                                                                                    else
                                                                                        if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                                                printf(fundo_magenta" "reset);
                                                                                                                
                                                                                                                
                                                                                        }
                                                                                        else{
                                                                                            printf(" ");
                                                                                        }
                                                                    }
                                                                }
                                                                for(tempo=0;tempo<tempo_max;tempo++){}
                                                                system("clear||cls");

                                                                printf("\n\tpara sair clique = f");
                                                                printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                                                printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                                                for(i=0;i<linha;i++){
                                                                    printf("\n\t\t");
                                                                    for(j=0;j<coluna;j++){
                                                                        if(labirito[i][j] == 'x'){
                                                                            printf(fundo_blue blue" "reset);
                                                                            continue;
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == 'V'){
                                                                                x = i;
                                                                                y = j;
                                                                                printf(fundo_red red" "reset);
                                                                            }
                                                                            else
                                                                                if(labirito[i][j] == 'S'){
                                                                                    printf(fundo_red red"S"reset);
                                                                                }
                                                                                else
                                                                                    if(labirito[i][j] == '@'){
                                                                                        printf(fundo_branco" "reset);
                                                                                    }
                                                                                    else{
                                                                                        printf(" ");
                                                                                    }
                                                                    }
                                                                }


                                                                break;
                                                            }

                                                        }
                                                        while(vida > 0 || vida_chefe>0);
                                                        break;
                                                case 3: //chefe contra o atirador
                                                    combo1 = 0;
                                                    combo2 = 0;
                                                    cont = 0;
                                                        do{
                                                            system("clear||cls");
                                                            printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Final Boss !! : LP"reset); //introdução sobre o chefe jutamente com as habilidades da classe escolhida
                                                            printf("\n\n\t\t\tLP eh um chefe ardiloso,quando voce menos espera ele ...");
                                                            printf("\n\n\t\t\tHabilidades da classe "amarelo"Atirador"reset" : "amarelo"i"reset" - Perfuracao eletrizante|| "amarelo"o"reset" - Mata-Craquens||  "amarelo"p"reset" - Arco-escudo ");
                                                            printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                                            printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                                            printf("\n\n\t\t\tLP tirou um ';' do seu programa");
                                                            if(cont == 0){ // o dano desse chefe muda
                                                                dano_chefe = 5;
                                                            }
                                                            vida = vida - dano_chefe;
                                                            escudo_basico=(dano_chefe*0.4); //a quantidade de escudo depende do dano do chefe
                                                            printf("\n\n\t\t\tLance sua habilidade!!! ");
                                                            scanf("%c",&habilidades);
                                                            scanf("%*[^\n]");
                                                            scanf("%*c");
                                                            switch(habilidades){
                                                                    case 'i': printf("\n\n\t\t\tvoce usou Perfuracao eletrizante, " red"Dano Normal"reset);
                                                                              combo1++;
                                                                              if(combo1%2 == 0){
                                                                                printf("\n\t\t\t\t"red"COMBO!!"reset); //se a pessoa usar a mesma habilidade 2 vezes seguidas causa  dano extra
                                                                                vida_chefe = vida_chefe - dano_perto_basico - dano_combo;
                                                                              }
                                                                              else{
                                                                                vida_chefe = vida_chefe - dano_perto_basico;
                                                                              }
                                                                              combo2 = 0;
                                                                              scanf("%*[^\n]");
                                                                              scanf("%*c");
                                                                              break;
                                                                    case 'o' : printf("\n\n\t\t\tvoce usou Mata-Craquens, "red"Dano Normal"reset);
                                                                               combo2++;
                                                                               if(combo2%2 == 0){
                                                                                printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                                                vida_chefe = vida_chefe - dano_longe_atirador - dano_combo;
                                                                               }
                                                                               else{
                                                                                vida_chefe = vida_chefe - dano_longe_atirador;
                                                                               }
                                                                               combo1 = 0;
                                                                               scanf("%*[^\n]");
                                                                               scanf("%*c");
                                                                               break;
                                                                    case 'p' : printf("\n\n\t\t\tvoce usou Arco-escudo, "red"bloqueou parte do proximo ataque do chefe"reset);
                                                                               vida = vida + escudo_basico;
                                                                               combo1 = 0;
                                                                               combo2 =0;
                                                                               scanf("%*[^\n]");
                                                                               scanf("%*c");
                                                                               break;
                                                                    default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , sem segunda chance ;-;");
                                                                             scanf("%*[^\n]");
                                                                             scanf("%*c");

                                                                    }
                                                            if(vida_chefe <= 30 && cont == 0){ // quando a vida do chefe estiver <= 30 ele voltara mais forte
                                                                cont = 1; // para acontecer so uma vez
                                                                vida_chefe = 125;
                                                                dano_chefe = 15;

                                                            }
                                                            labirito[7][93] = ' '; //retira o chefe da matriz
                                                            if(vida<=0){ //printa a tela de derrota
                                                                system("clear||cls");
                                                                for(i=0;i<linha;i++){
                                                                    printf("\n\t\t");
                                                                    for(j=0;j<coluna;j++){
                                                                        if(labirito[i][j] == 'x'){
                                                                            printf(fundo_branco" "reset);
                                                                            continue;
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == 'V'){
                                                                                x = i;
                                                                                y = j;
                                                                                printf(fundo_red red" "reset);
                                                                            }
                                                                            else
                                                                                if(labirito[i][j] == 'S'){
                                                                                    printf(fundo_red red"S"reset);
                                                                                }
                                                                                else
                                                                                    if(labirito[i][j] == '@'){
                                                                                        printf(fundo_red red" "reset);
                                                                                    }
                                                                                    else{
                                                                                        printf(" ");
                                                                                    }
                                                                    }
                                                                }
                                                                printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                                                fim = 1; //condição para finalizar o jogo
                                                                break;
                                                            }
                                                            if(vida_chefe<=0){ //printa o labirinto temporario juntamente com o orginal
                                                                labirito[7][91] = ' '; //abre uma parede
                                                                nota = nota + 2;
                                                                printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                                                scanf("%*[^\n]");
                                                                scanf("%*c");
                                                                system("clear||cls");

                                                                printf("\n\tpara sair clique = f");
                                                                printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                                                printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                                                
                                                                for(i=0;i<linha;i++){
                                                                    printf("\n\t\t");
                                                                    for(j=0;j<coluna;j++){
                                                                        if(labirito[i][j] == 'x'){
                                                                            printf(fundo_blue blue" "reset);
                                                                            continue;
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == 'V'){
                                                                                x = i;
                                                                                y = j;
                                                                                printf(fundo_red red" "reset);
                                                                            }
                                                                            else
                                                                                if(labirito[i][j] == 'S'){
                                                                                    printf(fundo_red red"S"reset);
                                                                                }
                                                                                else
                                                                                    if(labirito[i][j] == '@'){
                                                                                        printf(fundo_branco" "reset);
                                                                                    }
                                                                                    else
                                                                                        if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                                                printf(fundo_magenta" "reset);
                                                                                                                
                                                                                                                
                                                                                        }
                                                                                        else{
                                                                                            printf(" ");
                                                                                        }
                                                                    }
                                                                }
                                                                for(tempo=0;tempo<tempo_max;tempo++){}
                                                                system("clear||cls");

                                                                printf("\n\tpara sair clique = f");
                                                                printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                                                printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                                                for(i=0;i<linha;i++){
                                                                    printf("\n\t\t");
                                                                    for(j=0;j<coluna;j++){
                                                                        if(labirito[i][j] == 'x'){
                                                                            printf(fundo_blue blue" "reset);
                                                                            continue;
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == 'V'){
                                                                                x = i;
                                                                                y = j;
                                                                                printf(fundo_red red" "reset);
                                                                            }
                                                                            else
                                                                                if(labirito[i][j] == 'S'){
                                                                                    printf(fundo_red red"S"reset);
                                                                                }
                                                                                else
                                                                                    if(labirito[i][j] == '@'){
                                                                                        printf(fundo_branco" "reset);
                                                                                    }
                                                                                    else{
                                                                                        printf(" ");
                                                                                    }
                                                                    }
                                                                }


                                                                break;
                                                            }

                                                        }
                                                        while(vida > 0 || vida_chefe>0);
                                                        break;
                                                case 4: //chefe contra a classe tank
                                                    combo1 = 0;
                                                    combo2 = 0;
                                                    combo3 = 0;
                                                    cont = 0;
                                                        do{
                                                            system("clear||cls");
                                                            printf("\n\n\n\t\t\tVoce encontrou um chefe!!!! :" verde" Final Boss !! : LP"reset); //introdução sobre o chefe jutamente com as habilidades da classe escolhida
                                                            printf("\n\n\t\t\tLP eh um chefe ardiloso,quando voce menos espera ele ...");
                                                            printf("\n\n\t\t\tHabilidades da classe "amarelo"Tank"reset" : "amarelo"i"reset" - Golpe de escudo fermentado|| "amarelo"o"reset" - Chuva de rochedos||  "amarelo"p"reset" - colete milenar de espinhos cerimoniais ");
                                                            printf("\n\n\n\t\t\t-------------------------------------------------"roxo"Batalaha"reset"------------------------------------------------------------------------");
                                                            printf("\n\n\t\t\t"verde"vida do chefe"reset" = %d \t\t\t "red"sanidade atual"reset" = %d",vida_chefe,vida);
                                                            printf("\n\n\t\t\tLP tirou um ';' do seu programa");
                                                            if(cont == 0){ // o dano desse chefe muda
                                                                dano_chefe = 5;
                                                            }
                                                            vida = vida - dano_chefe;
                                                            escudo_basico=(dano_chefe*0.4); //a quantidade de escudo depende do dano do chefe
                                                            escudo_tank=(dano_chefe*0.8); //o tank tem uma quantidade de escudo maior
                                                            printf("\n\n\t\t\tLance sua habilidade!!! ");
                                                            scanf("%c",&habilidades);
                                                            scanf("%*[^\n]");
                                                            scanf("%*c");
                                                            switch(habilidades){
                                                                    case 'i': printf("\n\n\t\t\tvoce usou Golpe de escudo fermentado, " red"Dano Normal"reset);
                                                                               combo1++;
                                                                              if(combo1%2 == 0){ //se a pessoa usar a mesma habilidade 2 vezes seguidas causa  dano extra
                                                                                printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                                                vida_chefe = vida_chefe - dano_perto_basico - dano_combo;
                                                                              }
                                                                              else{
                                                                                vida_chefe = vida_chefe - dano_perto_basico;
                                                                              }
                                                                              combo2 = 0;
                                                                              combo3 = 0;
                                                                              scanf("%*[^\n]");
                                                                              scanf("%*c");
                                                                              break;
                                                                    case 'o' : printf("\n\n\t\t\tvoce usou Chuva de rochedos, "red"Dano Normal"reset);
                                                                               combo2++;
                                                                               if(combo2%2 == 0){
                                                                                printf("\n\t\t\t\t"red"COMBO!!"reset);
                                                                                vida_chefe = vida_chefe - dano_longe_basico  - dano_combo;
                                                                                }
                                                                                else{
                                                                                    vida_chefe = vida_chefe - dano_longe_basico ;
                                                                                }
                                                                               combo1 = 0;
                                                                               combo3 = 0;
                                                                               scanf("%*[^\n]");
                                                                               scanf("%*c");
                                                                               break;
                                                                    case 'p' : printf("\n\n\t\t\tvoce usou colete milenar de espinhos cerimoniais, "red"bloqueou grande parte do proximo ataque do chefe e aplicou dano refletor"reset);
                                                                               combo3++;
                                                                               if(combo3 > 2){ // o tank nao pode usar a habilidade varias vezes seguidas, caso use sera tratado como um escudo basico
                                                                                printf("\n\t\t\t\t"red"Escudo quebrado!!"reset);
                                                                                vida = vida + escudo_basico;
                                                                               }
                                                                               else{
                                                                                vida = vida + escudo_tank;
                                                                                vida_chefe = vida_chefe - dano_tank;
                                                                               }
                                                                               combo2 = 0;
                                                                               combo1 = 0;

                                                                               scanf("%*[^\n]");
                                                                               scanf("%*c");
                                                                               break;
                                                                    default: printf("\n\n\t\t\tvoce "red"errou a habilidad envocador"reset" , sem segunda chance ;-;");
                                                                             scanf("%*[^\n]");
                                                                             scanf("%*c");

                                                                    }
                                                            if(vida_chefe <= 30 && cont == 0){ // quando a vida do chefe estiver <= 30 ele voltara mais forte
                                                                cont = 1; // para acontecer so uma vez
                                                                vida_chefe = 125;
                                                                dano_chefe = 15;

                                                            }
                                                            labirito[7][93] = ' '; //retira o chefe da matriz
                                                            if(vida<=0){ //printa a tela de derrota
                                                                system("clear||cls");
                                                                for(i=0;i<linha;i++){
                                                                    printf("\n\t\t");
                                                                    for(j=0;j<coluna;j++){
                                                                        if(labirito[i][j] == 'x'){
                                                                            printf(fundo_branco" "reset);
                                                                            continue;
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == 'V'){
                                                                                x = i;
                                                                                y = j;
                                                                                printf(fundo_red red" "reset);
                                                                            }
                                                                            else
                                                                                if(labirito[i][j] == 'S'){
                                                                                    printf(fundo_red red"S"reset);
                                                                                }
                                                                                else
                                                                                    if(labirito[i][j] == '@'){
                                                                                        printf(fundo_red red" "reset);
                                                                                    }
                                                                                    else{
                                                                                        printf(" ");
                                                                                    }
                                                                    }
                                                                }
                                                                printf(amarelo"\n\n\t\t\tvoce enlouqueceu %s, boa sorte na proxima vez(ou nao)\n"reset,nick);
                                                                fim = 1; //condição para finalizar o jogo
                                                                break;
                                                            }
                                                            if(vida_chefe<=0){ //printa o labirinto temporario juntamente com o orginal
                                                                labirito[7][91] = ' '; //abre uma parede
                                                                nota = nota + 2;
                                                                printf(amarelo"\n\n\t\t\tvoce derrotou o chefe, %s, parabens "reset,nick);
                                                                scanf("%*[^\n]");
                                                                scanf("%*c");
                                                                system("clear||cls");

                                                                printf("\n\tpara sair clique = f");
                                                                printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                                                printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);
                                                                
                                                                for(i=0;i<linha;i++){
                                                                    printf("\n\t\t");
                                                                    for(j=0;j<coluna;j++){
                                                                        if(labirito[i][j] == 'x'){
                                                                            printf(fundo_blue blue" "reset);
                                                                            continue;
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == 'V'){
                                                                                x = i;
                                                                                y = j;
                                                                                printf(fundo_red red" "reset);
                                                                            }
                                                                            else
                                                                                if(labirito[i][j] == 'S'){
                                                                                    printf(fundo_red red"S"reset);
                                                                                }
                                                                                else
                                                                                    if(labirito[i][j] == '@'){
                                                                                        printf(fundo_branco" "reset);
                                                                                    }
                                                                                    else
                                                                                        if(labirito[i][j] == 'q' || labirito[i][j] == 'c' || labirito[i][j] == 'z' || labirito[i][j] == 'b' || labirito[i][j] == 'l' || labirito[i][j] == 'n' || labirito[i][j] == 'm'){
                                                                                                printf(fundo_magenta" "reset);
                                                                                                                
                                                                                                                
                                                                                        }
                                                                                        else{
                                                                                            printf(" ");
                                                                                        }
                                                                    }
                                                                }
                                                                for(tempo=0;tempo<tempo_max;tempo++){}
                                                                system("clear||cls");

                                                                printf("\n\tpara sair clique = f");
                                                                printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                                                printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                                                for(i=0;i<linha;i++){
                                                                    printf("\n\t\t");
                                                                    for(j=0;j<coluna;j++){
                                                                        if(labirito[i][j] == 'x'){
                                                                            printf(fundo_blue blue" "reset);
                                                                            continue;
                                                                        }
                                                                        else
                                                                            if(labirito[i][j] == 'V'){
                                                                                x = i;
                                                                                y = j;
                                                                                printf(fundo_red red" "reset);
                                                                            }
                                                                            else
                                                                                if(labirito[i][j] == 'S'){
                                                                                    printf(fundo_red red"S"reset);
                                                                                }
                                                                                else
                                                                                    if(labirito[i][j] == '@'){
                                                                                        printf(fundo_branco" "reset);
                                                                                    }
                                                                                    else{
                                                                                        printf(" ");
                                                                                    }
                                                                    }
                                                                }


                                                                break;
                                                            }

                                                        }
                                                        while(vida > 0 || vida_chefe>0);
                                                        break;
                                                }

                                        }

     if(fim == 1){ // para finalizar o jogo
        break;
      }

      do{
        scanf("%c",&seta);
        scanf("%*[^\n]");
        scanf("%*c");
        if(seta == 'd' || seta == 'D'){ //para o personagem andar para a direita
            if(labirito[x][y+1] == '@' || labirito[x][y+1] == 'x'){ //aviso de parede
                    printf("\n\t jogador(a) " red"%s"reset " ,eh impossivel passar parede,tente novamente",nick);
                    scanf("%*[^\n]");
                    scanf("%*c");
                    system("clear||cls");
            }
            else
                if(labirito[x][y+1]=='u'){ //recuperação de sanidade
                    printf("\n\n\t\t\t voce fez uma pausa espiritual, parabens + 25 de "verde"sanidade"reset);
                    scanf("%*[^\n]");
                    scanf("%*c");
                    for(cont = 1;vida<vida_max;cont++){ //para a sanidade não passar de 100
                        vida++;
                        if(cont == vida_ext){
                            break;
                        }
                    }
                    labirito[x][y] = ' ';
                    labirito[x][y+1]= 'V';

                }
                else{
                    labirito[x][y] = ' ';
                    labirito[x][y+1]= 'V';
                }


        }
        else
            if(seta == 'w'|| seta == 'W'){ //para andar para cima
                if(labirito[x-1][y] == '@' || labirito[x-1][y] == 'x'){ //aviso de parede
                    printf("\n\t jogador(a) " red"%s"reset " ,eh impossivel passar parede,tente novamente",nick);
                    scanf("%*[^\n]");
                    scanf("%*c");
                    system("clear||cls");


                }
                else
                    if(labirito[x-1][y]=='h'){ //teleporte para o inicio do jogo
                        labirito[x][y] = ' ';
                        labirito[18][1] = 'V';

                    }
                    else
                        if(labirito[x-1][y]=='t'){ //teleporte para o chefe LP
                            labirito[x][y] = ' ';
                            labirito[1][93] = 'V';
                            printf("\n\n\t\t\t Vish, voce se perdeu na cabruca, "amarelo"descubra uma maneira de escapar"reset);
                            scanf("%*[^\n]");
                            scanf("%*c");


                        }
                        else
                            if(labirito[x-1][y]=='g'){ //aditivo de dano em todas as classes
                                printf("\n\n\t\t\tParabens voce encontrou um incentivo dos seus veteranos,"verde"dano aumentado"reset);
                                dano_longe_atirador = dano_longe_atirador + 10;
                                dano_longe_basico = dano_longe_basico + 10;
                                dano_perto_assasino = dano_perto_assasino + 10;
                                dano_perto_basico = dano_perto_basico + 10;
                                dano_tank = dano_tank + 5;
                                labirito[x][y] = ' ';
                                labirito[x-1][y]= 'V';
                                scanf("%*[^\n]");
                                scanf("%*c");
                            }
                            else
                                if(labirito[x-1][y]=='u'){ //recuperação de sanidade
                                  printf("\n\n\t\t\t voce fez uma pausa espiritual, parabens + 25 de "verde"sanidade"reset);
                                  scanf("%*[^\n]");
                                  scanf("%*c");
                                  for(cont = 1;vida<vida_max;cont++){ //para a sanidade não passar de 100
                                    vida++;
                                    if(cont == vida_ext){
                                        break;
                                    }
                                  }
                                  labirito[x][y] = ' ';
                                  labirito[x-1][y]= 'V';

                                }
                                else{
                                    labirito[x][y] = ' ';
                                    labirito[x-1][y]= 'V';
                                }


            }
            else
                if(seta == 'a'|| seta == 'A'){
                    if(labirito[x][y-1] == '@' || labirito[x][y-1] == 'x'){ //aviso de parede

                        printf("\n\t jogador(a) " red"%s"reset " ,eh impossivel passar parede,tente novamente",nick);
                        scanf("%*[^\n]");
                        scanf("%*c");
                        system("clear||cls");
                        continue;
                    }
                    else
                      if(labirito[x][y-1] == 'k'){ //Para receber um aviso
                        printf("\n\n\t\tVoce chegou no ponto de onibus, "roxo"escolha sabiamente"reset", um leva ao seu destino, outro te da uma presentinho e os outros ... descubra rs");
                        labirito[x][y]=' ';
                        labirito[x][y-1]='V';
                        scanf("%*[^\n]");
                        scanf("%*c");


                      }
                      else
                        if(labirito[x][y-1]=='u'){   //recuperação de sanidade
                                  printf("\n\n\t\t\t voce fez uma pausa espiritual, parabens + 25 de "verde"sanidade"reset);
                                  scanf("%*[^\n]");
                                  scanf("%*c");
                                  for(cont = 1;vida<vida_max;cont++){  //para a sanidade não passar de 100
                                    vida++;
                                    if(cont == vida_ext){
                                        break;
                                    }
                                  }
                                  labirito[x][y] = ' ';
                                  labirito[x][y-1]= 'V';

                        }
                        else
                            if(labirito[x][y-1] == 'S'){ //aviso de nota insuficiente
                                if(nota<7){
                                    printf("\n\n\t\t\t Quer concluir o curso com essa media ? "red"cren cren"reset);
                                    scanf("%*[^\n]");
                                    scanf("%*c");

                                }
                                else
                                    if(nota >= 7 && nota <= 9){ //aviso para auemntar a nota
                                        printf("\n\n\t\t\t Parabens,conseguiu estar na media, mas nao queremos estar na media, ne? "red"so vai sair com 10 Bb "reset);
                                        scanf("%*[^\n]");
                                        scanf("%*c");


                                    }
                                    else{ //aviso de conclusão de jogo
                                        printf("\n\n\t\t\t Agora sim" amarelo" %s "reset ", Adeus, espero que tenha sido uma "red"experiencia incrivel"reset" rs",nick);
                                        printf(" "red"o"reset amarelo"b"reset verde"r"reset blue"i"reset roxo"g"reset red"a"reset amarelo"d"reset verde"o"reset"\n\n");
                                        labirito[x][y-1] = 'x'; //Para completar a palavra CIC
                                        labirito[x][y] = ' ';
                                        scanf("%*[^\n]");
                                        scanf("%*c");
                                        fim = 1; //condição de fim
                                    }
                            }
                            else{
                            labirito[x][y] = ' ';
                            labirito[x][y-1]= 'V';
                            }

                }
                else
                    if(seta == 's' || seta == 'S'){ //para andar para baixo
                        if(labirito[x +1][y] == '@' || labirito[x + 1][y] == 'x'){ //aviso de parede
                            printf("\n\t jogador(a) " red"%s"reset " ,eh impossivel passar parede,tente novamente",nick);
                            scanf("%*[^\n]");
                            scanf("%*c");
                            system("clear||cls");

                        }
                        else
                            if(labirito[x+1][y]=='u'){ //recuperação de sanidade
                                  printf("\n\n\t\t\t voce fez uma pausa espiritual, parabens + 25 de "verde "sanidade"reset);
                                  scanf("%*[^\n]");
                                  scanf("%*c");
                                  for(cont = 1;vida<vida_max;cont++){ //para a sanidade não passar de 100
                                    vida++;
                                    if(cont == vida_ext){
                                        break;
                                    }
                                  }
                                  labirito[x][y] = ' ';
                                  labirito[x+1][y]= 'V';

                             }
                             else{
                                labirito[x][y] = ' ';
                                labirito[x+1][y]= 'V';
                             }

                    }
                    else
                    if(seta != 'a' && seta != 'A' && seta != 'd' && seta != 'D' && seta != 's' && seta != 'S' && seta != 'w' && seta != 'W' && seta != 'f' ){ //caso o player digite errado
                        system("clear||cls");
                        printf("\n\tpara sair clique = f");
                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                        for(i=0;i<linha;i++){
                            printf("\n\t\t");
                            for(j=0;j<coluna;j++){
                                if(labirito[i][j] == 'x'){
                                    printf(fundo_blue blue" "reset);
                                    continue;
                                }
                                else
                                    if(labirito[i][j] == 'V'){
                                        x = i;
                                        y = j;
                                        printf(fundo_red red" "reset);
                                    }
                                    else
                                        if(labirito[i][j] == 'S'){
                                            printf(fundo_red red"S"reset);
                                        }
                                        else
                                            if(labirito[i][j] == '@'){
                                                printf(fundo_branco" "reset);
                                            }
                                            else{
                                                printf(" ");
                                            }
                            }
                        }

                                        printf("\n\n\t\t\tDigite corretamente "red"player"reset", pressione qualquer tecla para continuar");
                                        scanf("%*[^\n]");
                                        scanf("%*c");
                                        system("clear||cls");
                                        printf("\n\tpara sair clique = f");
                                        printf("\t\t\t\t"red"sanidade mental"reset" = %d",vida);
                                        printf("\t\t\t\t"verde"nota"reset" = %d\n\n",nota);

                                        for(i=0;i<linha;i++){
                                            printf("\n\t\t");
                                            for(j=0;j<coluna;j++){
                                                if(labirito[i][j] == 'x'){
                                                    printf(fundo_blue blue" "reset);
                                                    continue;
                                                }
                                                else
                                                    if(labirito[i][j] == 'V'){
                                                        x = i;
                                                        y = j;
                                                        printf(fundo_red red" "reset);
                                                    }
                                                    else
                                                        if(labirito[i][j] == 'S'){
                                                            printf(fundo_red red"S"reset);
                                                        }
                                                        else
                                                            if(labirito[i][j] == '@'){
                                                                printf(fundo_branco" "reset);
                                                            }
                                                            else{
                                                                printf(" ");
                                                            }
                                            }
                                        }

                    }

      }
      while(seta != 'a' && seta != 'A' && seta != 'd' && seta != 'D' && seta != 's' && seta != 'S' && seta != 'w' && seta != 'W' && seta != 'f' );
            system("clear||cls");

            if(seta == 'f'){ //caso o jogador desista

                for(i=0;i<linha;i++){//imprime a bandeira LGBT
                    printf("\n\t\t");
                    for(j=0;j<coluna;j++){
                        if( i == 0 || i == 1 || i == 2 || i == 3){
                            printf(fundo_red" "reset);
                        }
                        else
                            if(i == 4 || i == 5 || i == 6 || i == 7){
                                printf( fundo_amarelo" "reset);
                            }
                            else
                                if(i == 8 || i == 9 || i == 10 || i == 11){
                                    printf( fundo_verde" "reset);
                                }
                                else
                                    if(i == 12 || i == 13 || i == 14 || i == 15){
                                        printf(fundo_blue " " reset);
                                    }
                                    else
                                        if(i == 16 || i == 17 || i == 18 || i == 19){
                                            printf( fundo_magenta" " reset);
                                        }
                    }
                }
                printf("\n\n\t\t\t\t\t\t\t"red"o"reset amarelo"b"reset verde"r"reset blue"i"reset roxo"g"reset red"a"reset amarelo"d"reset verde"o"reset"\n\n");
            }

    }
    while(seta!='f');

    return 0;
}

