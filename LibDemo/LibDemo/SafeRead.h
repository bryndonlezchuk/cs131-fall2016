#ifndef SAFEREAD_H
#define SAFEREAD_H
#include <stdio.h>
#pragma warning(disable: 4996)

void cleanBuffer();
void safeReadInt(int* number_ptr, const char* prompt);
void safeReadDouble(double* number_ptr, const char* prompt);

#endif
