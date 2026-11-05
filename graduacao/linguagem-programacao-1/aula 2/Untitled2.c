int main (void){

    int perguntas = 30;
    int valor_parcial = 100;
    long long int valor_total = 0;
    const int REAIS = 1000000;
    int auxiliar = 0;

    for(;perguntas >= 1;perguntas--){

        valor_total  += valor_parcial;
        valor_parcial *=  2;




        if(valor_total >= REAIS ){

            break;
        }

         auxiliar++;
    }

    printf("toal de perguntas  = %d",auxiliar);
}
