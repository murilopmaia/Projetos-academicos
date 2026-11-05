#include <stdio.h> 
#include <ctype.h> 
#include <string.h>

/* Declarações globais */ 
#define TAMMAX 9999
/* Variáveis */
char labelProd[TAMMAX][TAMMAX][5]; // Lista de produção
int tpLabel[TAMMAX]; // Topo de labelProd
int arvore[TAMMAX][TAMMAX]; // Arvore Ternaria
int tpMat = 0;
int aceitacao = 1;

int charClass; 
char lexeme [100]; 
char nextChar; 
int lexLen; 
int token; 
int nextToken; 
FILE *in_fp; 
/* Declarações de Funções */ 
void addChar(); 
void getChar(); 
void getNonBlank(); 
int lex();

void ini(int topo); // Inicializar todos os elementos de arvore com 0
char* traduz(int codigo); // Para melhoras a visualização da árvore
void printarArvore(int *arvore, int indice, int nivel); // Printa a árvore
void factor(int nvl);
void term(int nvl);
void expr(int nvl);
void error(int tipo);
/* Classes de caracteres */ 
#define LETTER 0 
#define DIGIT 1 
#define UNKNOWN 99 
/* Códigos de tokens */ 
#define INT_LIT 10 
#define IDENT 11 
#define ASSIGN_OP 20 
#define ADD_OP 21 
#define SUB_OP 22 
#define MULT_OP 23 
#define DIV_OP 24 
#define LEFT_PAREN 25 
#define RIGHT_PAREN 26 

#define TERM 100
#define EXPR 101
#define FACTOR 102


/******************************************************/ 
/* função principal */ 
int main() { 
/* Abrir o arquivo de dados de entrada e processar seu 
conteúdo */ 
    if ((in_fp = fopen("front.in", "r")) == NULL) 
        printf("ERROR - cannot open front.in \n"); 
    else {
        
        getChar();
        do{
            lex();
            ini(tpMat); // Inicializando com 0 a arvore atual
            aceitacao = 1;// Redefinindo aceitacao
            arvore[tpMat][0] = EXPR; // start da arvore
            tpLabel[tpMat] = 0; // start do topo da label
            expr(0);
            printf("Arvore de analise:\n");
            printarArvore(arvore[tpMat], 0, 0);

            printf("\n\nLista de producoes: \n");
            for(int i = 0; i < tpLabel[tpMat]; i++){
                printf(" %s ", labelProd[tpMat][i]);
            }

            if(aceitacao == 1){
                printf("\n\n----------------Expressao aceita----------------\n\n");
            }
            else{
                printf("\n\n----------------Erro----------------\n\n");
            }
            tpMat++;
        }
        while(nextToken != EOF);
    }
    
    return 0;
}

void ini(int topo){
    for(int i = 0; i < TAMMAX; i++){
        arvore[topo][i] = 0;
    }
}

void printarArvore(int *arvore, int indice, int nivel) {
    if (indice < TAMMAX && arvore[indice] != 0) {
        for (int i = 0; i < nivel; i++) {
            printf("   ");
        }

        printf("|-- %s\n", traduz(arvore[indice]));

        printarArvore(arvore,3 * indice + 1, nivel + 1); 
        printarArvore(arvore, 3 * indice + 2, nivel + 1); 
        printarArvore(arvore, 3 * indice + 3, nivel + 1); 
    }
}

char* traduz(int codigo) {
    switch (codigo) {
        case INT_LIT:
            return "int_constant";
        case IDENT:
            return "id";
        case ASSIGN_OP:
            return "ASSIGN_OP";
        case ADD_OP:
            return "+";
        case SUB_OP:
            return "=";
        case MULT_OP:
            return "*";
        case DIV_OP:
            return "/";
        case LEFT_PAREN:
            return "(";
        case RIGHT_PAREN:
            return ")";
        case TERM:
            return "TERM";
        case EXPR:
            return "EXPR";
        case FACTOR:
            return "FACTOR";
        default:
            return "UNKNOWN";
    }
}


/******************************************************/ 
/* lookup - uma função para processar operadores e parênteses 
 e retornar o token */ 
int lookup(char ch) { 
 switch (ch) { 
    case '(': 
        addChar(); 
        nextToken = LEFT_PAREN; 
    break; 
        case ')': 
        addChar(); 
        nextToken = RIGHT_PAREN; 
    break; 
    case '+': 
        addChar(); 
        nextToken = ADD_OP; 
        break; 
    case '-': 
        addChar(); 
        nextToken = SUB_OP; 
        break; 
    case '*': 
        addChar(); 
        nextToken = MULT_OP; 
        break; 
    case '/': 
        addChar(); 
        nextToken = DIV_OP; 
        break;
    case ';':
        addChar();
        nextToken = -2;
        break;
    default: 
        addChar(); 
        nextToken = EOF; 
        break; 
 } 
 
 return nextToken; 
} 
/*****************************************************/ 
/* addChar - uma função para adicionar nextChar ao 
vetor lexeme */ 
void addChar() { 
 if (lexLen <= 98) { 
    lexeme[lexLen++] = nextChar; 
    lexeme[lexLen] = 0; 
 } 
 else 
 printf("Error - lexeme is too long \n"); 
} 
/*******************************************************/ 
/* getChar - uma função para obter o próximo caractere da entrada e determinar sua classe de caracteres */ 
void getChar() { 
 if ((nextChar = getc(in_fp)) != EOF) { 
    if (isalpha(nextChar)) 
        charClass = LETTER; 
    else if (isdigit(nextChar)) 
        charClass = DIGIT; 
    else charClass = UNKNOWN; 
 } 
 else 
    charClass = EOF; 
} 
/*******************************************************/ 
/* getNonBlank - uma função para chamar getChar até que ela 
retorne um caractere diferente de espaço em 
branco */ 
void getNonBlank() { 
 while (isspace(nextChar)) {
   
     getChar(); 
 }
 
} 

/* lex - um analisador léxico simples para expressões 
aritméticas */ 
int lex() { 
 lexLen = 0; 
 getNonBlank(); 
 switch (charClass) { 
/* Reconhecer identificadores */ 
    case LETTER: 
        addChar(); 
        getChar(); 
        while (charClass == LETTER || charClass == DIGIT) { 
            addChar(); 
            getChar(); 
        } 
        nextToken = IDENT; 
    break; 
    /* Reconhecer literais inteiros */ 
    case DIGIT: 
        addChar(); 
        getChar(); 
        while (charClass == DIGIT) { 
            addChar(); 
            getChar(); 
        } 
        nextToken = INT_LIT; 
        break; 
    /* Parênteses e operadores */ 
    case UNKNOWN: 
        lookup(nextChar); 
        getChar(); 
        break;
    /* Fim do arquivo */ 
    case EOF: 
        nextToken = EOF; 
        lexeme[0] = 'E'; 
        lexeme[1] = 'O'; 
        lexeme[2] = 'F'; 
        lexeme[3] = 0; 
    break; 
 } /* Fim do switch */ 
    printf("Next token is: %d, Next lexeme is %s\n", 
 nextToken, lexeme); 
 return nextToken; 
} /* Fim da função lex */ 

/* expr 
 Analisa sintaticamente cadeias na linguagem gerada pela 
regra: 
 <expr> -> <term> {(+ | -) <term>} 
 */ 
void expr(int nvl) { 
    int ind = tpLabel[tpMat]; // Para armazenar o indice
    strcpy(labelProd[tpMat][ind], "p1");
    tpLabel[tpMat]++;
    /* Analisa sintaticamente o primeiro termo */
    arvore[tpMat][3*nvl + 1] = TERM;
    term(3*nvl + 1); 
    /* Desde que o próximo token seja + ou -, obtenha o próximo
    token e analise sintaticamente o próximo termo */ 
    while (nextToken == ADD_OP || nextToken == SUB_OP) { 
        if(nextToken == ADD_OP){
            arvore[tpMat][3*nvl + 2] = ADD_OP;
            strcpy(labelProd[tpMat][ind], "p2");
        }
        else{
            arvore[tpMat][3*nvl + 2] = SUB_OP;
            strcpy(labelProd[tpMat][ind], "p3");
        }
        lex();
        arvore[tpMat][3*nvl + 3] = TERM;
        term(3*nvl + 3); 
    } 
} /* Fim da função expr */ 

/* term 
 Analisa sintaticamente cadeias na linguagem gerada pela 
regra: 
 <term> -> <factor> {(* | /) <factor>) 
 */ 
void term(int nvl) { 
    int ind = tpLabel[tpMat];
    strcpy(labelProd[tpMat][ind], "p4");
    tpLabel[tpMat]++;
    /* Analisa sintaticamente o primeiro termo */
    arvore[tpMat][3*nvl + 1] = FACTOR;
    factor(3*nvl + 1); 
    /* Desde que o próximo token seja + ou -, obtenha o próximo 
    token e analise sintaticamente o próximo termo */ 
    while (nextToken == MULT_OP || nextToken == DIV_OP) { 
        if(nextToken == MULT_OP){
            arvore[tpMat][3*nvl + 2] = MULT_OP;
            strcpy(labelProd[tpMat][ind], "p5");
        }
        else{
            arvore[tpMat][3*nvl + 2] = DIV_OP;
            strcpy(labelProd[tpMat][ind], "p6");
        }
        lex(); 
        arvore[tpMat][3*nvl + 3] = FACTOR;
        factor(3*nvl + 3); 
    } 

} /* Fim da função term */

/* factor 
 Analisa sintaticamente cadeias na linguagem gerada pela 
regra: 
 <factor> -> id | int_constant | (<expr) 
 */ 
void factor(int nvl) {
    
    /* Determina qual RHS */ 
    if (nextToken == IDENT || nextToken == INT_LIT){
    /* Obtém o próximo token */
        if(nextToken == IDENT){
            arvore[tpMat][3 * nvl + 1] = IDENT;
            strcpy(labelProd[tpMat][tpLabel[tpMat]], "p7");
            tpLabel[tpMat]++;
        }
        else{
            arvore[tpMat][3 * nvl + 1] = INT_LIT;
            strcpy(labelProd[tpMat][tpLabel[tpMat]], "p8");
            tpLabel[tpMat]++;
        }
        lex();
    }
    /* Se a RHS é (<expr>), chame lex para passar o parêntese 
    esquerdo, chame expr e verifique pelo parêntese 
    direito */ 
    else { 
        if (nextToken == LEFT_PAREN) { 
            lex();
            strcpy(labelProd[tpMat][tpLabel[tpMat]], "p9");
            tpLabel[tpMat]++; 
            arvore[tpMat][3 * nvl + 1] = LEFT_PAREN;
            arvore[tpMat][3 * nvl + 2] = EXPR;
            expr(3*nvl + 2); 
            if (nextToken == RIGHT_PAREN){
                arvore[tpMat][3 * nvl + 3] = RIGHT_PAREN;
                lex();
            }
            else 
                error(1); 
        } /* Fim do if (nextToken == ... */ 
        /* Não era um identificador, um literal inteiro ou um 
        parêntese esquerdo */ 
        else 
            error(2); 
    } /* Fim do else */  
} /* Fim da função factor */

void error(int tipo){
    aceitacao = 0;
    switch (tipo)
    {
    case 1:
        printf("error: expected ')'\n\n");
        break;
    case 2:
        printf("error: expected expression\n\n");
        break;
    default:
        printf("Erro desconhecido");
        break;
    }
}
