#include <stdio.h>
#include <stdlib.h>

struct stuff
{
	int n;
	float f;
};
typedef struct stuff Stuff;
void printStuff(const Stuff * s_ptr);
void inputStuff(Stuff * s_ptr);
int isStuffEqual(const Stuff * s1_ptr, const Stuff * s2_ptr);
//----------------------------------------------------------------------------
int main(void)
{
	Stuff s1 = {3, 3.1f};
	Stuff s2 = s1;
	if(isStuffEqual(&s1, &s2))
		puts("equal");
	else
		puts(" not equal");
	inputStuff(&s1);
	s2.n = 4;
	s2.f = 4.4f;
	printStuff(&s1);
	getchar();
	return EXIT_SUCCESS;
}

//----------------------------------------------------------------------------
int isStuffEqual(const Stuff * s1_ptr, const Stuff * s2_ptr)
{
	return s1_ptr->n == s2_ptr->n && s1_ptr->f == s2_ptr->f; //  ->  is a target operator
	// (*s1_ptr).n == (*s2_ptr).n && s1_ptr->f == s2_ptr->f;
}

//----------------------------------------------------------------------------
void printStuff(const Stuff * s_ptr)
{
	// printf("n: %d, f: %f ", (*s_ptr).n, (*s_ptr).f); // ugly
	printf("n: %d, f: %f ", s_ptr->n, s_ptr->f);
}

//----------------------------------------------------------------------------
void inputStuff(Stuff * s_ptr)
{
	puts("Enter a number");
	while(scanf("%d", &s_ptr->n) != 1)
	{
		puts("Enter a NUMBER");
		while(getchar() != '\n')
			;
	}
	while(getchar() != '\n')
		;
	puts("Enter another number");
	while(scanf("%f", &s_ptr->f) != 1)
	{
		puts("Enter a NUMBER");
		while(getchar() != '\n')
			;
	}
	while(getchar() != '\n')
		;

}