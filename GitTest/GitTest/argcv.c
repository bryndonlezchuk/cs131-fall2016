//----------------------------------------------------------------------------
// File: argcv.c
// Functions:
//		int main(int argc, char *argv[])
//----------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#pragma warning(disable: 4996) 
//----------------------------------------------------------------------------
// Sample Code showing command line parameters and file handles
// CS& 131
//----------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	FILE * inFileHandle = NULL;
	FILE * outFileHandle = NULL;
	char filename[FILENAME_MAX] = "";
	char c = ' ';
	if(argc > 1)
	{
		strncpy(filename, argv[1], FILENAME_MAX);
	}
	else
	{
		puts("Enter the name of the file to read (source):");
		fgets(filename, FILENAME_MAX, stdin);
		if(filename[strlen(filename) - 1] == '\n')
			filename[strlen(filename) - 1] = '\0';
		else
			while(getchar() != '\n')
				;
	}
	
	inFileHandle = fopen(filename, "r");
	if(inFileHandle == NULL)
	{
		printf("Could not open file %s for input.\n"
			"Press any key to Continue", filename );
		getch();
		returnValue = EXIT_FAILURE;
	}
	if(argc > 2)
	{
		strncpy(filename, argv[2], FILENAME_MAX);
	}
	else
	{
		puts("Enter the name of the file to write (output):");
		gets(filename); // not safe! (potential buffer overflow)
	}

	outFileHandle = fopen(filename, "a");
	if(outFileHandle == NULL)
	{
		fclose(inFileHandle);
		printf("Could not open file %s for output.\n"
			"Press any key to Continue", filename );
		getch();
		return EXIT_FAILURE;
	}

	while((c = (char)getc(inFileHandle)) != EOF)
	{
		if(c == ' ')
			c = '\n';
		putc(c, outFileHandle);
	}
	fclose(inFileHandle);
	fclose(outFileHandle);
	puts("\nPress any key to Continue");
	getch();
	return EXIT_SUCCESS;
}
