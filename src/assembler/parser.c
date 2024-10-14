/**
 * @file parser.c
 * @copyright (c) 2024 Toru Yamanaka
 */
#include "parser.h"

#include "ctype.h"
#include "string.h"

#define LINE_LIMITS 256

typedef struct Parser {
  FILE* fp;
  char line[LINE_LIMITS];
} Parser_t;

static Parser_t parser;

static bool IsEOF(void);

static bool IsValidLine(const char* line);

void Parser_Init(FILE* fp) { parser.fp = fp; }

bool Parser_HasMoreCommands(void) { return !IsEOF(); }

void Parser_Advance(void) {
  while (fgets(parser.line, LINE_LIMITS, parser.fp)) {
    if (IsValidLine(parser.line)) {
      break;
    }
  }
}

Parser_CommandType_t Parser_CommandType(void);

const char* Parser_Symbol(void);

const char* Parser_Dest(void);

const char* Parser_Comp(void);

const char* Parser_Jump(void);

static bool IsEOF(void) {
  if (!parser.fp) {
    fprintf(stderr, "error: File pointer is NULL\n");

    return true;
  }

  long pos = ftell(parser.fp);

  int c = fgetc(parser.fp);
  if (c != EOF) {
    fseek(parser.fp, pos, SEEK_SET);

    return false;
  } else if (ferror(parser.fp)) {
    perror("error: Failed to read a character");
  }

  return true;
}

static bool IsValidLine(const char* line) {
  if (!line || *line == '\0') {
    return false;
  }

  while (isspace(*line)) {
    line++;
  }

  if (*line == '\0') {
    return false;
  }

  return (strncmp(line, "//", 2) != 0);
}
