#include "rtpreproc.h"
#include <string>
#include <iostream>  

void proccess_strings(AST *root, StringData *sd) {
    bool recurse = true;
    if(root->children.size() > 0) {
        if(root->type == EXPRESSION) {
            AST *tree = root->children[0];
            if(tree->type == STRING) {
                recurse = false;
                
                int length = tree->data.length();

                char* offset_ptr = &(std::to_string(sd->offset)[0]);
                char* length_ptr = &(std::to_string(sd->offset + length)[0]);
                AST *offset_data = make_new_node(NUMBER, offset_ptr, 0);
                AST *length_data = make_new_node(NUMBER, length_ptr, 0);

                sd->offset += length;

                sd->total_strings += "(data (i32.const ";
                sd->total_strings += offset_data->data;
                sd->total_strings += ") ";
                sd->total_strings += tree->data;
                sd->total_strings += ")\n";

                root->children.clear();

                root->type = ARG_LIST;
                root->data = "no data";
                add_child(root, offset_data);
                add_child(root, length_data);
            }
        }
    } 
    if(recurse)  {
        for(long unsigned int i = 0; i < root->children.size(); i++) {
            proccess_strings(root->children[i], sd);
        }
    }
}


void add_runetime(sym_table *sym) {
    symbol* prints = new symbol();
    prints->id = string("prints");
    prints->type = VOID;
    prints->exp_type = FUNC;
    prints->arguments.push_back(INT_DEC);
    prints->arguments.push_back(INT_DEC);
    add_symbol(sym, prints);

    symbol* printc = new symbol();
    printc->id = string("printc");
    printc->type = VOID;
    printc->exp_type = FUNC;
    printc->arguments.push_back(INT_DEC);
    add_symbol(sym, printc);

    symbol* printi = new symbol();
    printi->id = string("printi");
    printi->type = VOID;
    printi->exp_type = FUNC;
    printi->arguments.push_back(INT_DEC);
    add_symbol(sym, printi);

    symbol* printb = new symbol();
    printb->id = string("printb");
    printb->type = VOID;
    printb->exp_type = FUNC;
    printb->arguments.push_back(BOOL_DEC);
    add_symbol(sym, printb);

    symbol* halt = new symbol();
    halt->id = string("halt");
    halt->type = VOID;
    halt->exp_type = FUNC;
    add_symbol(sym, halt);

    symbol* getchar = new symbol();
    getchar->id = string("getchar");
    getchar->type = INT_DEC;
    getchar->exp_type = FUNC;
    add_symbol(sym, getchar);
}