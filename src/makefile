# Makefile

BIN_DIR	= ../bin/
HEAD_DIR = ../headers/
PARSER_DIR	= ./parser/
SCANNER_DIR	= ./scanner/
DATA_DIR = ./data/

CC	= g++
CFLAGS	= -g -Wall -ansi -pedantic -I$(HEAD_DIR) -Wno-write-strings

OBJS	= $(BIN_DIR)bison.o $(BIN_DIR)lex.o $(BIN_DIR)main.o $(BIN_DIR)tokens.o $(BIN_DIR)ast.o

compiler:		$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(BIN_DIR)compiler -lfl

$(BIN_DIR)lex.o:	lex.yy.c
		$(CC) $(CFLAGS) -c $(SCANNER_DIR)lex.yy.c -o $(BIN_DIR)lex.o

lex.yy.c:		./scanner/scan.l 
		flex ./scanner/scan.l
		@ mv lex.yy.c $(SCANNER_DIR)lex.yy.c

$(BIN_DIR)bison.o:	bison.c
		$(CC) $(CFLAGS) -c $(PARSER_DIR)bison.c -o $(BIN_DIR)bison.o

$(BIN_DIR)tokens.o:	tokens.c
		$(CC) $(CFLAGS) -c tokens.c -o $(BIN_DIR)tokens.o

bison.c:	$(PARSER_DIR)parse.y
	bison -d -v -b $(PARSER_DIR)parse $(PARSER_DIR)parse.y 
	@ cp $(PARSER_DIR)parse.tab.c $(PARSER_DIR)bison.c
	@ cp $(PARSER_DIR)parse.tab.h $(HEAD_DIR)parse.h

$(BIN_DIR)main.o:		main.cc
		$(CC) $(CFLAGS) -c main.cc -o $(BIN_DIR)main.o

$(BIN_DIR)ast.o:	$(DATA_DIR)ast.cpp
	$(CC) $(CFLAGS) -c $(DATA_DIR)ast.cpp -o $(BIN_DIR)ast.o

lex.o yac.o main.o	: $(HEAD_DIR)heading.h
lex.o main.o bison.c 	: $(HEAD_DIR)tokens.h

clean:
	rm -f *.o *~ lex.c lex.yy.c bison.c tok.h pasrse.tab.c pasrse.tab.h compiler.output compiler