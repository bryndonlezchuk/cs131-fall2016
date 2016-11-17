#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFILENAME "FallGrades.dat"
#define OUTFILENAME "FallGradesPlus.dat"
#define NAME_MAX 81
#define SID_MAX 12
#define INCREMENT 1

int main(void)
{
	FILE *inFileHandler;
	FILE *outFileHandler;

	int exitStatus = EXIT_SUCCESS;
	char name[NAME_MAX] = "";
	char sid[SID_MAX] = "";
	float grade = 0.0f;

	if ((inFileHandler = fopen(INFILENAME, "r")) == NULL) // if failed to open input file
	{
		exitStatus = EXIT_FAILURE;
	}
	
	if ((outFileHandler = fopen(OUTFILENAME, "w")) == NULL) // if failed to open output file
	{
		if (exitStatus) // if EXIT_SUCCESS then... (indicating an active input file)
		{
			fclose(inFileHandler);
			exitStatus = EXIT_FAILURE;
		}
	}
	else // output file opens correctly
	{
		fgets(name, NAME_MAX, inFileHandler);
		fprintf(outFileHandler, "%s", name);
		fgets(sid, SID_MAX, inFileHandler);
		fprintf(outFileHandler, "%s\n", sid);

		while (fscanf(inFileHandler, "%f", &grade) != EOF)
		{
			if (grade <= 3.0f) //0.0 to 2.9
			{
				grade += INCREMENT;
			}
			else //3.0 to 4.0
			{
				grade = 4.0f;
			}
			fprintf(outFileHandler, "%3.1f ", grade); // print grade with one decimal followed by a space
		}

		if (exitStatus)
		{
			fclose(inFileHandler);
			fclose(outFileHandler);
		}

		return exitStatus;
	}
}