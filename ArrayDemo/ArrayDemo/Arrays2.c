#include <stdio.h>
#include <stdlib.h>

#define ROWS1 5
#define COLS1 4
void fillArray(int a[], int size);
void printIntArray(const int a[], int size);
void printInt2dArray(const int a[][COLS1], int size);
void printInt2dArray2(const int a[][COLS1], int size);
int * getSubTotalArray(int subTotal[], const int a[], int size);
//----------------------------------------------------------------------------
int main(void)
{
	int ai[COLS1] = {0, 2, 3, 7};
	int subs[COLS1] ={0};
	int ai2[COLS1] = {0, 5, 8, 7};
	int ai3[ROWS1] = {1, 5, 8, 7, 9};
	int * oneDCollection[3] = {ai, ai2, ai3};

	int ai2d[ROWS1][COLS1] =  { {0, 1, 2, 3},
								{1, 2, 3, 4},
								{1, 3, 5, 7},
								{0, 2, 4, 6},
								{1, 4, 7, 0} };
	puts("enter numbers");
	fillArray(ai, COLS1);
	getchar();
	printf("%d\n", ai2d[1][2]);	
	printf("%d\n", (*ai2d[1]) + 2);		
	printf("%d\n", (*(*ai2d) + 1) + 2);
	printf("%d\n", oneDCollection[1][2]); // 8
	printIntArray(ai, COLS1);	
	printIntArray(ai + 1, COLS1 - 2);
	printInt2dArray(ai2d, ROWS1);
	puts("");
	printInt2dArray2(ai2d, ROWS1);
puts("subtotal");
	printIntArray(getSubTotalArray(subs, ai, COLS1), COLS1 );
	getchar();
	return EXIT_SUCCESS;
}

//----------------------------------------------------------------------------
// subTotal will contain a running subtotal of a
//----------------------------------------------------------------------------
int * getSubTotalArray(int subTotal[], const int a[], int size)
{
	int i = 0;
	int sub = 0;
	if (size > 0)
	{
		for(i = 0; i < size; i++)
		{
			sub += a[i];
			subTotal[i] = sub;
		}
	}
	return subTotal;
}

//----------------------------------------------------------------------------
 void fillArray(int a[], int size)
 {
	int i = 0;
	for(i = 0; i < size; i++)
	{
		scanf("%d", a + i); //scanf("%d", &a[i])

	}

 }
 
//----------------------------------------------------------------------------
void printIntArray(const int a[], int size)
// void printIntArray(const int * const a, int size)
{
	int i = 0;
	putchar('|');
	for(i = 0; i < size; i++)
	{
		printf("%4d|", a[i]);
	}
	putchar('\n');
}

//----------------------------------------------------------------------------
void printInt2dArray(const int a[][COLS1], int size)
{
	int i = 0;
	for(i = 0; i < size; i++)
	{
		printIntArray(a[i], COLS1);
	}
}

//----------------------------------------------------------------------------
void printInt2dArray2(const int a[][COLS1], int size)
{
	int i = 0;
	int j = 0;
	for(i = 0; i < size; i++)
	{
		putchar('|');
		for(j = 0; j < COLS1; j++)
		{
			printf("%4d|", a[i][j]);
		}
	putchar('\n');
	}
}