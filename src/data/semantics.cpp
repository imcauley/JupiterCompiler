#include "semantics.h"
#include "heading.h"

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

// sym_table *make_sym_table(AST* tree) {
//     sym_table *table = new sym_table();
//     open_scope(table);
//     make_sym_table(tree, table);
//     return table;
// }

void type_check(AST* tree, sym_table* table) {
    if(tree->type == VAR_DEC) {
        symbol *new_symbol = new symbol();
        new_symbol->type = tree->children[0]->type;
        new_symbol->id = tree->children[1]->data;

        if(get_symbol_in_scope(table, new_symbol->id) != NULL) {
            fprintf(stderr, "Redeclaration of %s\n", new_symbol->id.c_str());
            exit(-1);
        }

        add_symbol(table, new_symbol);
    }

    else if(tree->type == FUNC_HEAD) {
        symbol *new_symbol = new symbol();
        new_symbol->type = tree->children[0]->type;
        new_symbol->id = tree->children[1]->children[1]->data;

        if(get_symbol_in_scope(table, new_symbol->id) != NULL) {
            fprintf(stderr, "Redeclaration of %s\n", new_symbol->id.c_str());
            exit(-1);
        }

        add_symbol(table, new_symbol);
        open_scope(table);
        for(long unsigned int i = 0; i < tree->children.size(); i++) {
            type_check(tree->children[i], table);
        }
        exit_scope(table);
    }
    else if(tree->type == FORM_PARAM) {
        symbol *new_symbol = new symbol();
        new_symbol->type = tree->children[0]->type;
        new_symbol->id = tree->children[1]->data;

        if(get_symbol_in_scope(table, new_symbol->id) != NULL) {
            fprintf(stderr, "Redeclaration of %s\n", new_symbol->id.c_str());
            exit(-1);
        }

        add_symbol(table, new_symbol);
    }

    // else if(tree->type == IDENTIFIER) {
    //     if(get_symbol(table, tree->data) == NULL) {
    //          //ERROR IN SEMANTICS
    //     }
    // }
    // else if (tree->type == PARAM_LIST) {
    //     for(int i = 0; i < tree->children.size(); i++) {
    //         symbol *new_symbol = new symbol();
    //         new_symbol->type = tree->children[i]->children[0]->type;
    //         new_symbol->id = tree->children[i]->children[1]->data;
    //     }
    // }
    else {
        for(long unsigned int i = 0; i < tree->children.size(); i++) {
            type_check(tree->children[i], table);
        }
    }
}