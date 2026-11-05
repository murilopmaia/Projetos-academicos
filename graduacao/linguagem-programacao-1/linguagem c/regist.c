
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
        int quant_animal;
    }tutor[TUT_MAX];

    int op,i=0,j,x,tamanho_veri=0,contador,tamanho_nome=0,fim=0,z;
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
                        printf("\ninforme a data de cadastro DD MM AA ");
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
                        printf("informe o nome do tutor que queres cadastrar o animal  ");
                        scanf("%[^\n]s",&nome_verificar);
                        scanf("%*[^\n]");
                        scanf("%*c");
                        tamanho_veri = 0;
                        fim = 0;
                        for(j=0;nome_verificar[j]!= '\0';j++){
                            tamanho_veri++;
                        }
                        for(x=0;x<i;x++){
                            contador = 0;
                            tamanho_nome = 0;
                            
                            for(j=0;tutor[x].nome_tutor[j]!= '\0';j++){
                            tamanho_nome++;
                            }
                            if(fim == 1){
                                fim = 0;
                                break;
                            }
                            if(tamanho_veri == tamanho_nome){
                                    for(j=0; tutor[x].nome_tutor[j]!='\0'; j++){
                                        if(tutor[x].nome_tutor[j] == nome_verificar[j])
                                           contador++;
                                    }
                                    if(contador == tamanho_veri){
                                        
                                        for(j=0;j<ANI_MAX;){
                                            if(tutor[x].animal[j].cadastrado == 1){
                                                j++;
                                            }
                                            else{
                                                printf("\ninforme o nome do animal ");
                                                scanf("%[^\n]s",&tutor[x].animal[j].nome_animal);
                                                scanf("%*[^\n]");
                                                scanf("%*c");
                                                printf("\ninforme a especie do animal ");
                                                scanf("%[^\n]s",&tutor[x].animal[j].especie);
                                                scanf("%*[^\n]");
                                                scanf("%*c");
                                                do{
                                                    printf("\ninforme o genero biologico do animal M - macho F - femea ");
                                                    scanf("%c",&tutor[x].animal[j].genero);
                                                    scanf("%*[^\n]");
                                                    scanf("%*c");
                                                    if(tutor[x].animal[j].genero != 'M' && tutor[x].animal[j].genero != 'F'){
                                                        printf("\nDigite corretamente");
                                                        scanf("%*c");   
                                                    }
                                                }
                                                while(tutor[x].animal[j].genero != 'M' && tutor[x].animal[j].genero != 'F');
                                                printf("\ninforme a raca do animal ");
                                                scanf("%[^\n]s",&tutor[x].animal[j].raca);
                                                scanf("%*[^\n]");
                                                scanf("%*c");
                                                printf("\ninforme a data de nascimento do animal DD MM AA ");
                                                scanf("%d %d %d",&tutor[x].animal[j].data_nascimento.dia,&tutor[x].animal[j].data_nascimento.mes,&tutor[x].animal[j].data_nascimento.ano);
                                                scanf("%*[^\n]");
                                                scanf("%*c");
                                                tutor[x].quant_animal = j;
                                                printf("\ncadastro realizado");
                                                scanf("%*c");
                                                fim = 1;
                                                tutor[x].animal[j].cadastrado = 1;
                                                break;

                                            }
                                            
                                        }
                                    }
                                    else{
                                        if(x == i-1){
                                            printf("\nTutor nao cadastrado ");
                                            scanf("%*c");
                                            fim = 1;
                                        }
                                    }


                            }
                            else{
                                if(x == i-1){
                                    printf("\nTutor nao cadastrado");
                                    scanf("%*c");
                                    break;
                                }
                            }
                        }
                    break;

                case 3 :

                        printf("informe o nome do tutor para mostrar os animais ");
                        scanf("%[^\n]s",&nome_verificar);
                        scanf("%*[^\n]");
                        scanf("%*c");
                        tamanho_veri = 0;
                        fim = 0;
                        for(j=0;nome_verificar[j]!= '\0';j++){
                            tamanho_veri++;
                        }
                        for(x=0;x<=i;x++){
                            contador = 0;
                            tamanho_nome = 0;
                            
                            for(j=0;tutor[x].nome_tutor[j]!= '\0';j++){
                            tamanho_nome++;
                            }
                            if(fim == 1){
                                fim = 0;
                                break;
                            }
                            if(tamanho_veri == tamanho_nome){
                                    for(j=0; tutor[x].nome_tutor[j]!='\0'; j++){
                                        if(tutor[x].nome_tutor[j] == nome_verificar[j])
                                           contador++;
                                    }
                                    if(contador == tamanho_veri){
                                        for(j=0;j<=tutor[x].quant_animal;j++){
                                            printf("\n----------------------------\n");
                                            printf("\n\t.%s ",tutor[x].animal[j].nome_animal);
                                            printf("\nespecie : %s",tutor[x].animal[j].especie);
                                            printf("\ngenero : %c",tutor[x].animal[j].genero);
                                            printf("\nraca : %s",tutor[x].animal[j].raca);
                                            printf("\ndata de nascimento : %d/%d/%d",tutor[x].animal[j].data_nascimento.dia,tutor[x].animal[j].data_nascimento.mes,tutor[x].animal[j].data_nascimento.ano);

                                        }
                                        fim = 1;
                                        scanf("%*c");
                                    }
                                    else{
                                        if(x == i-1){
                                            printf("\nTutor nao cadastrado ");
                                            scanf("%*c");
                                            fim = 1;
                                        }
                                        
                                    }              
                            }
                            else{
                                if(x == i-1){
                                    printf("\nTutor nao cadastrado");
                                    scanf("%*c");
                                    break;
                                }
                            }
                        }
                    break;
                case 4 :
                        printf("informe o nome do tutor ");
                        scanf("%[^\n]s",&nome_verificar);
                        scanf("%*[^\n]");
                        scanf("%*c");
                        tamanho_veri = 0;
                        fim = 0;
                        for(j=0;nome_verificar[j]!= '\0';j++){
                            tamanho_veri++;
                        }
                        for(x=0;x<=i;x++){
                            contador = 0;
                            tamanho_nome = 0;
                            
                            for(j=0;tutor[x].nome_tutor[j]!= '\0';j++){
                            tamanho_nome++;
                            }
                            if(fim == 1){
                                fim = 0;
                                break;
                            }
                            if(tamanho_veri == tamanho_nome){
                                    for(j=0; tutor[x].nome_tutor[j]!='\0'; j++){
                                        if(tutor[x].nome_tutor[j] == nome_verificar[j])
                                           contador++;
                                    }
                                    if(contador == tamanho_veri){
                                        for(j=0;j<=tutor[x].quant_animal;j++){
                                            printf("\n.%s  ",tutor[x].animal[j].nome_animal);
                                        }
                                        
                                        scanf("%*c");
                                        printf("\nQual animal desejas excluir? ");
                                        scanf("%[^\n]s",&nome_verificar);
                                        scanf("%*[^\n]");
                                        scanf("%*c");
                                        tamanho_veri = 0;
                                        for(j=0;nome_verificar[j]!= '\0';j++){
                                            tamanho_veri++;
                                        }
                                        for(z=0;z<=tutor[x].quant_animal;z++){
                                            contador = 0;
                                            tamanho_nome = 0;
                                            
                                            for(j=0;tutor[x].animal[z].nome_animal[j]!= '\0';j++){
                                            tamanho_nome++;
                                            }
                                            if(fim == 1){
                                                fim = 0;
                                                break;
                                            }
                                            if(tamanho_veri == tamanho_nome){
                                                    for(j=0; tutor[x].animal[z].nome_animal[j]!='\0'; j++){
                                                        if(tutor[x].animal[z].nome_animal[j] == nome_verificar[j])
                                                        contador++;
                                                    }
                                                    if(contador == tamanho_veri){
                                                        for(j=z;j<tutor[x].quant_animal;j++){
                                                            tutor[x].animal[z] = tutor[x].animal[z+1];
                                                        }
                                                        tutor[x].quant_animal--;
                                                        printf("\no animal foi excluido");
                                                        scanf("%*c");
                                                        fim = 1;
                                                       
                                                    }
                                                    else{
                                                        if(z == tutor[x].quant_animal+1){
                                                            printf("\nanimal nao cadastrado ");
                                                            scanf("%*c");
                                                            fim = 1;
                                                        }
                                                    }


                                            }
                                             else{
                                              if(z == tutor[x].quant_animal+1){
                                                 printf("\nanimal nao cadastrado");
                                                 scanf("%*c");
                                                 break;
                                               }
                                             }
                                        }

                                    }
                                    else{
                                        if(x == i-1){
                                            printf("\nTutor nao cadastrado ");
                                            scanf("%*c");
                                            fim = 1;
                                        }
                                    }              
                            }
                            else{
                                if(x == i-1){
                                    printf("\nTutor nao cadastrado");
                                    scanf("%*c");
                                    break;
                                }
                            }
                        }
                    break;
                case 5 :
                    printf("informe o nome do tutor que queres excluir ");
                        scanf("%[^\n]s",&nome_verificar);
                        scanf("%*[^\n]");
                        scanf("%*c");
                        tamanho_veri = 0;
                        fim = 0;
                        for(j=0;nome_verificar[j]!= '\0';j++){
                            tamanho_veri++;
                        }
                        for(x=0;x<=i;x++){
                            contador = 0;
                            tamanho_nome = 0;
                            
                            for(j=0;tutor[x].nome_tutor[j]!= '\0';j++){
                            tamanho_nome++;
                            }
                            if(fim == 1){
                                fim = 0;
                                break;
                            }
                            if(tamanho_veri == tamanho_nome){
                                    for(j=0; tutor[x].nome_tutor[j]!='\0'; j++){
                                        if(tutor[x].nome_tutor[j] == nome_verificar[j])
                                           contador++;
                                    }
                                    if(contador == tamanho_veri){
                                        for(j=x;j<i;j++){
                                            tutor[x] = tutor[x+1];
                                        }
                                        i--;
                                        printf("\ntutor  excluido");
                                        scanf("%*c");
                                        fim = 1;
                                    }
                                    else{
                                        if(x == i-1){
                                            printf("\nTutor nao cadastrado ");
                                            scanf("%*c");
                                            fim = 1;
                                        }
                                        
                                    }              
                            }
                            else{
                                if(x == i-1){
                                    printf("\nTutor nao cadastrado");
                                    scanf("%*c");
                                    break;
                                }
                            }
                        }
                    break;
                case 6 :
                    printf("informe o nome do tutor que queres ver ");
                        scanf("%[^\n]s",&nome_verificar);
                        scanf("%*[^\n]");
                        scanf("%*c");
                        tamanho_veri = 0;
                        fim = 0;
                        for(j=0;nome_verificar[j]!= '\0';j++){
                            tamanho_veri++;
                        }
                        for(x=0;x<=i;x++){
                            contador = 0;
                            tamanho_nome = 0;
                            
                            for(j=0;tutor[x].nome_tutor[j]!= '\0';j++){
                            tamanho_nome++;
                            }
                            if(fim == 1){
                                fim = 0;
                                break;
                            }
                            if(tamanho_veri == tamanho_nome){
                                    for(j=0; tutor[x].nome_tutor[j]!='\0'; j++){
                                        if(tutor[x].nome_tutor[j] == nome_verificar[j])
                                           contador++;
                                    }
                                    if(contador == tamanho_veri){
                                       for(j=0;j<i;j++){
                                        printf("-------------------------------");
                                        printf("\n\t%s",tutor[j].nome_tutor);
                                        printf("\ndata de cadastro = %d/%d/%d",tutor[j].data_cadastro.dia,tutor[j].data_cadastro.mes,tutor[j].data_cadastro.ano);
                                        printf("\ntem = %d animais",tutor[j].quant_animal);
                                        printf("\ncep = %s",tutor[j].endereco.cep);
                                        scanf("%*c");
                                       }
                                       fim = 1;
                                    }
                                    else{
                                        if(x == i-1){
                                            printf("\nTutor nao cadastrado ");
                                            scanf("%*c");
                                            fim = 1;
                                        }
                                        
                                    }              
                            }
                            else{
                                if(x == i-1){
                                    printf("\nTutor nao cadastrado");
                                    scanf("%*c");
                                    break;
                                }
                            }
                        }
                    break;
                
            }
   }
   while(op != 7);






































return 0;
}

