int main(){
    int **p;
    int m ;
    do{
    printf("\ninforme o tamanho da matriz quadrada ");
      scanf("%d",&m);
        scanf("%*[^\n]");
        scanf("%*c");
        system("cls||clear");
    }
    while(m<=0);

    p = (int**) malloc(m * sizeof(int*));

    for(int x=0;x<m;x++){
        p[x] = (int*) malloc(m * sizeof(int));
    }

    printf("\n\tinforme os valores da matriz %dx%d\n\n",m,m);
    for(int x =0;x<m;x++){
        for(int y = 0;y<m;y++){
            printf("  Valor do A[%d][%d] ",x+1,y+1);
            scanf("%d",&p[x][y]);
            scanf("%*[^\n]");
            scanf("%*c");

        }
    }
    printf("\n\n");

    for(int x =0;x<m;x++){
        for(int y = 0;y<m;y++){
           printf("  %3d",p[x][y]);

        }
        free(p[x]);
        printf("\n");
    }


    printf("\n\n");//teste pra ve se limpou
      for(int x =0;x<m;x++){
        for(int y = 0;y<m;y++){
           printf("  %3d",p[x][y]);

    }

    printf("\n");
    }
    free(p);
    return 0;
}
