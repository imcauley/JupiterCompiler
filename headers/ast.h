#ifndef AST_H
#define AST_H

#include <string>
#include <vector>

typedef struct AST {
    std::string data;
    std::vector<AST*> children;
} AST;

AST* make_new_node(std::string name);
AST* make_new_node(char* name);
void add_child(AST* node, AST* child);
std::string ast_to_string(AST* tree);

#endif