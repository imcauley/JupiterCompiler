#include "semantics.h"
#include "heading.h"

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
        add_arguments_to_scope(table, tree->children[0]->children[1]);

        // Making sure returns match type
        int function_type = tree->children[0]->children[0]->type;
        std::vector<AST*> returns =  filter_children(tree, RETURN);
        if(function_type != VOID && returns.size() < 1) {
            fprintf(stderr, "No return on non void function\n");
            exit(-1);
        }

        for(long unsigned int i = 0; i < returns.size(); i++) {
            if(function_type == VOID && returns[i]->children.size() > 0) {
                fprintf(stderr, "None void return in void function\n");
                exit(-1);
            }
            else {
                if(returns[i]->children.size() == 0) {
                    fprintf(stderr, "Type mismatch on return statement\n");
                    exit(-1);
                }

                int return_type = get_expression_type(table, returns[i]->children[0]);
                if(return_type != function_type) {
                    fprintf(stderr, "Type mismatch on return statement\n");
                    exit(-1);
                }
            }
        }

        for(long unsigned int i = 1; i < tree->children.size(); i++) {
            type_check(tree->children[i], table);
        }
        exit_scope(table);
    }
    else if(tree->type == MAIN_FUNC) {
        open_scope(table);
        for(long unsigned int i = 0; i < tree->children.size(); i++) {
            type_check(tree->children[i], table);
        }
        exit_scope(table);
    }
    else if(tree->type == FUNC_INVOKE) {
        symbol *function_symbol = get_symbol(table, tree->children[0]->data);
        if(function_symbol->exp_type == FUNC_MAIN) {
            fprintf(stderr, "Cannot call main function\n");
            exit(-1);        
        }
    }
    else if(tree->type == IF || tree->type == ELSE || tree->type == WHILE) {
        //type checking conditional
        int if_exp = get_expression_type(table, tree->children[0]);
        if(if_exp != BOOL_DEC) {
            fprintf(stderr, "Non-boolean type in if conditional\n");
            exit(-1);
        }
        for(long unsigned int i = 1; i < tree->children.size(); i++) {
            // checking if varaibles are declared
            std::vector<AST*> assignments =  filter_children(tree->children[i], VAR_DEC);
            if(assignments.size() > 0) {
                fprintf(stderr, "Varaible declaration in internal block\n");
                exit(-1);
            }
            type_check(tree->children[i], table);
        }
    }
    else if(tree->type == ASSIGNMENT) {
        int left_type = get_expression_type(table, tree->children[0]);
        int right_type = get_expression_type(table, tree->children[1]);

        if(left_type != right_type) {
            fprintf(stderr, "Type mismatch\n");
            exit(-1);
        }
    }
    else {
        for(long unsigned int i = 0; i < tree->children.size(); i++) {
            type_check(tree->children[i], table);
        }
    }
}

void add_arguments_to_scope(sym_table *table, AST* tree) {
    if(tree->children.size() > 1) {
        AST* parameters = tree->children[1];
        for(long unsigned int i = 0; i < parameters->children.size(); i++) {
            AST *param = parameters->children[i];
            symbol *new_symbol = new symbol();
            new_symbol->type = param->children[0]->type;
            new_symbol->id = param->children[1]->data;
            new_symbol->exp_type = VAR;
            if(get_symbol_in_scope(table, new_symbol->id) != NULL) {
                fprintf(stderr, "Redeclaration of %s\n", new_symbol->id.c_str());
                exit(-1);
            }

            add_symbol(table, new_symbol);
        }
    }
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

int get_expression_type(sym_table *table, AST* tree) {
    if(tree->type == EXPRESSION) {
        return(get_expression_type(table, tree->children[0]));
    }
    else if(tree->type == BOOL_DEC ||
            tree->type == BOOL) {
        return BOOL_DEC;
    }
    else if(tree->type == INT_DEC ||
            tree->type == NUMBER) {
        return INT_DEC;
    }
    else if(tree->type == IDENTIFIER) {
        symbol *ident = get_symbol(table, tree->data);  
        if(ident == NULL) {
            fprintf(stderr, "No declaration of %s\n", tree->data.c_str());
            exit(-1);        
        }
        return ident->type;
    }
    else if(tree->type == FUNC_INVOKE) {
        symbol *function_symbol = get_symbol(table, tree->children[0]->data);
        if(function_symbol->exp_type == FUNC_MAIN) {
            fprintf(stderr, "Cannot call main function\n");
            exit(-1);        
        }
        return function_symbol->type;
    }
    else if(tree->type == LT || 
            tree->type == GT || 
            tree->type == LTE || 
            tree->type == GTE ) {
        
        int left_type = get_expression_type(table, tree->children[0]);
        int right_type = get_expression_type(table, tree->children[1]);

        if(left_type != INT_DEC || right_type != INT_DEC) {
            fprintf(stderr, "Type mismatch\n");
            exit(-1);
        }

        return BOOL_DEC;
    }
    else if(tree->type == MULT ||
            tree->type == DIV ||
            tree->type == ADD ||
            tree->type == SUB ||
            tree->type == MOD ) {

        int left_type = get_expression_type(table, tree->children[0]);
        int right_type = get_expression_type(table, tree->children[1]);

        if(left_type != INT_DEC || right_type != INT_DEC) {
            fprintf(stderr, "Type mismatch\n");
            exit(-1);
        }

        return INT_DEC;
    }
    else if(tree->type == OR ||
            tree->type == AND ) {

        int left_type = get_expression_type(table, tree->children[0]);
        int right_type = get_expression_type(table, tree->children[1]);

        if(left_type != BOOL_DEC || right_type != BOOL_DEC) {
            fprintf(stderr, "Type mismatch\n");
            exit(-1);
        }

        return BOOL_DEC;
    }
    else if(tree->type == EQ ||
            tree->type == NEQ) {

        int left_type = get_expression_type(table, tree->children[0]);
        int right_type = get_expression_type(table, tree->children[1]);

        if(left_type != right_type) {
            fprintf(stderr, "Type mismatch\n");
            exit(-1);
        }

        return BOOL_DEC;
    }
    else if(tree->type == NOT) {
        if(get_expression_type(table, tree->children[0]) != BOOL_DEC) {
            fprintf(stderr, "Type mismatch\n");
            exit(-1);
        }
        return BOOL_DEC;
    }
    else if(tree->type == NEG) {
        if(get_expression_type(table, tree->children[0]) != INT_DEC) {
            fprintf(stderr, "Type mismatch\n");
            exit(-1);
        }
        return INT_DEC;
    }
    return -1;
}