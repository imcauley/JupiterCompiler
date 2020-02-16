/* 
* 411 Project - Milestone 1
* Isaac McAuley
* 30062453
*/

%{
    #include "tokens.h"
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

int_op (\+|\-|\*|\/|%|<|>|<=|>=)
bool_op_un (!)
bool_op_bin (&&|\|\|)
equality (==|!=)
assignment (=)
type    (int|boolean|void)

bool_literal (true|false)
int_literal {dig}+
str_literal \"(.|\0|\\0|\\b|\\n|\\|\\f|\\t|\\r|\\\"|\')+\"


%%
{type}              output_token(TYPE_DEF, yylineno, yytext);

"if"                output_token(IF_TOK, yylineno, yytext);
"else"              output_token(ELSE_TOK, yylineno, yytext);
"while"             output_token(WHILE_TOK, yylineno, yytext);
"break"             output_token(BREAK_TOK, yylineno, yytext);
"return"            output_token(RETURN_TOK, yylineno, yytext);

{bool_literal}      output_token(BOOL_LIT, yylineno, yytext);
{int_literal}       output_token(INT_LIT, yylineno, yytext);
{str_literal}       output_token(STR_LIT, yylineno, yytext);

{int_op}            output_token(INT_OP, yylineno, yytext);
{bool_op_un}        output_token(BOOL_OP_UN, yylineno, yytext);
{bool_op_bin}       output_token(BOOL_OP_BIN, yylineno, yytext);
{equality}          output_token(EQUALITY, yylineno, yytext);
{assignment}        output_token(ASSIGNMENT, yylineno, yytext);

"("                 output_token(OPEN_PAREN, yylineno, yytext);
")"                 output_token(END_PAREN, yylineno, yytext);
"{"                 output_token(OPEN_BRACE, yylineno, yytext);
"}"                 output_token(END_BRACE, yylineno, yytext);
","                 output_token(COMMA, yylineno, yytext);
";"                 output_token(SEMICOLON, yylineno, yytext);

{ws}                /* do nothing */
\/\/.*              /* do nothing */
###(.|\n)*###       /*also do nothing*/
{identifier}        output_token(IDENTIFIER, yylineno, yytext);

.                   {fprintf(stderr, "Unidentifed token: %s\nAt line %d\n", yytext, yylineno); exit(2);};

%%

int main(int argc, char **argv)
{
  if(argc < 2) {
    fprintf(stderr, "No input file\n");
    exit(1);
  }
  yyin = fopen(argv[1], "r" );
  yylex();
}

