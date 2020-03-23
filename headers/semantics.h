#ifndef SEM_H
#define SEM_H

#include "ast.h"
#include "parse.h"

bool check_for_main(AST* tree);
bool contains_type(AST* tree, int node_type);

#endif