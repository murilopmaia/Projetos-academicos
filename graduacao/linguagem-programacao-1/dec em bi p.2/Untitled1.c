int main(void){
    int dec;
    int auxiliar;
    int contador=0;
    int print[contador];
    int local= 0;
    int auxiliar2;


    printf("informe o numero em decimal(inteiro)");
    scanf("%d%*c",&dec);

    auxiliar2 = dec;

    for(;auxiliar2 > 0;auxiliar2 /= 2){
        contador++;
    }

printf("%d",contador);

    for(;dec > 0;dec /= 2){
       //auxiliar = dec%2;
        //print[local] = auxiliar;
        local++;

    }
printf("%d",local);

   // local = 0;

    //for(;contador > 0;contador--){
       // printf("%d",print[contador]);

   // }

    return 0;



}
