#include "token/tokens.c"
#include <string.h>

typedef struct Lexer {
	char *input;
	int position;		// current position in input
	int readPosition;	// current reading position in input
	char ch;			// current character under examination
} Lexer;

/* readChar : reads the next character in input, set readPosition to 0 if at end of input */
void readChar(Lexer lx)
{
	if(lx.readPosition >= strlen(lx.input)) {
		lx.readPosition = 0;
	} else {
		lx.ch = *(lx.input + lx.readPosition);
	}
	
	lx.position = lx.readPosition;
	++lx.readPosition;
}

/* newLexer : returns a Lexer struct */
Lexer newLexer(char *input)
{
	Lexer lx;
	lx.input = input;
	readChar(lx);
	return lx;
}

