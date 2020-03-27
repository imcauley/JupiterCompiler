/* main.cc */
#include "heading.h"
// prototype of bison-generated parser function
#include "ast.h"
#include "parse.h"
#include "semantics.h"
#include "symbol_table.h"


// int yyparse(final_tree);

AST *final_tree;


int main(int argc, char **argv)
{  
  if ((argc > 1) && (freopen(argv[1], "r", stdin) == NULL))
  {
    cerr << argv[0] << ": File " << argv[1] << " cannot be opened.\n";
    exit(1);
  }
  

  sym_table *table = new sym_table;
  open_scope(table);

  yyparse();
  type_check(final_tree, table);

  return 0;
}
