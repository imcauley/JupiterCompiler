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
                char* length_ptr = &(std::to_string(length)[0]);
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
    prints->type = FUNC;
    prints->exp_type = FUNC;
    prints->arguments.push_back(INT_DEC);
    prints->arguments.push_back(INT_DEC);
    add_symbol(sym, prints);
}