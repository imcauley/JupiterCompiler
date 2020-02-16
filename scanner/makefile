tokens.o: tokens.c tokens.h
	gcc -c -o tokens.o tokens.c

scanner.o: scan.l tokens.h
	flex scan.l
	gcc -c -o scanner.o -lfl lex.yy.c

scanner: scanner.o tokens.o
	gcc -o scanner tokens.o scanner.o
