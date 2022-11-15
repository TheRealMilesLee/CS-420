%{
#include "Scanner.h"
%}

%%
:         return COLON;
"LISTEN_PORT"     return LISTEN_PORT;
"SERVER_NAME"     return SERVER_NAME;
"LOG_LEVEL" return LOG_LEVEL;
"PHP_INI_DIR"     return PHP_INI_DIR;

[a-zA-Z][_a-zA-Z0-9]* return IDENTIFIER;
[1-9][0-9]*       return INTEGER;
[ \t\n]         ;
.         printf("unexpected character\n");
%%

int yywrap()
{
  return 1;
}
