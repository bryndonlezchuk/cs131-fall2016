#include "Amort.h"
#include <math.h>

/*
Given i, the monthly interest rate represented as a decimal (yearly rate  / 1200),  you can calculate:

the monthly payment amount;  if you know the principal and the number of monthly payments ("round" up to next cent),
the principal (total amount loaned);  if you know the payment amount and the number of months payments are to be made (round off to nearest cent),
the number of months;  if you know the payment amount and the total principal ("round" up to next integer).
*/

//
//
//
double getPaymentAmount(float monthlyInterestInDecimal, int numberMonths, double principalInDollars)
{
	// assumes numberMonths > 0, monthlyInterestInDecimal >= 0

	double paymentAmountInDollars = 0.0;

	if (monthlyInterestInDecimal > 0)
	{
		paymentAmountInDollars = ((pow((1.0 + monthlyInterestInDecimal), numberMonths) / (pow((1.0 + monthlyInterestInDecimal), numberMonths) - 1)) * principalInDollars * monthlyInterestInDecimal);
	}
	else if (monthlyInterestInDecimal = 0.0)
	{
		paymentAmountInDollars = (principalInDollars / numberMonths);
	}

	//returns the amount of each monthly payment ("rounded" up to the next cent).

	paymentAmountInDollars = (ceil(paymentAmountInDollars * 100) / 100);

	return paymentAmountInDollars;
}

//
//
//
double getLoanAmount(float monthlyInterestInDecimal, int numberMonths, double paymentAmountInDollars)
{
	double loanAmountInDollars = 0.0;

	if (monthlyInterestInDecimal > 0)
	{
		loanAmountInDollars = (pow((1.0 + monthlyInterestInDecimal), numberMonths) / (monthlyInterestInDecimal * pow((1.0 + monthlyInterestInDecimal), numberMonths))) * paymentAmountInDollars;
	}
	else if (monthlyInterestInDecimal == 0.0)
	{
		loanAmountInDollars = numberMonths * paymentAmountInDollars;
	}

	//returns the amount of the entire loan (rounded off to the nearest cent).
	loanAmountInDollars = (ceil(loanAmountInDollars * 100) / 100);

	return loanAmountInDollars;
}

//
//
//
int getNumberOfMonths(float monthlyInterestInDecimal, double paymentAmountInDollars, double principalInDollars)
{
	int numberMonths = 0;

	if (monthlyInterestInDecimal > 0)
	{
		numberMonths = (int)ceil((log(paymentAmountInDollars) - log(paymentAmountInDollars - (principalInDollars * monthlyInterestInDecimal))) / log(1 + monthlyInterestInDecimal));
	}
	else if (monthlyInterestInDecimal = 0)
	{
		numberMonths = (int)ceil(principalInDollars / paymentAmountInDollars);
	}

	//returns the number of monthly payments to be made ("rounded" up to the next integer).

	return numberMonths;
}