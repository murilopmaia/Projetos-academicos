%{
#include <stdio.h>
#include <stdlib.h>

FILE *fp2;

%}

/*** Definição de tokens ***/
ID	            [a-zA-Z][a-zA-Z0-9]{0,9} 
FLOAT_INVALIDO  [+-][0]+,[0]{1,2}
FLOAT_NUM	    [+-]?[0-9]+,[0-9]{1,2}
CHAR_LIT	    \'[A-Za-z0-9@\_#\+\-\*\/\.\: \\]\' 
COMMENT	        \\[^\\]*\\
NEW_LINE	    [ \t\n]+
LIST_SIZE	    \([1-9]+[0-9]*\)
STRING	        \"[A-Za-z0-9@\_#\+\-\*\/\.\:\'\' \\]*\"


%%

"PROGRAMA"		{ fprintf(fp2, "PR_PROG: %s\n", yytext);}
"PREX"	        { fprintf(fp2, "PR_PREX: %s\n", yytext);}
"CONST"	        { fprintf(fp2, "PR_CONST: %s\n", yytext);}
"BOOL"          { fprintf(fp2, "PR_BOOL: %s\n", yytext);}
"CHAR"          { fprintf(fp2, "PR_CHAR: %s\n", yytext);}
"FLOAT"         { fprintf(fp2, "PR_FLOAT: %s\n", yytext);}
"LISTA"	        { fprintf(fp2, "PR_LIST: %s\n", yytext);}
"SE"	        { fprintf(fp2, "PR_SE: %s\n", yytext);}
"ENTAO"	        { fprintf(fp2, "PR_ENTAO: %s\n", yytext);}
"SENAO"	        { fprintf(fp2, "PR_SENAO: %s\n", yytext);}
"ENQUANTO"	    { fprintf(fp2, "PR_ENQUANTO: %s\n", yytext);}
"FAÇA"	        { fprintf(fp2, "PR_FAÇA: %s\n", yytext);}
"LER"	        { fprintf(fp2, "PR_LER: %s\n", yytext);}
"ESCREVER"	    { fprintf(fp2, "PR_ESCREVER: %s\n", yytext);}



"{"	            { fprintf(fp2, "CHAVE ESQUERDA: %s\n", yytext);}
"}"	            { fprintf(fp2, "CHAVE DIREITA: %s\n", yytext);}
";"	            { fprintf(fp2, "DELIMITADOR: %s\n", yytext);}
","	            { fprintf(fp2, "SEPARADOR: %s\n", yytext);}


"+"	            { fprintf(fp2, "OPERADOR DE SOMA: %s\n", yytext);}
"-"	            { fprintf(fp2, "OPERADOR DE SUBTRACAO: %s\n", yytext);}
"*"	            { fprintf(fp2, "OPERADOR DE MULTIPLICACAO: %s\n", yytext);}
"/"	            { fprintf(fp2, "OPERADOR DE DIVISAO: %s\n", yytext);}



"=="	        { fprintf(fp2, "OPERADOR RELACIONAL IGUAL A: %s\n", yytext);}
"~="	        { fprintf(fp2, "OPERADOR RELACIONAL DIFERENTE DE: %s\n", yytext);}
">" 	        { fprintf(fp2, "OPERADOR RELACIONAL MAIOR QUE: %s\n", yytext);}
"<"	            { fprintf(fp2, "OPERADOR RELACIONAL MENOR QUE: %s\n", yytext);}


"^"	            { fprintf(fp2, "OPERADOR LOGICO E: %s\n", yytext);}
"|"	            { fprintf(fp2, "OPERADOR LOGICO OU: %s\n", yytext);}
"~"             { fprintf(fp2, "OPERADOR LOGICO NEGACAO: %s\n", yytext);}

"="	            { fprintf(fp2, "OPERADOR DE ATRIBUICAO: %s\n", yytext);}


"0"             { fprintf(fp2, "BOOl FALSO: %s\n", yytext);}
"1"             { fprintf(fp2, "BOOl VERDADEIRO: %s\n", yytext);}


{ID}            { fprintf(fp2, "IDENTIFICADOR: %s\n", yytext);}


{FLOAT_INVALIDO} { fprintf(fp2, "NUMERO DE PONTO FLUTUANTE INVALIDO: %s\n", yytext); exit(1);}
{FLOAT_NUM}	    { fprintf(fp2, "NUMERO DE PONTO FLUTUANTE: %s\n", yytext);}


{CHAR_LIT}	    { fprintf(fp2, "CARACTERE LITERAL: %s\n", yytext);}


{STRING}	    {fprintf(fp2, "CADEIA DE CARACTERES: %s\n", yytext);}


{COMMENT}	    {}
{NEW_LINE}	    {}


{LIST_SIZE}	    { fprintf(fp2, "TAMANHO DA LISTA: %s\n", yytext);}


.	            { fprintf(fp2, "CARACTERE INVALIDO: %s\n", yytext); exit(1); }

%%

int yywrap(){}
int main(){

    FILE *fp;
    fp = fopen("input.txt","r");

    fp2 = fopen("output.txt","w");
    yyin = fp;

    yylex();

    fclose(fp);
    fclose(fp2);
    return 0;
}
