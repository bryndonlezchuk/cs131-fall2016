//----------------------------------------------------------------------------
// fontFormat.c
//----------------------------------------------------------------------------


#include "fontFormat.h"
const char* formatStrings[] =
	{"NO_FORMAT", "B", "U", "I", "STRIKE", "SUB", "SUP"};
//----------------------------------------------------------------------------
// prints out which formats are set
//----------------------------------------------------------------------------
void printFormats(unsigned char format)
{
	unsigned char oneBit = B;  
	int i = 1;

	for(i = 1; i <= NUMBER_OF_FORMATS; i++, oneBit <<= 1) 
	{
		if(format & oneBit)
			printf("|%s| ", formatStrings[i]);
	}
	puts("");
}