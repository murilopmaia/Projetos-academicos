#include <string.h>

void afd(char **q, char **sigma, char ***delta, char *q0, char **f, char *cadeia){
    char estadoAtual[100];
    strcpy(estadoAtual, q0);
    int tam = (int)strlen(cadeia);
    
    for(int i = 0; i < tam; i++){
        
    }
}

int main(){
    char q[2][3] = {"q0", "q1"};
    char sigma[10][2] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    char delta[20][3][10] = {
        {"q0", "1", "q1"},
        {"q0", "2", "q1"},
        {"q0", "3", "q1"},
        {"q0", "4", "q1"},
        {"q0", "5", "q1"},
        {"q0", "6", "q1"},
        {"q0", "7", "q1"},
        {"q0", "8", "q1"},
        {"q0", "9", "q1"},
        {"q0", "0", "q1"},
        {"q1", "1", "q1"},
        {"q1", "2", "q1"},
        {"q1", "3", "q1"},
        {"q1", "4", "q1"},
        {"q1", "5", "q1"},
        {"q1", "6", "q1"},
        {"q1", "7", "q1"},
        {"q1", "9", "q1"},
        {"q1", "9", "q1"},
        {"q1", "0", "q1"},

    };
    char q0[] = "q0";
    char f[1][3] = {"q1"};
    char cadeia[] = "1234213213124235";
    afd(q, sigma, delta, q0, f, cadeia);
    return 0;
}