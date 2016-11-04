#include <stdio.h>
#include <stdlib.h>
#include "saferead.h"
#define SIZE 5
#define ROWS 2

void fillArray(int array[], int size);   //(int* array, int size)
void printArray(const int array[], int size);
void printArray2D(const int array[][SIZE], int rows);
//----------------------------------------------------------------------------
// playing with arrays
//----------------------------------------------------------------------------
int main(void)
{
	int intArray[SIZE] = {0};
	//int intArray[] = {0,1,2,3,4}; //array of 5
	int* a_ptr = intArray;
	int intArray2D[ROWS][SIZE] = {  {1, 2, 3, 4, 5},
									{6, 7, 8, 9, 0}};
	printArray2D(intArray2D, ROWS); 
	fillArray(intArray, SIZE);
	printArray(intArray, SIZE);
	getchar();
	return EXIT_SUCCESS;
}

//----------------------------------------------------------------------------
// fill the array from user
//----------------------------------------------------------------------------
void fillArray(int array[], int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("Enter in the value for element %d:" , i + 1);
		//safeReadInt(&array[i], "Enter a NUMBER");
		safeReadInt(array + i, "Enter a NUMBER");
	}
}

//----------------------------------------------------------------------------
// fill the array from user
//----------------------------------------------------------------------------
void printArray(const int array[], int size) //void printArray(const int* array, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d: %4d  | ", i, array[i]);		
	}
	putchar('\n');
}

void printArray2D(const int array[][SIZE], int rows)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
			printArray(array[i], SIZE);	
	}

}