#include <stdlib.h>

/* LANGUAGE SYMBOLS */
enum symbols {
	_EOF,
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

/* STRUCTURES */

typedef struct Lexer {
		char *input;
		int position;		// current position in input
		int readPosition;	// current reading position in input
		char ch;			// current character under examination
} Lexer;

typedef struct Token {
	int Type;
	char *Literal;	
} Token;

typedef struct Identifier {
	char *start;
	char *end;
} Identifier;

/* newIdentifier : return an initialized identifier struct */
/* TODO: find better name for this struct as numbers also use it */
Identifier newIdentifier ();

/* lookupIdentifier : checks if an identifier is a keyword or not */
int lookupIdentifier(char *ident);

/* readChar : reads the next character in input, set readPosition to 0 if at end of input */
void readChar(Lexer *lx);

/* readNumber : */
Identifier readNumber(Lexer lx);

/* readIdentifier: read an identifier up until the first space is encountered */
Identifier readIdentifier(Lexer lx);

/* newLexer : returns a Lexer struct */
Lexer newLexer(char *input);

/* newToken : returns a token struct */
void newToken(Token *tk, int tokenType, char *ch);

/* isLetter: */
int isLetter(char ch);

/* consumeWhitespace : skip whitespace characters */
void consumeWhitespace(Lexer *lx);

/* nextToken : return token depending on char under examination */
Token nextToken(Lexer lx);

/* initToken: set the Literal to NULL to ensure it's always initialised */
void initToken(Token *tk);

/* lookupIdentifier : checks if an identifier is a keyword or not */
int lookupIdentifier(char *ident);
