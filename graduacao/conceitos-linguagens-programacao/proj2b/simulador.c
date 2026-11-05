#include <stdio.h>

char arvoreVet[100] = {'S'};
int nivel = 0;

char stack[100];
int topo = 0;

char palavra[100];
int next = 0;

void putArvore(int p){
    if(p == 1){
        arvoreVet[nivel*3 + 1] = 'a';
        arvoreVet[nivel*3 + 2] = 'S';
        arvoreVet[nivel*3 + 3] = 'b';
        nivel++;
    }
    else{
        if(p == 2){
            arvoreVet[nivel*3 + 1] = ' ';
            arvoreVet[nivel*3 + 2] = 'c';
            arvoreVet[nivel*3 + 3] = ' ';
            nivel++;
        }
    }
}

void imprimeArvore(){
    
    printf("\n\nArvore de Analise Sintatica");
    printf("\n\n   ");
    for(int i = 0; i < nivel*3; i++){
        if(i%3 == 1 && i != (nivel*3 - 2)){
            printf("\n  / | \\\n");
        }
        else{
            if(i == (nivel*3 - 2)){
                printf("\n    |  \n");
            }
        }
        printf(" %c ", arvoreVet[i]);
    }
}

int tamPalavra(char *palavra){
    int tam = -1;
    for(int i = 0; palavra[i] != '\0'; i++){
        tam++;
    }
    return tam;
}

void cabecalho(){
    int tamPal = tamPalavra(palavra);
    printf("Tabela de Parsing:\n\n");
    printf("  i ||  q  ||");
    for(int i = 0; i < tamPal;i++){
        if(i == tamPal/2){
            printf(".w");
        }
        printf(" ");
    }
    printf("  ||  t  ||  p  || Stack\n");
    for(int i = 0; i < tamPal + 40; i++){
        printf("=");
    }

}

void push(char *valor){
    int tam = tamPalavra(valor);

    for (int i = 0; valor[i] != '\0'; i++){
        stack[topo] = valor[tam-i];
        topo++;
    }
}

void pop(){
    topo--;
}

char read(){
    return stack[topo-1];
}

char getNext(){
    next++;
    char token = palavra[next];
    return token;
}

void erro(int i){
    if(i == 1){
        printf("\n\n\tErro, palavra nao reconhecida\n");
    }
}

void relatorio(int i, char *estado, char *tran, char *p){
    printf("\n");
    printf("%3d || ", i);
    printf("%3s || ", estado);
    for(int j = 0; palavra[j] != '\0'; j++){
        if(j == next){
            printf(".");
        }
        printf("%c", palavra[j]);
    }
    if(palavra[next] == '\0'){
        printf(".");
    }
    printf(" || ");
    printf("%3s || ", tran);
    printf("%3s || ", p);
    if(topo == 0){
        printf("None");
    }
    else{
        for(int j = topo-1; j >= 0; j--){
            printf("%c", stack[j]);
        }
    }
}

int main(int argc, char *argv[]){
    char token;
    int i = 0;
    FILE *fp;

    // Lendo a palavra do arquivo
    fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("Problema na leitura\n");
        return 0;
    }
    fscanf(fp, "%s", palavra);
    fclose(fp);

    cabecalho();

    q0:
        relatorio(i, "q0", "t0", "-");
        token = palavra[topo];
        push("S");
        goto q1;
    q1:
        i++;
        if (token == 'a' && read() == 'S') { relatorio(i, "q1", "t1", "p1"); pop(); push("aSb") ; putArvore(1); goto q1;}
        else if(token == 'c' && read() == 'S') { relatorio(i, "q1", "t2", "p2"); pop(); push("c"); putArvore(2); goto q1;}
        else if(token == 'a' && read() == 'a') { relatorio(i, "q1", "t3", "-"); pop(); token = getNext(); goto q1;}
        else if(token == 'b' && read() == 'b') { relatorio(i, "q1", "t4", "-"); pop(); token = getNext(); goto q1;}
        else if(token == 'c' && read() == 'c') { relatorio(i, "q1", "t5", "-"); pop(); token = getNext(); goto q1;}
        else if(token == '\0' && topo == 0) { relatorio(i, "q1", "-", "-"); goto fim;}
        else {erro(1); return 0;}
    fim:
        imprimeArvore();

    return 0;
}