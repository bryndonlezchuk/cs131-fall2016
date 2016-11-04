#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
void copyArray(const int a1[], int a2, int length);

int main(void)
{
	int ia[SIZE] = { 2, 4, 6, 8, 0 };
	int ia2[SIZE] = { 0 };
	int i = 0;
	for (i = 0; i < SIZE; i++)
		printf("%3d", ia[i]);
	puts("");
	for (i = 0; i < SIZE; i++)
		printf("%3d", ia2[i]);
	puts("");
	puts("");
	copyArray(ia, ia2, SIZE);

	for (i = 0; i < SIZE; i++)
		printf("%3d", ia2[i]);
	puts("");
	getchar();
	return EXIT_SUCCESS;
}
// pre: a1 and a2 are the same length
void copyArray(const int a1[], int a2[], int length)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		a2[i] = a1[i];
		// *(a2 + i) = *(a1 + i);
	}
}