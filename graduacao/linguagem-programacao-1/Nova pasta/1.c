#define FUNCIONARIOS 10
int main(){

    int mmAtual, aaAtual, mmAdm, aaAdm, i, mes;
    float salario, anos, ajuste;

    do{
    printf("Insira a data(mm/aa): ");
    scanf("%d%*c%d%*c", &mmAtual, &aaAtual);
    if(mmAtual<1 || mmAtual>12 || aaAtual<0){
        printf("Data invalida\n");
    }}
    while(mmAtual<1 || mmAtual>12 || aaAtual<=0);


    for(i=0; i<FUNCIONARIOS; i++){
            do{
        printf("\nInsira a data de admissao do funcionario %d: ", i+1);
        scanf("%d%*c%d%*c", &mmAdm, &aaAdm);

        if(mmAdm<1 || mmAdm>12 || aaAdm<=0)
            printf("Data invalida\n");

        }
        while(mmAdm<1 || mmAdm>12 || aaAdm<=0);



        do{
        printf("Insira o salario do funcionario: ");
        scanf("%f", &salario);

        if(salario<0){
            printf("Nota invalida");
        }}
        while(salario<0);
        }

        anos=aaAtual-aaAdm;
        mes=mmAtual-mmAdm;

        if(anos<4 || (anos==4 && mes<0)){


            printf("O funcionario nao tem direito a ATS\n");}

            else{
                salario*=(1+(anos-4)/100);
                printf("O funcionario tem direito ao salario de %.2f", salario);
            }






return 0;}
