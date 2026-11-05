#include <stdio.h>

#define amax 2047 // Endereço máximo
#define levmax 3  // Profundidade máxima de aninhamento de blocos
#define cxmax 200 // Tamanho da matriz de código
#define stacksize 500

typedef enum { LIT, OPR, LOD, STO, CAL, INT, JMP, JPC} fct;

typedef struct{
    fct f;
    int l;
    int a;
} instruction;

int p, b, t;   // Registros de programa, base, topo da pilha
instruction i; // Registro de instrução
int s[stacksize];

void imprime(int p, int b, int t, instruction i){

    printf(" | (");

    switch (i.f){
        case LIT:
            printf("LIT");
            break;
        case OPR:
            printf("OPR");
            break;
        case LOD:
            printf("LOD");
            break;
        case STO:
            printf("STO");
            break;
        case CAL:
            printf("CAL");
            break;
        case INT:
            printf("INT");
            break;
        case JMP:
            printf("JMP");
            break;
        case JPC:
            printf("JPC");
            break;
    }
    printf(" %d %d) |", i.l, i.a);
    printf(" %d %d %d |", p, b, t);

    for (int x = 0; x <= t; x++){
        printf(" %d ", s[x]);
    }
}
int odd(int i){
    return i % 2 != 0;
}

instruction code[cxmax + 1] = {
    {OPR, 0, 0},
};

int base(int l){

    int b1 = b;

    while (l > 0){
        b1 = s[b1];
        l--;
    }

    return b1;
}

int main(){

    printf("start PL/0\n");
    t = 0;
    b = 1;
    p = 0;
    s[1] = 0;
    s[2] = 0;
    s[3] = 0;

    printf("p | (i.f  i.l  i.a) | p  b t | s[00] s[01] s[02] s[03] s[04] s[05] s[06] s[07] s[08] s[09] s[10]");
    printf("\n-----------------------------------------------------------------------------------------------");

    do{

        printf("\n\n%d", p);
        i = code[p];
        p++;
        switch (i.f){
            case LIT:
                t++;
                s[t] = i.a;
                break;
            case OPR:
                switch (i.a)
                {
                case 0: // return
                    t = b - 1;
                    p = s[t + 3];
                    b = s[t + 2];
                    break;
                case 1:
                    s[t] = -s[t];
                    break;
                case 2:
                    t--;
                    s[t] = s[t] + s[t + 1];
                    break;
                case 3:
                    t--;
                    s[t] = s[t] - s[t + 1];
                    break;
                case 4:
                    t--;
                    s[t] = s[t] * s[t + 1];
                    break;
                case 5:
                    t--;
                    s[t] = s[t] / s[t + 1];
                    break;
                case 6:
                    s[t] = odd(s[t]);
                    break;
                case 8:
                    t--;
                    s[t] = s[t] == s[t + 1];
                    break;
                case 9:
                    t--;
                    s[t] = s[t] != s[t + 1];
                    break;
                case 10:
                    t--;
                    s[t] = s[t] < s[t + 1];
                    break;
                case 11:
                    t--;
                    s[t] = s[t] >= s[t + 1];
                    break;
                case 12:
                    t--;
                    s[t] = s[t] > s[t + 1];
                    break;
                case 13:
                    t--;
                    s[t] = s[t] <= s[t + 1];
                    break;
                }
                break;
            case LOD:
                t++;
                s[t] = s[base(i.l) + i.a];
                break;
            case STO:
                s[base(i.l) + i.a] = s[t];
                t--;
                break;
            case CAL:
                s[t + 1] = base(i.l);
                s[t + 2] = b;
                s[t + 3] = p;
                b = t + 1;
                p = i.a;
                break;
            case INT:
                t += i.a;
                break;
            case JMP:
                p = i.a;
                break;
            case JPC:
                if (s[t] == 0)
                    p = i.a;
                t--;
                break;
        }
        imprime(p, b, t, i);
    } while (p != 0);

    printf("\n\nend PL/0\n");
    return 0;
}