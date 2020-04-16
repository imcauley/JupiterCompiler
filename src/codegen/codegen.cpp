#include "codegen.h"
#include <fstream>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>

// using namespace std

#define WA_FALSE "(i32.const 0)\n"
#define WA_TRUE "(i32.const 1)\n"

void generate_program(AST *root, StringData *sd)
{
    BlockContext *bc = new BlockContext();
    bc->counter = 0;

    std::cout << "(module \n";
    add_prologue(root);
    for (long unsigned int i = 0; i < root->children[0]->children.size(); i++)
    {
        AST *global_dec = root->children[0]->children[i];
        if(global_dec->type == VAR_DEC) {
            std::cout << "(global $";
            std::cout << global_dec->children[1]->data;
            std::cout << " (mut i32) (i32.const 0))\n";
            
            bc->globals.push_back(global_dec->children[1]->data);
        }
    }
    for (long unsigned int i = 0; i < root->children.size(); i++)
    {
        generate_code(root->children[i], bc);
    }
    std::cout << "(start $__main)\n";
    std::cout << sd->total_strings;
    std::cout << "(memory 10)";
    std::cout << "\n)\n";
}

void generate_code(AST *tree, BlockContext *block_state)
{
    if (tree->type == MAIN_FUNC)
    {
        std::cout << "(func $__main\n";
        function_varaibles(tree);
        for (long unsigned int i = 0; i < tree->children.size(); i++)
        {
            generate_code(tree->children[i], block_state);
        }
        std::cout << ")\n";
    }
    else if (tree->type == EXPRESSION)
    {
        expression_evaluation(tree, block_state);
    } 
    else if (tree->type == ASSIGNMENT) {
        expression_evaluation(tree, block_state);
        std::cout << "(drop)\n";

    }
    else if (tree->type == FUNC_DEC)
    {
        function_header(tree);
        function_varaibles(tree);
        generate_code(tree->children[1], block_state);
        std::cout << ")\n";
    }
    else if (tree->type == RETURN)
    {
        if (tree->children.size() > 0)
        {
            generate_code(tree->children[0], block_state);
            std::cout << "return\n";
        }
    }
    else if (tree->type == FUNC_INVOKE)
    {
        function_call(tree, block_state);
    }
    else if (tree->type == IF)
    {
        generate_code(tree->children[0], block_state);
        std::cout << "if\n";
        generate_code(tree->children[1], block_state);
        std::cout << "end\n";
    }
    else if (tree->type == WHILE)
    {
        int block_num = block_state->counter;
        block_state->counter++;
        block_state->stack.push_back(block_num);
        std::cout << "(block $B" << block_num << "\n"
                  << "(loop $L" << block_num << "\n";

        expression_evaluation(tree->children[0], block_state);
        std::cout << "i32.eqz\n"
                  << "br_if $B" << block_num << "\n";

        generate_code(tree->children[1], block_state);
        std::cout << "br $L" << block_num << "\n";
        std::cout << ")\n)\n";
        block_state->stack.pop_back();
    }
    else if (tree->type == BREAK)
    {
        std::cout << "br $B" << block_state->stack.back() << "\n";
    }
    else
    {
        for (long unsigned int i = 0; i < tree->children.size(); i++)
        {
            generate_code(tree->children[i], block_state);
        }
    }
}

void function_call(AST *tree, BlockContext *bc)
{
    if (tree->children.size() > 1)
    {
        AST *params = tree->children[1];
        for (long unsigned int i = 0; i < params->children.size(); i++)
        {
            expression_evaluation(params->children[i], bc);
        }
    }
    std::cout << "(call $" << tree->children[0]->data << ")\n";
}

void expression_evaluation(AST *tree, BlockContext *bc)
{
    if (tree->type == EXPRESSION)
    {
        expression_evaluation(tree->children[0], bc);
    }
    else if (tree->type == NUMBER)
    {
        std::cout << "(i32.const " << tree->data << ")\n";
    }
    else if (tree->type == IDENTIFIER)
    {
        if (std::find(bc->globals.begin(), bc->globals.end(), tree->data) != bc->globals.end()) {
            std::cout << "(global.get $" << tree->data << ")\n";
        } else {
            std::cout << "(local.get $" << tree->data << ")\n";
        }
        
    }
    else if (tree->type == ADD)
    {
        expression_evaluation(tree->children[0], bc);
        expression_evaluation(tree->children[1], bc);
        std::cout << "i32.add\n";
    }
    else if (tree->type == SUB)
    {
        expression_evaluation(tree->children[0], bc);
        expression_evaluation(tree->children[1], bc);
        std::cout << "i32.sub\n";
    }
    else if (tree->type == MULT)
    {
        expression_evaluation(tree->children[0], bc);
        expression_evaluation(tree->children[1], bc);
        std::cout << "i32.mul\n";
    }
    else if (tree->type == DIV)
    {
        expression_evaluation(tree->children[0], bc);
        expression_evaluation(tree->children[1], bc);
        std::cout << "i32.div_s\n";
    }
    else if (tree->type == MOD)
    {
        expression_evaluation(tree->children[0], bc);
        expression_evaluation(tree->children[1], bc);
        std::cout << "i32.rem_s\n";
    }
    else if (tree->type == NEG)
    {
        std::cout << "(i32.const -1)\n";
        expression_evaluation(tree->children[0], bc);
        std::cout << "i32.mul\n";
    }
    else if (tree->type == FUNC_INVOKE)
    {
        function_call(tree, bc);
    }

    // COMPARISONS
    else if (tree->type == LT)
    {
        expression_evaluation(tree->children[0], bc);
        expression_evaluation(tree->children[1], bc);
        std::cout << "i32.lt_s\n";
    }
    else if (tree->type == GT)
    {
        expression_evaluation(tree->children[0], bc);
        expression_evaluation(tree->children[1], bc);
        std::cout << "i32.gt_s\n";
    }
    else if (tree->type == LTE)
    {
        expression_evaluation(tree->children[0], bc);
        expression_evaluation(tree->children[1], bc);
        std::cout << "i32.le_s\n";
    }
    else if (tree->type == GTE)
    {
        expression_evaluation(tree->children[0], bc);
        expression_evaluation(tree->children[1], bc);
        std::cout << "i32.ge_s\n";
    }
    else if (tree->type == EQ)
    {
        expression_evaluation(tree->children[0], bc);
        expression_evaluation(tree->children[1], bc);
        std::cout << "i32.eq\n";
    }
    else if (tree->type == NEQ)
    {
        expression_evaluation(tree->children[0], bc);
        expression_evaluation(tree->children[1], bc);
        std::cout << "i32.ne\n";
    }

    // BOOLEAN
    else if (tree->type == BOOL)
    {
        if (tree->data.compare("true") == 0)
        {
            std::cout << WA_TRUE;
        }
        else
        {
            std::cout << WA_FALSE;
        }
    }
    else if (tree->type == AND)
    {
        // A && B
        // Only evaluate B if A is true
        expression_evaluation(tree->children[0], bc);
        std::cout << WA_FALSE
                  << "i32.ne\n";
        std::cout << "if (result i32)\n";
        expression_evaluation(tree->children[1], bc);
        std::cout << "else\n";
        std::cout << WA_FALSE;
        std::cout << "end\n";
    }
    else if (tree->type == OR)
    {
        // A || B
        // Only evaluate B if A is false
        expression_evaluation(tree->children[0], bc);
        std::cout << WA_FALSE
                  << "i32.eq\n";
        std::cout << "if (result i32) \n";
        expression_evaluation(tree->children[1], bc);
        std::cout << "else\n";
        std::cout << WA_TRUE;
        std::cout << "end\n";
    }
    else if (tree->type == NOT)
    {
        expression_evaluation(tree->children[0], bc);
        std::cout << "i32.eqz\n"
                  << "if (result i32) \n"
                  << WA_TRUE
                  << "\nelse\n"
                  << WA_FALSE
                  << "\nend\n";
    } else if (tree->type == ASSIGNMENT) {
        expression_evaluation(tree->children[1], bc);
        if (std::find(bc->globals.begin(), bc->globals.end(), tree->children[0]->data) != bc->globals.end()) {
            std::cout << "(global.set $" << tree->children[0]->data << ")\n";
            std::cout << "(global.get $" << tree->children[0]->data << ")\n";
        } else {
            std::cout << "(local.set $" << tree->children[0]->data << ")\n";
            std::cout << "(local.get $" << tree->children[0]->data << ")\n";
        }
    }
    // else {
    //     for(long unsigned int i = 0; i < tree->children.size(); i++) {
    //         expression_evaluation(tree->children[i]);
    //     }
    // }
}

// Probably super insecure

void add_prologue(AST *tree)
{
    const std::string runtime = R"(
  (import "host" "exit" (func $exit))
  (import "host" "getchar" (func $getchar (result i32)))
  (import "host" "putchar" (func $putchar (param i32)))

  (func $printi (param $num i32)
    (local.get $num)
    (i32.const 0)
    (i32.lt_s)
    if
      (i32.const 45)
      (call $putchar)

      (local.get $num)
      (i32.const -1)
      (i32.mul)

      call $printi_u
    else
      (local.get $num)
      call $printi_u
    end
  )
  (func $printi_u (param $num i32)
    (local.get $num)
    (i32.const 0)
    i32.ne
    if
        (local.get $num)
        (i32.const 10)
        i32.div_u
        call $printi

        (local.get $num)
        (i32.const 10)
        i32.rem_u

        i32.const 48
        i32.add 
        call $putchar
    end
  )
  (func $printb (param $bool i32) 
    (local.get $bool)
    i32.eqz
    if
      i32.const 116
      call $putchar
      i32.const 114
      call $putchar
      i32.const 117
      call $putchar
      i32.const 101
      call $putchar
    else
      i32.const 102
      call $putchar
      i32.const 97
      call $putchar
      i32.const 108
      call $putchar
      i32.const 115
      call $putchar
      i32.const 101
      call $putchar
    end
  )
  (func $printc (param $char i32)
    (local.get $char)
    call $putchar
  )
  (func $prints (param $string_index i32) (param $string_offeset i32)
    (local $string_counter i32)
    (local.get $string_index)
    (local.set $string_counter)

    (block $B
      (loop $L
      (local.get $string_counter)
      (local.get $string_offeset)
      (i32.eq)
      br_if $B

      (local.get $string_counter)
      (i32.load)
      (call $putchar)

      (i32.const 1)
      (local.get $string_counter)
      (i32.add)
      (local.set $string_counter)

      br $L
      )
    )
  )
  (func $halt
    call $exit
  )

                  )";

    std::cout << runtime;
}

void function_header(AST *dec)
{
    AST *type = dec->children[0]->children[0];
    AST *declar = dec->children[0]->children[1];

    if (declar->children.size() > 1)
    {
        std::cout << "(func $" << declar->children[0]->data << " ";
        AST *params = declar->children[1];
        for (long unsigned int i = 0; i < params->children.size(); i++)
        {
            std::cout << "(param $" << params->children[i]->children[1]->data << " i32) ";
        }
    }
    else
    {
        std::cout << "(func $" << declar->data << " ";
    }
    std::cout << "\n";
    if (type->type != VOID)
    {
        std::cout << "(result i32)\n";
    }
}

void function_varaibles(AST *tree)
{
    if (tree->type == VAR_DEC)
    {
        std::cout << "(local $" << tree->children[1]->data << " i32)\n";
    }
    else
    {
        for (long unsigned int i = 0; i < tree->children.size(); i++)
        {
            function_varaibles(tree->children[i]);
        }
    }
}