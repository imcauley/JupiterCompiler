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


  symbol* test = get_symbol(table, "k");

  // std::cout << (table->scope_stack).size() << "\n";
  yyparse();
  type_check(final_tree, table);

  // std::cout << "here\n";
  // exit(0);
  std::cout << ast_to_string(final_tree, 0) << "\n";
  return 0;
}
