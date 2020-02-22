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

    INT_EQ_OP,
    INT_ADD_OP,
    INT_MULT_OP,
    BOOL_OP_ADD,
    BOOL_OP_OR,
    BOOL_OP_UN,
    EQUALITY,
    ASSIGNMENT,

    IDENTIFIER,

    BOOL_LIT,
    STR_LIT,
    INT_LIT,

    IF,
    ELSE,
    WHILE,
    BREAK,
    RETURN
} Token;

void output_token(Token t, int lineno, const char* text);
const char* token_to_string(Token t);
#endif