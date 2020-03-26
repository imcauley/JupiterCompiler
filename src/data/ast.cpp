#include "ast.h"
#include "token_map.h"
// #include <cstdarg>

// AST* make_new_node(std::string name) {
//     AST* new_node = new AST;
//     new_node->data = name;
//     return new_node;
// }

// AST* make_new_node(char* name) {
//     std::string str_name = name;

//     AST* new_node = new AST;
//     new_node->data = name;
//     return new_node;
// }

AST* make_new_node(int type, char* name, int num_children...) {
    std::string str_name = name;
    AST* new_node = new AST;
    new_node->data = name;
    new_node->type = type;

    va_list args;
    va_start(args, num_children);
 
    while (num_children > 0) {
        AST* current_child = va_arg(args, AST*);
        new_node->children.push_back(current_child);
        num_children--;
    }
 
    va_end(args);

    return new_node;
}

void combine_nodes(AST* parent, AST* children) {
    parent->children.insert(parent->children.end(), children->children.begin(), children->children.end());
}

void add_child(AST* node, AST* child) {
    node->children.push_back(child);
}

AST *get_child_of_type(AST* tree, int type) {
    if(tree->type == type) {
        return tree;
    }
    for(std::vector<AST*>::size_type i = 0; i < tree->children.size(); i++) {
        if(get_child_of_type(tree->children[i], type) != NULL) {
            return tree->children[i];
        }
    }
    return NULL;
}

std::string ast_to_string(AST* tree, int depth) {
    std::string output;
    std::string indent = "\n";

    for(int i = 0; i < depth; i++) {
        indent.append("  ");
    }

    output.append(indent);
    output.append(get_token_name(tree->type));
    output.append(" data=");
    output.append(tree->data);
    output.append("[ ");
    for(std::vector<AST*>::size_type i = 0; i < tree->children.size(); i++) {
        output.append(ast_to_string(tree->children[i], depth++));
    }
    output.append(indent);
    output.append("]");

    return output;
}

