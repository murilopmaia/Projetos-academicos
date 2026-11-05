#include <stdio.h>
int main (void) {
    int hora, cartao, parcial_hora, parcial_cartao, aux_hora, aux_cartao,
        numero_maior=0, numero_menor=0, subt, aux_codigo, cont=1, divisor=100;
    printf("Insira a hora que a compra foi efetuada no formato HHMM:\n");
    scanf("%d", &hora);
    while (hora<0000 || hora>2359) { //N1-validação de entrada das horas
        printf("Insira a hora que a compra foi efetuada no formato HHMM:\n");
        scanf("%d", &hora);
    }
    printf("Insira os ultimos 4 digitos do cartao:\n");
    scanf("%d", &cartao);
    while (cartao<0000 || cartao>9999) { //N2-validação de entrada do numero do cartao
        printf("Insira os ultimos 4 digitos do cartao:\n");
        scanf("%d", &cartao);
    }
    parcial_hora=hora%1000; //N3-armazenando o resto da divisão para separar os proximos digitos
    aux_hora=hora/1000; //N4-separando o digito de maior magnitude para efetuar a comparação
    parcial_cartao=cartao%1000; // idem N3
    aux_cartao=cartao/1000; //idem N4
    if (aux_hora>=aux_cartao) { //N5-ao efetuar a comparação, armazenar nas variáveis que serão utilizadas na subt.
        numero_maior+=aux_hora*1000;
        numero_menor+=aux_cartao*1000;
    }
        else {
            numero_maior+=aux_cartao*1000;
            numero_menor+=aux_hora*1000;
        }
    for ( ; cont<=3; cont++) {
        aux_hora=parcial_hora/divisor;//idem N4
        parcial_hora%=divisor;//idem N3
        aux_cartao=parcial_cartao/divisor;//idem N4
        parcial_cartao%=divisor; //idem N3
        if (aux_hora>=aux_cartao) { //idem N5
           numero_maior+=aux_hora*divisor;
           numero_menor+=aux_cartao*divisor;
        }
        else {
            numero_maior+=aux_cartao*divisor;
            numero_menor+=aux_hora*divisor;
        }
        divisor/=10;
    }
    subt=numero_maior-numero_menor; //N6-efetuando a subt. do numero de maiores algarismos - numero de menores alg.
    printf("O codigo de verificacao e:\n");
    while (subt!=0) { //N7-estrut. de repet. para inverter a ordem de saída e gerar o código de verificação
        aux_codigo= subt%10;
        subt/=10;
        printf("%d", aux_codigo);
    }
    return 0;
}

