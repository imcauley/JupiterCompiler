#include "heading.h"
#include "symbol_table.h"
#include "ast.h"
#include <vector>
#include "rtpreproc.h"


typedef struct BlockContext {
    std::vector<int> stack;
    int counter;
    std::vector<std::string> globals;
} BlockContext;

void generate_program(AST *root, StringData *sd);

void generate_code(AST *tree, BlockContext *table);
void function_varaibles(AST *tree);
void function_header(AST *dec);
void expression_evaluation(AST *tree, BlockContext *bc);
void function_call(AST *tree, BlockContext *bc);
void add_prologue(AST *tree);