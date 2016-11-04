#include <stdio.h>
#include <stdlib.h>
#include "SafeRead.h"

//----------------------------------------------------------------------------
// test driver for SafeRead Library
//----------------------------------------------------------------------------
int main(void)
{
	int number1 = 0;
	double number2 = 0.0;

	puts("Please Enter a number!");
	safeReadDouble(&number2, "Must be a double!");

	puts("Please Enter a number!");
	safeReadInt(&number1, "Must be an int!");

	printf("number1: %d, number2: %.2f\n", number1, number2);

	getchar();
	return EXIT_SUCCESS;
}
