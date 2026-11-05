int main (void){

    short int numero;
    short int auxiliar;
    short int num1;
    short int num2;
    short int num3;
    short int soma;


   do{

    printf("informe um numero de 3 digitos");
    scanf("%hd",&numero);

   }
   while (numero/1000 != 0);

   num1 = numero%10;
   num2 = (numero/10)%10;
   num3 = (numero/100)%10;

   soma = num1 + num2;

   if (num3 > soma){

        printf("o primeiro numero eh maior que a soma dos outros dois");

   }
   else{

        printf("o primeiro numero nao eh maior que a soma dos outros dois");
   }

   return 0;

}


