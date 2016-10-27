//----------------------------------------------------------------------------
// File: StandardDeviation.c
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
// Function:	main() 
//
// Title:		Project2
//
// Description:	Standard Deviation
//
//
// Programmer:	Bryndon Lezchuk (bryndonlezchuk@gmail.com)
//
// Date:		9/27/16
//
// Version:		1.00
//
// Environment:	Intel Core i5
//				Software: OS: Windows 10 
//				Compiles under Microsoft Visual Studio 2015
//
//				Intel Core i7
//				Software: OS: Windows 7
//				Compiles under Microsoft Visual Studio 2015 Community
// 
// Input:		- user inputs the filename to read data from
//				- user inputs the filename to write output to
//
// Output:		To a file:
//				- number of data
//				- sum of data
//				- range of data
//				- mean of data
//				- variance
//				- standard deviation
//
// Calls:		
//
// Parameters:	int argc, char *argv[]
//
// Returns:		EXIT_SUCCESS for successful completion 
//				EXIT_FAILURE for failed completion
//
// History Log:
//				10/11/16	bcl		started version 1.0
//				10/23/16	bcl		finished version 1.0
//----------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	int firstPass = 1; // 1=true; 0=false
	int numElements = 0;
	int currentElement = 0;
	int totalNumElements = 0;
	int sumOfElements = 0;
	int sumOfElementsSquares = 0;
	int lowElement = 0;
	int highElement = 0;
	float meanOfElements = 0.0f;
	float varianceOfElements = 0.0f;
	double deviationOfElements = 0.0f;


	FILE * inFileHandle = NULL;
	FILE * outFileHandle = NULL;
	char inFilename[FILENAME_MAX] = "";
	char outFilename[FILENAME_MAX] = "";
	char c = ' ';
	int returnValue = EXIT_SUCCESS;
	if (argc > 1)
	{
		strncpy(inFilename, argv[1], FILENAME_MAX);
	}
	else
	{
		puts("Enter the name of the file to read (source):");
		fgets(inFilename, FILENAME_MAX, stdin);
		if (inFilename[strlen(inFilename) - 1] == '\n')
			inFilename[strlen(inFilename) - 1] = '\0';
		else
			while (getchar() != '\n')
				;
	}

	inFileHandle = fopen(inFilename, "r");
	if (inFileHandle == NULL)
	{
		printf("Could not open file %s for input.\n"
			"Press any key to Continue", inFilename);
		getch();
		returnValue = EXIT_FAILURE;
	}
	else
	{
		if (argc > 2)
		{
			strncpy(outFilename, argv[2], FILENAME_MAX);
		}
		else
		{
			puts("Enter the name of the file to write (output):");
			// gets() - not safe! (potential buffer overflow)
			fgets(outFilename, FILENAME_MAX, stdin);
			if (outFilename[strlen(outFilename) - 1] == '\n')
				outFilename[strlen(outFilename) - 1] = '\0';
			else
				while (getchar() != '\n')
					;
		}

		outFileHandle = fopen(outFilename, "w");
		if (outFileHandle == NULL)
		{
			fclose(inFileHandle);
			printf("Could not open file %s for output.\n"
				"Press any key to Continue", outFilename);
			getch();
			returnValue = EXIT_FAILURE;
		}
		else
		{
			fprintf(outFileHandle, "The results from file %s are:\n", inFilename);
			fprintf(outFileHandle, "_____________________________________________________________________\n");
			fprintf(outFileHandle, "|# of data|  sum  |   range   | mean | variance | standard deviation|\n");
			fprintf(outFileHandle, "_____________________________________________________________________\n");

			//while ((c = (char)getc(inFileHandle)) != EOF)
			//{
			//	//if (c == ' ')
			//	//	c = '\n';
			//	//putc(c, outFileHandle);
			//}

			while ((fscanf(inFileHandle, "%d", &numElements)) == 1)
			{
				if (numElements != 0)
				{
					// for each element
					for (int i = 0; i < numElements; i++)
					{
						totalNumElements++;
						fscanf(inFileHandle, "%d", &currentElement);

						if (firstPass)
						{
							lowElement = currentElement;
							highElement = currentElement;
							firstPass = 0;
						}
						else if (currentElement < lowElement)
						{
							lowElement = currentElement;
						}
						else if (currentElement > highElement)
						{
							highElement = currentElement;
						}

						sumOfElements += currentElement;
						sumOfElementsSquares += (currentElement * currentElement);
					}

					// for each group of elements
					meanOfElements = (float)sumOfElements / totalNumElements;

					if (totalNumElements > 1)
					{
						varianceOfElements = (sumOfElementsSquares - ((float)(sumOfElements * sumOfElements) / totalNumElements)) / (totalNumElements - 1);
					}
					deviationOfElements = sqrt(fabs(varianceOfElements));
				}

				fprintf(outFileHandle, "| %7d | %5d | %3d to %2d | %4.3lf| %8.3lf | %17.3lf |\n", totalNumElements, sumOfElements,
					lowElement, highElement, meanOfElements, varianceOfElements, deviationOfElements);
				fprintf(outFileHandle, "_____________________________________________________________________\n");
			}

			fclose(inFileHandle);
			fclose(outFileHandle);
			puts("\nPress any key to Continue");
			getch();
		}
	}
	return returnValue;
}
