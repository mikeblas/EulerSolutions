// Euler71.cpp : Defines the entry point for the console application.
//


/*

We've got to find the proper fraction less than, but closest to 3/7.  
Despite the way the problem is written in the description, we really don't need
to find all the values and sort them; we can just try to find one that's as
close as possible.

The brute force approach would evaluate a trillion fractions; it's actually
not impossible, but it's expensive -- particularly considering that we have to
check the fraction is also proper by doing GCD on the numerator and denominator.

A simple reduction of the search space can be done by starting at 3/8 (could've
started at 4/7, too).  Then, for each fraction:

1) Evaluate n/d
2) If greater than 3/7, increment the denominator
   Else if less than 3/7, increment the numerator
3) If closer than any other candidate, check to see if it's a proper fraction.
4) If so, record it as the next closest solution.

*/

#include "stdafx.h"

int greatestCommonDivisor(int m, int n)
{
	int r;

	do
	{
		r = m % n;
		if (r == 0)
			break;
		m = n;
		n = r;
	} while (true);

	return n;
}


int main()
{
	const int MILLION = 1000000;
	double limit = 3.0 / 7.0;
	double closest = 0.0;
	int closestNumerator = 0;
	int closestDenominator = 0;

	int denominator = 3;
	int numerator = 8;

	while (denominator <= MILLION && numerator <= MILLION) {

		double test = numerator / (double)denominator;
		if (test > limit) {
			denominator++;
		}
		else {

			if (1 == greatestCommonDivisor(denominator, numerator)) {

				if (limit - test < limit - closest) {
					closest = test;
					closestDenominator = denominator;
					closestNumerator = numerator;

					printf("%2.15f == %d / %d\n", closest, numerator, denominator);
				}
			}

			numerator++;
		}
	}

	return 0;
}


