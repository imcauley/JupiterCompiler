#include "ast.h"

AST* make_new_node(std::string name) {
    AST* new_node = new AST;
    new_node->data = name;
    return new_node;
}

AST* make_new_node(char* name) {
    std::string str_name = name;
    return make_new_node(str_name);
}

void add_child(AST* node, AST* child) {
    node->children.push_back(child);
}

std::string ast_to_string(AST* tree) {
    std::string output = "[.";
    output.append(tree->data);
    output.append(" ");
    for(size_t i = 0; i < tree->children.size();i++) {
        output.append(ast_to_string(tree->children[i]));
    }
    output.append(" ]");
    return output;
}