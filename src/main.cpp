/* main.cc */
#include "heading.h"
// prototype of bison-generated parser function
#include "ast.h"
#include "parse.h"
#include "semantics.h"
#include "symbol_table.h"
#include "codegen.h"
#include "rtpreproc.h"

// int yyparse(final_tree);

AST *final_tree;


int main(int argc, char **argv)
{  
  if ((argc > 1) && (freopen(argv[1], "r", stdin) == NULL))
  {
    cerr << argv[0] << ": File " << argv[1] << " cannot be opened.\n";
    exit(1);
  }
  StringData *sd = new StringData();
  sd->offset = 0;

  sym_table *table = new sym_table;
  open_scope(table);
  add_runetime(table);
  open_scope (table);

  yyparse();
  // cout << ast_to_string(final_tree, 0);
  proccess_strings(final_tree, sd);

  type_check(final_tree, table);

  generate_program(final_tree, sd);
  // test_function();
  return 0;
}
