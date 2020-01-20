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

	Token token = { ASSIGN, "="};
	Token t;
	Lexer l = newLexer(input);
	printf("char: %c\n", l.ch);
	t = nextToken(l);
	_assert(t.Type == token.Type);
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
