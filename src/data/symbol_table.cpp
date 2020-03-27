#include "symbol_table.h"
#include <iostream>

void open_scope(sym_table* table) {
    scope *new_scope = new scope();
    table->scope_stack.push_back(new_scope);
}

void exit_scope(sym_table *table) {
    table->scope_stack.pop_back();
}

symbol* get_symbol(sym_table *table, std::string id) {
    for(long unsigned int i = table->scope_stack.size() - 1; i >= 0; i--) {
        if( table->scope_stack[i]->count(id) > 0) {
            return (*(table->scope_stack[i]))[id];
        }
    }
    return NULL;
}

symbol* get_symbol_in_scope(sym_table *table, std::string id) {
    int s = table->scope_stack.size() - 1;
    if( table->scope_stack[s]->count(id) > 0) {
        return (*(table->scope_stack[s]))[id];
    }
    return NULL;
}

bool add_symbol(sym_table *table, symbol *sym) {
    ((table->scope_stack).back())->insert( scope_pair(sym->id, sym) );
    return true;
}

bool type_exists(sym_table *table, int type) {
    for(long unsigned int i = table->scope_stack.size() - 1; i >= 0; i--) {
        std::map<std::string, symbol*>::iterator it;
        for ( it = table->scope_stack[i]->begin(); it != table->scope_stack[i]->end(); it++ ){
            if(it->second->type == type) {
                return true;
            }
        }
    }

    return false;
}

void table_to_string(sym_table *table) {
    for(long unsigned int i = 0; i < table->scope_stack.size(); i++) {
        std::cout << "=================\n";
        std::map<std::string, symbol*>::iterator it;
        for ( it = table->scope_stack[i]->begin(); it != table->scope_stack[i]->end(); it++ ){
            std::cout << it->second->type << "\t" << it->second->id << "\n";
        }
    }
}