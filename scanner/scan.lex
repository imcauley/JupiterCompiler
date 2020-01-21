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
*/

%{
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


%%
{ws}    ++whitespace;
\n      ++mylineno;
{alpha}+  printf("%s\n", yytext);
%%

int main()
{
  yylex();
  printf("whitespace = %d\n", mylineno);
}

