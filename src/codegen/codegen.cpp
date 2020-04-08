#include "codegen.h"
#include <iostream>


// using namespace std;

void generate_code(AST *tree, sym_table *table) {    
    if(tree->type == ROOT) {
        std::cout << "(module \n";
        for(long unsigned int i = 0; i < tree->children.size(); i++) {
            // TODO add global (global $g (import "js" "global") (mut i32))
            generate_code(tree->children[i], table);
        }
        std::cout << "(start $__main)\n)\n";
    }
    else if(tree->type == ASSIGNMENT) {
        generate_code(tree->children[1], table);
        std::cout << "(local.set $" << tree->children[0]->data << ")\n";
    }
    else if(tree->type == MAIN_FUNC) {
        std::cout << "(func $__main\n";
        function_varaibles(tree);
        for(long unsigned int i = 0; i < tree->children.size(); i++) {
            generate_code(tree->children[i], table);
        }
        std::cout << ")\n";
    }
    // else if(tree->type == VAR_DEC) {
    //     std::cout << "(local $" << tree->children[1]->data << " i32)\n";
    // }
    else if(tree->type == FUNC_DEC) {
        function_header(tree);
        function_varaibles(tree);
        generate_code(tree->children[1], table);
        std::cout << ")\n";
    }
    else if(tree->type == NUMBER) {
        std::cout << "i32.const " << tree->data << "\n";
    }
    else {
        for(long unsigned int i = 0; i < tree->children.size(); i++) {
            generate_code(tree->children[i], table);
        }
    }
}

void function_header(AST *dec) {
    AST *type = dec->children[0]->children[0];
    AST *declar = dec->children[0]->children[1];

    std::cout << "(func ";
    if(declar->children.size() > 1) {
        AST *params = declar->children[1];
        for(long unsigned int i = 0; i < params->children.size(); i++) {
            // std::cout << params->children[i]->children[1]->data;
            std::cout << "(param $" << params->children[i]->children[1]->data << " i32)";
        }
    }

    if(type->type != VOID ) {
        std::cout << "(result i32)\n";
    }
}

void function_varaibles(AST *tree) {
    if(tree->type == VAR_DEC) {
        std::cout << "(local $" << tree->children[1]->data << " i32)\n";
    }
    else {
        for(long unsigned int i = 0; i < tree->children.size(); i++) {
            function_varaibles(tree->children[i]);
        }
    }
}