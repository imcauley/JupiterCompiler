#include "codegen.h"
#include <fstream>
#include <string.h>
#include <iostream>
#include <stdio.h>
// using namespace std

#define WA_FALSE "(i32.const 0)\n" 
#define WA_TRUE "(i32.const 1)\n"

void generate_code(AST *tree, BlockContext *block_state) {    
    if(tree->type == ROOT) {
        std::cout << "(module \n";
        add_prologue(tree);
        for(long unsigned int i = 0; i < tree->children.size(); i++) {
            // TODO add global (global $g (import "js" "global") (mut i32))
            generate_code(tree->children[i], block_state);
        }
        std::cout << "(start $__main)\n)\n";
    }
    else if(tree->type == ASSIGNMENT) {
        expression_evaluation(tree->children[1]);
        std::cout << "(local.set $" << tree->children[0]->data << ")\n";
    }
    else if(tree->type == MAIN_FUNC) {
        std::cout << "(func $__main\n";
        function_varaibles(tree);
        for(long unsigned int i = 0; i < tree->children.size(); i++) {
            generate_code(tree->children[i], block_state);
        }
        std::cout << ")\n";
    }
    else if(tree->type == EXPRESSION) {
        expression_evaluation(tree);
    }
    else if(tree->type == FUNC_DEC) {
        function_header(tree);
        function_varaibles(tree);
        generate_code(tree->children[1], block_state);
        std::cout << ")\n";
    }
    else if(tree->type == RETURN) {
        if(tree->children.size() > 0) {
            generate_code(tree->children[0], block_state);
            std::cout << "return\n";
        }
    }
    else if(tree->type == FUNC_INVOKE) {
        function_call(tree);
    }
    else if(tree->type == IF) {
        generate_code(tree->children[0], block_state);
        std::cout << "if\n";
        generate_code(tree->children[1], block_state);
        std::cout << "end\n";
    }
    else if(tree->type == WHILE) {
        int block_num = block_state->counter;
        block_state->counter++;
        block_state->stack.push_back(block_num);
        std::cout << "(block $B" << block_num << "\n"
                  << "(loop $L" << block_num << "\n";

        expression_evaluation(tree->children[0]);
        std::cout << "i32.eqz\n"
                  << "br_if $B" << block_num << "\n";

        generate_code(tree->children[1], block_state);
        std::cout << "br $L" << block_num << "\n";
        std::cout << ")\n)\n";
        block_state->stack.pop_back();
    }
    else if(tree->type == BREAK) {
        std::cout << "br $B" << block_state->stack.back() << "\n";
    }
    else {
        for(long unsigned int i = 0; i < tree->children.size(); i++) {
            generate_code(tree->children[i], block_state);
        }
    }
}

void function_call(AST *tree) {
    if (tree->children.size() > 1) {
        AST *params = tree->children[1];
        for(long unsigned int i = 0; i < params->children.size(); i++) {
            expression_evaluation(params->children[i]);
        }
    }
    std::cout << "(call $" << tree->children[0]->data << ")\n";
}

void expression_evaluation(AST *tree) {
    if(tree->type == EXPRESSION) {
        expression_evaluation(tree->children[0]);
    }
    else if(tree->type == NUMBER) {
        std::cout << "(i32.const " << tree->data << ")\n";
    }
    else if(tree->type == IDENTIFIER) {
        std::cout << "(local.get $" << tree->data << ")\n";
    }
    else if(tree->type == ADD) {
         expression_evaluation(tree->children[0]);
         expression_evaluation(tree->children[1]);
         std::cout << "i32.add\n";
    }
    else if(tree->type == SUB) {
         expression_evaluation(tree->children[0]);
         expression_evaluation(tree->children[1]);
         std::cout << "i32.sub\n";
    }
    else if(tree->type == MULT) {
         expression_evaluation(tree->children[0]);
         expression_evaluation(tree->children[1]);
         std::cout << "i32.mul\n";
    }
    else if(tree->type == DIV) {
         expression_evaluation(tree->children[0]);
         expression_evaluation(tree->children[1]);
         std::cout << "i32.div_s\n";
    }
    else if(tree->type == MOD) {
         expression_evaluation(tree->children[0]);
         expression_evaluation(tree->children[1]);
         std::cout << "i32.rem_s\n";
    }
    else if(tree->type == NEG) {
         expression_evaluation(tree->children[0]);
         std::cout << "i32.rem_s\n";
    }
    else if(tree->type == FUNC_INVOKE) {
        function_call(tree);
    }

    // COMPARISONS
    else if(tree->type == LT) {
        expression_evaluation(tree->children[0]);
        expression_evaluation(tree->children[1]);
        std::cout << "i32.lt_s\n";
    }
    else if(tree->type == GT) {
        expression_evaluation(tree->children[0]);
        expression_evaluation(tree->children[1]);
        std::cout << "i32.gt_s\n";
    }
    else if(tree->type == LTE) {
        expression_evaluation(tree->children[0]);
        expression_evaluation(tree->children[1]);
        std::cout << "i32.le_s\n";
    }
    else if(tree->type == GTE) {
        expression_evaluation(tree->children[0]);
        expression_evaluation(tree->children[1]);
        std::cout << "i32.ge_s\n";
    }
    else if(tree->type == EQ) {
        expression_evaluation(tree->children[0]);
        expression_evaluation(tree->children[1]);
        std::cout << "i32.eq\n";
    }
    else if(tree->type == NEQ) {
        expression_evaluation(tree->children[0]);
        expression_evaluation(tree->children[1]);
        std::cout << "i32.ne\n";
    }
    // BOOLEAN
    else if(tree->type == BOOL) {
        if(tree->data.compare("true") == 0) {
            std::cout << WA_TRUE;
        } else { 
            std::cout << WA_FALSE;
        }
    }
    else if(tree->type == AND) {
        // A && B
        // Only evaluate B if A is true
        expression_evaluation(tree->children[0]);
        std::cout << WA_FALSE
                  << "i32.ne\n";
        std::cout << "if (result i32)\n";
        expression_evaluation(tree->children[1]);
        std::cout << "else\n";
        std::cout << WA_FALSE;
        std::cout << "end\n";
    }
    else if (tree->type == OR) {
        // A || B
        // Only evaluate B if A is false
        expression_evaluation(tree->children[0]);
        std::cout << WA_FALSE
                  << "i32.eq\n";
        std::cout << "if (result i32) \n";
        expression_evaluation(tree->children[1]);
        std::cout << "else\n";
        std::cout << WA_TRUE;
        std::cout << "end\n";
    }
    // else {
    //     for(long unsigned int i = 0; i < tree->children.size(); i++) {
    //         expression_evaluation(tree->children[i]);
    //     }
    // }
}

// Probably super insecure
void add_prologue(AST *tree) {
    ifstream myfile;
    std::string line;
    myfile.open ("./runtime/runtime.wat");
    while (getline(myfile, line)) {
      cout << line << '\n';
    }
    myfile.close();
}

void function_header(AST *dec) {
    AST *type = dec->children[0]->children[0];
    AST *declar = dec->children[0]->children[1];

    
    if(declar->children.size() > 1) {
        std::cout << "(func $" << declar->children[0]->data << " ";
        AST *params = declar->children[1];
        for(long unsigned int i = 0; i < params->children.size(); i++) {
            std::cout << "(param $" << params->children[i]->children[1]->data << " i32) ";
        }
    } else { 
        std::cout << "(func $" << declar->data << " ";
    }
    std::cout << "\n";
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