#ifndef AST_H
#define AST_H

#include <string>
#include <vector>
#include <cstdarg>

typedef struct AST {
    int type;
    std::string data;
    std::vector<AST*> children;
} AST;

AST* make_new_node(std::string name);
AST* make_new_node(char* name);
AST* make_new_node(int type, char* name, int num_children...);
AST *get_child_of_type(AST* tree, int type);
void add_child(AST* node, AST* child);
std::string ast_to_string(AST* tree, int depth);
std::vector<AST*> filter_children(AST* tree, int type);
#endif