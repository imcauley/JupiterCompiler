/* Mini Calculator */
/* calc.y */

%code top{
  #include "heading.h"
  #include "tokens.h"
  #include "ast.h"


  int yyerror(char *s);
  int yylex(void);
  extern int yylineno;	// defined and maintained in lex.c
  extern char *yytext;	// defined and maintained in lex.c
  AST *tree;
}

%code requires {
  #include "ast.h"
}

%union{
  int value;
  char name[64];
  AST * tree;
}

%token TYPE_DEF_TOK 0

%token OPEN_PAREN_TOK 1 
%token END_PAREN_TOK 2
%token OPEN_BRACE_TOK 3
%token END_BRACE_TOK 4

%token SEMICOLON_TOK 5
%token COMMA_TOK 6

%token INT_EQ_OP_TOK 7
%token INT_ADD_OP_TOK 8
%token INT_MULT_OP_TOK 9
%token BOOL_OP_ADD_TOK 10
%token BOOL_OP_OR_TOK 11
%token BOOL_OP_UN_TOK 12
%token EQUALITY_TOK 13
%token ASSIGNMENT_TOK 14

%token IDENTIFIER_TOK 15

%token BOOL_LIT_TOK 16
%token STR_LIT_TOK 17
%token INT_LIT_TOK 18

%token IF_TOK 19
%token ELSE_TOK 20
%token WHILE_TOK 21
%token BREAK_TOK 22
%token RETURN_TOK 23


%type <name> identifier;
%%

start           : /* empty */
                | globaldeclarations {$<tree>$ = make_new_node("start");}; 
                ;

literal         : BOOL_LIT_TOK
                | STR_LIT_TOK
                | INT_LIT_TOK
                ;

type            : TYPE_DEF_TOK
                ;

identifier              : IDENTIFIER_TOK {$<tree>$ = make_new_node(yytext);}; 
                        ;

globaldeclarations      : globaldeclaration
                        | globaldeclarations globaldeclaration
                        ;

globaldeclaration       : variabledeclaration
                        | functiondeclaration
                        | mainfunctiondeclaration
                        ;

variabledeclaration     : type identifier SEMICOLON_TOK
                        ;

functiondeclaration     : functionheader block
                        ;

functionheader          : type functiondeclarator
                        ;

functiondeclarator      : identifier OPEN_PAREN_TOK formalparameterlist END_PAREN_TOK
                        | identifier OPEN_PAREN_TOK END_PAREN_TOK
                        ;

formalparameterlist     : formalparameter
                        | formalparameterlist COMMA_TOK formalparameter
                        ;

formalparameter         : type identifier
                        ;

mainfunctiondeclaration : mainfunctiondeclarator block
                        ;

mainfunctiondeclarator  : identifier OPEN_PAREN_TOK END_PAREN_TOK
                        ;

block                   : OPEN_BRACE_TOK blockstatements END_BRACE_TOK
                        | OPEN_BRACE_TOK END_BRACE_TOK
                        ;

blockstatements         : blockstatement
                        | blockstatements blockstatement
                        ;

blockstatement          : variabledeclaration
                        | statement
                        ;

statement               : block
                        | SEMICOLON_TOK
                        | statementexpression SEMICOLON_TOK
                        | BREAK_TOK SEMICOLON_TOK
                        | RETURN_TOK expression SEMICOLON_TOK
                        | RETURN_TOK SEMICOLON_TOK
                        | IF_TOK OPEN_PAREN_TOK expression END_PAREN_TOK statement
                        | IF_TOK OPEN_PAREN_TOK expression END_PAREN_TOK statement ELSE_TOK statement
                        | WHILE_TOK OPEN_PAREN_TOK expression END_PAREN_TOK statement
                        ;

statementexpression     : assignment
                        | functioninvocation
                        ;

primary                 : literal
                        | OPEN_PAREN_TOK expression END_PAREN_TOK
                        | functioninvocation
                        ;

argumentlist            : expression
                        | argumentlist COMMA_TOK expression
                        ;

functioninvocation      : identifier OPEN_PAREN_TOK argumentlist END_PAREN_TOK
                        | identifier OPEN_PAREN_TOK END_PAREN_TOK
                        ;

postfixexpression       : primary
                        | identifier
                        ;

unaryexpression         : '-' unaryexpression
                        | '!' unaryexpression
                        | postfixexpression
                        ;

multiplicativeexpression: unaryexpression
                        | multiplicativeexpression INT_MULT_OP_TOK unaryexpression
                        ;

additiveexpression      : multiplicativeexpression
                        | additiveexpression INT_ADD_OP_TOK multiplicativeexpression
                        ;

relationalexpression    : additiveexpression
                        | relationalexpression INT_EQ_OP_TOK additiveexpression
                        ;

equalityexpression      : relationalexpression
                        | equalityexpression EQUALITY_TOK relationalexpression
                        ;

conditionalandexpression: equalityexpression
                        | conditionalandexpression BOOL_OP_ADD_TOK equalityexpression
                        ;

conditionalorexpression : conditionalandexpression
                        | conditionalorexpression BOOL_OP_OR_TOK conditionalandexpression
                        ;

assignmentexpression    : conditionalorexpression
                        | assignment
                        ;

assignment              : identifier ASSIGNMENT_TOK assignmentexpression
                        ;

expression              : assignmentexpression
                        ;
%%

int yyerror(string s)
{

  
  cerr << "ERROR: " << s << " at symbol \"" << yytext;
  cerr << "\" on line " << IDENTIFIER << endl;
  exit(1);
}

int yyerror(char *s)
{
  return yyerror(string(s));
}