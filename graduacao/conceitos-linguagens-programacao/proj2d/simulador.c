#include <stdio.h>
#define TAMMAX 900


char arvoreVet[TAMMAX];
int pilha[100];
int topoPilha = 0;

char stack[100];
int topo = 0;

char palavra[100];
int next = 0;

char polonesaRev[50];
int topoPolonesa = 0;

void pushPilha(int valor){
    pilha[topoPilha++] = valor;
}

int popPilha(){
    return pilha[--topoPilha];
}

int readPilha(){
    return pilha[topoPilha-1];
}

void iniArvore(char *arvore){
    for(int i = 0; i<TAMMAX;i++){
        arvore[i] = ' ';
    }
}

void putArvore(int p){
    if(p == 0){
        arvoreVet[0] = 'E';
        pushPilha(0);
    }
    else if(p == 1){
        int no = popPilha();
        arvoreVet[5* no + 1] = '(';
        arvoreVet[5* no + 2] = 'E';
        arvoreVet[5* no + 3] = 'X';
        arvoreVet[5* no + 4] = 'E';
        arvoreVet[5* no + 5] = ')';
        pushPilha(5* no + 4);
        pushPilha(5* no + 3);
        pushPilha(5* no + 2);
    }
    else if(p == 2){
        int no = popPilha();
        arvoreVet[5 * no + 1] = '0';
    }
    else if(p == 3){
        int no = popPilha();
        arvoreVet[5 * no + 1] = '1';
    }
    else if(p == 4){
        int no = popPilha();
        arvoreVet[5 * no + 1] = 'a';
    }
    else if(p == 5){
        int no = popPilha();
        arvoreVet[5 * no + 1] = 'b';
    }
    else if(p == 6){
        int no = popPilha();
        arvoreVet[5 * no + 1] = 'c';
    }
    else if(p == 7){
        int no = popPilha();
        arvoreVet[5 * no + 1] = '+';
    }
    else if(p == 8){
        int no = popPilha();
        arvoreVet[5 * no + 1] = '-';
    }
    else if(p == 9){
        int no = popPilha();
        arvoreVet[5 * no + 1] = '*';
    }
    else if(p == 10){
        int no = popPilha();
        arvoreVet[5 * no + 1] = '/';
    }
    
}

void penta2Bi(char *arvoreNew){
    int pai, avo;

    iniArvore(arvoreNew);

    for(int i=TAMMAX; i >= 0; i--){
        if(arvoreVet[i] == 'a' || arvoreVet[i] == 'b' || arvoreVet[i] == 'c' || arvoreVet[i] == '0' || arvoreVet[i] == '1'){
            
            pai = (i-1)/5;
            arvoreNew[pai] = arvoreVet[i];
            arvoreNew[i] = ' ';
            
        }
        else if(arvoreVet[i] == '+' || arvoreVet[i] == '-' || arvoreVet[i] == '*' || arvoreVet[i] == '/'){
            
            pai = (i-1)/5;
            avo = (pai-1)/5;
            arvoreNew[pai] = ' ';
            arvoreNew[avo] = arvoreVet[i];
            arvoreNew[i] = ' ';
        }
    }
}

void PostOrder(char *arvore, int indice){
    if(arvore[indice] != ' '){
        PostOrder(arvore, 5*indice+2);
        PostOrder(arvore, 5*indice+4);
        polonesaRev[topoPolonesa++] = arvore[indice];
        
    }
}

void Polo2Pcode(){
    for(int i = 0; polonesaRev[i] != '\0'; i++){
        switch (polonesaRev[i])
        {
        case 'a':
            printf(" LOD 0 3");
            break;
        case 'b':
            printf(" LOD 0 4");
            break;
        case 'c':
            printf(" LOD 0 5");
            break;
        case '1':
            printf(" LIT 0 1");
            break;
        case '0':
            printf(" LIT 0 0");
            break;
        case '+':
            printf(" OPR 0 2");
            break;
        case '-':
            printf(" OPR 0 3");
            break;
        case '*':
            printf(" OPR 0 4");
            break;
        case '/':
            printf(" OPR 0 5");
            break;
        default:
            break;
        
        }
        printf("\n");
    }
}

void printarArvore(char *arvore, int indice, int nivel) {
    if (indice < TAMMAX && arvore[indice] != ' ') {
        for (int i = 0; i < nivel; i++) {
            printf("   ");
        }

        printf("|-- %c\n", arvore[indice]);

        printarArvore(arvore, 5 * indice + 1, nivel + 1); 
        printarArvore(arvore, 5 * indice + 2, nivel + 1); 
        printarArvore(arvore, 5 * indice + 3, nivel + 1); 
        printarArvore(arvore, 5 * indice + 4, nivel + 1); 
        printarArvore(arvore, 5 * indice + 5, nivel + 1); 
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
    char arvoreBi[TAMMAX];

    // Lendo a palavra do arquivo
    fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("Problema na leitura\n");
        return 0;
    }
    fscanf(fp, "%s", palavra);
    fclose(fp);

    iniArvore(arvoreVet);
    cabecalho();

    q0:
        relatorio(i, "q0", "t0", "-");
        token = palavra[topo];
        push("E");
        putArvore(0);
        goto q1;
    q1:
        i++;
        if(token == '(' && read() == 'E') {relatorio(i, "q1", "t1", "p1"); pop(); push("(EXE)"); putArvore(1); goto q1;}
        else if(token == '0' && read() == 'E') {relatorio(i, "q1", "t2", "p2"); pop(); push("0"); putArvore(2); goto q1;}
        else if(token == '1' && read() == 'E') {relatorio(i, "q1", "t3", "p3"); pop(); push("1"); putArvore(3); goto q1;}
        else if(token == 'a' && read() == 'E') {relatorio(i, "q1", "t4", "p4"); pop(); push("a"); putArvore(4); goto q1;}
        else if(token == 'b' && read() == 'E') {relatorio(i, "q1", "t5", "p5"); pop(); push("b"); putArvore(5); goto q1;}
        else if(token == 'c' && read() == 'E') {relatorio(i, "q1", "t6", "p6"); pop(); push("c"); putArvore(6); goto q1;}
        else if(token == '+' && read() == 'X') {relatorio(i, "q1", "t7", "p7"); pop(); push("+"); putArvore(7); goto q1;}
        else if(token == '-' && read() == 'X') {relatorio(i, "q1", "t8", "p8"); pop(); push("-"); putArvore(8); goto q1;}
        else if(token == '*' && read() == 'X') {relatorio(i, "q1", "t9", "p9"); pop(); push("*"); putArvore(9); goto q1;}
        else if(token == '/' && read() == 'X') {relatorio(i, "q1", "t10", "p10"); pop(); push("/"); putArvore(10); goto q1;}

        else if(token == 'a' && read() == 'a') {relatorio(i, "q1", "t11", "-"); pop(); token = getNext(); goto q1;}
        else if(token == 'b' && read() == 'b') {relatorio(i, "q1", "t12", "-"); pop(); token = getNext(); goto q1;}
        else if(token == 'c' && read() == 'c') {relatorio(i, "q1", "t13", "-"); pop(); token = getNext(); goto q1;}
        else if(token == '0' && read() == '0') {relatorio(i, "q1", "t14", "-"); pop(); token = getNext(); goto q1;}
        else if(token == '1' && read() == '1') {relatorio(i, "q1", "t15", "-"); pop(); token = getNext(); goto q1;}
        else if(token == '(' && read() == '(') {relatorio(i, "q1", "t16", "-"); pop(); token = getNext(); goto q1;}
        else if(token == ')' && read() == ')') {relatorio(i, "q1", "t17", "-"); pop(); token = getNext(); goto q1;}
        else if(token == '+' && read() == '+') {relatorio(i, "q1", "t18", "-"); pop(); token = getNext(); goto q1;}
        else if(token == '-' && read() == '-') {relatorio(i, "q1", "t19", "-"); pop(); token = getNext(); goto q1;}
        else if(token == '*' && read() == '*') {relatorio(i, "q1", "t20", "-"); pop(); token = getNext(); goto q1;}
        else if(token == '/' && read() == '/') {relatorio(i, "q1", "t21", "-"); pop(); token = getNext(); goto q1;}
        else if(token == '\0' && topo == 0) { relatorio(i, "q1", "-", "-"); goto fim;}
        else {erro(1); return 0;}
    fim:
        printf("\n");
        printf("\nPenta:\n");
        printarArvore(arvoreVet, 0, 0);

        penta2Bi(arvoreBi);
        printf("\nBinary:\n");
        printarArvore(arvoreBi, 0, 0);

        PostOrder(arvoreBi, 0);
        polonesaRev[topoPolonesa] = '\0';
        printf("\n\nNotacao Polonesa:\n %s", polonesaRev);

        printf("\n\nP-code:\n");
        Polo2Pcode();

    return 0;
}