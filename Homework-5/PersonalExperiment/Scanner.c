#include "Scanner.h"
#include <stdio.h>

extern int yylex();
extern int yylineno;
extern char *yytext;

char *names[] = {NULL, "LISTEN_PORT", "SERVER_NAME", "LOG_LEVEL",
                 "PHP_INI_DIR"};

int main(void)
{
  int name_token, value_token;
  name_token = yylex();
  while (name_token)
  {
    printf("%d\n", name_token);
    if (yylex() != COLON)
    {
      printf("Syntax error in line %d, Expected a ':' but found %s\n", yylineno,
             yytext);
      return 1;
    }
    value_token = yylex();
    switch (name_token)
    {
    case LISTEN_PORT:
    case SERVER_NAME:
    case LOG_LEVEL:
      if (value_token != IDENTIFIER)
      {
        printf("Syntax error in line %d, Expected an identifier but found %s\n",
               yylineno, yytext);
        return 1;
      }
      printf("%s is set to %s\n", names[name_token], yytext);
      break;
    case PHP_INI_DIR:
      if (value_token != INTEGER)
      {
        printf("Syntax error in line %d, Expected an integer but found %s\n",
               yylineno, yytext);
        return 1;
      }
      printf("%s is set to %s\n", names[name_token], yytext);
      break;
    default:
      printf("Syntax error in line %d\n", yylineno);
    }
    name_token = yylex();
  }
  return 0;
}
