#define FUNCTION "FUNCTION"
#define LET "LET"

typedef struct Token {
	int Type;
	char *Literal;	
} Token;

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
