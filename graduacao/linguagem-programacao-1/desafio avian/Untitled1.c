
#define maximo 52

int main(void){


    char modelo;
    short int assento;
    short int total;
    short int fileira;
    //const int maximo = 52;

    do{
        printf("informe o modelo do avião\n 1.AirBus e Boing\n 2.Padrão intrnacional\n 3.Foccker 100\n\t");
        scanf("%d",&modelo);

        if(modelo != 1 && modelo != 2 && modelo != 3){
            printf("digite corretamente");
        }
    }
    while(modelo != 1 && modelo != 2 && modelo != 3); // validação de entrada

    do{
        printf("\ninforme o numero total de cadeiras\n\t");
        scanf("%hd",&total);

        if(total <= 0 || total > maximo){
            printf("digite corretamente");
        }
    }
    while(total <= 0 || total > maximo);// validação de entrada

    do{
        printf("informe sua poltrona\n\t");
        scanf("%hd",&assento);

        if(assento < 0 || assento > total){
            printf("digite corretamente");
        }
    }
    while(assento < 0 || assento > total);// validação de entrada



    if(modelo == 1){ // modelo 1
        if(assento%6 == 0){
            fileira = assento/6; // para saber a fileira que esta
            }
        else{
            fileira = assento/6 + 1;
        }

        if(assento%6 == 0){
            printf("\n esse assento eh na secao F fileira %d\n",fileira);
        }
        else
            if(assento%6 == 5){
                printf("\n esse assento eh na secao E na fileira %d\n",fileira);
            }
            else
                if(assento%6 == 4){
                printf("\n esse assento eh na secao D na fileira %d\n",fileira);

                }
                else
                    if(assento%6 == 3){
                        printf("\n esse assento eh na secao C na fileira %d\n",fileira);
                    }
                    else
                        if(assento%6 == 2){
                                printf("\n esse assento eh na secao B na fileira %d\n",fileira);
                        }
                        else{
                            printf("\n esse assento eh na secao A na fileira %d\n",fileira);
                        }



    }
    else
        if(modelo == 2){ // modelo 2

            if(assento%8 == 0){
            fileira = assento/8;
            }
            else{
            fileira = assento/8 + 1;
            }

            if(assento%8 == 0){
                printf("\n esse assento eh na secao H na fileira %d\n",fileira);
            }
            else
                if(assento%8 == 7){
                    printf("\n esse assento eh na secao G na fileira %d\n",fileira);

                }
                else
                    if(assento%8 == 6){
                        printf("\n esse assento eh na secao F na fileira %d\n",fileira);
                    }
                    else
                        if(assento%8 == 5){
                            printf("\n esse assento eh na secao E na fileira %d\n",fileira);

                        }
                        else
                            if(assento%8 == 4){
                                printf("\n esse assento eh na secao D na fileira %d\n",fileira);

                            }
                            else
                                if(assento%8 == 3){
                                    printf("\n esse assento eh na secao C na fileira %d\n",fileira);
                                }
                                else
                                    if(assento%8 == 2){
                                    printf("\n esse assento eh na  secao B na fileira %d\n",fileira);
                                }
                                else{
                                    printf("\n esse assento eh na no secao A na fileira %d\n",fileira);
                                }

        }
        else
            if(modelo == 3){ // modelo 3
                if(assento%5 == 0){
                fileira = assento/5;
                }
                else{
                fileira = assento/5 + 1;
                }

                if(assento%5 == 0){
                    printf("\n esse assento eh na secao E na fileira %d\n",fileira);
                }
                else
                    if(assento%5 == 4){
                        printf("\n esse assento eh na secao D na fileira %d\n",fileira);

                    }
                    else
                        if(assento%5 == 3){
                            printf("\n esse assento eh na secao C na fileira %d\n",fileira);
                        }
                        else
                           if(assento%5 == 2){
                                printf("\n esse assento eh na secao B na fileira %d\n",fileira);

                           }
                           else{
                                printf("\n esse assento eh na secao A na fileira %d\n",fileira);
                           }


            }

    return 0;
}

