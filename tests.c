#include <stdio.h>
#include <string.h>
#include "monkey.h"

int testsRun = 0;

#define FAIL() printf("\nFailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return 1; } } while (0)
#define _verify(test) do { int r = test(); testsRun++; if(r) return r;} while(0)

/* TESTS */
int testNextToken()
{
	//char *input = "=+(){},;";
	char *input2 = "let five = 5;let ten = 10;     let add = fn(x, y) { x + y;};    let result = add(five, ten);}";

	Token tokens[] = {
		{ LET, "let" },
		{ IDENT, "five" },
		{ ASSIGN, "=" },
		{ INT, "5" },
		{ SEMICOLON, ";" },
		{ LET, "let" },
		{ IDENT, "ten" },
		{ ASSIGN, "=" },
		{ INT, "10"},
		{ SEMICOLON, ";" },
		{ LET, "let" },
		{ IDENT, "add" },
		{ ASSIGN, "=" },
		{ FUNCTION,"fn" },
		{ LPAREN, "(" },
		{ IDENT, "x" },
		{ COMMA, "," },
		{ IDENT, "y" },
		{ RPAREN, ")" },
		{ LBRACE, "{" },
		{ IDENT, "x" },
		{ PLUS, "+" },
		{ IDENT, "y" },
		{ SEMICOLON, ";" },
		{ RBRACE, "}" },
		{ SEMICOLON, ";" },
		{ LET, "let" },
		{ IDENT, "result" },
		{ ASSIGN, "=" },
		{ IDENT, "add" },
		{ LPAREN, "(" },
		{ IDENT, "five" },
		{ PLUS, "+" },
		{ IDENT, "ten" },
		{ SEMICOLON, ";" },
		{ _EOF, "" }
	};

	Token t;
	initToken(&t);
	Lexer l = newLexer(input2);
	int i = 0;
	int numtokens = (sizeof tokens) / (sizeof t);
	while(i <= numtokens) {
		nextToken(&l, &t);
		printf("%d\n", (int) strlen(t.Literal));
		_assert(t.Type == tokens[i++].Type);
	}
	return 0;
}

/* allTests: call all unit tests */
int all_tests() {
	_verify(testNextToken);
	return 0;
}

/* main: runs all the tests*/
int main()
{
	int result = all_tests();
	(result == 0 )? printf("PASSED\n") : printf("Tests run: %d\n", testsRun);

	return result != 0;
}
