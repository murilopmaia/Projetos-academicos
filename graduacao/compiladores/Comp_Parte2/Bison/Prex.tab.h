/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PREX_TAB_H_INCLUDED
# define YY_YY_PREX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PR_PROG = 258,                 /* PR_PROG  */
    PR_PREX = 259,                 /* PR_PREX  */
    PR_CONST = 260,                /* PR_CONST  */
    PR_BOOL = 261,                 /* PR_BOOL  */
    PR_CHAR = 262,                 /* PR_CHAR  */
    PR_FLOAT = 263,                /* PR_FLOAT  */
    PR_LIST = 264,                 /* PR_LIST  */
    PR_SE = 265,                   /* PR_SE  */
    PR_ENTAO = 266,                /* PR_ENTAO  */
    PR_SENAO = 267,                /* PR_SENAO  */
    PR_ENQUANTO = 268,             /* PR_ENQUANTO  */
    PR_FACA = 269,                 /* PR_FACA  */
    PR_LER = 270,                  /* PR_LER  */
    PR_ESCREVER = 271,             /* PR_ESCREVER  */
    CHAVE_ESQUERDA = 272,          /* CHAVE_ESQUERDA  */
    CHAVE_DIREITA = 273,           /* CHAVE_DIREITA  */
    DELIMITADOR = 274,             /* DELIMITADOR  */
    SEPARADOR = 275,               /* SEPARADOR  */
    OPERADOR_SOMA = 276,           /* OPERADOR_SOMA  */
    OPERADOR_SUB = 277,            /* OPERADOR_SUB  */
    OPERADOR_MULT = 278,           /* OPERADOR_MULT  */
    OPERADOR_DIV = 279,            /* OPERADOR_DIV  */
    OPERADOR_IGUAL = 280,          /* OPERADOR_IGUAL  */
    OPERADOR_DIFERENTE = 281,      /* OPERADOR_DIFERENTE  */
    OPERADOR_MAIOR = 282,          /* OPERADOR_MAIOR  */
    OPERADOR_MENOR = 283,          /* OPERADOR_MENOR  */
    OPERADOR_LOGICO_E = 284,       /* OPERADOR_LOGICO_E  */
    OPERADOR_LOGICO_OU = 285,      /* OPERADOR_LOGICO_OU  */
    OPERADOR_LOGICO_NEGACAO = 286, /* OPERADOR_LOGICO_NEGACAO  */
    OPERADOR_ATRIB = 287,          /* OPERADOR_ATRIB  */
    BOOL_FALSO = 288,              /* BOOL_FALSO  */
    BOOL_VERDADEIRO = 289,         /* BOOL_VERDADEIRO  */
    IDENTIFICADOR = 290,           /* IDENTIFICADOR  */
    CADEIA_DE_CARACTERES = 291,    /* CADEIA_DE_CARACTERES  */
    NUMERO_DE_PONTO_FLUTUANTE = 292, /* NUMERO_DE_PONTO_FLUTUANTE  */
    CHAR_LIT = 293,                /* CHAR_LIT  */
    LIST_SIZE = 294                /* LIST_SIZE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "Prex.y"
  // Tipo de dado que permite armazenar diferentes tipos de dados no mesmo local de memória
    float fval;
    int ival;
    char* sval;
    char cval;

#line 110 "Prex.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PREX_TAB_H_INCLUDED  */
