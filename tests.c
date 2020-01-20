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
	char *input = "=+(){},;";

	Token tokens[] = {
		{ ASSIGN, "=" },
		{ PLUS, "+" },
		{ LPAREN, "(" },
		{ RPAREN, ")" },
		{ LBRACE, "{" },
		{ RBRACE, "}" },
		{ COMMA, "," },
		{ SEMICOLON, ";" }
	};

	Token t;
	Lexer l = newLexer(input);
	int i = 0;
	int numtokens = (sizeof tokens) / (sizeof t);
	while(i <= numtokens-1) {
		nextToken(&l, &t);
		printf("%d\n", t.Type);
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
