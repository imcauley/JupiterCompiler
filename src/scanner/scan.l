/* 
* 411 Project - Milestone 1
* Isaac McAuley
* 30062453
*/

%{
    #include "tokens.h"
    #include "parse.h"
    int mylineno = 0;
    int whitespace = 0;
    int all_characters = 0;
%}

%option yylineno
%option noyywrap

string  \"[^\n"]+\"

ws      [ \t\r\n]+

alpha   [A-Za-z]
dig     [0-9]


identifier ({alpha}|_|\-)({alpha}|{dig}|_|\-)*

int_mult_op (\*|\/|%)
int_add_op (\+|\-)
int_eq_op (<|>|<=|>=)

bool_op_un (!)
bool_op_bin (&&|\|\|)
equality (==|!=)
assignment (=)
type    (int|boolean|void)

bool_literal (true|false)
int_literal {dig}+
str_literal \"(.|\0|\\0|\\b|\\n|\\|\\f|\\t|\\r|\\\"|\')+\"


%%
{type}              {return TYPE_DEF;};

"if"                {return IF;};
"else"              {return ELSE;};
"while"             {return WHILE;};
"break"             {return BREAK;};
"return"            {return RETURN;};

{bool_literal}      {return BOOL_LIT;};
{int_literal}       {printf("test int lit"); return INT_LIT;};
{str_literal}       {return STR_LIT;};

{int_mult_op}            {return INT_MULT_OP;};
{int_add_op}            {return INT_ADD_OP;};
{int_eq_op}            {return INT_EQ_OP;};

{bool_op_un}        {return BOOL_OP_UN;};
"&&"                {return BOOL_OP_ADD;};
"\|\|"              {return BOOL_OP_OR;};
{equality}          {return EQUALITY;};
{assignment}        {return ASSIGNMENT;};

"("                 {return OPEN_PAREN;};
")"                 {return END_PAREN;};
"{"                 {return OPEN_BRACE;};
"}"                 {return END_BRACE;};
","                 {return COMMA;};
";"                 {return SEMICOLON;};

{ws}                /* do nothing */
\/\/.*              /* do nothing */
###(.|\n)*###       /*also do nothing*/
{identifier}        {return IDENTIFIER;};

.                   {fprintf(stderr, "Unidentifed token: %s\nAt line %d\n", yytext, yylineno); exit(2);};

%%

// int main(int argc, char **argv)
// {
//   if(argc < 2) {
//     fprintf(stderr, "No input file\n");
//     exit(1);
//   }
//   yyin = fopen(argv[1], "r" );
//   yylex();
// }

