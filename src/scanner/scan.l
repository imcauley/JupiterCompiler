/* 
* 411 Project - Milestone 1
* Isaac McAuley
* 30062453
*/

%{
    // #include "tokens.h"
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
{ws}                /* do nothing */
"int"               {yylval.name = strdup(yytext); return INT_DEC;};
"boolean"               {yylval.name = strdup(yytext); return BOOL_DEC;};
"void"               {yylval.name = strdup(yytext); return VOID;};

"if"                {yylval.name = strdup(yytext); return IF;};
"else"              {yylval.name = strdup(yytext); return ELSE;};
"while"             {yylval.name = strdup(yytext); return WHILE;};
"break"             {yylval.name = strdup(yytext); return BREAK;};
"return"            {yylval.name = strdup(yytext); return RETURN;};

{bool_literal}      {yylval.name = strdup(yytext); return BOOL;};
{int_literal}       {yylval.name = strdup(yytext); return NUMBER;};
{str_literal}       {yylval.name = strdup(yytext); return STRING;};

"*"                 {yylval.name = strdup(yytext); return MULT;};
"/"                 {yylval.name = strdup(yytext); return DIV;};
"%"                 {yylval.name = strdup(yytext); return MOD;};
"+"                 {yylval.name = strdup(yytext); return ADD;};
"-"                 {yylval.name = strdup(yytext); return SUB;};

"!"                 {yylval.name = strdup(yytext); return NOT;};

"<"                 {yylval.name = strdup(yytext); return LT;};
">"                 {yylval.name = strdup(yytext); return GT;};
"<="                {yylval.name = strdup(yytext); return LTE;};
">="                {yylval.name = strdup(yytext); return GTE;};

"&&"                {yylval.name = strdup(yytext); return AND;};
"||"                {yylval.name = strdup(yytext); return OR;};

"=="                {yylval.name = strdup(yytext); return EQ;};
"!="                {yylval.name = strdup(yytext); return NEQ;};

"="                 {yylval.name = strdup(yytext); return ASSIGNMENT;};

"("                 {yylval.name = strdup(yytext); return OPEN_PAREN;};
")"                 {yylval.name = strdup(yytext); return END_PAREN;};
"{"                 {yylval.name = strdup(yytext); return OPEN_BRACE;};
"}"                 {yylval.name = strdup(yytext); return END_BRACE;};
","                 {yylval.name = strdup(yytext); return COMMA;};
";"                 {yylval.name = strdup(yytext); return SEMICOLON;};

\/\/.*              /* do nothing */
###(.|\n)*###       /*also do nothing*/
{identifier}        {yylval.name = strdup(yytext); return IDENTIFIER;};

.                   {fprintf(stderr, "Unidentifed token: %s\nAt line %d\n", strdup(yytext), yylineno); exit(2);};

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

