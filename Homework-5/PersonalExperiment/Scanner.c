#include "Scanner.h"
#include <stdio.h>

extern int yylex();
extern int yylineno;
extern char *yytext;

char *names[] = {NULL, "LISTEN_PORT", "SERVER_NAME", "LOG_LEVEL",
                 "PHP_INI_DIR"};

int main() {
  int name_token;
  int value_token;

  name_token = yylex();

  while (name_token) {
    printf("%d\n", name_token);
    name_token = yylex();
  }
  return 0;
}
