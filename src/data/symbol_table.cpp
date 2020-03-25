#include "symbol_table.h"

void open_scope(sym_table* table) {
    scope *new_scope = new scope();
    table->scope_stack.push_back(new_scope);
}

void exit_scope(sym_table *table) {
    table->scope_stack.pop_back();
}

symbol* get_symbol(sym_table *table, std::string id) {
    for(int i = table->scope_stack.size() - 1; i >= 0; i--) {
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
    (table->scope_stack.back())->insert( scope_pair(sym->id, sym) );
    return true;
}
