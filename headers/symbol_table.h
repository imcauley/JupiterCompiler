#ifndef SYM_M
#define SYM_M

#include "parse.h"
#include <map> 
#include <vector>
#include <string>

typedef struct symbol {
    std::string id;
    int type;
} symbol;

typedef std::map<std::string,symbol*> scope;
typedef std::pair<std::string,symbol*> scope_pair;

typedef struct sym_table {
    std::vector<scope*> scope_stack;

} sym_table;


void    open_scope(sym_table *table);
void    exit_scope(sym_table *table);
bool    type_exists(sym_table* table, int type);
symbol* get_symbol(sym_table *table, std::string id);
symbol* get_symbol_in_scope(sym_table *table, std::string id);
bool    add_symbol(sym_table *table, symbol *sym);
#endif