#include <string>
#include <vector>
#include "ast.h"
#include "heading.h"
#include "symbol_table.h"

#ifndef RTPP_H
#define RTPP_H
typedef struct StringData {
    int offset;
    std::string total_strings;
} StringData;

void proccess_strings(AST *tree, StringData *sd);
void add_runetime(sym_table *sym);

#endif