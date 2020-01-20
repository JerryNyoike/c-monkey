monkey: monkey.h lexer/lexer.c token/tokens.c tests.c
	gcc lexer/lexer.c token/tokens.c monkey.h

test: monkey.h lexer/lexer.c token/tokens.c tests.c
	gcc tests.c lexer/lexer.c token/tokens.c monkey.h

run: test
	./a.out
