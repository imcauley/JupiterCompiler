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
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 25 "./parser/parse.y" /* yacc.c:1910  */

  #include "ast.h"

#line 48 "./parser/parse.tab.h" /* yacc.c:1910  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT_DEC = 258,
    BOOL_DEC = 259,
    NUMBER = 260,
    STRING = 261,
    BOOL = 262,
    VOID = 263,
    OPEN_PAREN = 264,
    END_PAREN = 265,
    OPEN_BRACE = 266,
    END_BRACE = 267,
    SEMICOLON = 268,
    COMMA = 269,
    MULT = 270,
    DIV = 271,
    MOD = 272,
    ADD = 273,
    SUB = 274,
    GT = 275,
    LT = 276,
    GTE = 277,
    LTE = 278,
    EQ = 279,
    NEQ = 280,
    NEG = 281,
    NOT = 282,
    AND = 283,
    OR = 284,
    ASSIGNMENT = 285,
    IDENTIFIER = 286,
    IF = 287,
    ELSE = 288,
    WHILE = 289,
    BREAK = 290,
    RETURN = 291,
    NO_TYPE = 292,
    VAR_DEC = 293,
    GLOBAL_DEC = 294,
    FUNC_DEC = 295,
    FUNC_DECL = 296,
    FUNC_HEAD = 297,
    MAIN_FUNC = 298,
    ARG_LIST = 299,
    FUNC_INVOKE = 300,
    BLOCK_STATE = 301,
    PARAM_LIST = 302,
    FORM_PARAM = 303,
    BLOCK = 304,
    ROOT = 305,
    EXPRESSION = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 30 "./parser/parse.y" /* yacc.c:1910  */

  char *name;
  AST * tree;

#line 117 "./parser/parse.tab.h" /* yacc.c:1910  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_PARSE_TAB_H_INCLUDED  */
