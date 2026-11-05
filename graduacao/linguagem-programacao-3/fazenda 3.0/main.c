#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int id;
    char grandeza[21];
    float valor;

}Tsensor;

typedef struct{
    int id;
    char descricao[21];
    char status;
}Tequipamento;

void limpa_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
}



int main(){
    system("clear||cls");

    Tsensor Tumidade;
    Tequipamento e_bomba;
    int mudou=0;
    char continuar;

    printf("Informe o Id do sensor:  ");
    scanf("%d",&Tumidade.id);
    limpa_buffer();

    printf("\nInforme a Grandeza: ");
    scanf("%[^\n]s",Tumidade.grandeza);
    limpa_buffer();

    printf("\nInforme o Valor: ");
    scanf("%f",&Tumidade.valor);
    limpa_buffer();

    printf("\n--------------------------------------------\n");
    printf("Id: %d",Tumidade.id);
    printf("\nGrandeza : %s",Tumidade.grandeza);
    printf("\nValor : %.2f",Tumidade.valor);
    scanf("%*c");

    printf("\n--------------------------------------------||||-----------------------------------------------------\n");

    printf("Informe o Id do equipamento: ");
    scanf("%d",&e_bomba.id);
    limpa_buffer();

    printf("Informe a descricao: ");
    scanf("%[^\n]s",e_bomba.descricao);
    limpa_buffer();

    do{
        printf("Informe o status (L,D): ");
        scanf("%c",&e_bomba.status);
        limpa_buffer();

        if(e_bomba.status != 'L' && e_bomba.status != 'D'){
            printf("\nDigite corretamente\n");
        }
    }
    while(e_bomba.status != 'L' && e_bomba.status != 'D');

    printf("\n--------------------------------------------\n");
    printf("\nId : %d",e_bomba.id);
    printf("\nDescricao : %s",e_bomba.descricao);

    if(e_bomba.status == 'L'){
        printf("\nStatus : Ligado");
    }
    else{
        printf("\nStatatus : Desligado");
    }
    scanf("%*c");

    printf("\n--------------------------------------------||||-----------------------------------------------------\n");

    do{
        if(Tumidade.valor <= 30){
         if(e_bomba.status != 'L'){
                    mudou = 1;
                }
            e_bomba.status = 'L';

        }
        else
            if(Tumidade.valor >= 80){
                 if(e_bomba.status != 'D'){
                    mudou = 1;
                }
                e_bomba.status = 'D';

            }
        if(e_bomba.status == 'D'){
            Tumidade.valor = Tumidade.valor + 1;
        }else{
            Tumidade.valor = Tumidade.valor + - 1;
        }



        if(mudou == 1){
            printf("\n\nId: %d",Tumidade.id);
            printf("\nGrandeza : %s",Tumidade.grandeza);
            printf("\nValor : %.2f",Tumidade.valor);

            printf("\n--------------------------------------------\n");
            printf("\nId : %d",e_bomba.id);
            printf("\nDescricao : %s",e_bomba.descricao);

            if(e_bomba.status == 'L'){
                printf("\nStatus : Ligado");
            }
            else{
                printf("\nStatatus : Desligado");
            }
            mudou = 0;
            printf("\n\nDeseja continuar? : ");
            scanf("%c",&continuar);
            limpa_buffer();


        }

        


    }
    while(continuar != 'N');

    return 0;
}
