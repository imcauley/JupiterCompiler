%{
  #define YYDEBUG 1
%}


%code top{
  #include "heading.h"
  // #include "tokens.h"
  #include "ast.h"


  void yyerror(const char *s);
  int yylex(void);
  extern int yylineno;	// defined and maintained in lex.c
  extern char *yytext;	// defined and maintained in lex.c

  extern AST* final_tree;
  AST *tree;

  char *no_data = "no data";

  // yydebug = 1;
}

%code requires {
  #include "ast.h"
}


%union{
  char *name;
  AST * tree;
}

%define parse.error verbose
%expect 1

%token <name> INT_DEC
%token <name> BOOL_DEC

%token <name> NUMBER
%token <name> STRING
%token <name> BOOL
%token <name> VOID

%token <name> OPEN_PAREN 
%token <name> END_PAREN
%token <name> OPEN_BRACE
%token <name> END_BRACE

%token <name> SEMICOLON
%token <name> COMMA

%token <name> MULT
%token <name> DIV
%token <name> MOD
%token <name> ADD
%token <name> SUB


%token <name> GT
%token <name> LT
%token <name> GTE
%token <name> LTE

%token <name> EQ
%token <name> NEQ

%token <name> NEG
%token <name> NOT

%token <name> AND
%token <name> OR

%token <name> ASSIGNMENT

%token <name> IDENTIFIER

%token <name> IF
%token <name> ELSE
%token <name> WHILE
%token <name> BREAK
%token <name> RETURN

// Tokens used for tree creation
%token NO_TYPE
%token VAR_DEC
%token GLOBAL_DEC
%token FUNC_DEC
%token FUNC_DECL
%token FUNC_HEAD
%token MAIN_FUNC
%token ARG_LIST
%token FUNC_INVOKE
%token BLOCK_STATE
%token PARAM_LIST
%token FORM_PARAM
%token BLOCK
%token ROOT

%type <tree> start;
%type <tree> literal;
%type <tree> type;
%type <tree> identifier;
%type <tree> globaldeclarations;
%type <tree> globaldeclaration;
%type <tree> variabledeclaration;
%type <tree> functiondeclaration;
%type <tree> functionheader;
%type <tree> functiondeclarator;
%type <tree> formalparameterlist;
%type <tree> formalparameter;
%type <tree> mainfunctiondeclaration;
%type <tree> mainfunctiondeclarator;
%type <tree> block;
%type <tree> blockstatements;
%type <tree> blockstatement;
%type <tree> statement;
%type <tree> statementexpression;
%type <tree> primary;
%type <tree> argumentlist;
%type <tree> functioninvocation;
%type <tree> postfixexpression;
%type <tree> unaryexpression;
%type <tree> multiplicativeexpression;
%type <tree> additiveexpression;
%type <tree> relationalexpression;
%type <tree> equalityexpression;
%type <tree> conditionalandexpression;
%type <tree> conditionalorexpression;
%type <tree> assignmentexpression;
%type <tree> assignment;
%type <tree> expression;
%%

start:
   /* empty */
 | globaldeclarations {$$ = make_new_node(ROOT, no_data, 1, $1);
                      final_tree = $$;
                      };
 ;

literal:
   NUMBER {$$ = make_new_node(NUMBER, $1, 0);};
 | STRING {$$ = make_new_node(STRING, $1, 0);};
 | BOOL   {$$ = make_new_node(BOOL, $1, 0);};
 ;

type:
   BOOL_DEC {$$ = make_new_node(BOOL_DEC, $1, 0);};
 | INT_DEC {$$ = make_new_node(INT_DEC, $1, 0);};
 | VOID   {$$ = make_new_node(VOID, $1, 0);};
 ;

globaldeclarations:
   globaldeclaration                                                {$$ = make_new_node(GLOBAL_DEC, no_data, 1, $1);};
 | globaldeclarations globaldeclaration                             {$$ = $1;
                                                                     add_child($$, $2);
                                                                    };
 ;

globaldeclaration:
   variabledeclaration
 | functiondeclaration 
 | mainfunctiondeclaration 
 ;

variabledeclaration:
   type identifier SEMICOLON {$$ = make_new_node(VAR_DEC, no_data, 2, $1, $2);};
 ;

identifier:
   IDENTIFIER {$$ = make_new_node(IDENTIFIER, $1, 0);};
 ;

mainfunctiondeclaration:
   mainfunctiondeclarator block                                       {$$ = make_new_node(MAIN_FUNC, no_data, 2, $1, $2);};
 ;

mainfunctiondeclarator:
   identifier OPEN_PAREN END_PAREN
 ;


functiondeclaration:
   functionheader block {$$ = make_new_node(FUNC_DEC, no_data, 2, $1, $2);};
 ;

functionheader:
   type functiondeclarator  {$$ = make_new_node(FUNC_HEAD, no_data, 2, $1, $2);};
 ;

functiondeclarator:
   identifier OPEN_PAREN formalparameterlist END_PAREN {$$ = make_new_node(FUNC_DECL, no_data, 2, $1, $3);};
 | identifier OPEN_PAREN END_PAREN
 ;

formalparameterlist:
   formalparameter                            {$$ = make_new_node(PARAM_LIST, no_data, 1, $1);};
 | formalparameterlist COMMA formalparameter  {$$ = $1;
                                               add_child($$, $3);
                                              };
 ;

formalparameter:
   type identifier                                                   {$$ = make_new_node(FORM_PARAM, no_data, 2, $1, $2);};
 ;

block:
   OPEN_BRACE blockstatements END_BRACE                              {$$ = make_new_node(BLOCK, no_data, 1, $2);};
 | OPEN_BRACE END_BRACE                                              {$$ = make_new_node(NO_TYPE, no_data, 0);};
 ;

blockstatements:
   blockstatement                                                    {$$ = make_new_node(BLOCK_STATE, no_data, 1, $1);};
 | blockstatements blockstatement                                    {$$ = $1;
                                                                      add_child($$, $2);
                                                                     };
 ;

blockstatement:
   variabledeclaration
 | statement
 ;

statement:
   block
 | SEMICOLON                                                        {$$ = make_new_node(NO_TYPE, no_data, 0);};
 | statementexpression SEMICOLON                                    {$$ = $1;};
 | BREAK SEMICOLON                                                  {$$ = make_new_node(BREAK, $1, 0);};
 | RETURN expression SEMICOLON                                      {$$ = make_new_node(RETURN, $1, 1, $2);};
 | RETURN SEMICOLON                                                 {$$ = make_new_node(RETURN, $1, 0);};
 | IF OPEN_PAREN expression END_PAREN statement                     {$$ = make_new_node(IF, no_data, 2, $3, $5);};
 | IF OPEN_PAREN expression END_PAREN statement ELSE statement      {$$ = make_new_node(ELSE, no_data, 3, $3, $5, $7);};
 | WHILE OPEN_PAREN expression END_PAREN statement                  {$$ = make_new_node(WHILE, no_data, 2, $3, $5);};
 ;

statementexpression:
   assignment
 | functioninvocation
 ;

primary:
   literal
 | OPEN_PAREN expression END_PAREN                                  {$$ = $2;};
 | functioninvocation
 ;

argumentlist:
   expression
 | argumentlist COMMA expression                                    {$$ = make_new_node(ARG_LIST, no_data, 2, $1, $3);};
 ;

functioninvocation:
   identifier OPEN_PAREN argumentlist END_PAREN                     {$$ = make_new_node(FUNC_INVOKE, no_data, 2, $1, $3);};
 | identifier OPEN_PAREN END_PAREN                                  {$$ = make_new_node(FUNC_INVOKE, no_data, 1, $1);};
 ;

postfixexpression:
   primary
 | identifier
 ;

unaryexpression:
   NEG unaryexpression                                              {$$ = make_new_node(NEG, no_data, 1, $2);};
 | NOT unaryexpression                                              {$$ = make_new_node(NOT, no_data, 1, $2);};
 | postfixexpression
 ;

multiplicativeexpression: 
   unaryexpression
 | multiplicativeexpression MULT unaryexpression                    {$$ = make_new_node(MULT, no_data, 2, $1, $3);};
 | multiplicativeexpression DIV unaryexpression                     {$$ = make_new_node(DIV, no_data, 2, $1, $3);};
 | multiplicativeexpression MOD unaryexpression                     {$$ = make_new_node(MOD, no_data, 2, $1, $3);};
 ;

additiveexpression:
   multiplicativeexpression
 | additiveexpression ADD multiplicativeexpression                  {$$ = make_new_node(ADD, no_data, 2, $1, $3);};
 | additiveexpression SUB multiplicativeexpression                  {$$ = make_new_node(SUB, no_data, 2, $1, $3);};
 ;

relationalexpression:
   additiveexpression
 | relationalexpression LT additiveexpression {$$ = make_new_node(LT, no_data, 2, $1, $3);};
 | relationalexpression GT additiveexpression {$$ = make_new_node(GT, no_data, 2, $1, $3);};
 | relationalexpression LTE additiveexpression {$$ = make_new_node(LTE, no_data, 2, $1, $3);};
 | relationalexpression GTE additiveexpression {$$ = make_new_node(GTE, no_data, 2, $1, $3);};
 ;

equalityexpression:
   relationalexpression
 | equalityexpression EQ relationalexpression {$$ = make_new_node(EQ, no_data, 2, $1, $3);};
 | equalityexpression NEQ relationalexpression {$$ = make_new_node(NEQ, no_data, 2, $1, $3);};
 ;

conditionalandexpression: equalityexpression
 | conditionalandexpression AND equalityexpression {$$ = make_new_node(AND, no_data, 2, $1, $3);};
 ;

conditionalorexpression:
   conditionalandexpression
 | conditionalorexpression OR conditionalandexpression {$$ = make_new_node(OR, no_data, 2, $1, $3);};
 ;

assignmentexpression:
   conditionalorexpression
 | assignment
 ;

assignment:
   identifier ASSIGNMENT assignmentexpression {$$ = make_new_node(ASSIGNMENT, no_data, 2, $1, $3);};
 ;

expression:
   assignmentexpression 
 ;
%%

void yyerror(const char *s)
{
  fprintf (stderr, "line no: %i   %s\n", yylineno, s);
  exit(-1);
}