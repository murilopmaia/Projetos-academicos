#include <math.h>

int main (void){

    int binario;
    int expoente = 0;
    int auxiliar;
    int resultado = 0;

    printf("informe o numero binario (inteiro)");
    scanf("%d",&binario);

    for(;binario > 0;binario = binario/10){

        if(binario%10 == 1){

            auxiliar = pow(2,expoente);
            resultado += auxiliar;

        }
        expoente++;
    }

    printf("%d",resultado);

    return 0;

}

