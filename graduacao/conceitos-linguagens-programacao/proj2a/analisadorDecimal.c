// Murilo Patricio Maia
#include <stdio.h>
#define TESTE c == '0' || c == '1' || c == '2' || c == '3' || c  == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'

// Funcao para pegar a proxima "letra"
char get(char *palavra, int *i){
    char valor = palavra[*i];
    (*i)++;
    return valor;
}

int main(int argc, char *argv[]){

    FILE *fp = fopen(argv[1], "r"); // arquivo
    char palavra[999]; // palavra
    char c; // "letra"
    int estadoAceito = 0; // Serve para saber se o estado atual é de aceitacao
    int i;

    while (!feof(fp)){
        fscanf(fp, "%s", palavra); // Le a palavra inteira, linha por linha
        i = 0;

        q0:
            c = get(palavra, &i);
            estadoAceito = 0;

            if (TESTE){
                goto q1;
            }
            else{
                goto f;
            }
        q1:
            c = get(palavra, &i);
            estadoAceito = 1;

            if (TESTE){
                goto q1;
            }
            else{
                if (c != '\0' && c != '\n'){ // Caso a palavra não tenha acabado é rejeitado
                    estadoAceito = 0;
                }
                goto f;
            }   
        f: // Estado final

        if (estadoAceito == 1){ // Printa o resultado
            printf("palavra: %s reconhecida\n", palavra);
        }
        else{
            printf("palavra: %s rejeitada\n", palavra);
        }
    }

    fclose(fp);
    return 0;
}