//---------------------------------------------------------
// File: Project1.cpp
//
// Functions:
//    main()
//---------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

//---------------------------------------------------------
// Function: main() 
//
// Title: Project1
//
// Description: Change Counter
//
//
// Programmer: Bryndon Lezchuk (bryndonlezchuk@gmail.com)
//
// Date: 9/27/16
//
// Version: 1.00
//
// Environment:
//   Intel Core i5
//   Software: OS: Windows 10 
//   Compiles under Microsoft Visual Studio 2015
// 
// Input: 
//		- a dollar amount for a purchase
//		- the amount tendered for the purchase
//
// Output: 
//		- a listing of the change
//
// Parameters: void
//
// Returns: EXIT_SUCCESS for successful completion 
//
// History Log:
//   9/27/16	bcl		started version 1.0
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

	printf("Welcome to Change Counter by Bryndon Lezchuk!\n\n");
	printf("\tPlease enter the total amount of purchase: $");
	//input total amount of purchase
	printf("\t"); //output amount entered rounded to nearest cent

	printf("\tPlease enter amount of money tendered: $");
	//input tender amount
	printf("\t"); //output amount entered rounded to nearest cent

	

	return EXIT_SUCCESS;
}