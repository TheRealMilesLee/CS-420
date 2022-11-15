/**
 * @file Scanner.c
 * @author Hengyi Li and Dr.Yu
 * @brief This file is the lexical scanner
 * @version 0.1
 * @date 2022-11-14
 * @copyright Copyright (c) 2022. Hengyi Li, All rights reserved
 */
#include "Scanner.h"
#include <stdio.h>

/* A declaration of the functions and variables defined in the lexical analyzer. */
extern int yylex();
extern int yylineno;
extern char *yytext;

/* A global variable that is used to store the names of the tokens. */
char *names[] = {NULL, "LISTEN_PORT", "SERVER_NAME", "LOG_LEVEL", "PHP_INI_DIR"};

int main(void)
{
  /* Getting the token from the lexical analyzer. */
  int name_token, value_token;
  name_token = yylex();
  /* Checking if the token is valid. */
  while (name_token)
  {
    /* Checking if the token is valid. */
    printf("name token is %d\n", name_token);
    if (yylex() != COLON)
    {
      printf("Syntax error in line %d, Expected a ':' but found %s\n", yylineno,
             yytext);
      return 1;
    }
    value_token = yylex();
    /* Checking if the value token is an integer. */
    switch (name_token)
    {
    case LISTEN_PORT:
      if (value_token != INTEGER)
      {
        printf("Syntax error in line %d, Expected an integer but found %s\n",
               yylineno, yytext);
        return 1;
      }
      printf("%s is set to %s\n", names[name_token], yytext);
      break;
    /* Checking if the value token is an identifier. */
    case SERVER_NAME:
    case LOG_LEVEL:
    case PHP_INI_DIR:
      if (value_token != IDENTIFIER)
      {
        printf("Syntax error in line %d, Expected an identifier but found %s\n",
               yylineno, yytext);
        return 1;
      }
      printf("%s is set to %s\n", names[name_token], yytext);
      break;
      /* A default case for the switch statement. */
    default:
      printf("Syntax error in line %d\n", yylineno);
    }
    /* Getting the token from the lexical analyzer. */
    name_token = yylex();
  }
  return 0;
}
