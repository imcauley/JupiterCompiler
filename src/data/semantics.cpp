#include "semantics.h"

bool check_for_main(AST* tree) {
    int main_index = 0;
    for(unsigned int i = 0; i < tree->children.size(); i++) {
        if(tree->children[i]->type == MAIN_FUNC) {
            main_index = i;
            break;
        }
    }
    bool has_return;
    if(main_index > 0) {
        has_return = contains_type(tree->children[main_index], RETURN);
    }

    return (!has_return);
}

bool contains_type(AST* tree, int node_type) {
    for(unsigned int i = 0; i < tree->children.size(); i++) {
        AST* subtree = tree->children[i];
        if(subtree->type == node_type) {
            return true;
        }
        if(subtree->children.size() > 0) {
            return contains_type(subtree, node_type);
        }
    }
    return false;
}

sym_table *make_sym_table(AST* tree) {
    std::vector<AST*> nodes_to_vist;
    AST* current = tree;

    while(current != NULL || nodes_to_vist.empty() != false) {
        if(current->type == VAR_DEC) {
            int i = 1;
        }
    }
    return NULL;
}