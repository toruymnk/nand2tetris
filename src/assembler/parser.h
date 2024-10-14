/**
 * @file parser.h
 * @copyright (c) 2024 Toru Yamanaka
 */
#ifndef ASSEMBLER_PARSER_H_
#define ASSEMBLER_PARSER_H_

#include <stdbool.h>
#include <stdio.h>

typedef enum {
  kACommand,
  kCCommand,
} Parser_CommandType_t;

void Parser_Init(FILE* fp);

bool Parser_HasMoreCommands(void);

void Parser_Advance(void);

Parser_CommandType_t Parser_CommandType(void);

const char* Parser_Symbol(void);

const char* Parser_Dest(void);

const char* Parser_Comp(void);

const char* Parser_Jump(void);

#endif  // ASSEMBLER_PARSER_H_
