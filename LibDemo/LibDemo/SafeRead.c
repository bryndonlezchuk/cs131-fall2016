#include "SafeRead.h"
//----------------------------------------------------------------------------
// safely reads in an int -- prompts until proper input received
//----------------------------------------------------------------------------
void safeReadInt(int* number_ptr, const char* prompt)
{
	while((scanf("%d", number_ptr)) != 1)
	{
		puts(prompt);
		cleanBuffer();
	}
	cleanBuffer();
}

//----------------------------------------------------------------------------
// safely reads in a double -- prompts until proper input received
//----------------------------------------------------------------------------
void safeReadDouble(double* number_ptr, const char* prompt)
{
	while((scanf("%lf", number_ptr)) != 1)
	{
		puts(prompt);
		cleanBuffer();
	}
	cleanBuffer();
}


//----------------------------------------------------------------------------
// reads past '\n' in stdin
//----------------------------------------------------------------------------
void cleanBuffer()
{	
	while(getchar() != '\n')
		;
}

