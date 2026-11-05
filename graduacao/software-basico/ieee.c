// Equipe 1
// Beatriz Oliviera 202211134
// Murilo Patricio 202210355

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Função para calcular a potência
double potencia(double base, int expoente) {
    if (expoente == 0)
        return 1;  // Qualquer número elevado a 0 é 1
    else if (expoente > 0) {
        double resultado = 1;
        for (int i = 0; i < expoente; i++) {
            resultado *= base;  // Multiplica 'base' por 'expoente' vezes
        }
        return resultado;
    } else {
        double resultado = 1;
        for (int i = 0; i < -expoente; i++) {
            resultado /= base;  // Divide 'resultado' pela 'base' por '-expoente' vezes
        }
        return resultado;
    }
}

// Função para inicializar o vetor binário com zeros
void inicializa(char *binario, char w) {
    for (int i = 0; i < w; i++) {
        binario[i] = 0;
    }
}

// Função para converter um número decimal para binário
void D2B(char *binario, unsigned long long int numero, char w) {
    int resto;
    for (int i = w-1; numero != 0; i--) {
        resto = numero % 2;  // Calcula o resto da divisão por 2
        numero = numero / 2; // Atualiza o número para a próxima iteração
        binario[i] = resto;  // Atribui o resto à posição correspondente no vetor
    }
}

// Função para converter um número binário para decimal
int B2D(char *binario, char k) {
    int resultado = 0;
    for (int i = 1; i < k + 1; i++) {
        resultado += potencia(2, k-i) * binario[i];  // Calcula o valor decimal
    }
    return resultado;
}

// Função para converter a parte fracionária de um número binário para decimal
double B2F(char *binario, int k, char n) {
    double resultado = 0.0;
    int w = 1 + k + n;
    int i, j;
    for (i = k + 1, j = 1; i < w; i++, j++) {
        resultado += potencia(2, -j) * binario[i];  // Calcula o valor fracionário
    }
    return resultado;
}

// Função para imprimir o vetor binário
void printBinario(char *binario, char w) {
    for (int i = 0; i < w; i++) {
        printf("%d", binario[i]);
    }
}

int main() {
    char w,  // Tamanho total do vetor binário
        k,  // Número de bits para o expoente
        n;  // Número de bits para a parte fracionária

    printf("Informe o W: ");
    scanf("%hhd", &w);
    scanf("%*c");
    printf("\nInforme o K: ");
    scanf("%hhd", &k);
    scanf("%*c");
    printf("\nInforme o N: ");
    scanf("%hhd", &n);
    scanf("%*c");

    if(w != (k + n + 1)){ // Validação de W
        printf("\n\nErro na entrada\n");
        return 0;
    }

    char *binario = (char*)malloc(sizeof(char) * w);  // Aloca memória para o vetor binário
    unsigned long long int maxU = potencia(2, w) - 1;  // Número máximo de valores únicos representáveis com w bits
    unsigned int maxUK = potencia(2, k) - 1; // Número máximo de valores para o expoente com k bits
    unsigned int bias = potencia(2, k-1) - 1; // Bias utilizado para ajustar o expoente
    int E;
    unsigned int e;
    char s;
    double f, M, valor;
    unsigned long long int cont = 0;

    inicializa(binario, w);  // Inicializa o vetor binário com zeros

    printf("\nBits | e | E | f | M | Valor");
    printf("\n=================================================\n");

    while (cont != maxU) {
        s = binario[0];  // Sinal (bit mais significativo)
        e = B2D(binario, k);  // Converte a parte do expoente do vetor binário para decimal
        f = B2F(binario, k, n); // Converte a parte fracionária do vetor binário para decimal

        if (e != 0) {
            E = e - bias;  // Ajusta o expoente com o bias
            M = 1 + f;  // Calcula a mantissa
        } else {
            E = 1 - bias;  // Ajusta o expoente com o bias para o caso de e igual a 0
            M = f;  // Mantissa é apenas a parte fracionária
        }

        valor = potencia(-1, s) * M * potencia(2, E);  // Calcula o valor final

        printBinario(binario, w);  // Imprime o vetor binário
        if (e != maxUK)
            printf(" | %d | %d | %lf | %lf | %lf", e, E, f, M, valor);  // Imprime os valores calculados
        else {
            if (f == 0.0) {
                if (s == 0)
                    printf(" | +infinito");
                else
                    printf(" | -infinito");
            } else
                printf(" | NaN");
        }

        printf("\n");
        D2B(binario, ++cont, w);  // Incrementa o contador e converte para binário
    }

    free(binario);  // Libera a memória alocada
    return 0;
}

/*
O código utiliza tipos de dados grandes para garantir precisão e capacidade de lidar com a 
ampla faixa de valores necessária para representar números em ponto flutuante em 64 bits
*/