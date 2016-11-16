#include <stdio.h> 
#include <stdlib.h>  
#include <string.h> 
#define SIZE 20

//****************************************************************************
// type definitions
//****************************************************************************
struct stuff_s
{
	char name[SIZE];
	int value;
};
typedef struct stuff_s stuffs;

union stuff_u
{
	char name[SIZE];
	int value;
};
typedef union stuff_u stuffu;

//****************************************************************************
//  function declarations
//****************************************************************************
void setName(stuffs *sptr, const char name[]);
void setName_u(stuffu *suptr, const char name[]);

//****************************************************************************
//  test driver
//****************************************************************************
int main(void)
{
	stuffs ss = {"my stuff", 100};
	stuffu su;
	su.value = 99;

	printf("size of struct: %d\nsize of union: %d\n",
		sizeof(ss), sizeof(su));

	printf("%d\n", su.value);
	printf("%s\n", su.name);
	setName(&ss, "The best stuff in the whole world");
	printf("%s, %d\n", ss.name, ss.value);
	
	setName_u(&su,"really,really,really good stuff");
	printf("%d\n", su.value);
	printf("%s\n", su.name);
	getchar();
    return EXIT_SUCCESS;
} 

//****************************************************************************
//  sets the name part of the stuffs struct
//****************************************************************************
void setName(stuffs *sptr, const char name[])
{
	strncpy(sptr->name, name, SIZE - 1);
	// oops-- needs the line below
	// sptr->name[SIZE - 1] = '\0';
}

//****************************************************************************
//  sets the name stuffs struct to contain the given name
//****************************************************************************
void setName_u(stuffu *suptr, const char name[])
{
	strncpy(suptr->name, name, SIZE - 1);
	// oops-- needs the line below
	// suptr->name[SIZE - 1] = '\0';
}