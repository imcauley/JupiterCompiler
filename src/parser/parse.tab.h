/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_PARSER_PARSE_TAB_H_INCLUDED
# define YY_YY_PARSER_PARSE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 17 "./parser/parse.y" /* yacc.c:1910  */

  #include "ast.h"

#line 48 "./parser/parse.tab.h" /* yacc.c:1910  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TYPE_DEF_TOK = 0,
    OPEN_PAREN_TOK = 1,
    END_PAREN_TOK = 2,
    OPEN_BRACE_TOK = 3,
    END_BRACE_TOK = 4,
    SEMICOLON_TOK = 5,
    COMMA_TOK = 6,
    INT_EQ_OP_TOK = 7,
    INT_ADD_OP_TOK = 8,
    INT_MULT_OP_TOK = 9,
    BOOL_OP_ADD_TOK = 10,
    BOOL_OP_OR_TOK = 11,
    BOOL_OP_UN_TOK = 12,
    EQUALITY_TOK = 13,
    ASSIGNMENT_TOK = 14,
    IDENTIFIER_TOK = 15,
    BOOL_LIT_TOK = 16,
    STR_LIT_TOK = 17,
    INT_LIT_TOK = 18,
    IF_TOK = 19,
    ELSE_TOK = 20,
    WHILE_TOK = 21,
    BREAK_TOK = 22,
    RETURN_TOK = 23
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 21 "./parser/parse.y" /* yacc.c:1910  */

  int value;
  char name[64];
  AST * tree;

#line 93 "./parser/parse.tab.h" /* yacc.c:1910  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_PARSE_TAB_H_INCLUDED  */
