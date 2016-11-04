//----------------------------------------------------------------------------
// fontFormat.h
//----------------------------------------------------------------------------
#ifndef FONTFORMAT_H
#define FONTFORMAT_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUMBER_OF_FORMATS 7

enum textFormat {NO_FORMAT, B, U, I = 4, STRIKE = 8, SUB = 16, SUP = 32};
typedef enum textFormat Format;

void printFormats(unsigned char format);

#endif