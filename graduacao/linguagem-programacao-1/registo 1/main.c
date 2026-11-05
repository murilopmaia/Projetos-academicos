int main (void){

    struct data{
        int dia;
        int mes;
        int ano;
    }hoje;
    struct dados{
        char nome[100];
        char sexo;
        int salario;
        struct data data_nascimento;
        struct data data_admissao;
    }gerente,vendedor;
    ;
    
    printf("\nInforme a data de hoje DD MM AA - ");
    scanf("%d %d %d",&hoje.dia,&hoje.mes,&hoje.ano);
    scanf("%*[^\n]");
    scanf("%*c");
    printf("\nQual o nome do(a) vendedor - ");
    scanf("%[^\n]s",&vendedor.nome);
    scanf("%*[^\n]");
    scanf("%*c");
    printf("\nQual o sexo do(a) vendedor - ");
    scanf("%c",&vendedor.sexo);
    scanf("%*[^\n]");
    scanf("%*c");
    printf("\nInforme o salario do(a) vendedor - ");
    scanf("%d",&vendedor.salario);
    scanf("%*[^\n]");
    scanf("%*c");
    printf("\ninforme a data de amissao do(a) vendedor DD MM AA - ");
    scanf("%d %d %d",&vendedor.data_admissao.dia,&vendedor.data_admissao.mes,&vendedor.data_admissao.ano);
    scanf("%*[^\n]");
    scanf("%*c");
    printf("\ninforme a data de nascimento do(a) vendedor DD MM AA - ");
    scanf("%d %d %d",&vendedor.data_nascimento.dia,&vendedor.data_nascimento.mes,&vendedor.data_nascimento.ano);
    scanf("%*[^\n]");
    scanf("%*c");
    system("clear||cls");


    printf("\nQual o nome do(a) gerente - ");
    scanf("%[^\n]s",&gerente.nome);
    scanf("%*[^\n]");
    scanf("%*c");
    printf("\nQual o sexo do(a) gerente - ");
    scanf("%c",&gerente.sexo);
    scanf("%*[^\n]");
    scanf("%*c");
    printf("\nInforme o salario do(a) gerente - ");
    scanf("%d",&gerente.salario);
    scanf("%*[^\n]");
    scanf("%*c");
    printf("\ninforme a data de amissao do(a) gerente DD MM AA - ");
    scanf("%d %d %d",&gerente.data_admissao.dia,&gerente.data_admissao.mes,&gerente.data_admissao.ano);
    scanf("%*[^\n]");
    scanf("%*c");
    printf("\ninforme a data de nascimento do(a) vendedor DD MM AA - ");
    scanf("%d %d %d",&gerente.data_nascimento.dia,&gerente.data_nascimento.mes,&gerente.data_nascimento.ano);
    scanf("%*[^\n]");
    scanf("%*c");
    system("clear||cls");


    printf("\n-------------------------Gerente-----------------------\n");
    printf("\nNome = %s",gerente.nome);
    printf("\nSexo = %c",gerente.sexo);
    printf("\nSalario = %d",gerente.salario);
    printf("\nData de admissao = %d/%d/%d",gerente.data_admissao.dia,gerente.data_admissao.mes,gerente.data_admissao.ano);
    printf("\nData de nascimento = %d/%d/%d",gerente.data_nascimento.dia,gerente.data_nascimento.mes,gerente.data_nascimento.ano);
    if(hoje.ano - gerente.data_admissao.ano > 0){
        printf("\nAnos de serviCo = %d",(hoje.ano - gerente.data_admissao.ano));
    }
    if(hoje.mes - gerente.data_admissao.mes > 0){
        printf("\nMeses de serviCo = %d",(hoje.mes - gerente.data_admissao.mes));
    }

    printf("\n-------------------------Vendedor-----------------------\n");
    printf("\nNome = %s",vendedor.nome);
    printf("\nSexo = %c",vendedor.sexo);
    printf("\nSalario = %d",vendedor.salario);
    printf("\nData de admissao = %d/%d/%d",vendedor.data_admissao.dia,vendedor.data_admissao.mes,vendedor.data_admissao.ano);
    printf("\nData de nascimento = %d/%d/%d",vendedor.data_nascimento.dia,vendedor.data_nascimento.mes,vendedor.data_nascimento.ano);
    if(hoje.ano - vendedor.data_admissao.ano > 0){
        printf("\nAnos de serviCo = %d",(hoje.ano - vendedor.data_admissao.ano));
    }
    if(hoje.mes - vendedor.data_admissao.mes > 0){
        printf("\nMeses de serviCo = %d",(hoje.mes - vendedor.data_admissao.mes));
    }

    if(vendedor.salario > gerente.salario){
        printf("\n\n\tO vendedor tem um salario maior que o gerente");
    }
    else
        if(vendedor.salario == gerente.salario){
            printf("\n\n\tAmbos tem o mesmo salario");
        }
        else{
            printf("\n\n\tO gerente tem um salario maior que o vendedor");
        }

    return 0;
}

