//---------------------------------------------------------
// File: Project1.cpp
//
// Functions:
//    main()
//---------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable: 4996)

const int CENTS_PER_TWENTY = 2000;
const int CENTS_PER_TEN = 1000;
const int CENTS_PER_FIVE = 500;
const int CENTS_PER_ONE = 100;
const int CENTS_PER_QUARTER = 25;
const int CENTS_PER_DIME = 10;
const int CENTS_PER_NICKLE = 5;

const float DOLLAR_PER_TWENTY = 20.00f;
const float DOLLAR_PER_TEN = 10.00f;
const float DOLLAR_PER_FIVE = 5.00f;
const float DOLLAR_PER_ONE = 1.00f;
const float DOLLAR_PER_QUARTER = 0.25f;
const float DOLLAR_PER_DIME = 0.10f;
const float DOLLAR_PER_NICKLE = 0.05f;
const float DOLLAR_PER_PENNY = 0.01f;

//const 

double roundToCent(double numToRound);
double shiftDecimal(double numberToRound, int decimalPlaces);

//---------------------------------------------------------
// Function:	main() 
//
// Title:		Project1
//
// Description:	Change Counter
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
// Input:		- user inputs a dollar amount for a purchase
//				- user inputs the amount tendered for the purchase
//
// Output:		- console output of purchase amount entered
//				- console output of tender amount entered
//				- console output of the listing of the change
//
// Calls:		roundToCents()
//
// Parameters:	void
//
// Returns:		EXIT_SUCCESS for successful completion 
//
// History Log:
//				9/27/16	bcl		started version 1.0
//---------------------------------------------------------
int main(void)
{
	/*
		Design, write and test a fully documented, user 
		friendly ANSI C program which takes in (a) a dollar 
		amount for a purchase and (b) the amount tendered
		for the purchase. The program should then give a 
		listing of the change, specifically in the 
		denominations listed below.

		To do this, calculate the total change as an 
		integer number of cents. It should be accurate 
		for a positive, zero or negative amount of change. 
		Enter in the cost and tendered amounts as fixed 
		floating point numbers, rounding off to the nearest 
		cent--be careful not to lose pennies due to rounding 
		errors. Print these values to two places. Calculate 
		the total change as a floating point number, round 
		off to the nearest cent, and display it to two 
		decimal places. Now use an integer variable to store 
		this number (multiplied by 100) as the number of 
		cents. Divide to find the number of twenties, tens, 
		etc., exactly as in the example below--no other 
		denominations. You MUST use the % (or %=) operator 
		to find the remainder after each denomination is 
		removed from the total. Do not use arrays or loops.
	*/
	double purchaseTotalInDollars = 0.00;
	double tenderAmountInDollars = 0.00;
	double changeinDollars = 0.00;

	int purchaseTotalInCents = 0;
	int tenderAmountInCents = 0;
	int changeInCents = 0;

	int numTwenties = 0;
	int numTens = 0;
	int numOnes = 0;
	int numQuarters = 0;
	int numDimes = 0;
	int numNickles = 0;
	int numPennies = 0;

	int remainderInCents = 0;
	

	printf("Welcome to Change Counter by Bryndon Lezchuk!\n\n");
	printf("\tPlease enter the total amount of purchase: $");
	scanf("%lf",&purchaseTotalInDollars);									//input total amount of purchase
	purchaseTotalInDollars = roundToCent(purchaseTotalInDollars);			//round to nearest penny
	printf("\t$%.2lf\n", purchaseTotalInDollars);							//output amount entered rounded to nearest cent

	printf("\tPlease enter amount of money tendered: $");
	scanf("%lf", &tenderAmountInDollars);									//input tender amount
	tenderAmountInDollars = roundToCent(tenderAmountInDollars);				//round to nearest penny
	printf("\t$%.2lf\n", tenderAmountInDollars);							//output amount entered rounded to nearest cent

	////convert dollars to cents
	//purchaseTotalInCents = (int)round(purchaseTotalInDollars * CENTS_PER_ONE);
	//tenderAmountInCents = (int)round(tenderAmountInDollars * CENTS_PER_ONE);

	//calculate change
	changeinDollars = tenderAmountInDollars - purchaseTotalInDollars;
	changeInCents = shiftDecimal(changeinDollars, 2);

	printf("\tYour change is: $%.2lf\n",changeinDollars);

	printf("\t-------------------------------------------\n");

	//count change
	numTwenties = changeInCents / CENTS_PER_TWENTY;
	remainderInCents = changeInCents % CENTS_PER_TWENTY;
	printf("\tTwenties\t: %d\n", numTwenties);

	numTens = remainderInCents / CENTS_PER_TEN;
	remainderInCents %= CENTS_PER_TEN;
	printf("\tTens\t\t: %d\n", numTens);

	getchar();

	return EXIT_SUCCESS;
}


//---------------------------------------------------------
// Function:	roundToCent(double numToRound)
//
// Title:		Round Off Cents
//
// Description: Rounds a dollar amount off to the nearest
//					complete cent ($0.01)
//
// Programmer:	Bryndon Lezchuk (bryndonlezchuk@gmail.com)
//
// Date:		9/29/16
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
// Input:		
//
// Output:		
//
// Parameters:	double numToRound 
//
// Returns:		the parameter number rounded to 2 decimal points
//
// History Log:
//				9/29/16	bcl		created version 1.0
//---------------------------------------------------------
double roundToCent(double numToRound)
{
	return (floor((numToRound * 100.0) + 0.5) / 100.0);
}



double shiftDecimal(double numberToShift, int decimalPlaces)
{
	double multiplier = pow(10.0, decimalPlaces);
	
	return (numberToShift * multiplier);
}