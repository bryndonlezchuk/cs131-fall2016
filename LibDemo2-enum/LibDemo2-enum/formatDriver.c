//----------------------------------------------------------------------------
// driver to test enums
//----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "fontFormat.h"
//----------------------------------------------------------------------------
// etst driver to test enum textFormat
//----------------------------------------------------------------------------
int main(void)
{
	unsigned char form = (unsigned char)(B | U | SUB);

	printf("The format U is");
	if(!(form & U)) // true if B is set
		printf(" not"); 
	puts(" set");
	form |= STRIKE;
	puts("The formats set are:");
	printFormats(form);
	form &= ~U;  // turn off underline	
	puts("The formats set are:");
	printFormats(form);

	getchar();
	return EXIT_SUCCESS;
}