#include <stdio.h>
#include <stdlib.h>
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
int main(void)
{
	float annualInterestRatePercentage = 0.0f;
	float monthlyInterestRateInDecimal = 0.0f;

	int loanAmountInCents = 0;
	double loanAmountInDollars = 0.0;

	int numberOfPayments = 0;

	int paymentAmountInCents = 0;
	double paymentAmountInDollars = 0.0;







	monthlyInterestRateInDecimal = annualInterestRatePercentage / (MONTH_PER_YEAR * PERCENTAGE_BASE);
}