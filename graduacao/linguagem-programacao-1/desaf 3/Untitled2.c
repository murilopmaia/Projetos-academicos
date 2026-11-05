int main(void){

    int matriz[4][4];
    int i,j;
    int teste,maior=0,cont,cont2=1,cont3=0;

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("informe o valor da matriz[%d][%d]",i+1,j+1);
            scanf("%d",&matriz[i][j]);
            scanf("%*[^\n]");
            scanf("%*c");
        }
    }

    int *p=matriz;

    for(i=0;i<16;i++){
        teste = p[i];
        cont = 0;
        for(j=0;j<16;j++){
            if (teste == p[j]){
                cont++;

                if(cont>=cont2){
                    cont3 = cont2;
                    cont2=cont;
                    maior = teste;

                }
            }

        }


    }

    if(cont2 == 1 || cont3 == cont2){
        printf("não tem repeticao");
    }
    else{
        printf("o termo que mais se repete eh = %d, %d vezez",maior,cont2);
    }

    return 0;}
