#ifndef SEM_H
#define SEM_H

#include "parse.h"
#include <map> 
#include <vector>

typedef struct symbol {
    int id;
    int type;
} symbol;

typedef map<int,*symbol> scope;

typedef struct symbol_table {
    std::vector<*scope> scope_stack;

} symbol_table;



void open_scope();
#endif