#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct person
{
	char name[FILENAME_MAX];
	int age;
	char gender;
};
typedef struct person Person;

void printPerson(const Person* person_ptr);

int main(void)
{
	Person me = { "Fred", 93, 'M' };
	Person you;
	printPerson(&me);
	strcpy(you.name, "Barney");
	you.age = 89;
	you.gender = 'M';
	printPerson(&you);
	getchar();
	return EXIT_SUCCESS;
}

void printPerson(const Person* person_ptr)
{
	//printf("%s, %c, age: %d", (*person_ptr).name, (*person_ptr).gender,
	//	(*person_ptr).age);
	printf("%s, %c, age: %d\n", person_ptr->name, person_ptr->gender,
		person_ptr->age);
}