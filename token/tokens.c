#define FUNCTION "FUNCTION"
#define LET "LET"

typedef struct Token {
	char *Type;
	char *Literal;	
} Token;

enum {
	EOF = -1,
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
