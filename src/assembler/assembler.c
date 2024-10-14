/**
 * @file assembler.c
 * @copyright (c) 2024 Toru Yamanaka
 */
#include <error.h>
#include <stdio.h>
#include <string.h>

#include "parser.h"

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s file\n", argv[0]);

    return -1;
  }

  FILE *input_file = fopen(argv[1], "r");
  if (!input_file) {
    perror(argv[1]);

    return -1;
  }

  char output_file_name[256] = {};
  strncpy(output_file_name, argv[1], sizeof(output_file_name) - 1);
  output_file_name[sizeof(output_file_name) - 1] = '\0';
  char *dot = strrchr(output_file_name, '.');
  if (dot) {
    *dot = '\0';
  }
  snprintf(output_file_name + strlen(output_file_name),
           sizeof(output_file_name) - strlen(output_file_name), ".hack");

  FILE *output_file = fopen(output_file_name, "w");
  if (!output_file) {
    perror(output_file_name);
    fclose(input_file);

    return -1;
  }

  char buf[256] = {};
  while (fgets(buf, sizeof(buf), input_file)) {
    fprintf(output_file, "%s", buf);
  }

  fclose(input_file);
  fclose(output_file);

  return 0;
}
