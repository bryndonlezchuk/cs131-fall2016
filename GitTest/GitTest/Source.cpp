#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

int main(void)
{
	char x = ' ';
	printf("Enter a character: ");
	scanf("%[\^]c", &x);
	printf("You entered \'%c\'", x);

	while(getchar() != '\n');
	getchar();

	return EXIT_SUCCESS;
}