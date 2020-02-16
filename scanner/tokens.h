#ifndef TOKENS
#define TOKENS

#include <stdio.h>

typedef enum{
    TYPE_DEF = 0,

    OPEN_PAREN,
    END_PAREN,
    OPEN_BRACE,
    END_BRACE,

    SEMICOLON,
    COMMA,

    INT_OP,
    BOOL_OP_BIN,
    BOOL_OP_UN,
    EQUALITY,
    ASSIGNMENT,

    IDENTIFIER,

    BOOL_LIT,
    STR_LIT,
    INT_LIT,

    IF_TOK,
    ELSE_TOK,
    WHILE_TOK,
    BREAK_TOK,
    RETURN_TOK
} Token;

void output_token(Token t, int lineno, const char* text);
const char* token_to_string(Token t);
#endif