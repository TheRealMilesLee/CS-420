%{
#include "Scanner.h"
%}
%option nounput yylineno

%%
:         return COLON;
"Listen"     return LISTEN_PORT;
"ServerName"     return SERVER_NAME;
"LogLevel" return LOG_LEVEL;
"PHPIniDir"     return PHP_INI_DIR;

[a-zA-Z][_a-zA-Z0-9]*return IDENTIFIER;
[0-9][0-9]*       return INTEGER;
[ \t\n]         ;
.         printf("unexpected character\n");
%%

int yywrap()
{
  return 1;
}
