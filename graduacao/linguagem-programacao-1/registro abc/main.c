#include <string.h>
int main (void){
    typedef int inteiro;
    typedef char texto;
    /*typedef struct{
        texto nome[100];
        inteiro telefone_casa;
        inteiro telefone_celuar;
    }lista;*/
    inteiro opcao,i = 0,retorno,y,x,z;
    

    struct lista{
        texto nome[100];
        inteiro telefone_casa;
        inteiro telefone_celular;
    }contato_normal[100],*contato,subst,subst2,novo_contato; 
    contato = &contato_normal;
    do{
        do{
            printf("\n\t----------------menu---------------\n");
            printf("\n\t1 - inserir dados do contato");
            printf("\n\t2 - listar toda a agenda");
            printf("\n\t3 - editar agenda ");
            printf("\n\t4 - excluir contato");
            printf("\n\t5 - procurar por nome ou por numero");
            printf("\n\t6 - sair\n");
            scanf("%d",&opcao);
            scanf("%*[^\n]");
            scanf("%*c");
            if(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5 && opcao != 6){
                printf("\n\tDigite corretamente");
                scanf("%*c");
                system("clear||cls");
            }
        }
        while(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5 && opcao != 6);

        switch(opcao){

            case 1: 
                    if(i>100){
                        printf("\nLista esta cheia");
                        scanf("%*c");
                        break;
                    }
                    system("clear||cls");
                    printf("\nInforme o nome do contato: ");
                    scanf("%[^\n]s",novo_contato.nome);
                    scanf("%*[^\n]");
                    scanf("%*c");
                    printf("\nInforme o telefone de casa: ");
                    scanf("%d",&novo_contato.telefone_casa);
                    scanf("%*[^\n]");
                    scanf("%*c");
                    printf("\nInforme o telefone celular: ");
                    scanf("%d",&novo_contato.telefone_celular);
                    scanf("%*[^\n]");
                    scanf("%*c");
                    system("clear||cls");
                    /*
                    for(x=0;x<=i;x++){
                        for(z=0; z > 0 ;z++){
                            if(novo_contato.nome[z] < contato[x].nome[z]){
                                
                                subst = contato[x];
                                contato[x] = novo_contato;
                                subst2 = contato[x + 1];
                                contato[x + 1] = subst;
                                for(y = x + 1; y <= i ;y++){
                                    contato[y + 1] = subst2;
                                    subst2 = contato[y + 2];
                                }
                                fim = 1;
                                break;
                            }
                            else
                                if(novo_contato.nome[z] > contato[x].nome[z]){
                                    break;
                                }
                        }
                        if(fim == 1){
                            fim = 0;
                            break;
                        }
                        
                    }
                    */

                if(i==0){
                    contato[i]=novo_contato;
                    i++;
                    break;
                }
                else
                    for(x=0;x<=i;x++){
                        retorno = strcmp(novo_contato.nome,contato[x].nome);
                        if(retorno < 0 ){
                                for(z=i;z>x;z--){
                                    contato[z] = contato[z-1];
                                }
                        }
                       
                    }
                    contato[x] = novo_contato;
                    for(x = 0;x<=i;x++){
                        printf("\n%d %s",x+1,contato[x].nome);
                        scanf("%*c");
                    }
                    system("clear||cls");
                    i++;
                    

              /* for(x=0;x<i;x++){
                    retorno = strcmp(contato[i-1].nome,contato[x].nome);
                    if(retorno < 0 ){
                                subst = contato[x];
                                contato[x] = contato[i-1];
                                subst2 = contato[x + 1];
                                contato[x + 1] = subst;
                                for(y = x + 1; y < i ;y++){
                                    contato[y + 1] = subst2;
                                    subst2 = contato[y + 2];
                                }
                    }
                   }
                    for(x = 0;x<i;x++){
                        printf("\n%d %s",x+1,contato[x].nome);
                        scanf("%*c");
                    }
                    system("clear||cls");*/

                break;















        }

    }
    while(opcao != 6);












    return 0;
}