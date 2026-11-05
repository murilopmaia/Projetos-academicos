%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Prex.tab.h"   /* Arquivo gerado pelo Bison contendo definições de tokens e funções */

void sub(char * str);    /* Função para substituir a , por . no float */
%}

/* Definição de tokens */
ID	[a-zA-Z][a-zA-Z0-9]{0,9} 
FLOAT_INVALIDO [+-][0]+,[0]{1,2}
FLOAT_NUM	[+-]?[0-9]+,[0-9]{1,2}
CHAR_LIT	\'[A-Za-z0-9@\_#\+\-\*\/\.\: \\]\' 
COMMENT	\\[^\\]*\\
NEW_LINE	[ \t\n]+
LIST_SIZE	\([1-9]+[0-9]*\)
STRING	\"[A-Za-z0-9@\_#\+\-\*\/\.\:\'\' \\]*\"


%%

"PROGRAMA"	     return PR_PROG; 
"PREX"	         return PR_PREX; 
"CONST"	         return PR_CONST; 
"BOOL"           return PR_BOOL; 
"CHAR"           return PR_CHAR; 
"FLOAT"          return PR_FLOAT; 
"LISTA"	         return PR_LIST; 
"SE"	         return PR_SE; 
"ENTAO"	         return PR_ENTAO; 
"SENAO"	         return PR_SENAO; 
"ENQUANTO"	 return PR_ENQUANTO; 
"FAÇA"	         return PR_FACA; 
"LER"	         return PR_LER; 
"ESCREVER"	 return PR_ESCREVER; 

"{"	         return CHAVE_ESQUERDA; 
"}"	         return CHAVE_DIREITA; 
";"	         return DELIMITADOR; 
","	         return SEPARADOR; 

"+"	         return OPERADOR_SOMA; 
"-"	         return OPERADOR_SUB; 
"*"	         return OPERADOR_MULT; 
"/"	         return OPERADOR_DIV; 

"=="	         return OPERADOR_IGUAL; 
"~="	         return OPERADOR_DIFERENTE; 
">" 	         return OPERADOR_MAIOR; 
"<"	         return OPERADOR_MENOR; 

"^"	         return OPERADOR_LOGICO_E; 
"|"	         return OPERADOR_LOGICO_OU; 
"~"              return OPERADOR_LOGICO_NEGACAO; 

"="	         return OPERADOR_ATRIB; 

"0"              return BOOL_FALSO; 
"1"              return BOOL_VERDADEIRO; 

{ID}             { yylval.sval = strdup(yytext); return IDENTIFICADOR; }  /* Identificador armazenado no yylval como string */

{FLOAT_INVALIDO} { printf("Erro: número de ponto flutuante inválido: %s\n", yytext); exit(1); }
{FLOAT_NUM}        { sub(yytext); yylval.fval = atof(yytext); return NUMERO_DE_PONTO_FLUTUANTE; }  /* Substitui vírgula por ponto e converte para float e armazena no yylval */
{CHAR_LIT}         {  yylval.cval = yytext[1]; return CHAR_LIT; }  /* Armazena o valor do literal de caractere no yylval */
{STRING}           { yylval.sval = strdup(yytext); return CADEIA_DE_CARACTERES;}  /* Armazena a string completa no yylval */


{COMMENT}	    { /* Ignorar comentários */ }
{NEW_LINE}	    { /* Ignorar quebras de linha */ }

{LIST_SIZE}	 { yytext[strlen(yytext) - 1] = '\0'; yylval.ival = atoi(yytext + 1); return LIST_SIZE; }  /* converte uma string que representa um tamanho de lista em um valor inteiro, armazenando-o em yylval */
.	           { printf("Erro: caractere inválido: %s\n", yytext); exit(1); }

%%


void sub(char * str){
    for (int i = 0; str[i] != '\0'; i++) {   /* Itera por cada caractere da string */
        if (str[i] == ',') {   /* Se encontrar uma vírgula */
            str[i] = '.';  /* Substitui a vírgula por ponto */
        }
    }
}
