/**
 * @file main.c
 * @copyright (c) 2024 Toru Yamanaka
 */
#include <stdio.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: assembler <file>\n");
    return -1;
  }

  return 0;
}
