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
    // else if(tree->type == GLOBAL_DEC) {
    //     for(long unsigned int i = 0; i < tree->children.size(); i++) {
    //         generate_code(tree->children[i], table);
    //     }
    // }
    else if(tree->type == ASSIGNMENT) {
        generate_code(tree->children[1], table);
        std::cout << "(local.set $" << tree->children[0]->data << ")\n";
    }
    // else if(tree->type == BLOCK) {
    //     for(long unsigned int i = 0; i < tree->children.size(); i++) {
    //         generate_code(tree->children[i], table);
    //     }
    // }
    else if(tree->type == FUNC_DEC) {
        std::cout << "(func ";
        for(long unsigned int i = 0; i < tree->children.size(); i++) {
            generate_code(tree->children[i], table);
        }
        std::cout << ")\n";
    }
    else if(tree->type == MAIN_FUNC) {
        std::cout << "(func $__main\n";
        for(long unsigned int i = 0; i < tree->children.size(); i++) {
            generate_code(tree->children[i], table);
        }
        std::cout << ")\n";
    }
    else if(tree->type == VAR_DEC) {
        std::cout << "(local $" << tree->children[1]->data << " i32)\n";
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