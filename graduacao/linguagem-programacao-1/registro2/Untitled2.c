
#include <stdio.h>
int main(void){
    struct funcionarios{
        char nome[50];
        int endereco;
        float salario;
        char sexo;
        int cpf;
        int telefone;
    }secretaria,contadora,estagiaria;
    int i=0,j;

    printf("-------------funcionario %d--------------",++i);

    printf("\ninforme o nome do funcionario ");
    scanf("%[^\n]s",secretaria.nome);
    scanf("%*[^\n]");
    scanf("%*c");

    printf("\ninforme o endereco(cep) do funcionario ");
    scanf("%d",&secretaria.endereco);
    scanf("%*[^\n]");
    scanf("%*c");

    printf("\ninforme o salario do funcionario ");
    scanf("%f",&secretaria.salario);
    scanf("%*[^\n]");
    scanf("%*c");

    do{
        printf("\ninforme o sexo biologico(M ou F) do funcionario ");
        scanf("%c",&secretaria.sexo);
        scanf("%*[^\n]");
        scanf("%*c");
    }
    while(secretaria.sexo!= 'M' && secretaria.sexo != 'F');

    printf("\ninforme o cpf do funcionario ");
    scanf("%d",&secretaria.cpf);
    scanf("%*[^\n]");
    scanf("%*c");

    printf("\ninforme o telefone do funcionario ");
    scanf("%d",&secretaria.telefone);
    scanf("%*[^\n]");
    scanf("%*c");

    system("clear||cls");

    printf("-------------funcionario %d--------------",++i);

    printf("\ninforme o nome do funcionario ");
    scanf("%[^\n]s",contadora.nome);
    scanf("%*[^\n]");
    scanf("%*c");

    printf("\ninforme o endereco(cep) do funcionario ");
    scanf("%d",&contadora.endereco);
    scanf("%*[^\n]");
    scanf("%*c");

    printf("\ninforme o salario do funcionario ");
    scanf("%f",&contadora.salario);
    scanf("%*[^\n]");
    scanf("%*c");

    do{
        printf("\ninforme o sexo biologico(M ou F) do funcionario ");
        scanf("%c",&contadora.sexo);
        scanf("%*[^\n]");
        scanf("%*c");
    }
    while(contadora.sexo!= 'M' && contadora.sexo != 'F');

    printf("\ninforme o cpf do funcionario ");
    scanf("%d",&contadora.cpf);
    scanf("%*[^\n]");
    scanf("%*c");

    printf("\ninforme o telefone do funcionario ");
    scanf("%d",&contadora.telefone);
    scanf("%*[^\n]");
    scanf("%*c");

    system("clear||cls");

    printf("-------------funcionario %d--------------",++i);

    printf("\ninforme o nome do funcionario ");
    scanf("%[^\n]s",estagiaria.nome);
    scanf("%*[^\n]");
    scanf("%*c");

    printf("\ninforme o endereco(cep) do funcionario ");
    scanf("%d",&estagiaria.endereco);
    scanf("%*[^\n]");
    scanf("%*c");

    printf("\ninforme o salario do funcionario ");
    scanf("%f",&estagiaria.salario);
    scanf("%*[^\n]");
    scanf("%*c");

    do{
        printf("\ninforme o sexo biologico(M ou F) do funcionario ");
        scanf("%c",&estagiaria.sexo);
        scanf("%*[^\n]");
        scanf("%*c");
    }
    while(estagiaria.sexo!= 'M' && estagiaria.sexo != 'F');

    printf("\ninforme o cpf do funcionario ");
    scanf("%d",&estagiaria.cpf);
    scanf("%*[^\n]");
    scanf("%*c");

    printf("\ninforme o telefone do funcionario ");
    scanf("%d",&estagiaria.telefone);
    scanf("%*[^\n]");
    scanf("%*c");

    system("clear||cls");

    for(j=0;j<3;j++){

        if((secretaria.salario >= estagiaria.salario) && (secretaria.salario >= contadora.salario)){
            printf("\nNome : %s   endereco: %d   salario: %.2f    sexo: %c   CPF: %d      telefone: %d\n",secretaria.nome,secretaria.endereco,secretaria.salario,secretaria.sexo,secretaria.cpf,secretaria.telefone);
            secretaria.salario = 0;
        }
        else
            if((estagiaria.salario >= secretaria.salario) && (estagiaria.salario >= contadora.salario)){
                printf("\nNome : %s   endereco: %d   salario: %.2f    sexo: %c   CPF: %d      telefone: %d\n",estagiaria.nome,estagiaria.endereco,estagiaria.salario,estagiaria.sexo,estagiaria.cpf,estagiaria.telefone);
                estagiaria.salario = 0;
            }
            else
                if((contadora.salario >= secretaria.salario) && (contadora.salario >= estagiaria.salario)){
                    printf("\nNome : %s   endereco: %d   salario: %.2f    sexo: %c   CPF: %d      telefone: %d\n",contadora.nome,contadora.endereco,contadora.salario,contadora.sexo,contadora.cpf,contadora.telefone);
                    contadora.salario = 0;
                }

    }

    return 0;
}



