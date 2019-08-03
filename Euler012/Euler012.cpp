// Euler012.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

void Problem12()
{
	bool found = false;
	int candidate = 7;
	int tnumber = 28;

	while (!found)
	{
		/*
		int tnumber = 0;
		for ( int n = 1; n <= candidate; n++ )
		{
			tnumber += n;
		}
		*/

		// itself and one, plus ...
		int divisors = 2;
		for (int n = 2; n <= tnumber / 2; n++)
		{
			if (tnumber % n == 0)
				divisors += 1;
		}

		printf("%d: %d\n", candidate, divisors);

		if (divisors > 500)
		{
			printf("Value is %d\n", tnumber);
			found = true;
		}

		candidate++;
		tnumber += candidate;
	}
}



int main()
{
	Problem12();

}
