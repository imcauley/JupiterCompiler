/* main.cc */
#include "heading.h"
// prototype of bison-generated parser function
#include "ast.h"
#include "parse.h"
#include "semantics.h"
#include "symbol_table.h"


int data;
// int yyparse(parse_tree);

int main(int argc, char **argv)
{  
  if ((argc > 1) && (freopen(argv[1], "r", stdin) == NULL))
  {
    cerr << argv[0] << ": File " << argv[1] << " cannot be opened.\n";
    exit(1);
  }
  
  AST *parse_tree;
  sym_table *table;
  // yyparse(parse_tree);
  

  // std::cout << parse_tree->type << "\n";
  return 0;
}
