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
    table_to_string(table);
    std::cout << "\n\n";
    if(tree->type == GLOBAL_DEC) {
        bool is_main = false;
        for(long unsigned int i = 0; i < tree->children.size(); i++) {
            if(tree->children[i]->type == FUNC_DEC) {
                AST *header = tree->children[i]->children[0];
                add_func_to_table(table, header);
            }
            else if(tree->children[i]->type == MAIN_FUNC) {
                if(is_main) {
                    fprintf(stderr, "Two main functions\n");
                    exit(-1);    
                }

                symbol *new_symbol = new symbol();
                new_symbol->type = VOID;
                new_symbol->id = tree->children[i]->children[0]->data;
                new_symbol->exp_type = FUNC_MAIN;

                add_symbol(table, new_symbol);
                is_main = true;
            }
        }
        
        if(!is_main) {
            fprintf(stderr, "No main function declared\n");
            exit(-1);   
        }

        open_scope(table);
        for(long unsigned int i = 0; i < tree->children.size(); i++) {
            type_check(tree->children[i], table);
        }
    }
    else if(tree->type == VAR_DEC) {
        symbol *new_symbol = new symbol();
        new_symbol->type = tree->children[0]->type;
        new_symbol->id = tree->children[1]->data;
        new_symbol->exp_type = VAR;

        if(get_symbol_in_scope(table, new_symbol->id) != NULL) {
            fprintf(stderr, "Redeclaration of %s\n", new_symbol->id.c_str());
            exit(-1);
        }

        add_symbol(table, new_symbol);
    }
    else if(tree->type == FUNC_DEC) {
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
        new_symbol->exp_type = VAR;
        if(get_symbol_in_scope(table, new_symbol->id) != NULL) {
            fprintf(stderr, "Redeclaration of %s\n", new_symbol->id.c_str());
            exit(-1);
        }

        add_symbol(table, new_symbol);
    }
    else if(tree->type == MAIN_FUNC) {
        open_scope(table);
        for(long unsigned int i = 0; i < tree->children.size(); i++) {
            type_check(tree->children[i], table);
        }
        exit_scope(table);
    }
    // else if(tree->type == RETURN) {
    //     int func_type = get_function_type(table);
    //     if(func_type == -1) {
    //         if(tree->children.size() > 0) {
    //             fprintf(stderr, "Returning of non-void in void function\n");
    //             exit(-1);
    //         }
    //     }
    //     else {
    //         int ret_type = get_expression_type(tree->children[0]);
    //         if(ret_type != func_type) {
    //             fprintf(stderr, "Incorrect return type\n");
    //             exit(-1);
    //         }
    //     }
    // }
    else if(tree->type == IDENTIFIER) {
        if(get_symbol(table, tree->data) == NULL) {
            fprintf(stderr, "No declaration of %s\n", tree->data.c_str());
            exit(-1);        
        }
    }
    else {
        for(long unsigned int i = 0; i < tree->children.size(); i++) {
            type_check(tree->children[i], table);
        }
    }
}

int get_function_type(sym_table *table) {
    int i = table->scope_stack.size() - 1;
    std::map<std::string, symbol*>::iterator it;
    for ( it = table->scope_stack[i]->begin(); it != table->scope_stack[i]->end(); it++ ){
        if(it->second->exp_type == FUNC) {
            return it->second->type;
        }
    }

    return -1;
}

void add_func_to_table(sym_table *table, AST *header) {
    symbol *new_symbol = new symbol();
    new_symbol->type = header->children[0]->type;

    if(header->children[1]->type == IDENTIFIER) {
        new_symbol->id = header->children[1]->data;
    }
    else {
        new_symbol->id = header->children[1]->children[0]->data;
    }
    new_symbol->exp_type = FUNC;

    if(get_symbol_in_scope(table, new_symbol->id) != NULL) {
        fprintf(stderr, "Redeclaration of function %s\n", new_symbol->id.c_str());
        exit(-1);
    }

    add_symbol(table, new_symbol);
}

bool main_func_exists(sym_table *table) {
    for(int i = table->scope_stack.size() - 1; i >= 0; i--) {
        std::map<std::string, symbol*>::iterator it;
        for ( it = table->scope_stack[i]->begin(); it != table->scope_stack[i]->end(); it++ ){
            if(it->second->exp_type == FUNC_MAIN) {
                return true;
            }
        }
    }

    return false;
}


int get_expression_type(AST* tree) {
    return INT_DEC;
}