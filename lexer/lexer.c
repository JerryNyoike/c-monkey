#include <stdio.h>
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
void readChar(Lexer *lx)
{
	// check that we are not at the end of the input
	if (lx->readPosition >= strlen(lx->input))
		return;
	else
		lx->ch = *(lx->input + lx->readPosition);
	lx->position = lx->readPosition++;
}

/* readNumber : */
Identifier readNumber (Lexer lx)
{
	Identifier num = newIdentifier();
	num.start = lx.input + lx.position;
	while (isdigit(lx.ch))
		readChar(&lx);
	num.end = lx.input + lx.position;

	return num;
}

/* readIdentifier: read an identifier up until the first space is encountered */
Identifier readIdentifier(Lexer lx)
{
	Identifier id = newIdentifier();
	id.start = lx.input + lx.position;
	while (isalpha(lx.ch))
		readChar(&lx);
	id.end = lx.input + lx.position;

	return id;
}

/* newLexer : returns a Lexer struct */
Lexer newLexer(char *input)
{
	Lexer lx;
	lx.input = input;
	lx.position = 0;
	lx.readPosition = lx.position;
	readChar(&lx);
	return lx;
}

/* newToken : returns a token struct */
void newToken(Token *tk, int tokenType, char *ch)
{
	tk->Type = tokenType;
	tk->Literal = ch;
}

/* isLetter: */
int isLetter(char ch)
{
	return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || (ch == '_');
}

/* consumeWhitespace : skip whitespace characters */
void consumeWhitespace(Lexer *lx)
{
	while (isspace(lx->ch))
		readChar(lx);
}

/* nextToken : return token depending on char under examination */
Token nextToken(Lexer lx)
{
	Token tk;
	initToken(&tk);

	consumeWhitespace(&lx);

	switch (lx.ch) {
		case '=':
			newToken(&tk, ASSIGN, &lx.ch);
			break;
		case ';':
			newToken(&tk, SEMICOLON, &lx.ch);
			break;
		case '(':
			newToken(&tk, LPAREN, &lx.ch);
			break;
		case ')':
			newToken(&tk, RPAREN, &lx.ch);
			break;
		case ',':
			newToken(&tk, COMMA, &lx.ch);
			break;
		case '+':
			newToken(&tk, PLUS, &lx.ch);
			break;
		case '{':
			newToken(&tk, LBRACE, &lx.ch);
			break;
		case '}':
			newToken(&tk, LBRACE, &lx.ch);
			break;
		case 0:
			newToken(&tk, _EOF, "");
			break;
		default:
			if (isLetter(lx.ch)) {
				Identifier id = readIdentifier(lx);
				newToken(&tk, lookupIdentifier(tk.Literal), memcpy(tk.Literal, id.start, (id.end-id.start)));
				return tk;
			} else if (isdigit(lx.ch)) {
				Identifier num = readNumber(lx);
				newToken(&tk, INT, memcpy(tk.Literal, num.start, (num.end-num.start)));
				return tk;
			} else {
				 newToken(&tk, ILLEGAL, &lx.ch);
			}
			break;
	}

	readChar(&lx);
	return tk;
}
