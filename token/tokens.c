#include <stdlib.h>
#include <string.h>

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

	// Keywords
	LET,
	FUNCTION,
	
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

/* lookupIdentifier : checks if an identifier is a keyword or not */
int lookupIdentifier(char *ident)
{
	if (!strcmp(ident, "fn")) {
		return FUNCTION;
	} else if (!strcmp(ident, "let")) {
		return LET;
	} else {
		return IDENT;
	}
}
