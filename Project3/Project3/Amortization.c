#include <stdio.h>
#include <stdlib.h>
#include "../Amort/Amort.h"
#pragma warning(disable: 4996)

const int PERCENTAGE_BASE = 100;
const int MONTH_PER_YEAR = 12;

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
// Date:		11/8/2016
//
// Version:		1.00
//
// Environment:	Intel Core i5
//				Software: OS: Windows 10 
//				Compiles under Microsoft Visual Studio 2015
//
//				Intel Core i7
//				Software: OS: Windows 7
//				Compiles under Microsoft Visual Studio 2015
// 
// Input:		
//
// Output:		
//
// Calls:		
//
// Parameters:	void
//
// Returns:		EXIT_SUCCESS for successful completion 
//				EXIT_FAILURE for failed completion
//
// History Log:
//				11/8/16		bcl		started version 1.0
//----------------------------------------------------------------------------
int main(void)
{
	float annualInterestRatePercentage = 0.0f;
	float monthlyInterestRateInDecimal = 0.0f;

	int loanAmountInCents = 0;
	double loanAmountInDollars = 0.0;

	int numberOfPayments = 0;

	int paymentAmountInCents = 0;
	double paymentAmountInDollars = 0.0;

	printf("Welcome to Amortization by Bryndon Lezchuk.\n\n");

	char menuSelection = ' ';
	char continueChoice = ' ';
	int proceed = 1; // 1 = true, 0 = false

	while (proceed)
	{
		printf("Please select an option:\n");
		printf("\t1) Calculate (P)ayment size.\n");
		printf("\t2) Calculate (L)oan size.\n");
		printf("\t3) Calculate (N)umber of payments.\n");
		printf("\t4) (Q)uit.\n\n");
		printf("\tSelection: ");

		menuSelection = getchar();
		while (getchar() != '\n');

		switch (menuSelection)
		{
			case '1':
			case 'P':
			case 'p':

				break;
			case '2':
			case 'L':
			case 'l':
				break;
			case '3':
			case 'N':
			case 'n':
				break;
			case '4':
			case 'Q':
			case 'q':
				break;
			default:
				printf("Invalid option, please try again.\n\n");
				continue;
				break;
		}
		printf("\n");

		printf("Would you like to continue operations? (y/n) : ");

		continueChoice = getchar();
		while (getchar() != '\n');

		switch (continueChoice)
		{
			case 'y':
			case 'Y':
				proceed = 1;
				break;
			case 'n':
			case 'N':
				//break;
			default:
				proceed = 0;
				break;
		}
	}



	

	//monthlyInterestRateInDecimal = annualInterestRatePercentage / (MONTH_PER_YEAR * PERCENTAGE_BASE);

	return EXIT_SUCCESS;
}


float getMonthlyInterestInDecimal(float annualInterest)
{
	return annualInterest / (MONTH_PER_YEAR * PERCENTAGE_BASE);
}