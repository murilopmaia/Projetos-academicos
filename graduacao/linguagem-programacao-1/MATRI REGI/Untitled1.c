#define TUT_MAX 100
#define ANI_MAX 10
int main (void){

    struct data{
        int dia;
        int mes;
        int ano;
    };
    struct end {
        char rua[100];
        char bairro[100];
        char numero[10];
        char cidade[100];
        char cep[10];
    };

    struct ficha_animal {
        char nome_animal[50];
        char especie[50];
        char genero;
        char raca[50];
        struct data data_nascimento;
        char cadastrado;

    };

    struct ficha_tutor {
        char nome_tutor[100];
        struct data data_cadastro;
        struct end endereco;
        struct ficha_animal animal[ANI_MAX];
    }tutor[TUT_MAX];
    int op,i=0,j,x,z,tamanho_veri=0,contador,tamanho_nome=0;
    char nome_verificar[100];

   do{
        do{
            system("clear||cls");
            printf("\n\t\tMenu\n\n"
                   "\t1 - cadastrar tutor\n"
                   "\t2 - cadastrar animal\n"
                   "\t3 - listar todos animais\n"
                   "\t4 - excluir um animal\n"
                   "\t5 - excluir tutor\n"
                   "\t6 - listar todos tutores\n"
                   "\t7 - encerrar\n");
            scanf("%d",&op);
            scanf("%*[^\n]");
            scanf("%*c");
            system("clear||cls");
            if(op != 1 && op != 2 && op != 3 && op != 4 && op != 5 && op != 6 && op != 7){
                printf("\n\tdigite corretamente");
                scanf("%*c");
                system("clear||cls");
            }
        }
        while(op != 1 && op != 2 && op != 3 && op != 4 && op != 5 && op != 6 && op != 7);

            switch(op){

                case 1 :
                        printf("\ninforme o nome do tutor ");
                        scanf("%[^\n]s",&tutor[i].nome_tutor);
                        scanf("%*[^\n]");
                        scanf("%*c");
                        printf("\ninforme a data de cadastro DD/MM/AA ");
                        scanf("%d %d %d",&tutor[i].data_cadastro.dia,&tutor[i].data_cadastro.mes,&tutor[i].data_cadastro.ano);
                        scanf("%*[^\n]");
                        scanf("%*c");
                        printf("\ninforme o endereco do tutor: ");
                        printf("\n\ninforme a rua ");
                        scanf("%[^\n]s",&tutor[i].endereco.rua);
                        scanf("%*[^\n]");
                        scanf("%*c");
                        printf("\ninforme o bairro ");
                        scanf("%[^\n]s",&tutor[i].endereco.bairro);
                        scanf("%*[^\n]");
                        scanf("%*c");
                        printf("\ninforme o numero da residencia ");
                        scanf("%[^\n]s",&tutor[i].endereco.numero);
                        scanf("%*[^\n]");
                        scanf("%*c");
                        printf("\ninforme a cidade ");
                        scanf("%[^\n]s",&tutor[i].endereco.cidade);
                        scanf("%*[^\n]");
                        scanf("%*c");
                        printf("\n informe o cep ");
                        scanf("%[^\n]s",&tutor[i].endereco.cep);
                        scanf("%*[^\n]");
                        scanf("%*c");
                        i++;
                        break;

                case 2 :
                        printf("informe o nome do tutor que queres cadastrar ");
                        scanf("%[^\n]s",&nome_verificar);
                        scanf("%*[^\n]");
                        scanf("%*c");
                        tamanho_veri = 0;
                        for(j=0;nome_verificar[j]!= '\0';j++){
                            tamanho_veri++;
                        }

                        for(x=0;x<=i;x++){
                            contador = 0;
                            tamanho_nome = 0;
                            for(j=0;tutor[x].nome_tutor[j]!= '\0';j++){
                            tamanho_nome++;
                            }
                            if(tamanho_veri == tamanho_nome){
                                    for(j=0; tutor[x].nome_tutor[j]!='\0'; j++){
                                        if(tutor[x].nome_tutor[j] == nome_verificar[j])
                                           contador++;
                                    }
                                    if(contador == tamanho_veri){
                                        z=0;
                                        for(j=0;j<ANI_MAX;j++){

                                        }
                                    }


                            }
                        }
                    break;

            }

   }
   while(op != 7);






































return 0;
}

