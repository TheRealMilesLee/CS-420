/**
 * @file simpleCompiler.c
 * @author Hengyi Li (hl3265@truman.edu) and Dr.Yu (cyyu@truman.edu)
 * @brief This file is to show a simple compiler that compile an integer
 * @version 0.1
 * @date 2022-08-31
 * @copyright Copyright (c) 2022. Truman State University. All rights reserve
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  // If the parameter is empty, throw error
  if (argc != 2)
  {
    fprintf(stderr, "Num of args is wrong");
    return 1;
  }

  // Read in a number from user and cast to integer
  int input_integer = atoi(argv[1]);
  printf(".intel_syntax noprefix\n");
  printf(".global main\n");
  printf("main:\n");
  printf("  mov rax, %d\n", input_integer);
  printf("  ret\n");
  return 0;
}
