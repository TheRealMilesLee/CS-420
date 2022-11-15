/* Hengyi Li*/
%{
  /* Inclue the DEFINE file*/
#include "Scanner.h"
%}
%option nounput yylineno

/* Find a symbol for each type of token that is in the input file */
%%
:         return COLON;
"Listen"     return LISTEN_PORT;
"ServerName"     return SERVER_NAME;
"LogLevel" return LOG_LEVEL;
"PHPIniDir"     return PHP_INI_DIR;

[a-zA-Z+-][_a-zA-Z0-9+-]* return IDENTIFIER;
[1-9][0-9]*       return INTEGER;
[ \t\n]         ;
.         printf("unexpected character\n");
%%

/* Connection to the C program */
int yywrap()
{
  return 1;
}
