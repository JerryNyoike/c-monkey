#include <stdlib.h>
#include <string.h>
#include "../monkey.h"

/* initToken: set the Literal to NULL to ensure it's always initialised */
void initToken(Token *tk)
{
	tk->Literal = NULL;
}

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
