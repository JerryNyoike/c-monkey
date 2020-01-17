#include <stdlib.h>
#define FUNCTION "FUNCTION"
#define LET "LET"

typedef struct Token {
	int Type;
	char *Literal;	
} Token;

/* initToken: set the Literal to NULL to ensure it's always initialised */
Token initToken()
{
	Token tk;
	tk.Literal = NULL;
	return tk;
}

enum {
	EOF,
	ILLEGAL,
	
	// Identifiers + literals
	IDENT,
	INT,

	// Operators
	ASSIGN,
	PLUS,

	// Delimiters
	COMMA,
	SEMICOLON,

	LPAREN,
	RPAREN,
	LBRACE,
	RBRACE,
};
