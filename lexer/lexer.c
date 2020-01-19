#include <string.h>
#include <ctype.h>
#include "../monkey.h"

/* newIdentifier : return an initialized identifier struct */
Identifier newIdentifier ()
{
	Identifier id;
	id.start = NULL;
	id.end = NULL;
	return id;
}

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

/* readNumber : */
Identifier readNumber (Lexer lx)
{
	Identifier num = newIdentifier();
	num.start = lx.input + lx.position;
	while (isdigit(lx.ch))
		readChar(lx);
	num.end = lx.input + lx.position;

	return num;
}

/* readIdentifier: read an identifier up until the first space is encountered */
Identifier readIdentifier(Lexer lx)
{
	Identifier id = newIdentifier();
	id.start = lx.input + lx.position;
	while (isalpha(lx.ch))
		readChar(lx);
	id.end = lx.input + lx.position;

	return id;
}

/* newLexer : returns a Lexer struct */
Lexer newLexer(char *input)
{
	Lexer lx;
	lx.input = input;
	readChar(lx);
	return lx;
}

/* newToken : returns a token struct */
Token newToken(int tokenType, char *ch)
{
	Token tk;
	tk.Type = tokenType;
	tk.Literal = ch;
	return tk;
}

/* isLetter: */
int isLetter(char ch)
{
	return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || (ch == '_');
}

/* consumeWhitespace : skip whitespace characters */
void consumeWhitespace(Lexer lx)
{
	while (isspace(lx.ch))
		readChar(lx);
}

/* nextToken : return token depending on char under examination */
Token nextToken(Lexer lx)
{
	Token tk = initToken();

	consumeWhitespace(lx);

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
			tk.Type = _EOF;
			break;
		default:
			if (isLetter(lx.ch)) {
				Identifier id = readIdentifier(lx);
				memcpy(tk.Literal, id.start, (id.end-id.start));
				tk.Type = lookupIdentifier(tk.Literal);

				return tk;
			} else if (isdigit(lx.ch)) {
				tk.Type = INT;
				Identifier num = readNumber(lx);
				memcpy(tk.Literal, num.start, (num.end-num.start));

				return tk;
			} else {
				tk = newToken(ILLEGAL, &lx.ch);
			}
			break;
	}

	readChar(lx);
	return tk;
}
