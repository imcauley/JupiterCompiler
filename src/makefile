# Makefile

BIN_DIR	= ../bin/
HEAD_DIR = ../headers/
PARSER_DIR	= ./parser/
SCANNER_DIR	= ./scanner/
DATA_DIR = ./data/
GEN_DIR = ./codegen/

CC	= g++
CFLAGS	= -DDEBUG -g -Wall -ansi -pedantic -I$(HEAD_DIR) -Wno-write-strings

LOGIC = $(BIN_DIR)main.o $(BIN_DIR)bison.o $(BIN_DIR)lex.o $(BIN_DIR)semantics.o $(BIN_DIR)codegen.o
DATA = $(BIN_DIR)tokens.o $(BIN_DIR)ast.o $(BIN_DIR)token_map.o $(BIN_DIR)symbol_table.o

OBJS = $(LOGIC) $(DATA)

compiler:		$(OBJS)
		$(CC) -DYYDEBUG $(CFLAGS) $(OBJS) -o ../compiler -lfl

$(BIN_DIR)lex.o:	lex.yy.c
		$(CC) $(CFLAGS) -c $(SCANNER_DIR)lex.yy.c -o $(BIN_DIR)lex.o

lex.yy.c:	$(SCANNER_DIR)scan.l 
		flex $(SCANNER_DIR)scan.l
		@ mv lex.yy.c $(SCANNER_DIR)lex.yy.c

$(BIN_DIR)bison.o:	bison.c
		$(CC) -DYYDEBUG -DYYTRACE $(CFLAGS) -c $(PARSER_DIR)bison.c -o $(BIN_DIR)bison.o

$(BIN_DIR)tokens.o:	tokens.c
		$(CC) $(CFLAGS) -c tokens.c -o $(BIN_DIR)tokens.o

bison.c:	$(PARSER_DIR)parse.y
	bison --debug -d -v -b $(PARSER_DIR)parse $(PARSER_DIR)parse.y 
	@ cp $(PARSER_DIR)parse.tab.c $(PARSER_DIR)bison.c
	@ cp $(PARSER_DIR)parse.tab.h $(HEAD_DIR)parse.h

${BIN_DIR}token_map.o:
	python3 $(PARSER_DIR)convert_tokens.py
	$(CC) $(CFLAGS) -c $(PARSER_DIR)token_map.c -o $(BIN_DIR)token_map.o

$(BIN_DIR)main.o:	main.cpp
		$(CC) $(CFLAGS) -c main.cpp -o $(BIN_DIR)main.o

$(BIN_DIR)ast.o:	$(DATA_DIR)ast.cpp  ${BIN_DIR}token_map.o
	$(CC) $(CFLAGS) -c $(DATA_DIR)ast.cpp -o $(BIN_DIR)ast.o

$(BIN_DIR)semantics.o: $(DATA_DIR)semantics.cpp $(BIN_DIR)ast.o $(BIN_DIR)bison.o $(BIN_DIR)symbol_table.o
	$(CC) $(CFLAGS) -c $(DATA_DIR)semantics.cpp -o $(BIN_DIR)semantics.o

$(BIN_DIR)symbol_table.o: $(DATA_DIR)symbol_table.cpp $(BIN_DIR)ast.o $(BIN_DIR)bison.o
	$(CC) $(CFLAGS) -c $(DATA_DIR)symbol_table.cpp -o $(BIN_DIR)symbol_table.o

$(BIN_DIR)codegen.o:	$(GEN_DIR)codegen.cpp $(BIN_DIR)ast.o $(BIN_DIR)bison.o $(BIN_DIR)symbol_table.o $(BIN_DIR)outbuffer.o
	$(CC) $(CFLAGS) -c $(GEN_DIR)codegen.cpp -o $(BIN_DIR)codegen.o

lex.o yac.o main.o	: $(HEAD_DIR)heading.h
lex.o main.o bison.c 	: $(HEAD_DIR)tokens.h

clean:
	rm -f *.o *~ lex.c lex.yy.c bison.c tok.h pasrse.tab.c pasrse.tab.h compiler.output compiler