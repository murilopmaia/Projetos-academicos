%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex();  // Declaração da função lexer gerada pelo Flex
int yyparse();  // Declaração da função parser gerada pelo Bison


void yyerror(const char *s); 
extern FILE *yyin;  // Declaração do arquivo de entrada global gerenciado pelo Flex
FILE *output;
%}

%union{  // Tipo de dado que permite armazenar diferentes tipos de dados no mesmo local de memória
    float fval;
    int ival;
    char* sval;
    char cval;
}

%token  PR_PROG PR_PREX PR_CONST PR_BOOL PR_CHAR PR_FLOAT PR_LIST PR_SE PR_ENTAO PR_SENAO
%token  PR_ENQUANTO PR_FACA PR_LER PR_ESCREVER
%token  CHAVE_ESQUERDA CHAVE_DIREITA DELIMITADOR SEPARADOR
%token  OPERADOR_SOMA OPERADOR_SUB OPERADOR_MULT OPERADOR_DIV
%token  OPERADOR_IGUAL OPERADOR_DIFERENTE OPERADOR_MAIOR OPERADOR_MENOR
%token  OPERADOR_LOGICO_E OPERADOR_LOGICO_OU OPERADOR_LOGICO_NEGACAO
%token  OPERADOR_ATRIB BOOL_FALSO BOOL_VERDADEIRO  
%token <sval> IDENTIFICADOR  CADEIA_DE_CARACTERES  // Tokens associados a strings
%token <fval> NUMERO_DE_PONTO_FLUTUANTE  // Token associado a float
%token <cval> CHAR_LIT  // Token associado a caracteres
%token <ival> LIST_SIZE  // Token associado a inteiros

%type <sval> bloco lista_declaracoes lista_comandos declaracao comando comando_escrita argumentos_escrita
%type <sval> comando_leitura argumentos_leitura comando_expressao expressao  fator lista_variaveis
%type <sval> somatorio sub_acomulada produtorio div_acomulada   // Tipos intermediários usados em expressões

%start programa  // Ponto de entrada do parser

%%

programa:
    PR_PROG PR_PREX CHAVE_ESQUERDA bloco CHAVE_DIREITA
    {
        fprintf(output, "#include <stdio.h>\n#include <stdlib.h>\n\nint main() {\n");
        fprintf(output, "%s", $4);  // Escreve o bloco no arquivo de saída
        fprintf(output, "    return 0;\n}\n");  // Finaliza a função main
    }
;

bloco:
    lista_declaracoes lista_comandos
    {
        $$ = malloc(strlen($1) + strlen($2) + 1); 
        sprintf($$, "%s%s", $1, $2);  // Concatena declarações e comandos
        free($1);
        free($2);
    }
;

lista_declaracoes:
    /* Vazio */
    { $$ = strdup(""); }  // Caso não haja declarações, retorna string vazia
    | lista_declaracoes declaracao
    {
        $$ = malloc(strlen($1) + strlen($2) + 1);
        sprintf($$, "%s%s", $1, $2);  // Concatena declarações
        free($1);
        free($2);
    }
;

declaracao:
    PR_FLOAT lista_variaveis DELIMITADOR
    {
        $$ = malloc(strlen($2) + 10);
        sprintf($$, "    float %s;\n", $2);  // Gera código para variáveis do tipo float
        free($2);
    }
;

lista_variaveis:
    lista_variaveis SEPARADOR IDENTIFICADOR
    {
        $$ = malloc(strlen($1) + strlen($3) + 10);  
        sprintf($$, "%s, %s", $1, $3);  // Concatena variáveis separadas por vírgula
        free($1);
        free($3);
    }
    | IDENTIFICADOR 
    {
        $$ = strdup($1);
        free($1);
    }

lista_comandos:
    /* Vazio */
    { $$ = strdup(""); }  // String vazia quando não há comandos 
    | lista_comandos comando
    {
        $$ = malloc(strlen($1) + strlen($2) + 1);
        sprintf($$, "%s%s", $1, $2);  // Concatena comandos
        free($1);
        free($2);
    }
;

comando:
    comando_escrita
    | comando_leitura
    | comando_expressao
;

comando_escrita:
    PR_ESCREVER argumentos_escrita DELIMITADOR
    {
        $$ = strdup($2);  // Armazena os argumentos da escrita
        free($2);
    }
;

argumentos_escrita:
    argumentos_escrita SEPARADOR IDENTIFICADOR
    {
        $$ = malloc(strlen($1) + strlen($3) + 30);
        sprintf($$, "%s    printf(\"%%f\", %s);\n", $1, $3);  
        free($1);
        free($3);
    }
    | argumentos_escrita SEPARADOR CADEIA_DE_CARACTERES
    {
        $$ = malloc(strlen($1) + strlen($3) + 30);
        sprintf($$, "%s    printf(%s);\n", $1, $3);
        free($1);
        free($3);
    }
    | IDENTIFICADOR
    {
        $$ = malloc(strlen($1) + 30);
        sprintf($$, "    printf(\"%%f\", %s);\n", $1);  
        free($1);
    }
    | CADEIA_DE_CARACTERES
    {
        $$ = malloc(strlen($1) + 20);
        sprintf($$, "    printf(%s);\n", $1); 
        free($1);
    }

;

comando_leitura:
    PR_LER argumentos_leitura DELIMITADOR
    {
        $$ = strdup($2);  // Copia os argumentos de leitura 
        free($2);
    }
;

argumentos_leitura:
    argumentos_leitura SEPARADOR IDENTIFICADOR
    {
        $$ = malloc(strlen($1) + strlen($3) + 30);
        sprintf($$, "%s    scanf(\"%%f\", &%s);\n", $1, $3); // Gera um comando `scanf` para leitura de um ou mais identificador separado por ,
        free($1);
        free($3);
    }
    | IDENTIFICADOR
    {
        $$ = malloc(strlen($1) + 30);
        sprintf($$, "    scanf(\"%%f\", &%s);\n", $1);
        free($1);
    }
;


comando_expressao:
    IDENTIFICADOR OPERADOR_ATRIB expressao DELIMITADOR
    {
        $$ = malloc(strlen($1) + strlen($3) + 10);
        sprintf($$, "    %s = %s;\n", $1, $3);  // Cria um comando de atribuição no formato `identificador = expressão`
        free($1);
        free($3);
        
    }
;


expressao:
    fator {
        $$ = strdup($1);
        free($1);

    }
    | OPERADOR_SOMA fator somatorio {
        $$ = malloc(strlen($2) + strlen($3) + 8);
        sprintf($$, "(%s + %s)", $2, $3);  // Cria expressão no formato `(termo1 + termo2)`
        free($3);
        free($2);
    }
    | OPERADOR_SUB fator sub_acomulada {
        $$ = malloc(strlen($2) + strlen($3) + 8);
        sprintf($$, "(%s - %s)", $2, $3);  // Cria expressão no formato `(termo1 - termo2)`
        free($3);
        free($2);

    }
    | OPERADOR_MULT fator produtorio {
        $$ = malloc(strlen($2) + strlen($3) + 8);
        sprintf($$, "(%s * %s)", $2, $3);  // Cria expressão no formato `(termo1 * termo2)`
        free($3);
        free($2);
    }
    | OPERADOR_DIV fator div_acomulada {
        $$ = malloc(strlen($2) + strlen($3) + 8);
        sprintf($$, "(%s / %s)", $2, $3);  // Cria expressão no formato `(termo1 / termo2)`
        free($3);
        free($2);
    }
;

somatorio:
    fator somatorio{
        $$ = malloc(strlen($1) + strlen($2) + 8);
        sprintf($$, "%s + %s", $1, $2);
        free($1);
        free($2);
    }
    | expressao {
        $$ = strdup($1);
        free($1);
    }
;
sub_acomulada:
    fator sub_acomulada{
        $$ = malloc(strlen($1) + strlen($2) + 8);
        sprintf($$, "%s - %s", $1, $2);
        free($1);
        free($2);
    }
    | expressao {
        $$ = strdup($1);
        free($1);
    }
;
produtorio:
    fator produtorio{
        $$ = malloc(strlen($1) + strlen($2) + 8);
        sprintf($$, "%s * %s", $1, $2);
        free($1);
        free($2);
    }
    | expressao {
        $$ = strdup($1);
        free($1);
    }
;
div_acomulada:
    fator div_acomulada{
        $$ = malloc(strlen($1) + strlen($2) + 8);
        sprintf($$, "%s / %s", $1, $2);
        free($1);
        free($2);
    }
    | expressao {
        $$ = strdup($1);
        free($1);
    }
;
fator:
    NUMERO_DE_PONTO_FLUTUANTE
    {
        $$ = malloc(50);
        sprintf($$, "%.2f", $1);
    }
    | IDENTIFICADOR
    {
        $$ = strdup($1);
        free($1);
    }
;
%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro: %s\n", s);  // Exibe o erro recebido como argumento
    exit(1);
}

int main(int argc, char **argv) {
    
    FILE *input = fopen("input.txt", "r");
    if (!input) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    yyin = input;
    output = fopen("output.c", "w");
    if (!output) {
        perror("Erro ao criar o arquivo de saída");
        exit(1);
    }

    yyparse();

    fclose(input);
    fclose(output);
    return 0;
}

