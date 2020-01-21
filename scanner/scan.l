/* 
 * Sample Scanner2: 
 * Description: Count the number of characters and the number of lines 
 *              from standard input
 * Usage: (1) $ flex sample2.lex
 *        (2) $ gcc lex.yy.c -lfl
 *        (3) $ ./a.out
 *            stdin> whatever you like
 *	      stdin> Ctrl-D
 * Questions: Is it ok if we do not indent the first line?
 *            What will happen if we remove the second rule?
 *
 *
 * http://alumni.cs.ucr.edu/~lgao/teaching/flex.html
 * http://dinosaur.compilertools.net/flex/flex_7.html
 * http://web.mit.edu/gnu/doc/html/flex_1.html
*/

%{
    #include "tokens.h"
    int mylineno = 0;
    int whitespace = 0;
    int all_characters = 0;
%}

string  \"[^\n"]+\"

ws      [ \t]+

alpha   [A-Za-z]
dig     [0-9]
name    ({alpha}|{dig}|\$)({alpha}|{dig}|[_.\-/$])*
num1    [-+]?{dig}+\.?([eE][-+]?{dig}+)?
num2    [-+]?{dig}*\.{dig}+([eE][-+]?{dig}+)?
number  {num1}|{num2}
operator (\*|\+|\-|\/)
type    (int|char)


%%
{type}              printf("TYPE_DEF\n");
\(                  printf("BEGIN_PAREN\n");
\)                  printf("END_PAREN\n");
=                   printf("ASSIGNMENT\n");
{operator}          printf("OPERATOR\n");
{num1}              printf("NUM_LIT\n");
\".*\"              printf("STR_LIT\n");
{ws}                ++whitespace;
\n                  ++mylineno;
\/\/.*\n            /* do nothing */
###(.|\n)*###       /*also do nothing*/
.                   /*nothing */
%%

int main()
{
  yylex();
  printf("whitespace = %d\n", mylineno);
}

