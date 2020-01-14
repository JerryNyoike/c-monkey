#include <string.h>
#include "../token/tokens.c"

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

/* newToken : */
Token newToken(int tokenType, char *ch)
{
	Token tk;
	tk.Type = tokenType;
	tk.Literal = ch;
	return tk;
}

/* nextToken : return token depending on char under examination */
Token nextToken(Lexer lx)
{
	Token tk;

	switch (lx.ch) {
		case '=':
			tk = newToken(ASSIGN, &lx.ch);
			break;
		case ';':
			tk = newToken(SEMICOLON, &lx.ch);
			break;
		case '(':
			tk = newToken(LPAREN, &lx.ch);
			break;
		case ')':
			tk = newToken(RPAREN, &lx.ch);
			break;
		case ',':
			tk = newToken(COMMA, &lx.ch);
			break;
		case '+':
			tk = newToken(PLUS, &lx.ch);
			break;
		case '{':
			tk = newToken(LBRACE, &lx.ch);
			break;
		case '}':
			tk = newToken(LBRACE, &lx.ch);
			break;
		case 0:
			tk.Literal = "";
			tk.Type = EOF;
	}

	readChar(lx);
	return tk;
}
