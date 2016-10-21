//----------------------------------------------------------------------------
// File: argcv.c
// Functions:
//		int main(int argc, char *argv[])
//----------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#pragma warning(disable: 4996) 
//----------------------------------------------------------------------------
// Sample Code showing command line parameters and file handles
// CS& 131
//----------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	int firstPass = 1; // 1=true; 0=false
	int numElements = 0;
	int currentElement = 0;
	int totalNumElements = 0;
	int sumOfElements = 0;
	int lowElement = 0;
	int highElement = 0;
	float meanOfElements = 0.0f;
	float varianceOfElements = 0.0f;
	float deviationOfElements = 0.0f;


	FILE * inFileHandle = NULL;
	FILE * outFileHandle = NULL;
	char filename[FILENAME_MAX] = "";
	char c = ' ';
	int returnValue = EXIT_SUCCESS;
	if (argc > 1)
	{
		strncpy(filename, argv[1], FILENAME_MAX);
	}
	else
	{
		puts("Enter the name of the file to read (source):");
		fgets(filename, FILENAME_MAX, stdin);
		if (filename[strlen(filename) - 1] == '\n')
			filename[strlen(filename) - 1] = '\0';
		else
			while (getchar() != '\n')
				;
	}

	inFileHandle = fopen(filename, "r");
	if (inFileHandle == NULL)
	{
		printf("Could not open file %s for input.\n"
			"Press any key to Continue", filename);
		getch();
		returnValue = EXIT_FAILURE;
	}
	else
	{
		if (argc > 2)
		{
			strncpy(filename, argv[2], FILENAME_MAX);
		}
		else
		{
			puts("Enter the name of the file to write (output):");
			// gets() - not safe! (potential buffer overflow)
			fgets(filename, FILENAME_MAX, stdin);
			if (filename[strlen(filename) - 1] == '\n')
				filename[strlen(filename) - 1] = '\0';
			else
				while (getchar() != '\n')
					;
		}

		outFileHandle = fopen(filename, "w");
		if (outFileHandle == NULL)
		{
			fclose(inFileHandle);
			printf("Could not open file %s for output.\n"
				"Press any key to Continue", filename);
			getch();
			returnValue = EXIT_FAILURE;
		}
		else
		{
			//while ((c = (char)getc(inFileHandle)) != EOF)
			//{
			//	//if (c == ' ')
			//	//	c = '\n';
			//	//putc(c, outFileHandle);
			//}

			while ((fscanf(inFileHandle, "%d", &numElements)) == 1)
			{
				for (int i = 0; i < numElements; i++)
				{
					totalNumElements++;
					fscanf(inFileHandle, "%d", &currentElement);

					if (firstPass)
					{
						lowElement, highElement = currentElement;
					}
					else if (currentElement < lowElement)
					{
						lowElement = currentElement;
					}
					else if (currentElement > highElement)
					{
						highElement = currentElement;
					}


				}
			}

			fclose(inFileHandle);
			fclose(outFileHandle);
			puts("\nPress any key to Continue");
			getch();
		}
	}
	return returnValue;
}
