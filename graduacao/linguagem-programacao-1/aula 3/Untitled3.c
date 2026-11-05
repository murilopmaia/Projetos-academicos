int main (void){

    short int poltronas;
    short acento;
    int x;


    do{
        printf("quantas poltronas tem no onibus ?");
        scanf("%hd",&poltronas);



        if(poltronas > 52 || poltronas <= 0){
            printf("maximo de poltronas passado\n");
        }
    }
    while(poltronas >52 || poltronas <= 0);

    do{
        printf("qual o acento");
        scanf("%hd",&acento);

        if(acento > poltronas || acento <= 0){
            printf("maximo de acentos passado\n");
        }
    }
    while(acento >poltronas || acento <= 0);

    if(acento%4 == 0){
        printf("o acento esta a direita , na janela");
    }
    else{
        if(acento%2 == 0){
            printf("o acento esta a esquerda , no corredor");

        }else{


                    for(;acento > 0; acento = acento -4){
                        if(acento == 1){
                                x = 1;

                        }
                        else{
                            x = 2;


                        }
                    }
            }
    }

    if(x == 1){
            printf("o acento esta a esquerda , na janela");

    }
    else{
        if(x == 2){
                printf("o acento esta a direita , no corredor ");

        }
    }



    return 0;

}



