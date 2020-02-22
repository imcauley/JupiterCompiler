#include "tokens.h"

const char* TOKEN_STRINGS[] = {
			       "TYPE_DEF",

			       "OPEN_PAREN",
			       "END_PAREN",
			       "OPEN_BRACE",
			       "END_BRACE",

			       "SEMICOLON",
			       "COMMA",

			       "INT_OP",
			       "BOOL_OP_BIN",
			       "BOOL_OP_UN",
			       "EQUALITY",
			       "ASSIGNMENT",

			       "IDENTIFIER",

			       "BOOL_LIT",
			       "STR_LIT",
			       "INT_LIT",

			       "IF",
			       "ELSE",
			       "WHILE",
			       "BREAK",
			           "RETURN"
};

void output_token(Token t, int lineno, const char* text) {
  printf("%s %i %s\n", TOKEN_STRINGS[t], lineno, text);
}

const char* token_to_string(Token t) {
  return TOKEN_STRINGS[t];
}
