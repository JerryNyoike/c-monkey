lexer: lexer/lexer.c
	gcc lexer/lexer.c -o lexer

tokens : token/tokens.c
	gcc token/tokens.c -o tokens

run_tests: tests.c
	gcc tests.c -o tests && ./tests
