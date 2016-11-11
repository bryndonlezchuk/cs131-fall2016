#ifndef AMORT_H
#define AMORT_H
#include <math.h>
#pragma warning(disable: 4996)

double getPaymentAmount(float monthlyInterestInDecimal, int numberMonths, double principalInDollars);
double getLoanAmount();
int getNumberOfMonths();

#endif