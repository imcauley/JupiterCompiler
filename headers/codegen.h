#include "heading.h"
#include "symbol_table.h"
#include "ast.h"

void generate_code(AST *tree, sym_table *table);
void function_varaibles(AST *tree);
void function_header(AST *dec);
void expression_evaluation(AST *tree);
void function_call(AST *tree);
void add_prologue(AST *tree);