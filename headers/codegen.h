#include "heading.h"
#include "symbol_table.h"
#include "ast.h"
#include <vector>

typedef struct BlockContext {
    std::vector<int> stack;
    int counter;
} BlockContext;

void generate_code(AST *tree, BlockContext *table);
void function_varaibles(AST *tree);
void function_header(AST *dec);
void expression_evaluation(AST *tree);
void function_call(AST *tree);
void add_prologue(AST *tree);