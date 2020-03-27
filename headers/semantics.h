#ifndef SEM_H
#define SEM_H

#include "ast.h"
#include "parse.h"
#include "symbol_table.h"

void type_check(AST* tree, sym_table* table);
void add_func_to_table(sym_table *table, AST *header);
int get_expression_type(sym_table *table, AST* tree);
void add_arguments_to_scope(sym_table *table, AST* tree);
std::vector<int> formal_list_to_type(sym_table *table, AST* list);

#endif