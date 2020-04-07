#include "codegen.h"
#include <iostream>


// using namespace std;

void generate_code(AST *tree, sym_table *table) {    
    if(tree->type == ROOT) {
        std::cout << "(module \n";
        for(long unsigned int i = 0; i < tree->children.size(); i++) {
            generate_code(tree->children[i], table);
        }
        std::cout << "(start $__main)\n)\n";
    }
    else if(tree->type == GLOBAL_DEC) {
        for(long unsigned int i = 0; i < tree->children.size(); i++) {
            generate_code(tree->children[i], table);
        }
    }
    else if(tree->type == FUNC_DEC) {
        std::cout << "(func ";
        for(long unsigned int i = 0; i < tree->children.size(); i++) {
            generate_code(tree->children[i], table);
        }
        std::cout << ")\n"
    }
    else if(tree->type == MAIN_FUNC) {
        std::cout << "(func $__main\n";
    for(long unsigned int i = 0; i < tree->children.size(); i++) {
        generate_code(tree->children[i], table);
    }
        std::cout << ")\n";
    }
    else if(tree->type == NUMBER) {
        std::cout << "i32.const " << tree->data << "\n";
    }
}