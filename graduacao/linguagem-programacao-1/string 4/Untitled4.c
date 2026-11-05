int main(void){

    char valor[100];
    int i;

    printf("quando quiser parar digite f\n\n");
    printf("informe uma sequencia de numeros\n\n");

    for(i = 0 ; i<100 ; i++){

        scanf("%d%*c",&valor[i]);
        if(valor[i] == 'f'){
            break;
        }
    }

    printf("%s",valor);
return 0;
}
